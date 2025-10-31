// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : BaseElement.cs
// 파일 설명    : 다이어그램을 구성하는 노드(node)가 상속받아야 하는 클래스
// 최초 작성자  : 임혁수(maverick@miracom.co.kr)
// 최초 작성일  : 2007년 5월 8일
// 최종 수정일  : 2007년 5월 8일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 08 : [임혁수] 최초 작성
// 2007. 05. 09 : [노현종] Properties, Constructor, Event, XML Region에 메소드 추가
// 2007. 05. 11 : [노현종] Draw 관련 메소드 추가
// 2007. 05. 15 : [임혁수] 객체 관리를 위한 클래스 수정
// 2007. 05. 16 : [노현종] ContentObject, ContentObjectType 프로퍼티 추가 ( BaseShape, BaseShape<ContentType> )
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;
using System.Xml;
using System.Collections.Generic;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 다이어그램을 구성하는 노드(node)가 상속받아야 하는 클래스입니다.
    /// </summary>
    public abstract class BaseShape : BaseElement
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        ShapeLabel inLabel;
        ShapeLabel outLabel;

        /// <summary>
        /// 고유값 Entity
        /// </summary>
        Entity entity = null;

        /// <summary>
        /// 이 컨트롤을 소유하고 있는 컨트롤 입니다. (Panel 타입)
        /// </summary>
        BaseDiagramPanel parentPanel;

        /// <summary>
        /// 그려질 다이어그램의 GraphicsPath 입니다.
        /// </summary>
        protected GraphicsPath path;

        /// <summary>
        /// 노드(도형)이 가지고 있는 DefaultHolder 리스트
        /// </summary>
        protected List<BaseHolder> holders = new List<BaseHolder>();

        /// <summary>
        /// 다이어그램을 구성하는 요소의 선택 여부가 변경되었을 경우에 발생하는 이벤트입니다.
        /// </summary>
        public new event EventHandler SelectionChanged;

        /// <summary>
        /// 다이어그램 구성 요소가 표현하고 있는 실제 데이터가 변경되었을 경우에 발생하는 이벤트입니다.
        /// </summary>
        public new event EventHandler ContentChanged;

        /// <summary>
        /// 다이어그램을 구성하는 요소가 삭제되었을 경우 발생하는 이벤트입니다.
        /// </summary>
        public new event EventHandler ElementDeleted;

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 도형의 중심점 값을 얻어오는 프로퍼티 입니다.
        /// </summary>
        public Point ShapeCenter
        {
            get { return new Point(this.Location.X + (this.Width / 2), this.Location.Y + (this.Height / 2)); }
        }

        /// <summary>
        /// 절대좌표로 좌측끝 값을 가져오는 프로퍼티 입니다.
        /// </summary>
        public int AbsoluteLeft
        {
            get { return parentPanel.Offset.Width + this.Left; }
        }

        /// <summary>
        /// 절대좌표로 위쪽끝 값을 가져오는 프로퍼티 입니다.
        /// </summary>
        public int AbsoluteTop
        {
            get { return parentPanel.Offset.Height + this.Top; }
        }

        /// <summary>
        /// 절대좌표로 위치값을 가져오는 프로퍼티 입니다.
        /// </summary>
        public Point AbsoluteLocation
        {
            get { return this.Location + parentPanel.Offset; }
        }

        /// <summary>
        /// 내부 Label을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public ShapeLabel IntenalLabel
        {
            get { return this.inLabel;  }
            set { this.inLabel = value; }
        }

        /// <summary>
        /// 외부 Label을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public ShapeLabel ExternalLabel
        {
            get { return this.outLabel; }
            set { this.outLabel = value; }
        }
        
        /// <summary>
        /// Entity를 가져오는 프로퍼티 입니다.
        /// </summary>
        public Entity Entity
        {
            get { return entity; }
        }

        /// <summary>
        /// 최소 높이값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        protected int MinHeight
        {
            get
            {
                return MinimumSize.Height;
            }
            set
            {
                if (value != MinimumSize.Height)
                    MinimumSize = new Size(MinimumSize.Width, value);
            }
        }

        /// <summary>
        /// DefaultHolder 리스트를 가져오는 프로퍼티 입니다.
        /// </summary>
        internal List<BaseHolder> Holders
        {
            get { return holders; }
        }

        /// <summary>
        /// 노드(도형)이 올려져 있는 Panel을 가져오는 프로퍼티 입니다.
        /// </summary>
        public BaseDiagramPanel ParentPanel
        {
            get { return parentPanel; }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 기본 생성자 입니다.
        /// </summary>
        protected BaseShape()
        {
            inLabel = new ShapeLabel(this,true);
            outLabel = new ShapeLabel(this,false);

        }

        /// <summary>
        /// BaseShape의 변환생성자 입니다.
        /// </summary>
        /// <param name="parentPanel">Shape가 소속된 Panel</param>
        protected BaseShape(BaseDiagramPanel parentPanel) : this()
        {
            if (parentPanel == null)
                throw new ArgumentException("parent");

            this.parentPanel = parentPanel;
            this.MinimumSize = new Size(40, 40);
            this.ResizeRedraw = true;
            this.DoubleBuffered = true;    
        }

        #endregion
        

        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 그리기를 처리합니다.
        /// </summary>
        /// <param name="g">GDI+ 그리기 화면을 캡슐화한 Graphics입니다.</param>
        /// <param name="position">그리기 시작하는 좌표를 나타내는 Point입니다.</param>
        public void Draw(Graphics g, Point position)
        {
            Draw(g, position, DiagramSettings.Zoom, false);
        }

        /// <summary>
        /// 그리기를 처리합니다.
        /// </summary>
        /// <param name="g">GDI+ 그리기 화면을 캡슐화한 Graphics입니다.</param>
        /// <param name="position">그리기 시작하는 좌표를 나타내는 Point입니다.</param>
        /// <param name="zoom">그리기 배율을 정하는 Float입니다.</param>
        public void Draw(Graphics g, Point position, float zoom)
        {
            Draw(g, position, zoom, false);
        }

        /// <summary>
        /// 다시그리기를 실행합니다.
        /// </summary>
        /// <param name="g"></param>
        public void Redraw(Graphics g)
        {
            g.PixelOffsetMode = PixelOffsetMode.HighSpeed;
            g.SmoothingMode = SmoothingMode.AntiAlias;
            Draw(g, Point.Empty, DiagramSettings.Zoom, true);
        }

        /// <summary>
        /// 영역 선택시 선택 영역내에 속해있는지 판단하여 선택여부를 처리하는 메소드 입니다.
        /// </summary>
        /// <param name="selectionRectangle">선택영역을 나타내는 Rectangle 입니다</param>
        public virtual void TrySelect(Rectangle selectionRectangle)
        {
            Rectangle rectangle = new Rectangle(Location, Size);

            if (selectionRectangle.IntersectsWith(rectangle))
                IsSelected = true;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        protected override void ToggleSelected(bool value)
        {
            if (value == true)
                this.BringToFront();
            Invalidate();
            OnSelectionChanged(EventArgs.Empty);
        }

        

        #region XML >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <exception cref="ArgumentNullException">
        /// <paramref name="node"/> is null.
        /// </exception>
        public void Serialize(XmlNode node)
        {
            if (node == null)
                throw new ArgumentNullException("node");
        }

        /// <exception cref="ArgumentNullException">
        /// <paramref name="node"/> is null.
        /// </exception>
        public void Deserialize(XmlNode node)
        {
            if (node == null)
                throw new ArgumentNullException("node");
        }

        #endregion

        #endregion


        #region <<< [ Events       ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// OnPaint Event를 처리합니다.
        /// </summary>
        /// <param name="e">이벤트 데이터가 들어있는 PaintEventArgs입니다</param>
        protected override void OnPaint(System.Windows.Forms.PaintEventArgs e)
        {
            base.OnPaint(e);
            Redraw(e.Graphics);
        }

        /// <summary>
        /// 크기 변경 이벤트 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected override void OnResize(EventArgs e)
        {
            for (int i = 0; i < Holders.Count; i++)
            {
                BaseHolder node = Holders[i];

                if (node.IsVertical && node.RelativeLocation >= this.Width)
                    node.RelativeLocation = this.Width - 1;
                else if (node.IsHorizontal && node.RelativeLocation >= this.Height)
                    node.RelativeLocation = this.Height - 1;
                else
                    node.IsDirty = true;
            }
            base.OnResize(e);
        }

        /// <summary>
        /// 선택 여부가 변경되었을 경우에 처리해야 하는 내용을 정의한 메서드 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected virtual void OnSelectionChanged(EventArgs e)
        {
            if (SelectionChanged != null)
                SelectionChanged(this, e);
        }

        /// <summary>
        /// 내용이 변경되었을 경우에 처리해야 하는 내용을 정의한 메서드 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected virtual void OnContentsChanged(EventArgs e)
        {
            if (ContentChanged != null)
                ContentChanged(this, e);
        }

        /// <summary>
        /// 요소가 삭제되엇을 경우에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected virtual void OnElementDeleted(EventArgs e)
        {
            if (ElementDeleted != null)
                ElementDeleted(this, e);
        }

        /// <summary>
        /// Mouse Down 이벤트 입니다.
        /// </summary>
        /// <param name="e">MouseEventArgs</param>
        protected override void OnMouseDown(MouseEventArgs e)
        {
            OnEnter(EventArgs.Empty);
            base.OnMouseDown(e);
        }

        /// <summary>
        /// Mouse 이동에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected override void OnMove(EventArgs e)
        {
            base.OnMove(e);
            for (int i = 0; i < Holders.Count; i++)
                Holders[i].IsDirty = true;

            ParentPanel.Invalidate();
        }

        #endregion


        #region <<< [ Abstracts    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        
        /// <summary>
        /// 그리기를 SubClass에 맞게 처리하도록 하는 abstract 메소드 입니다.
        /// </summary>
        /// <param name="g">GDI+ 그리기 화면을 캡슐화한 Graphics입니다.</param>
        /// <param name="position">그리기 시작하는 좌표를 나타내는 Point입니다.</param>
        /// <param name="zoom">그리기 배율을 정하는 Float입니다.</param>
        /// <param name="onScreen">그리기를 화면상에 처리할지 그렇지 않을지에 대한 Bool입니다</param>
        protected abstract void Draw(Graphics g, Point position, float zoom, bool onScreen);

        /// <summary>
        /// 사용자 정의 Shape를 내주적으로 처리할 수 있도록 해주기 위해 사용되는 생성자격의 함수입니다.
        /// </summary>
        /// <returns>생성된 새 Shape</returns>
        public abstract BaseShape CreateNew();

        /// <summary>
        /// 
        /// </summary>
        /// <param name="parentPanel"></param>
        /// <returns>생성된 새 Shape</returns>
        public abstract BaseShape CreateNew(BaseDiagramPanel parentPanel);

        #endregion

    }
}
