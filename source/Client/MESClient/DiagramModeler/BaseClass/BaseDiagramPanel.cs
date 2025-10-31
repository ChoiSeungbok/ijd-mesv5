// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : BaseDiagramPanel.cs
// 파일 설명    : 다이어그램을 보여주거나 편집할 수 있는 컨테이너(Container) 컨트롤의 구현
// 최초 작성자  : 임혁수(maverick@miracom.co.kr)
// 최초 작성일  : 2007년 5월 7일 
// 최종 수정일  : 2007년 5월 7일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 07 : [임혁수] 최초 작성
// 2007. 05. 14 : [노현종] Properties, Constructor, Event Region 추가와 Method 추가 및 구현
// 2007. 05. 30 : [노현종] 기본기능 구현 완료
// 2007. 06. 12 : [노현종] CustomConnection, CustomConnectionHolder를 외부에서 추가하여 내부적으로 적용할 수
//                         있도록 하는 구현 추가
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Imaging;
using System.Drawing.Printing;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 다이어그램을 보여주거나 편집할 수 있는 컨테이너 컨트롤을 구현한 클래스입니다.
    /// </summary>
    public partial class BaseDiagramPanel : Panel, IDiagramVisualizer
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        bool isDesignMode = true;

        const int _iMarginSize = 2;
        const int _iResizeMargin = 5;
        const int _iPrecisionSize = 10;

        static readonly Point _defaultElementLocation = new Point(5, 5);
        static readonly Color _transparentAlternativeColor = Color.FromArgb(194, 203, 207);

        /// <summary>
        /// 노드(도형) 리스트
        /// </summary>
        protected List<BaseShape> shapes = new List<BaseShape>();

        /// <summary>
        /// 간선 리스트
        /// </summary>
        protected List<BaseConnection> connections = new List<BaseConnection>();

        List<BaseConnection> customConnections = new List<BaseConnection>();
        List<BaseHolder> customHolders = new List<BaseHolder>();
        
        // PreviewConnection variables
        bool bConnecting = false;
        BaseHolder previewStartHolder = null;
        BaseHolder previewEndHolder = null;
        PreviewConnection previewConnection = null;

        // Positioning variables
        bool bShapePositioning = false;
        bool bShapeHorizontalResizing = false;
        bool bShapeVerticalResizing = false;
        Point oldMouseLocation = Point.Empty;
        Size oldSize = Size.Empty;
        BaseHolder modifyingNode = null;

        // Selectioning variables
        bool bSelecting = false;
        bool bSelectionChanged = false;
        bool bSelectionChanging = false;
        int iSelectedElementCount = 0;
        int iSelectionChangingSetCount = 0;
        Point selectionStartPoint = Point.Empty;
        Rectangle selectionRectangle = Rectangle.Empty;
        IDiagramElement firstSelectedElement = null;

        DiagramGrid diagramGrid = new DiagramGrid();

        /// <summary>
        /// 내용 변경에 대한 이벤트 핸들러 입니다.
        /// </summary>
        public event EventHandler ContentsChanged;

        /// <summary>
        /// 선택 변경에 대한 이벤트 핸들러 입니다.
        /// </summary>
        public event EventHandler SelectionChanged;

        /// <summary>
        /// 요소 삭제에 대한 이벤트 핸들러 입니다.
        /// </summary>
        public event EventHandler ElementDeleted;

        #endregion

        
        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Diagram Panel에서 사용할 배경 Grid를 설정하거나 가져오는 프로퍼티 입니다.
        /// </summary>
        public DiagramGrid Grid
        {
            get { return diagramGrid;  }
            set { diagramGrid = value; }
        }
        
        /// <summary>
        /// 간선 리스트를 받아오는 프로퍼티 입니다.
        /// </summary>
        public List<BaseConnection> Connections
        {
            get { return connections; }
        }

        /// <summary>
        ///  바탕색을 나타내는 값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        [Browsable(false)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public override Color BackColor
        {
            get
            {
                return base.BackColor;
            }
            set
            {
                if (value.A < 255)
                    base.BackColor = _transparentAlternativeColor;
                else
                    base.BackColor = value;
            }
        }

        /// <summary>
        /// WFM_Undo 작업이 가능한지를 나타내는 값을 가져오는 프로퍼티 입니다.
        /// </summary>
        [Browsable(false)]
        public bool CanUndo
        {
            get { return false; }
        }

        /// <summary>
        /// WFM_Redo 작업이 가능한지를 나타내는 값을 가져오는 프로퍼티 입니다.
        /// </summary>
        [Browsable(false)]
        public bool CanRedo
        {
            get { return false; }
        }

        /// <summary>
        /// 선 연결 값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        protected bool Connecting
        {
            get
            {
                return bConnecting;
            }
            set
            {
                if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함


                if (value && !bConnecting)
                {
                    if (DiagramSettings.UseCustomConnectionHolder)
                    {
                        previewStartHolder = CurrentCustomConnectionHolder.CreateNew();
                        previewEndHolder = CurrentCustomConnectionHolder.CreateNew();
                    }
                    else
                    {
                        previewStartHolder = new DefaultHolder();
                        previewEndHolder = new DefaultHolder();
                    }
                    previewConnection = new PreviewConnection(previewStartHolder, previewEndHolder);
                    connections.Add(previewConnection);
                    DeselectElements();
                }
                else if (!value && bConnecting)
                {
                    bConnecting = value;

                    if (StartChosen && EndChosen)
                    {
                        try
                        {
                            AddConnection(previewStartHolder.Shape.Entity, previewEndHolder.Shape.Entity, true);
                            OnContentsChanged(EventArgs.Empty);
                        }
                        catch (ArgumentException ex)
                        {
                            MessageBox.Show(ex.Message, ("error"),
                                MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }
                    }
                    connections.Remove(previewConnection);
                    previewStartHolder = null;
                    previewEndHolder = null;
                    previewConnection = null;
                    Invalidate();
                }

                StartChosen = false;
                EndChosen = false;
                if (value)
                {
                    previewStartHolder.Shape = null;
                    previewEndHolder.Shape = null;
                    Invalidate();
                }

                bConnecting = value;
            }
        }

        /// <summary>
        /// 연결 위치를 가져오는 프로퍼티 입니다.
        /// </summary>
        private bool ConnectionPositioning
        {
            get
            {
                return (Connecting && (previewStartHolder.Shape != null || previewEndHolder.Shape != null));
            }
        }

        /// <summary>
        /// 현재 사용되고 있는 사용자 정의 Connection을 가져옵니다.
        /// </summary>
        public BaseConnection CurrentCustomConnection
        {
            get { return customConnections[DiagramSettings.CurrentCustomConnectionIndex]; }
        }

        /// <summary>
        /// 현재 사용되고 있는 사용자 정의 ConnectionHolder를 가져옵니다.
        /// </summary>
        public BaseHolder CurrentCustomConnectionHolder
        {
            get { return customHolders[DiagramSettings.CurrentCustomConnectionHolderIndex]; }
        }

        /// <summary>
        /// Design 작업을 하도록 허용하는지에를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public bool DiagramDesignMode
        {
            get { return isDesignMode; }
            set 
            { 
                isDesignMode = value;
                this.Enabled = value;                
                Invalidate();
            }
        }

        /// <summary>
        /// 노드와 간선을 합한 총 요소의 수를 가져오는 프로퍼티 입니다.
        /// </summary>
        [Browsable(false)]
        public int ElementCount
        {
            get
            {
                return (shapes.Count + connections.Count);
            }
        }

        /// <summary>
        /// 현재 연결을 수행하려고 작업중인 끝 노드를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        private bool EndChosen
        {
            get
            {
                if (previewConnection != null)
                    return previewConnection.EndChosen;
                else
                    return false;
            }
            set
            {
                if (previewConnection != null)
                    previewConnection.EndChosen = value;
            }
        }

        /// <summary>
        /// 선택된 노드와 간선들중 가장 먼저 선택된 대상을 가져오는 프로퍼티 입니다.
        /// </summary>
        [Browsable(false)]
        public IDiagramElement FirstSelectedElement
        {
            get
            {
                if (SelectedElementCount > 0)
                    return firstSelectedElement;
                else
                    return null;
            }
        }

        /// <summary>
        /// ModifyingNode ConnectionHolder를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        private BaseHolder ModifyingNode
        {
            get
            {
                return modifyingNode;
            }
            set
            {
                if (value != null && modifyingNode == null)
                    Cursor = Cursors.SizeAll;
                else if (value == null && modifyingNode != null)
                    Cursor = Cursors.Default;

                modifyingNode = value;
            }
        }

        /// <summary>
        /// 수직 수평의 스크롤에 따른 Offset을 Size를 가져오는 프로퍼티 입니다.
        /// </summary>
        public Size Offset
        {
            get { return new Size(HorizontalScroll.Value, VerticalScroll.Value); }
        }

        /// <summary>
        /// 
        /// </summary>
        private bool OverTeminalNode
        {
            get { return (ModifyingNode != null); }
        }

        /// <summary>
        /// 선택된 요소들를 가져오거나 설정하는 입니다.
        /// </summary>
        [Browsable(false)]
        public IEnumerable<IDiagramElement> SelectedElements
        {
            get
            {
                for (int i = 0; i < shapes.Count; i++)
                {
                    if (shapes[i].IsSelected)
                        yield return shapes[i];
                }
                for (int i = 0; i < connections.Count; i++)
                {
                    if (connections[i].IsSelected)
                        yield return connections[i];
                }
            }
        }

        /// <summary>
        /// 선택된 요소의 수를 가져오는 프로퍼티 입니다.
        /// </summary>
        [Browsable(false)]
        public int SelectedElementCount
        {
            get
            {
                return iSelectedElementCount;
            }
            private set
            {
                if (iSelectedElementCount != value)
                {
                    iSelectedElementCount = value;
                    OnSelectionChanged(EventArgs.Empty);
                }
                else
                {
                    iSelectedElementCount = value;
                }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        private bool ShapeResizing
        {
            get { return (bShapeHorizontalResizing || bShapeVerticalResizing); }
        }

        /// <summary>
        /// 선택 변경에 대한 프로퍼티 입니다.
        /// </summary>
        private bool SelectionChanging
        {
            get
            {
                return bSelectionChanging;
            }
            set
            {
                if (value)
                {
                    iSelectionChangingSetCount++;
                    bSelectionChanging = value;
                }
                else
                {
                    if (--iSelectionChangingSetCount < 0)
                        iSelectionChangingSetCount = 0;

                    if (iSelectionChangingSetCount == 0)
                    {
                        if (bSelectionChanged)
                            OnSelectionChanged(EventArgs.Empty);
                        bSelectionChanged = false;
                        bSelectionChanging = false;
                        Invalidate();
                    }
                }
            }
        }

        /// <summary>
        /// 현재 연결을 수행하려고 작업중인 시작 노드에 접근하는 프로퍼티 입니다.
        /// </summary>
        private bool StartChosen
        {
            get
            {
                if (previewConnection != null)
                    return previewConnection.StartChosen;
                else
                    return false;
            }
            set
            {
                if (previewConnection != null)
                    previewConnection.StartChosen = value;
            }
        }

        /// <summary>
        /// Holder를 지정한 위치로 이동시킵니다.
        /// </summary>
        /// <param name="holder">이동시킬 Holder</param>
        /// <param name="mouseLocation">이동시킬 위치</param>
        /// <returns>이동시킨 결과</returns>
        private bool SetHolder(BaseHolder holder, Point mouseLocation)
        {
            for (int i = 0; i < shapes.Count; i++)
            {
                if (IsShapeEdge(shapes[i], mouseLocation))
                {
                    holder.Shape = shapes[i];
                    holder.SetPosition(mouseLocation);
                    return true;
                }
            }

            return false;
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 기본생성자입니다.
        /// </summary>
        public BaseDiagramPanel()
        {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.Width = DiagramSettings.WorkspaceWidth;
            this.Height = DiagramSettings.WorkspaceHeight;
        }

        #endregion
        

        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Diagram Panel상에서 노드간 선 연결 작업을 작동하도록 합니다.
        /// 한회 작동시 DefaultConnection 1개를 생성할 수 있습니다.
        /// ( StartNode를 클릭하고 EndNode를 클릭하면 연결됩니다. )
        /// </summary>
        public void ActivateConnector()
        {
            Connecting = true;
        }

        /// <summary>
        /// 노드(도형)을 추가해주고 이번트를 연결해주는 작업을 수행합니다.
        /// </summary>
        /// <param name="shape">추가할 노드(도형)</param>
        /// <param name="iLocation">추가할 좌표</param>
        /// <returns>추가된 노드(도형)</returns>
        internal BaseShape AddShape(BaseShape shape, Point location)
        {
            if (shape == null)
                throw new ArgumentNullException("shape");

            if (location.IsEmpty)
                shape.Location = GetNewLocation(shape.Size);
            else
                shape.Location = location;

            if(DiagramSettings.Zoom != 1.0F)
            {
                location.X = (int)(location.X * DiagramSettings.Zoom);
                location.Y = (int)(location.Y * DiagramSettings.Zoom);
                shape.Scale(new SizeF(DiagramSettings.Zoom, DiagramSettings.Zoom));
            }

            shape.KeyDown += new KeyEventHandler(Shape_KeyDowned);
            shape.Enter += new EventHandler(Shape_Enter);
            shape.Move += new EventHandler(Shape_Move);
            shape.MouseDown += new MouseEventHandler(Shape_MouseDown);
            shape.MouseMove += new MouseEventHandler(Shape_MouseMove);
            shape.MouseUp += new MouseEventHandler(Shape_MouseUp);
            shape.Resize += new EventHandler(Shape_Resize);
            shape.ContentChanged += new EventHandler(Element_ContentChanged);
            shape.SelectionChanged += new EventHandler(Element_SelectionChanged);
            shape.ElementDeleted += new EventHandler(Element_ElementDeleted);

            AddShapeEventHandler(shape);

            shapes.Add(shape);

            

            Connecting = false;

            return shape;
        }

        /// <summary>
        /// 상속받은 클래스에서 추가적으로 Shape의 핸들러를 다루고자 할때 Override하여 핸들 추가 작업을 하도록 합니다.
        /// ( 도형이 Panel이 추가되는 작업 중간에 호출됩니다. )
        /// </summary>
        /// <param name="shape"></param>
        protected virtual void AddShapeEventHandler(BaseShape shape)
        {
        }

        /// <summary>
        /// 연결 미리보기 선을 적용합니다.
        /// </summary>
        private void ApplyPreviewConnection()
        {
            if (!StartChosen && previewStartHolder.Shape != null)
            {
                StartChosen = true;
            }
            else if (StartChosen && previewEndHolder.Shape != null)
            {
                EndChosen = true;
                Connecting = false;
            }
        }

        /// <summary>
        /// 관계를 추가합니다.
        /// </summary>
        /// <param name="first">StartNode의 Entity정보</param>
        /// <param name="second">EndNode의 Entity정보</param>
        /// <param name="fromScreen">모니터상의 작업으로부터 요청인지에 대한 Bool값</param>
        /// <returns></returns>
        private BaseConnection AddConnection(Entity first, Entity second, bool fromScreen)
        {
            BaseConnection connection = null;

            if (!fromScreen || previewStartHolder == null || previewEndHolder == null)
            {
                if (DiagramSettings.UseCustomConnectionHolder)
                {
                    previewStartHolder = CurrentCustomConnectionHolder.CreateNew();
                    previewEndHolder = CurrentCustomConnectionHolder.CreateNew();
                }
                else
                {
                    previewStartHolder = new DefaultHolder();
                    previewEndHolder = new DefaultHolder();
                }

                for (int i = 0; i < shapes.Count; i++)
                {
                    if (shapes[i].Entity == first)
                        previewStartHolder.Shape = shapes[i];
                    if (shapes[i].Entity == second)
                        previewEndHolder.Shape = shapes[i];
                }
            }

            previewStartHolder.IsDirty = true;
            previewEndHolder.IsDirty = true;

            if (DiagramSettings.UseCustomConnection)
            {
                connection = CurrentCustomConnection.CreateNew(previewStartHolder, previewEndHolder);
            }
            else
            {
                connection = new DefaultConnection(previewStartHolder, previewEndHolder);
            }

            if (connection.IsConnectable == false)
                return connection;

            if (connection == null)
                throw new ArgumentException("Relation Exception");

            connection.ContentsChanged += new EventHandler(Element_ContentChanged);
            connection.SelectionChanged += new EventHandler(Element_SelectionChanged);
            connection.ElementDeleted += new EventHandler(Element_ElementDeleted);
            connections.Add(connection);

            return connection;
        }

        /// <summary>
        /// 지정된 Connection을 추가합니다.
        /// </summary>
        /// <param name="connection">추가할 DefaultConnection</param>
        public void AddConnection(BaseConnection connection)
        {
            connections.Add(connection);
            connection.StartHolder.IsDirty = true;
            connection.EndHolder.IsDirty = true;

            Invalidate();
        }

        /// <summary>
        /// 사용자 정의 Connection을 리스트에 추가합니다.
        /// </summary>
        /// <param name="connection">추가할 DefaultConnection</param>
        /// <returns>추가 처리 결과 True/False</returns>
        public bool RegisterCustomConnection(BaseConnection connection)
        {
            if (connection == null)
                return false;

            if (customConnections.Contains(connection))
                return false;

            customConnections.Add(connection);

            return true;
        }

        /// <summary>
        /// 사용자 정의 Connection을 리스트에서 제거합니다.
        /// </summary>
        /// <param name="connection">삭제할 DefaultConnection</param>
        /// <returns>삭제 처리 결과 True/False</returns>
        public bool UnregisterCustomConnection(BaseConnection connection)
        {
            if (connection == null)
                return false;

            if (!customConnections.Contains(connection))
                return false;

            if (customConnections.IndexOf(connection) == DiagramSettings.CurrentCustomConnectionIndex)
                DiagramSettings.CurrentCustomConnectionIndex = 0;

            customConnections.Remove(connection);

            return true;
        }

        /// <summary>
        /// 사용자 정의 ConnectionHolder를 리스트에 추가합니다.
        /// </summary>
        /// <param name="holder">추가할 DefaultHolder</param>
        /// <returns>추가 처리 결과 True/False</returns>
        public bool RegisterCustomHolder(BaseHolder holder)
        {
            if (holder == null)
                return false;

            if (customHolders.Contains(holder))
                return false;

            customHolders.Add(holder);

            return true;
        }

        /// <summary>
        /// 사용자 정의 ConnectionHolder를 리스트에서 제거합니다.
        /// </summary>
        /// <param name="holder">삭제할 DefaultHolder</param>
        /// <returns>삭제 처리 결과 True/False</returns>
        public bool UnregisterCustomHolder(BaseHolder holder)
        {
            if (holder == null)
                return false;

            if (!customHolders.Contains(holder))
                return false;

            if (customHolders.IndexOf(holder) == DiagramSettings.CurrentCustomConnectionHolderIndex)
                DiagramSettings.CurrentCustomConnectionHolderIndex = 0;

            customHolders.Remove(holder);

            return true;
        }

        /// <summary>
        /// 새 노드(도형)을 추가합니다. - ( 차후 수정이 필요 )
        /// </summary>
        /// <param name="shape">추가할 노드(도형)</param>
        public void AddNewShape(BaseShape shape)
        {
            AddNewShape(shape, Point.Empty);
            Invalidate();
        }

        /// <summary>
        /// 새 노드(도형)을 추가합니다. - ( 차후 수정이 필요 )
        /// </summary>
        /// <param name="shape">추가할 노드(도형)</param>
        /// <param name="iLocation">위치를 나타내는 Point</param>
        public void AddNewShape(BaseShape shape, Point location)
        {
            this.Controls.Add(AddShape(shape, location));
        }

        /// <summary>
        /// 선택 영역 사각형을 정리합니다. ( DrawSelectionRectangle과 바로 연결되어 있음 )
        /// </summary>
        private void ClearSelectionRectangle()
        {
            DrawSelectionRectangle();
        }

        /// <summary>
        /// Diagram의 경계 영역을 확인합니다.
        /// </summary>
        /// <param name="movingSize">이동 크기 Size</param>
        /// <returns>경계 영역을 확인하여 보정된 이동 크기 Size</returns>
        private Size CheckDiagramBorders(Size movingSize)
        {
            for (int i = 0; i < shapes.Count; i++)
            {
                if (shapes[i].IsSelected)
                {
                    Point newLocation = shapes[i].Location + movingSize + Offset;

                    if (newLocation.X < _iMarginSize)
                        movingSize.Width -= newLocation.X - _iMarginSize;
                    if (newLocation.Y < _iMarginSize)
                        movingSize.Height -= newLocation.Y - _iMarginSize;
                }
            }

            return movingSize;
        }

        /// <summary>
        /// 선택된 요소들의 수를 계산합니다.
        /// </summary>
        private void CountSelectedElements()
        {
            int count = 0;

            for (int i = 0; i < shapes.Count; i++)
                if (shapes[i].IsSelected)
                    count++;
            for (int i = 0; i < connections.Count; i++)
                if (connections[i].IsSelected)
                    count++;

            iSelectedElementCount = count;
        }

        /// <summary>
        /// 마우스 위치를 기준으로 터미널 노드를 확인합니다.
        /// </summary>
        /// <param name="mouseLocation">마우스의 위치값 Point</param>
        private void CheckHolders(Point mouseLocation)
        {
            for (int i = 0; i < connections.Count; i++)
            {
                BaseHolder node = connections[i].GetHolder(mouseLocation);

                if (node != null)
                {
                    ModifyingNode = node;
                    return;
                }
            }

            ModifyingNode = null;
        }

        /// <summary>
        /// 선택된 요소를 삭제합니다. ( 삭제할지에 대한 확인을 수행합니다. )
        /// </summary>
        public virtual void DeleteSelectedElements()
        {
            if (SelectedElementCount == 0)
                return;

            if (MessageBox.Show(("Element Deletion"),
                ("confirmation"), MessageBoxButtons.YesNo,
                MessageBoxIcon.Warning) == DialogResult.Yes)
            {
                RemoveSelectedElements();
            }
        }

        /// <summary>
        /// 요소 선택을 초기화 하여 아무것도 선택되지 않은 상태로 되돌려주는 작업을 수행합니다.
        /// </summary>
        private void DeselectElements()
        {
            if (SelectedElementCount > 0)
            {
                SelectionChanging = true;
                for (int i = 0; i < shapes.Count; i++)
                    shapes[i].IsSelected = false;
                for (int i = 0; i < connections.Count; i++)
                    connections[i].IsSelected = false;

                SelectedElementCount = 0;
                SelectionChanging = false;
            }
        }

        /// <summary>
        /// 간선 그리기 작업을 수행합니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        private void DrawConnections(Graphics g)
        {
            for (int i = 0; i < connections.Count; i++)
                connections[i].DrawOnScreen(g, Point.Empty, DiagramSettings.Zoom);
        }

        /// <summary>
        /// 도형(노드) 그리기 작업을 수행합니다
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        private void DrawShapes(Graphics g, Point location, float scale)
        {
            for (int i = 0; i < shapes.Count; i++)
                if (shapes[i].Visible)
                {
                    shapes[i].Draw(g, location, scale );
                    shapes[i].ExternalLabel.Draw(g, shapes[i].AbsoluteLocation);
                }
        }

        /// <summary>
        /// 도형(노드에) 붙은 외부 Label 그리기 작업을 수행합니다.
        /// </summary>
        /// <param name="g"></param>
        private void DrawElementLabels(Graphics g)
        {
            for (int i = 0; i < shapes.Count; i++)
                if(shapes[i].Visible)
                    shapes[i].ExternalLabel.Draw(g, shapes[i].AbsoluteLocation);
                    
        }

        /// <summary>
        /// 영역 선택 사각형을 그립니다.
        /// </summary>
        private void DrawSelectionRectangle()
        {
            if (selectionRectangle.Size != Size.Empty)
            {
                Rectangle rectangle = selectionRectangle;

                rectangle.Location += (Size)this.PointToScreen(Point.Empty);
                ControlPaint.DrawReversibleFrame(rectangle, this.BackColor, FrameStyle.Dashed);
            }
        }

        /// <summary>
        /// 새 위치를 생성합니다.
        /// </summary>
        /// <param name="shapeSize">도형의 크기값 Size</param>
        /// <returns>생성된 좌표 Point</returns>
        private Point GetNewLocation(Size shapeSize)
        {
            Point newLocation = _defaultElementLocation;
            bool isEmpty = false;

            while (!isEmpty)
            {
                Rectangle selection = new Rectangle(newLocation, shapeSize);
                isEmpty = true;

                for (int i = 0; i < shapes.Count && isEmpty; i++)
                {
                    Rectangle reserved = new Rectangle(shapes[i].Location, shapes[i].Size);

                    if (selection.IntersectsWith(reserved))
                    {
                        newLocation = new Point(shapes[i].Right + _defaultElementLocation.X,
                            _defaultElementLocation.Y);
                        isEmpty = false;
                    }
                }
            }

            return newLocation;
        }

        /// <summary>
        /// Diagram의 영역을 얻어옵니다.
        /// </summary>
        /// <returns>Diagram의 영역이 되는 Rectangle을 Return합니다.</returns>
        private Rectangle GetDiagramArea()
        {
            if (shapes.Count == 0)
                return Rectangle.Empty;

            Point topLeftCorner;
            Point bottomRightCorner;

            topLeftCorner = shapes[0].Location;
            bottomRightCorner = shapes[0].Location + shapes[0].Size;

            for (int i = 1; i < shapes.Count; i++)
            {
                Point location = shapes[i].Location;

                if (location.X < topLeftCorner.X)
                    topLeftCorner.X = location.X;
                if (location.Y < topLeftCorner.Y)
                    topLeftCorner.Y = location.Y;
                if (location.X + shapes[i].Width - 1 > bottomRightCorner.X)
                    bottomRightCorner.X = location.X + shapes[i].Size.Width - 1;
                if (location.Y + shapes[i].Height - 1 > bottomRightCorner.Y)
                    bottomRightCorner.Y = location.Y + shapes[i].Size.Height - 1;
            }

            return new Rectangle(topLeftCorner.X, topLeftCorner.Y, bottomRightCorner.X -
                topLeftCorner.X, bottomRightCorner.Y - topLeftCorner.Y);
        }

        /// <summary>
        /// 선택된 요소들을 이동시킵니다.
        /// </summary>
        /// <param name="movingSize">이동시킬 크기 Size</param>
        private void MoveSelectedElements(Size movingSize)
        {
            for (int i = 0; i < shapes.Count; i++)
            {
                if (shapes[i].IsSelected)
                    shapes[i].Location += movingSize;
            }
        }

        /// <summary>
        /// Diagram을 이미지로 출력합니다.
        /// </summary>
        /// <param name="path">출력할 경로 string</param>
        /// <param name="format">출력할 이미지 포멧</param>
        public void SaveAsImage(string path, ImageFormat format)
        {
            const int Margin = BaseConnection.iMarginSize + 3;

            if (format == null)
                throw new ArgumentNullException("format");
            if (path == null)
                throw new ArgumentNullException("path");

            Rectangle area = GetDiagramArea();
            Size marginSize = new Size(Margin, Margin);

            using (Image image = new Bitmap(area.Width + Margin * 2, area.Height + Margin * 2))
            using (Graphics g = Graphics.FromImage(image))
            {

                g.Clear(DiagramSettings.DiagramBackColor);
                for (int i = 0; i < shapes.Count; i++)
                    shapes[i].Draw(g, shapes[i].Location - (Size)area.Location + marginSize);
                for (int i = 0; i < connections.Count; i++)
                    connections[i].Draw(g, Point.Empty - (Size)area.Location + marginSize);

                try
                {
                    image.Save(path, format);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(
                        string.Format("{0}\n{1}: {2}", ("error_in_saving_image"),
                            ("errors_reason"), ex.Message),
                        ("error"), MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        /// <summary>
        /// Diagram을 프린터로 출력합니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 PrintPageEventArgs</param>
        public void Print(PrintPageEventArgs e)
        {
            if (shapes.Count == 0)
                return;

            Rectangle area = this.DisplayRectangle;
            float scaleX = (float)e.MarginBounds.Width / area.Width;
            float scaleY = (float)e.MarginBounds.Height / area.Height;
            float scale = Math.Min(scaleX, scaleY);

            if (scale > 1) scale = 1;

            e.Graphics.TranslateTransform(e.MarginBounds.X, e.MarginBounds.Y);

            for (int i = 0; i < connections.Count; i++)
                connections[i].Draw(e.Graphics, new Point(-area.X, -area.Y), scale);

            for (int i = 0; i < shapes.Count; i++)
                if (shapes[i].Visible)
                    shapes[i].Draw(e.Graphics, shapes[i].Location - (Size)area.Location, scale);

            e.Graphics.ScaleTransform(scale, scale);

            for(int i = 0; i <shapes.Count; i++)
                shapes[i].ExternalLabel.Draw(e.Graphics, shapes[i].AbsoluteLocation - (Size)area.Location);
                    
            
                    

            e.Graphics.ResetTransform();

            Connecting = false;
        }

        /// <summary>
        /// Diagram을 프린터로 출력합니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 PrintPageEventArgs</param>
        public void Print(Rectangle rectangel, Graphics g)
        {

            if (shapes.Count == 0)
                return;

            Rectangle area = this.DisplayRectangle;
            float scaleX = (float)rectangel.Width / area.Width;
            float scaleY = (float)rectangel.Height / area.Height;
            float scale = Math.Min(scaleX, scaleY);

            if (scale > 1) scale = 1;

            g.TranslateTransform(rectangel.X, rectangel.Y);

            for (int i = 0; i < connections.Count; i++)
                connections[i].Draw(g, new Point(-area.X, -area.Y), scale);

            for (int i = 0; i < shapes.Count; i++)
                if (shapes[i].Visible)
                {
                    shapes[i].Draw(g, shapes[i].Location - (Size)area.Location, scale);
                    shapes[i].ExternalLabel.Draw(g, shapes[i].AbsoluteLocation - (Size)area.Location);
                }


            g.ResetTransform();

            Connecting = false;
        }



        /// <summary>
        /// 간선 선택을 상태 값을 반전시킵니다 ( !IsSelected )
        /// </summary>
        /// <param name="mouseLocation">마우스의 위치 좌표</param>
        /// <returns>반전되었는가 그렇지 않은가에 대한 결과 True/False</returns>
        private bool InvertConnectionSelection(Point mouseLocation)
        {
            bool inversion = false;

            for (int i = 0; i < connections.Count; i++)
            {
                if (connections[i].IsSelectable(mouseLocation) && connections[i].Visible == true)
                {
                    connections[i].IsSelected = !connections[i].IsSelected;
                    inversion = true;
                }
            }
            Invalidate();

            return inversion;
        }

        /// <summary>
        /// 지정한 포인트가 노드(도형)의 변에 위치해 있는지 판단합니다.
        /// </summary>
        /// <param name="shape">대상이 되는 노드(도형) 입니다.</param>
        /// <param name="point">판단의 대상이 되는 좌표값 Point 입니다.</param>
        /// <returns>대상 노드(도형)의 변에 지정한 Point가 위치해 있는지에 대한 True/Fasle</returns>
        private bool IsShapeEdge(BaseShape shape, Point point)
        {
            if (shape == null)
                return false;

            return
                (point.X < shape.Left || point.X >= shape.Right) &&
                (point.X >= shape.Left - BaseConnection.iMarginSize) &&
                (point.X < shape.Right + BaseConnection.iMarginSize) &&
                (point.Y >= shape.Top && point.Y < shape.Bottom)
                ||
                (point.Y < shape.Top || point.Y >= shape.Bottom) &&
                (point.Y >= shape.Top - BaseConnection.iMarginSize) &&
                (point.Y < shape.Bottom + BaseConnection.iMarginSize) &&
                (point.X >= shape.Left && point.X < shape.Right);
        }

        /// <summary>
        /// 다시 그리기를 수행합니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected virtual void Redraw(Graphics g)
        {
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            g.PixelOffsetMode = System.Drawing.Drawing2D.PixelOffsetMode.HighQuality;

            Rectangle area = this.DisplayRectangle;

            if (DiagramDesignMode)
                diagramGrid.DrawGrid(g, this.DisplayRectangle);

            DrawConnections(g);

            g.ScaleTransform(DiagramSettings.Zoom, DiagramSettings.Zoom);
            DrawElementLabels(g);
            g.ResetTransform();

            if (Connecting && previewStartHolder.Shape != null && previewEndHolder.Shape == null)
            {
                Point mouseLocation =
                    Control.MousePosition - (Size)this.PointToScreen(Point.Empty);
                previewConnection.DrawOnlyStartSign(g, mouseLocation);
            }
        }

        /// <summary>
        /// 선택된 요소를 제거합니다.
        /// </summary>
        private void RemoveSelectedElements()
        {
            for (int i = 0; i < shapes.Count; i++)
            {
                if (shapes[i].IsSelected)
                    RemoveShape(shapes[i--]);
            }
            for (int i = 0; i < connections.Count; i++)
            {
                if (connections[i].IsSelected)
                    RemoveConnection(connections[i--]);
            }

            Invalidate();
            SelectedElementCount = 0;
        }

        /// <summary>
        /// 노드(도형)을 제거합니다.
        /// </summary>
        /// <param name="shape">제거할 노드(도형)</param>
        public void RemoveShape(BaseShape shape)
        {
            shapes.Remove(shape);
            shape.Dispose();
        }

        /// <summary>
        /// 간선을 제거합니다.
        /// </summary>
        /// <param name="connection">제거할 간선(DefaultConnection)</param>
        public virtual void RemoveConnection(BaseConnection connection)
        {
            if (connection != null)
            {
                connections.Remove(connection);
                connection.Dispose();
            }
        }

        /// <summary>
        /// 하나의 간선을 선택하고자 하는지에 대해 판단합니다.
        /// </summary>
        /// <param name="mouseLocation">판댄의 대상이 되는 마우스 좌표값입니다.</param>
        /// <returns>선택 가능한 경우에 대한 True/False</returns>
        private bool SelectOneConnection(Point mouseLocation)
        {
            for (int i = 0; i < connections.Count; i++)
            {
                if (connections[i].IsSelectable(mouseLocation))
                {
                    connections[i].IsSelected = true;
                    CountSelectedElements();
                    return true;

                }
            }

            return false;
        }

        /// <summary>
        /// 요소들을 선택합니다
        /// </summary>
        private void SelectElements()
        {
            Rectangle rectangle = selectionRectangle;

            if (rectangle.Size != Size.Empty)
            {
                if (rectangle.Width < 0)
                {
                    rectangle.X += selectionRectangle.Width;
                    rectangle.Width *= -1;
                }
                if (rectangle.Height < 0)
                {
                    rectangle.Y += selectionRectangle.Height;
                    rectangle.Height *= -1;
                }

                SelectionChanging = true;

                for (int i = 0; i < shapes.Count; i++)
                    if(shapes[i].Enabled && shapes[i].Visible)
                        shapes[i].TrySelect(rectangle);

                for (int i = 0; i < connections.Count; i++)
                    if(connections[i].Enabled && connections[i].Visible)
                        connections[i].TrySelect(rectangle);

                SelectionChanging = false;
            }
        }

        /// <summary>
        /// 사각 영역과 접하거나 포함된 Element들의 리스트를 가져옵니다.
        /// </summary>
        /// <param name="rectangle">비교할 사각 영역</param>
        /// <returns>사각 영역과 접한 Elemet들의 리스트</returns>
        internal List<BaseElement> GetElementsRectangle(Rectangle rectangle)
        {
            List<BaseElement> list = new List<BaseElement>();
            if (rectangle.Size != Size.Empty)
            {
                if (rectangle.Width < 0)
                {
                    rectangle.X += selectionRectangle.Width;
                    rectangle.Width *= -1;
                }
                if (rectangle.Height < 0)
                {
                    rectangle.Y += selectionRectangle.Height;
                    rectangle.Height *= -1;
                }

                SelectionChanging = true;
                for (int i = 0; i < shapes.Count; i++)
                    if(shapes[i].Enabled && shapes[i].Visible)
                        if (rectangle.IntersectsWith(shapes[i].DisplayRectangle))
                            list.Add(shapes[i]);

                for (int i = 0; i < connections.Count; i++)
                    if(connections[i].Enabled && connections[i].Visible)
                        if (connections[i].IsSelectable(rectangle))
                            list.Add(connections[i]);

                return list;
            }
            return list;
        }

        /// <summary>
        /// 사각형의 선택 영역을 설정합니다.
        /// </summary>
        /// <param name="mouseLocation">현재의 마우스 포인터 위치</param>
        private void SetSelectionRectangle(Point mouseLocation)
        {
            if (mouseLocation.X < 1)
                mouseLocation.X = 1;
            if (mouseLocation.X > ClientRectangle.Width - 1)
                mouseLocation.X = ClientRectangle.Width - 1;
            if (mouseLocation.Y < 1)
                mouseLocation.Y = 1;
            if (mouseLocation.Y > ClientRectangle.Height - 1)
                mouseLocation.Y = ClientRectangle.Height - 1;

            selectionRectangle = new Rectangle(
                selectionStartPoint.X, selectionStartPoint.Y,
                mouseLocation.X - selectionStartPoint.X,
                mouseLocation.Y - selectionStartPoint.Y);
        }

        /// <summary>
        /// 노드(도형)의 크기를 조정할때 조작중인 변의 잡아 끌기를 처리합니다. 
        /// </summary>
        /// <param name="shape">조작중인 노드(도형)</param>
        /// <param name="movingSize">조작된 크기 Size</param>
        private void SnapEdges(BaseShape shape, ref Size movingSize)
        {
            if (shape == null)
                return;

            for (int i = 0; i < shapes.Count; i++)
            {
                if (shape != shapes[i])
                {
                    Point bottomRight = shape.Location + shape.Size;
                    int newRight = bottomRight.X + movingSize.Width;
                    int newBottom = bottomRight.Y + movingSize.Height;

                    if (Math.Abs(shapes[i].Right - newRight) < _iPrecisionSize &&
                        movingSize.Width != 0)
                    {
                        int oldWidth = shape.Width;
                        shape.Width += shapes[i].Right - shape.Right;
                        oldMouseLocation.X += shape.Width - oldWidth;
                        movingSize.Width = 0;
                    }

                    if (Math.Abs(shapes[i].Bottom - newBottom) < _iPrecisionSize &&
                        movingSize.Height != 0)
                    {
                        int oldHeight = shape.Height;

                        shape.Height += shapes[i].Bottom - shape.Bottom;
                        oldMouseLocation.Y += shape.Height - oldHeight;
                        movingSize.Height = 0;
                    }
                }
            }
        }

        /// <summary>
        /// 노드(도형)의 위치를 변경할때 잡아 끌기를 처리합니다.
        /// </summary>
        /// <param name="iLocation">잡아끌기를 할 위치값 Point</param>
        /// <param name="movingSize">잡아끌기를 할 크기값 Size</param>
        private void SnapLocations(Point location, ref Size movingSize)
        {
            for (int i = 0; i < shapes.Count; i++)
            {
                if (!shapes[i].IsSelected)
                {
                    Point newLocation = location + movingSize;

                    if (Math.Abs(newLocation.X - shapes[i].Left) < _iPrecisionSize &&
                        movingSize.Width != 0)
                    {
                        MoveSelectedElements(new Size(shapes[i].Left - location.X, 0));
                        movingSize.Width = 0;
                    }

                    if (Math.Abs(newLocation.Y - shapes[i].Top) < _iPrecisionSize &&
                        movingSize.Height != 0)
                    {
                        MoveSelectedElements(new Size(0, shapes[i].Top - location.Y));
                        movingSize.Height = 0;
                    }
                }
            }
        }

        #endregion


        #region <<< [ Events       ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        #region <<< [ Element      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 요소의 선택 상태 변경에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Element_SelectionChanged(object sender, EventArgs e)
        {
            CountSelectedElements();
            if (SelectedElementCount == 1)
                firstSelectedElement = (IDiagramElement)sender;

            if (SelectionChanging)
                bSelectionChanged = true;
            else
                OnSelectionChanged(e);
        }

        /// <summary>
        /// 요소의 내용 변경에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Element_ContentChanged(object sender, EventArgs e)
        {
            OnContentsChanged(e);
        }

        /// <summary>
        /// 요소 삭제에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Element_ElementDeleted(object sender, EventArgs e)
        {
            OnElementDeleted(e);
        }

        #endregion

        #region <<< [ Key          ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 키 누름에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Shape_KeyDowned(object sender, KeyEventArgs e)
        {
            OnKeyDown(e);
        }

        /// <summary>
        /// 키가 눌림에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 KeyEventArgs</param>
        protected override void OnKeyDown(KeyEventArgs e)
        {
            base.OnKeyDown(e);

            if (e.KeyCode == Keys.Delete)
                DeleteSelectedElements();

            if (e.KeyCode == Keys.Escape)
            {
                DeselectElements();
                bShapePositioning = false;
                Connecting = false;
            }

            if (e.Control && e.KeyCode == Keys.A)
            {
                for (int i = 0; i < shapes.Count; i++)
                    shapes[i].IsSelected = true;
                for (int i = 0; i < connections.Count; i++)
                    connections[i].IsSelected = true;
                Invalidate();
            }
        }

        #endregion

        #region <<< [ DiagramPanel ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 내용 변경에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        protected virtual void OnContentsChanged(EventArgs e)
        {
            if (ContentsChanged != null)
                ContentsChanged(this, e);
        }

        /// <summary>
        /// 선택 변경에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        protected virtual void OnSelectionChanged(EventArgs e)
        {
            if (SelectionChanged != null)
                SelectionChanged(this, e);
        }

        /// <summary>
        /// Diagram 변경에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e"></param>
        protected virtual void OnDiagramChanged(EventArgs e)
        {
            if (DiagramChanged != null)
                DiagramChanged(this, e);
        }

        /// <summary>
        /// 요소 삭제에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        protected virtual void OnElementDeleted(EventArgs e)
        {
            if (ElementDeleted != null)
                ElementDeleted(this, e);
        }

        /// <summary>
        /// 마우스 버튼 다운에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        protected override void OnMouseDown(MouseEventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함

            base.OnMouseClick(e);

            // 마우스 오른쪽 버튼이 눌린 경우 작업을 수행합니다.
            if (e.Button == MouseButtons.Right)
                ContextMenuStrip = null;

            this.Focus();

            // 노드 연결 작업 수행중인 경우 작업을 수행합니다.
            if (Connecting)
            {
                if (e.Button == MouseButtons.Left)
                    ApplyPreviewConnection();
                else if (e.Button == MouseButtons.Right)
                    Connecting = false;
            }
            // 노드 연결 작업 수행이 아닌 경우 작업을 수행합니다.
            else
            {
                bool isConnectionSelected = false;

                // Ctrl 키가 눌린 상태에 따른 작업을 수행합니다.
                if (Control.ModifierKeys == Keys.Control)
                {
                    InvertConnectionSelection(e.Location);
                }
                // Ctrl 키가 눌리지 않은 상태에 따른 작업을 수행합니다.
                else
                {
                    DeselectElements();
                    isConnectionSelected = SelectOneConnection(e.Location);
                    Invalidate();
                }

                // 마우스 왼쪽 버튼이 눌린 경우 작업을 수행합니다.
                if (e.Button == MouseButtons.Left && !OverTeminalNode)
                {
                    bSelecting = true;
                    selectionStartPoint = e.Location;
                    SetSelectionRectangle(e.Location);
                    SelectElements();
                }
            }
        }

        /// <summary>
        /// 마우스 이동에 대한 이벤트 입니다
        /// </summary>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        protected override void OnMouseMove(MouseEventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함

            base.OnMouseMove(e);

            // 노드간 선 연결 작업을 수행중인지 판단합니다.
            if (Connecting)
            {
                BaseHolder node = (StartChosen) ? previewEndHolder : previewStartHolder;
                bool needInvalidate = false;

                if (node != null && node.Shape != null)
                    needInvalidate = true;
                if (SetHolder(node, e.Location))
                    needInvalidate = true;

                if (needInvalidate)
                    Invalidate();
            }
            // 영역 선택 작업을 수행중인지 판단합니다.
            else if (bSelecting)
            {
                ClearSelectionRectangle();
                SetSelectionRectangle(e.Location);
                DrawSelectionRectangle();
            }
            //  노드 내용 수정 작업을 수행중인지 판단합니다.
            else if (ModifyingNode != null && e.Button == MouseButtons.Left)
            {
                if (ModifyingNode.SetPosition(e.Location))
                {
                    Invalidate();
                    OnContentsChanged(EventArgs.Empty);
                }
            }
            // 노드(도형) 크기 조정 작업을 수행중인지 판단합니다.
            else if (ShapeResizing)
            {
                bShapeHorizontalResizing = false;
                bShapeVerticalResizing = false;
                Cursor = Cursors.Default;
            }
            // 터미널 노드를 확인하는 작업을 수행합니다.
            else
            {
                CheckHolders(e.Location);
            }
        }

        /// <summary>
        /// 마우스 버튼 업에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        protected override void OnMouseUp(MouseEventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함

            base.OnMouseUp(e);

            // 선택 작업을 수행중이었으며 선택 영역의 크기가 존재하는 경우 작업을 수행합니다.
            if (e.Button == MouseButtons.Left && bSelecting && selectionRectangle.Size != Size.Empty)
            {
                ClearSelectionRectangle();
                SelectElements();
                selectionRectangle = Rectangle.Empty;
            }

            bSelecting = false;

            Invalidate();
        }

        /// <summary>
        /// 페인트 이벤트 입니다. ( 구현된 내용 없음 - 구현 필요 )
        /// </summary>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        protected override void OnPaint(PaintEventArgs e)
        {
            Redraw(e.Graphics);
        }

        /// <summary>
        /// 스크롤 이벤트 입니다.
        /// </summary>
        /// <param name="se">이벤트 파라메터 EventArgs</param>
        protected override void OnScroll(ScrollEventArgs se)
        {
            base.OnScroll(se);
            Invalidate();
        }

        /// <summary>
        /// Lost 포커스 이벤트 입니다.
        /// </summary>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        protected override void OnLostFocus(EventArgs e)
        {
            base.OnLostFocus(e);
            bSelecting = false;
        }

        # endregion

        #region <<< [ Shape        ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 노드(도형) 이동 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Shape_Move(object sender, EventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함



            // 노드(도형)의 위치 변경 작업을 수행중인지 판단합니다.
            if (bShapePositioning)
            {
                BaseShape shape = (BaseShape)sender;

                if (shape.Holders.Count > 0)
                    Invalidate();
                OnContentsChanged(EventArgs.Empty);
            }
        }

        /// <summary>
        /// 노드(도형) 선택 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Shape_Enter(object sender, EventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함

            // 연결작업이 아닌 상태에 대한 작업을 수행합니다.
            if (!Connecting)
            {
                BaseShape shape = (BaseShape)sender;

                SelectionChanging = true;

                // 현재 도형이 이미 선택된 상태가 아니며 Ctrl 키가 사용하지 않고 선택된 경우에 대한 작업을 수행합니다.
                if (!shape.IsSelected && Control.ModifierKeys != Keys.Control)
                {
                    DeselectElements();
                    shape.IsSelected = !shape.IsSelected;
                }
                // Ctrl 키가 사용되어 선택된 경우에 대한 작업을 수행합니다.
                else if (Control.ModifierKeys == Keys.Control)
                {
                    shape.IsSelected = !shape.IsSelected;
                }
                // 단순 선택 작업을 수행합니다.
                else
                {
                    shape.IsSelected = true;
                }
                SelectionChanging = false;
            }
        }

        /// <summary>
        /// 노드(도형)의 MouseDown 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Shape_MouseDown(object sender, MouseEventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함

            // 노드(도형) 연결 작업을 수행중인지 판단합니다.
            if (Connecting)
            {
                if (e.Button == MouseButtons.Left)
                    ApplyPreviewConnection();
            }
            // 노드(도형) 연결 작업은 아닌 상태이며, 마우스 왼쪽 버튼이 눌린 경우 작업을 수행합니다.
            else if (e.Button == MouseButtons.Left)
            {
                oldMouseLocation = e.Location;
                oldSize = ((BaseShape)sender).Size;
                bShapePositioning = true;
            }
        }

        /// <summary>
        /// 노드(도형)의 MouseMove 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Shape_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함

            BaseShape shape = (BaseShape)sender;

            // 도형 위치와 크기 변경에 대한 작업을 수행합니다.
            if (bShapePositioning)
            {
                Size movingSize = new Size(e.Location.X - oldMouseLocation.X,
                    e.Location.Y - oldMouseLocation.Y);

                // 도형의 크기 변경에 대한 작업을 수행합니다.
                if (ShapeResizing)
                {
                    if (!bShapeHorizontalResizing) movingSize.Width = 0;
                    if (!bShapeVerticalResizing) movingSize.Height = 0;

                    if (DiagramSettings.UsePrecisionSnapping &&
                        Control.ModifierKeys == Keys.Shift)
                    {
                        // 주위의 인접한 도형의 변과 같은 위치가 되도록 변을 잡아끌기를 수행합니다.
                        SnapEdges(shape, ref movingSize);
                    }
                    oldMouseLocation += movingSize;
                    Size oldSize = shape.Size;
                    shape.Size += movingSize;
                    oldMouseLocation -= oldSize - shape.Size + movingSize;
                }
                // 도형의 위치 변경에 대한 작업을 수행합니다.
                else
                {
                    movingSize = CheckDiagramBorders(movingSize);
                    if (DiagramSettings.UsePrecisionSnapping &&
                        Control.ModifierKeys == Keys.Shift)
                    {
                        // 주위의 인접한 도형과 행이나 열이 맞춰지도록 위치 잡아 끌기를 수행합니다.
                        SnapLocations(shape.Location, ref movingSize);
                    }
                    MoveSelectedElements(movingSize);
                }
            }
            // 간선의 위치 변경에 대한 처리를 수행합니다.
            else if (ConnectionPositioning)
            {
                if (previewStartHolder != null && !StartChosen)
                {
                    if (previewStartHolder.IsVertical)
                        previewStartHolder.RelativeLocation = e.X;
                    else
                        previewStartHolder.RelativeLocation = e.Y;
                }
                else if (previewEndHolder != null)
                {
                    if (previewEndHolder.IsVertical)
                        previewEndHolder.RelativeLocation = e.X;
                    else
                        previewEndHolder.RelativeLocation = e.Y;
                }
                Invalidate();
            }
            // 도형의 위치변경, 간선의 위치변경, 연결작업이 아닌 경우의 작업을 수행합니다.
            else if (!Connecting)
            {
                bShapeHorizontalResizing = (e.Location.X >= shape.Width - _iResizeMargin);
                bShapeVerticalResizing = (e.Location.Y >= shape.Height - _iResizeMargin);

                if (bShapeHorizontalResizing && bShapeVerticalResizing)
                    Cursor = Cursors.SizeNWSE;
                else if (bShapeHorizontalResizing)
                    Cursor = Cursors.SizeWE;
                else if (bShapeVerticalResizing)
                    Cursor = Cursors.SizeNS;
                else
                    Cursor = Cursors.Default;
            }
        }

        /// <summary>
        /// 노드(도형)의 MouseUp 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Shape_MouseUp(object sender, MouseEventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함

            bShapePositioning = false;
        }

        /// <summary>
        /// 노드(도형)의 Resize 이벤트 입니다.
        /// </summary>
        /// <param name="sender">이벤트를 발생시킨 object</param>
        /// <param name="e">이벤트 파라메터 EventArgs</param>
        private void Shape_Resize(object sender, EventArgs e)
        {
            if (isDesignMode == false) return; // 디자인 모드가 아닌경우 처리안함

            Invalidate();
            OnContentsChanged(EventArgs.Empty);
        }

        #endregion

        #endregion

    }
}