using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 
    /// </summary>
    public enum TreeConnectionType
    {
        /// <summary>
        /// 
        /// </summary>
        Default,

        /// <summary>
        /// 
        /// </summary>
        Sibling,

        /// <summary>
        /// 
        /// </summary>
        ParentChild
    }

    /// <summary>
    /// 
    /// </summary>
    public class TreeConnection : BaseConnection
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        TreeConnectionType connectionType;

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 
        /// </summary>
        public TreeConnectionType ConnectionType
        {
            get { return connectionType;  }
            set { connectionType = value; }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// TreeConnection을 생성합니다.
        /// </summary>
        public TreeConnection()
            : base()
        {
        }
        

        /// <summary>
        /// 
        /// </summary>
        /// <param name="startHolder"></param>
        /// <param name="endHolder"></param>
        /// <param name="type"></param>
        public TreeConnection(BaseHolder startHolder, BaseHolder endHolder, TreeConnectionType type)
            : base(startHolder, endHolder)
        {
            this.ConnectionType = type;
            bool verticalOrder = DiagramSettings.GetSortDirection(((TreeShape)endHolder.Shape).NodeLevel);
            
            switch (type)
            {
                case TreeConnectionType.Sibling:
                    startHolder.SetHorizontal(verticalOrder);
                    endHolder.SetHorizontal(verticalOrder);
                    this.ConnectionProperty.StartArrow = ArrowStyle.None;
                    this.ConnectionProperty.EndArrow = ArrowStyle.Realization;                    
                    break;

                case TreeConnectionType.ParentChild:
                    startHolder.SetHorizontal(verticalOrder);
                    endHolder.SetHorizontal(!verticalOrder);
                    this.ConnectionProperty.StartArrow = ArrowStyle.Nesting;
                    this.ConnectionProperty.EndArrow = ArrowStyle.None;                    
                    break;

                default:
                    break;
            }
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 시작점 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected override void DrawRelativeStartSign(System.Drawing.Graphics g)
        {
            base.DrawRelativeStartSign(g);

            switch (this.ConnectionType)
            {
                case TreeConnectionType.Sibling:
                    ConnectionArrowDrawings.LightBrush.Color = this.ConnectionProperty.LineColor;
                    ConnectionArrowDrawings.SolidPen.Color = this.ConnectionProperty.LineColor;
                    ConnectionArrowDrawings.Draw(g, ConnectionProperty.StartArrow);
                    break;
                case TreeConnectionType.ParentChild:
                    ConnectionArrowDrawings.LightBrush.Color = Color.White;
                    ConnectionArrowDrawings.SolidPen.Color = this.ConnectionProperty.LineColor;
                    ConnectionArrowDrawings.Draw(g, ConnectionProperty.StartArrow);
                    break;
                default:
                    break;
            }
        }

        /// <summary>
        /// 끝점 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected override void DrawRelativeEndSign(System.Drawing.Graphics g)
        {
            base.DrawRelativeEndSign(g);
            ConnectionArrowDrawings.LightBrush.Color = this.ConnectionProperty.LineColor;
            ConnectionArrowDrawings.SolidPen.Color = this.ConnectionProperty.LineColor;
            ConnectionArrowDrawings.Draw(g, ConnectionProperty.EndArrow);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public override BaseConnection CreateNew()
        {
            return new TreeConnection();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="previewStartHolder"></param>
        /// <param name="previewEndHolder"></param>
        /// <returns></returns>
        public override BaseConnection CreateNew(BaseHolder startHolder, BaseHolder endHolder)
        {
            return new TreeConnection(startHolder, endHolder, TreeConnectionType.Default);
        }

        #endregion

    }
}