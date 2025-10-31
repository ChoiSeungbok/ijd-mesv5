using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace Miracom.Common.DiagramModeler
{
    public delegate void UpdateDelegator(TreeShape sender, object obj);

    /// <summary>
    /// 
    /// </summary>
    public class TreeShape : BaseShape
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 노드의 문자형 Key
        /// </summary>
        string sKey;

        /// <summary>
        /// 노드의 숫자형 Key
        /// </summary>
        int iKey;

        /// <summary>
        /// 노드의 설명 데이터
        /// </summary>
        string description;

        /// <summary>
        /// 노드가 다른노드에 Attached 된 상태인지를 나타내는 값
        /// </summary>
        bool bAttached;

        /// <summary>
        /// 노드의 계층
        /// (Tree 구조에서 노드의 위치를 나타내는 값.)
        /// (Root Node = 1)
        /// </summary>
        int nodeLevel;

        /// <summary>
        /// 같은 계층의 노드들을 구별할 필요가 있을때 사용하는 값
        /// 기본값 (1)
        /// </summary>
        int nodeType = 1;

        /// <summary>
        /// 노드의 도형스타일 ( 코드에서 제공하는 도형중 선택 )
        /// </summary>
        ShapeStyle nodeShape = ShapeStyle.Rectangle;

        /// <summary>
        /// 도형의 Gradient 색상1
        /// </summary>
        Color backGradientColor = Color.OrangeRed;

        /// <summary>
        /// 도형의 Gradient 색상2
        /// </summary>
        Color frontGradientColor = Color.White;

        /// <summary>
        /// 부모 노드
        /// </summary>
        TreeShape parentNode = null;

        /// <summary>
        /// 자식 노드 List
        /// </summary>
        List<TreeShape> childNodes = new List<TreeShape>();

        /// <summary>
        /// 연결되어 나가는 DefaultConnection List
        /// </summary>
        List<TreeConnection> childConnections = new List<TreeConnection>();

        /// <summary>
        /// 하위 노드 펼침의 상태
        /// </summary>
        bool isExtended = true;

        /// <summary>
        /// 그리기용 Pen
        /// </summary>
        Pen drawPen;

        /// <summary>
        /// 선택되지 않은 상태의 Pen
        /// </summary>
        Pen unSelectedPen = new Pen(Color.DarkGray, 1);

        /// <summary>
        /// 선택된 상태의 Pen
        /// </summary>
        Pen selectedPen = new Pen(Color.Black, 2);

        /// <summary>
        /// Control의 Region
        /// </summary>
        Region region = new Region();

        /// <summary>
        /// Control의 영역을 담는데 사용할 Rectangle
        /// </summary>
        Rectangle rectangle;

        /// <summary>
        /// 선택된 Control을 표현하는데 사용할 Rectangle
        /// </summary>
        Rectangle selectedRect;

        /// <summary>
        /// 노드(도형)의 그리기 경로 정보
        /// </summary>
        GraphicsPath selectionPath;

        /// <summary>
        /// 그라디언트 색 표현을 위한 Brush
        /// </summary>
        LinearGradientBrush outterLinGrdBrush;

        LinearGradientBrush innerLinGrdBrush;

        GraphicsPath innerPath;

        Font selectedFont = new Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));

        Font unSelectedFont = new Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 노드의 StringKey값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public string StringKey
        {
            get { return sKey; }
            set { sKey = value; }
        }

        /// <summary>
        /// 노드의 Description을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public string Description
        {
            get { return description; }
            set { description = value; }
        }

        /// <summary>
        /// 노드의 IntegerKey값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public int IntegerKey
        {
            get { return iKey; }
            set { iKey = value; }
        }

        /// <summary>
        /// 
        /// </summary>
        protected ShapeStyle NodeShape
        {
            get { return nodeShape;  }
            set { nodeShape = value; }
        }

        /// <summary>
        /// 
        /// </summary>
        public List<TreeShape> ChildNodes
        {
            get { return childNodes; }
        }

        /// <summary>
        /// 연결되어 나가는 DefaultConnection List
        /// </summary>
        public List<TreeConnection> ChildConnections
        {
            get { return childConnections; }
        }
        
        /// <summary>
        /// 다른 노드와 연결되어 있는지에 대한 값을 가져오는 프로퍼티 입니다.
        /// </summary>
        public bool IsAttached
        {
            get { return bAttached; }
        }

        /// <summary>
        /// 자식노드를 가지고 있는지에 대한 값을 가져오는 프로퍼티 입니다.
        /// </summary>
        public bool HasChildNode
        {
            get { return childNodes.Count == 0 ? false : true; }
        }

        /// <summary>
        /// 노드의 하위노드 펼침 상태를 가져오는 프로퍼티 입니다.
        /// </summary>
        public bool IsExtended
        {
            get { return isExtended; }
        }

        /// <summary>
        /// 노드의 계층을 가져오거나 설정하는 프로퍼티 입니다.
        /// (Tree 구조에서 노드의 위치를 나타내는 값.)
        /// (Root Node = 1)
        /// </summary>
        public int NodeLevel
        {
            get { return nodeLevel;  }
            set { nodeLevel = value; }
        }

        /// <summary>
        /// 노드의 타입을 가져오거나 설정하는 프로퍼티 입니다.
        /// ( 노드 타입은 동일 Level의 노드를 구분하여 사용하고자 할때 할때 사용합니다. )
        /// </summary>
        public int NodeType
        {
            get { return nodeType;  }
            set { nodeType = value; }
        }

        /// <summary>
        /// 노드의 Gradient 색을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public Color BackGradientColor
        {
            get { return backGradientColor; }
            set { backGradientColor = value; }
        }

        /// <summary>
        /// 노드의 Gradient 색을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public Color FrontGradientColor
        {
            get { return frontGradientColor; }
            set { frontGradientColor = value; }
        }

        /// <summary>
        /// 노드의 부모노드를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public TreeShape ParentNode
        {
            get { return parentNode; }
            set
            {
                if (value != null)
                {
                    bAttached = true;
                    this.ContextMenu.MenuItems[1].Text = "Detach";
                    this.ContextMenu.MenuItems[2].Enabled = false;
                }
                else
                {
                    bAttached = false;
                    this.ContextMenu.MenuItems[1].Text = "Remove (Only This)";
                    this.ContextMenu.MenuItems[2].Enabled = true;
                }

                parentNode = value;
            }
        }

        /// <summary>
        /// 현재 노드의 RootNode에 해당하는 노드를 가져오는 프로퍼티 입니다.
        /// </summary>
        public TreeShape RootNode
        {
            get
            {
                if (ParentNode != null)
                    return ParentNode.RootNode;
                else
                    return this;
            }
        }

        /// <summary>
        /// 이전 노드를 가져오는 프로퍼티 입니다.
        /// </summary>
        public TreeShape PrevNode
        {
            get
            {
                if (ParentNode != null)
                    return ParentNode.GetPrevChildNode(this);
                return null;
            }
        }

        /// <summary>
        /// 다음 노드를 가져오는 프로퍼티 입니다.
        /// </summary>
        public TreeShape NextNode
        {
            get
            {
                if (ParentNode != null)
                    return ParentNode.GetNextChildNode(this);
                return null;
            }
        }

        /// <summary>
        /// 첫번째 Child 노드를 가져오는 프로퍼티 입니다.
        /// </summary>
        public TreeShape FirstChildNode
        {
            get
            {
                if (ChildNodes.Count != 0)
                    return ChildNodes[0];
                return null;
            }
        }

        /// <summary>
        /// 마지막 Child 노드를 가져오는 프로퍼티 입니다.
        /// </summary>
        public TreeShape LastChildNode
        {
            get
            {
                if (ChildNodes.Count != 0)
                    return ChildNodes[ChildNodes.Count - 1];
                return null;
            }
        }

        /// <summary>
        /// 자식 노드들의 갯수를 가져오는 프로퍼티 입니다.
        /// </summary>
        public int ChildNodesCount
        {
            get { return childNodes.Count; }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// TreeNode를 생성합니다.
        /// </summary>
        public TreeShape() : base()
        {
            this.AllowDrop = true;
            this.bAttached = false;
        }

        /// <summary>
        /// TreeNode를 생성합니다.
        /// </summary>
        /// <param name="parentPanel">노드가 속할 BaseDiagramPanel</param>
        public TreeShape(BaseDiagramPanel parent) : base(parent)
        {
            this.AllowDrop = true;
            this.bAttached = false;
            drawPen = unSelectedPen;
            GenerateDrawingValues();
            this.ContextMenu = new ContextMenu();
        }

        /// <summary>
        /// TreeNode를 생성합니다.
        /// </summary>
        /// <param name="parentPanel">노드가 속할 BaseDiagramPanel</param>
        /// <param name="nodeLevel">노드의 타입</param>
        public TreeShape(BaseDiagramPanel parent, int nodeLevel)
            : this(parent)
        {
            this.NodeLevel = nodeLevel;
            IntenalLabel.Font    = selectedFont;
            ExternalLabel.Font   = selectedFont;
            GenerateDrawingValues();
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        public static int operator +(TreeShape shape1, TreeShape shape2)
        {
            if (shape1 == null || shape2 == null)
                return -1; //오류
            return Convert.ToInt32(shape1.NodeLevel.ToString() + shape2.NodeLevel.ToString());
        }

        public virtual bool AddRelation(TreeConnection connection)
        {
            return ((TreeDiagramPanel)ParentPanel).AddRelation(connection);
        }

        /// <summary>
        /// Content 객체를 가져옵니다.
        /// </summary>
        public override object ContentObject
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        /// <summary>
        /// Content 객채의 타입을 가져옵니다.
        /// </summary>
        public override Type ContentObjectType
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        /// <summary>
        /// TreeShape를 Dispose 합니다.
        /// </summary>
        /// <param name="disposing"></param>
        protected override void Dispose(bool disposing)
        {
            if(selectedFont != null)
                selectedFont.Dispose();
            
            if(selectedPen != null)
                selectedPen.Dispose();

            if(unSelectedFont != null)
                unSelectedFont.Dispose();

            if(unSelectedPen != null)
                unSelectedPen.Dispose();

            RemoveAllChildNodes();

            base.Dispose(disposing);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public string GetParentRelationString()
        {
            string sRelationString = "";
            TreeShape node = this;

            while (node != null)
            {
                sRelationString += (node.StringKey + node.NodeLevel.ToString() + node.NodeType.ToString()) ;
                node = node.ParentNode;
            }

            return sRelationString;
        }

        /// <summary>
        /// 이 노드와 파라메터로 입력된 노드를 연결하는 Connection을 가져옵니다.
        /// </summary>
        /// <param name="shape">TreeShape</param>
        /// <returns></returns>
        public TreeConnection GetRelatedConnection(TreeShape shape)
        {
            foreach (TreeConnection connection in ChildConnections)
            {
                if (connection.EndHolder.Shape.Equals(shape))
                    return connection;
            }
                 
            return null;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>        
        public bool RemoveAllChildRelation()
        {
            if (ParentPanel == null)
                return false;

            // 펼침상태가 담힘인 경우 답힌 모든 Child 노드들을 펼친후 관계 제거 작업을 진행
            if (IsExtended == false)
                InvertExtends(true);
            
            foreach (TreeConnection connection in ChildConnections)
                ParentPanel.RemoveConnection(connection);

            ChildConnections.Clear();

            foreach (TreeShape shape in ChildNodes)               
                shape.ParentNode = null;

            ChildNodes.Clear();

            return true;
            
        }

        /// <summary>
        /// 
        /// </summary>
        public void RemoveAllChildNodes()
        {
            foreach (TreeConnection connection in ChildConnections)
                ParentPanel.RemoveConnection(connection);

            ChildConnections.Clear();

            foreach (TreeShape shape in ChildNodes)
            {
                shape.RemoveAllChildNodes();
                ParentPanel.RemoveShape(shape);
            }

            ChildNodes.Clear();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public bool RemoveParentRelation()
        {
            if (ParentNode != null)
                return ParentNode.RemoveChildRelation(this);
            return false;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="shape"></param>
        /// <returns></returns>
        public bool RemoveChildRelation(TreeShape shape)
        {
            if (ParentPanel == null)
                return false;

            if (ChildNodes.Contains(shape))
            {
                TreeConnection connection = GetRelatedConnection(shape);                
                Holders.Remove(connection.StartHolder);
                Holders.Remove(connection.EndHolder);
                ChildConnections.Remove(connection);                
                ParentPanel.RemoveConnection(connection);
                ChildNodes.Remove(shape);
                shape.ParentNode = null;

                return true;
            }
            return false;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="index"></param>
        /// <param name="connection"></param>
        /// <returns></returns>
        public bool ReplaceChildConnection(int index, TreeConnection connection)
        {
            if (ChildConnections[index] != null)
            {
                TreeConnection oldConnection = ChildConnections[index];
                ChildConnections[index] = connection;
                ParentPanel.RemoveConnection(oldConnection);
                return true;
            }
            return false;
        }

        /// <summary>
        /// 지정한 노드가 Child 노드인지 판단합니다.
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        public bool IsChildNode(TreeShape node)
        {
            return ChildNodes.Contains(node);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="connection"></param>
        /// <returns></returns>
        public bool IsChildConnection(TreeConnection connection)
        {
            return ChildConnections.Contains(connection);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        public int GetIndex(TreeShape node)
        {
            if (!childNodes.Contains(node))
                return -1;

            return childNodes.IndexOf(node);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="connection"></param>
        /// <returns></returns>
        public int GetIndex(TreeConnection connection)
        {
            if (!childConnections.Contains(connection))
                return -1;

            return childConnections.IndexOf(connection);
        }

        /// <summary>
        /// 지정한 Index의 Child 노드를 가져옵니다.
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public TreeShape GetChildNode(int index)
        {
            return childNodes[index];
        }

        /// <summary>
        /// 지정한 Index의 Connection을 가져옵니다.
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public TreeConnection GetChildConnection(int index)
        {
            return childConnections[index];
        }

        /// <summary>
        /// 지정한 Child 노드의 이전 노드에 해당하는 Child 노드를 가져옵니다.
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        public TreeShape GetPrevChildNode(TreeShape node)
        {
            if (childNodes.Count == 0 || childNodes.Count == 1)
                return null;

            if (childNodes.IndexOf(node) == 0)
                return null;

            return childNodes[childNodes.IndexOf(node) - 1];
        }

        /// <summary>
        /// 지정한 Child 노드의 다음 노드에 해당하는 Child 노드를 가져옵니다.
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        public TreeShape GetNextChildNode(TreeShape node)
        {
            if (childNodes.Count == 0 || childNodes.Count == 1)
                return null;

            if (childNodes.IndexOf(node) == childNodes.Count - 1)
                return null;

            return childNodes[childNodes.IndexOf(node) + 1];
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="g"></param>
        /// <param name="position"></param>
        /// <param name="zoom"></param>
        /// <param name="onScreen"></param>
        protected override void Draw(System.Drawing.Graphics g, System.Drawing.Point position, float zoom, bool onScreen)
        {
            g.ScaleTransform(zoom, zoom);
            g.TranslateTransform(position.X, position.Y);
            DrawSurface(g);
            IntenalLabel.Draw(g, new Point(5, this.Height / 2 - 6));
            g.ResetTransform();
        }

        /// <summary>
        /// 노드의 표면에 그려질 요소들을 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected void DrawSurface(Graphics g)
        {
            g.DrawPath(drawPen, path);
            g.FillPath(outterLinGrdBrush, path);
            g.FillPath(innerLinGrdBrush, innerPath);
            if (IsSelected)
                g.DrawPath(selectedPen, selectionPath);
        }

        /// <summary>
        /// 하위 노드 펼침 상태를 역전시킵니다.
        /// </summary>
        /// <param name="extends"></param>
        public void InvertExtends(bool extends)
        {
            if (isExtended == extends)
                return;

            isExtended = !isExtended;

            SetChildExtends(extends);
        }

        /// <summary>
        /// 하위 노드의 Visable 상태를 역전시킵니다.
        /// </summary>
        /// <param name="visable"></param>
        public void InvertVisable(bool visable)
        {
            if (isExtended)
            {
                SetChildVisable(visable);
                SetChildConnectionVisable(visable);
            }
            else
            {
                this.Visible = visable;
                this.Enabled = visable;
                
                if (ChildConnections.Count != 0)
                    ChildConnections[0].Enabled = visable;
            }
        }

        /// <summary>
        /// 하위 노드들의 Visable 상태를 변경합니다.
        /// </summary>
        /// <param name="visable"></param>
        private void SetChildVisable(bool visable)
        {
            foreach (TreeConnection connection in childConnections)
            {
                connection.Visible = visable;
                connection.Enabled = visable;
            }

            foreach (TreeShape child in childNodes)
            {
                child.Visible = visable;
                child.Enabled = visable;
                child.InvertVisable(visable);
            }
        }

        /// <summary>
        /// 하위 노드의 펼침 상태를 변경합니다.
        /// </summary>
        /// <param name="extends">변경할 상태</param>
        private void SetChildExtends(bool extends)
        {
            foreach (TreeConnection connection in ChildConnections)
            {
                connection.Visible = extends;
                connection.Enabled = extends;
            }

            if (ChildConnections.Count != 0)
                ChildConnections[0].Enabled = true;

            foreach (TreeShape child in childNodes)
            {
                child.Visible = extends;
                child.Enabled = extends;
                child.InvertVisable(extends);
            }
        }

        /// <summary>
        /// 노드와 연결되어 있는 Connection의 Visable 상태를 변경합니다.
        /// </summary>
        /// <param name="visable">변경할 상태</param>
        private void SetChildConnectionVisable(bool visable)
        {
            foreach (TreeConnection connection in childConnections)
            {
                connection.Visible = visable;
                connection.Enabled = visable;
            }
        }

        /// <summary>
        /// 노드와 연결되어 있는 Connection의 Visable 상태를 변경합니다.
        /// </summary>
        /// <param name="visable"></param>
        /// <param name="type"></param>
        private void SetChildConnectionVisable(bool visable, TreeConnectionType type)
        {
            foreach (TreeConnection connection in childConnections)
            {
                if (connection.ConnectionType == type)
                {
                    connection.Visible = visable;
                    connection.Enabled = visable;
                }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        protected override void InitializeComponent()
        {
            base.InitializeComponent();
        }

        /// <summary>
        /// 현재 노드와 하위 노드가 표현되고 있는 영역을 계산합니다.
        /// </summary>
        /// <returns>계산된 영역의 Rectangle</returns>
        public virtual Rectangle GetArea()
        {
            int left = this.Left, top = this.Top, right = this.Right, bottom = this.Bottom;
            Rectangle childArea;

            if (childNodes.Count < 0 || IsExtended == false)
                return new Rectangle(left, top, this.Width, this.Height);

            foreach (TreeShape childNode in childNodes)
            {
                childArea = childNode.GetArea();

                if (left > childArea.Left)
                    left = childArea.Left;

                if (right < childArea.Right)
                    right = childArea.Right;

                if (top > childArea.Top)
                    top = childArea.Top;

                if (bottom < childArea.Bottom)
                    bottom = childArea.Bottom;
            }

            return new Rectangle(left, top, right - left, bottom - top);
        }

        /// <summary>
        /// 현재 노드의 하위 노드가 표현되고 있는 영역을 계산합니다
        /// </summary>
        /// <returns>계산된 영역의 Rectangle</returns>
        public Rectangle GetChildArea()
        {
            if (childNodes.Count <= 0 || IsExtended == false)
                return new Rectangle(0, 0, 0, 0);

            int left = childNodes[0].Left, top = childNodes[0].Top, right = childNodes[0].Right, bottom = childNodes[0].Bottom;
            Rectangle childArea;

            foreach (TreeShape childNode in childNodes)
            {
                childArea = childNode.GetArea();

                if (left > childArea.Left)
                    left = childArea.Left;

                if (right < childArea.Right)
                    right = childArea.Right;

                if (top > childArea.Top)
                    top = childArea.Top;

                if (bottom < childArea.Bottom)
                    bottom = childArea.Bottom;
            }

            return new Rectangle(left, top, right - left, bottom - top);

        }

        /// <summary>
        /// 필요한 기본 값들을 생성
        /// </summary>
        protected virtual void GenerateDrawingValues()
        {
            Rectangle regionRectangle = new Rectangle(0, 0, (int)(this.Width * DiagramSettings.Zoom), (int)(this.Height * DiagramSettings.Zoom));
            Rectangle innerRect = new Rectangle(5, 5, this.Width - 11, this.Height - 11);
            rectangle = new Rectangle(1, 1, this.Width - 3, this.Height - 3);
            selectedRect = new Rectangle(1, 1, this.Width - 3, this.Height - 3);

            path = ShapeDrawings.GeneratePath(nodeShape, rectangle);
            innerPath = ShapeDrawings.GeneratePath(nodeShape, innerRect);
            selectionPath = ShapeDrawings.GeneratePath(nodeShape, selectedRect);

            outterLinGrdBrush = new LinearGradientBrush(rectangle, backGradientColor, frontGradientColor, LinearGradientMode.Horizontal);
            innerLinGrdBrush = new LinearGradientBrush(innerRect, frontGradientColor, backGradientColor, LinearGradientMode.Horizontal);

            region.MakeEmpty();
            region.Union(this.Bounds);
            this.Region = new Region(ShapeDrawings.GeneratePath(nodeShape, regionRectangle));
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public override BaseShape CreateNew()
        {
            return new TreeShape();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="parentPanel"></param>
        /// <returns></returns>
        public override BaseShape CreateNew(BaseDiagramPanel parentPanel)
        {
            return new TreeShape(parentPanel);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="obj"></param>
        public virtual void UpdateByDelegator(TreeShape sender, object obj)
        {
        }

        #endregion


        #region <<< [ Events       ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 마우스 더블클릭 이벤트 입니다.
        /// </summary>
        /// <param name="e"></param>
        protected override void OnDoubleClick(EventArgs e)
        {
            base.OnDoubleClick(e);
            InvertExtends(!isExtended);
            ((TreeDiagramPanel)ParentPanel).SortChilds(RootNode, DiagramSettings.GetSortDirection( RootNode.NodeLevel));
            ParentPanel.Invalidate();
        }

        /// <summary>
        /// 크기 변경에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected override void OnResize(EventArgs e)
        {
            base.OnResize(e);
            GenerateDrawingValues();
        }

        /// <summary>
        /// Move 이벤트 입니다.
        /// </summary>
        /// <param name="e"></param>
        protected override void OnMove(EventArgs e)
        {
            base.OnMove(e);
            if (ParentPanel != null)
                this.ParentPanel.Invalidate();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="e"></param>
        protected override void OnMouseUp(MouseEventArgs e)
        {
            base.OnMouseUp(e);

            if (e.Button == MouseButtons.Left)
            {
                if (IsExtended == false)
                    ((TreeDiagramPanel)ParentPanel).SortChilds(this, DiagramSettings.GetSortDirection( this.NodeLevel) );
            }
        }

        /// <summary>
        /// 노드가 선택되었을시의 이벤트 입니다.
        /// </summary>
        /// <param name="value"></param>
        protected override void ToggleSelected(bool value)
        {
            base.ToggleSelected(value);
            if (((TreeDiagramPanel)ParentPanel).ChildAutoSelect)
                if (IsExtended)
                    foreach (TreeShape node in ChildNodes)
                        node.IsSelected = value;
        }

        #endregion

    }
}
