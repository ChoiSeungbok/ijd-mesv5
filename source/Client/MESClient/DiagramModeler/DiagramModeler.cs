using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// Diagram Modeler 클래스 입니다.
    /// </summary>
    public class DiagramModeler
    {

        BaseDiagramPanel diagram = null;


        #region Properties >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Diagram Modeler에서 사용할 작업영역 Panel을 설정하거나 가져오는 프로퍼티 입니다.
        /// </summary>
        public BaseDiagramPanel WFM_CurrentDiagramPanel
        {
            get { return diagram;  }
            set { diagram = value; }
        }

        #endregion


        #region Constructors >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// DiagramModeler를 생성합니다.
        /// </summary>
        public DiagramModeler()
        {
            DiagramSettings.LoadSettings();
            diagram = new BaseDiagramPanel();           
        }

        /// <summary>
        /// DiagramModeler를 생성합니다.
        /// </summary>
        /// <param name="diagramPanel">Diagram 작업영역 Panel</param>
        public DiagramModeler(BaseDiagramPanel diagramPanel)
        {
            if( diagramPanel == null)
                throw new Exception("DiagramPanel is Null");
            DiagramSettings.LoadSettings();
            DiagramSettings.SaveSettings();
            this.diagram = diagramPanel;
        }

        #endregion


        #region Methods >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 두 Node를 지정한 Connection으로 연결하여 Diagram에 추가합니다.
        /// </summary>
        /// <param name="connection">간선</param>
        /// <param name="org">시작점 노드(도형)</param>
        /// <param name="dst">끝점 노드(도형)</param>
        public void WFM_AddConnection(BaseConnection connection, BaseShape org, BaseShape dst)
        {            
            BaseHolder holder1 = null;            
            BaseHolder holder2 = null;

            if( DiagramSettings.UseCustomConnectionHolder )
            {
                holder1 = WFM_CurrentDiagramPanel.CurrentCustomConnectionHolder.CreateNew(org);
                holder2 = WFM_CurrentDiagramPanel.CurrentCustomConnectionHolder.CreateNew(dst);
            }
            else
            {
                holder1 = new DefaultHolder(org);
                holder2 = new DefaultHolder(dst);
            }

            connection.ReplaceHolder(holder1, holder2);

            WFM_CurrentDiagramPanel.AddShape(org, Point.Empty);
            WFM_CurrentDiagramPanel.AddShape(dst, Point.Empty);
            WFM_CurrentDiagramPanel.AddConnection(connection);
        }

        /// <summary>
        /// 두 Node를 연결하는 Connection을 생성하여 Diagram에 추가합니다.
        /// </summary>
        /// <param name="org">시작점 노드(도형)</param>
        /// <param name="dst">끝점 노드(도형)</param>
        /// <returns></returns>
        public BaseConnection WFM_CreateConnection(BaseShape org, BaseShape dst)
        {
            BaseConnection connection = null;
            BaseHolder holder1 = null;
            BaseHolder holder2 = null;

            if (DiagramSettings.UseCustomConnectionHolder)
            {
                holder1 = WFM_CurrentDiagramPanel.CurrentCustomConnectionHolder.CreateNew(org);
                holder2 = WFM_CurrentDiagramPanel.CurrentCustomConnectionHolder.CreateNew(dst);
            }
            else
            {
                holder1 = new DefaultHolder(org);
                holder2 = new DefaultHolder(dst);
            }


            if (DiagramSettings.UseCustomConnection)
            {
                connection = WFM_CurrentDiagramPanel.CurrentCustomConnection.CreateNew(holder1, holder2);
            }
            else
            {
                connection = new DefaultConnection(holder1, holder2);
            }

            WFM_CurrentDiagramPanel.AddShape(org, Point.Empty);
            WFM_CurrentDiagramPanel.AddShape(dst, Point.Empty);
            WFM_CurrentDiagramPanel.AddConnection(connection);
            return connection;
        }

        /// <summary>
        /// 선택된 Element들을 삭제합니다.
        /// </summary>
        public void WFM_DeleteSel()
        {
            this.WFM_CurrentDiagramPanel.DeleteSelectedElements();
        }

        /// <summary>
        /// Diagram의 크기 영역값을 받아옵니다.
        /// </summary>
        /// <returns>영역값 SizeF</returns>
        public SizeF WFM_GetDiagramSize()
        {
            return WFM_CurrentDiagramPanel.Size;
        }

        /// <summary>
        /// 지정된 좌표 위에 위치하는 Element를 받아옵니다.
        /// </summary>
        /// <param name="pt">지정좌표 Point 입니다.</param>
        /// <returns>좌표상에 위치하는 Element</returns>
        public BaseElement WFM_GetElementAt(Point pt)
        {
            return null;
        }

        /// <summary>
        /// 지정된 영역에 존재하는 Element의 List를 받아옵니다.
        /// </summary>
        /// <param name="selRectangle">지정 영역 Rectangle</param>
        /// <returns>지정영역에 존재하는 Element 리스트</returns>
        public List<BaseElement> WFM_GetElementsRectangle(Rectangle selRectangle)
        {
            return WFM_CurrentDiagramPanel.GetElementsRectangle(selRectangle);
        }

        /// <summary>
        /// 지정된 영역에 존재하는 Element의 List를 받아옵니다.
        /// </summary>
        /// <param name="selRectangle">지정 영역 Rectangle</param>
        /// <param name="partial">부분포함시 추가할것인지에 대한 True/False</param>
        /// <returns>지정영역에 존재하는 Element 리스트</returns>
        public List<BaseElement> WFM_GetElementsRectangle(Rectangle selRectangle, bool partial)
        {
            return WFM_CurrentDiagramPanel.GetElementsRectangle(selRectangle);
        }

        /// <summary>
        /// 취소한 작업을 다시 실행합니다. ( 미구현 사항 )
        /// </summary>
        /// <returns>실행되었는지에 대한 True/False</returns>
        private bool WFM_Redo()
        {
            return false;
        }

        /// <summary>
        /// 실행한 작업을 취소합니다. ( 미구현 사항 )
        /// </summary>
        /// <returns>취소 되었는지에 대한 True/False</returns>
        private bool WFM_Undo()
        {
            return false;
        }

        #endregion

    }
}
