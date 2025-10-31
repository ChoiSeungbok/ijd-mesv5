using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 
    /// </summary>
    public class TreeDiagramPanel : BaseDiagramPanel
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        private ConnectionRuleSet _connectionRule = new ConnectionRuleSet();

        /// <summary>
        /// 노드 선택시 하위 노드를 자동으로 선택하도록 할지에 대한 True/False
        /// </summary>
        private bool bChildAutoSelect = false;

        /// <summary>
        /// 노드간 정렬시 사용할 간격 기준
        /// </summary>
        private Size nodeInterval = new Size(40, 20);

        #endregion


        #region <<< [ Constructor  ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// TreeDiagramPanel을 생성합니다.
        /// </summary>
        public TreeDiagramPanel()
            : base()
        {
        }

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        public ConnectionRuleSet ConnectionRule
        {
            get
            {
                return this._connectionRule;
            }
            set
            {
                this._connectionRule = value;
            }
        }

        /// <summary>
        /// 노드가 선택되었을때 하위 노드들도 자동으로 선택할도록 할것인지에 대한 값을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public bool ChildAutoSelect
        {
            get { return bChildAutoSelect;  }
            set { bChildAutoSelect = value; }
        }

        /// <summary>
        /// 
        /// </summary>
        public Size NodeInterval
        {
            get 
            {
                
                //return nodeInterval;

                return new Size((int)(nodeInterval.Width * DiagramSettings.Zoom), (int)(nodeInterval.Height * DiagramSettings.Zoom));
            
            }
            set { nodeInterval = value; }
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        public virtual bool AddRelation(TreeConnection connection)
        {
            return true;
        }

        /// <summary>
        /// 지정한 노드의 다음 Child가 올 위치를 계산합니다. (SortChilds 에서 사용됩니다.)
        /// </summary>
        /// <param name="parentNode">부모 노드</param>
        /// <param name="bVertical">수직정렬인지에 대한 True/False값</param>
        /// <returns>계산된 위치값</returns>
        protected Point GetNewChildLocation(TreeShape parentNode)
        {
            Point newLocation;
            // 추가될 노드의 위치를 계산
            if (parentNode.HasChildNode)
            {
                TreeShape lastChild = parentNode.LastChildNode;

                newLocation          = lastChild.Location;
                CalculateLocation(lastChild.Size, lastChild.GetChildArea().Size + NodeInterval, ref newLocation, DiagramSettings.GetSortDirection(parentNode.NodeLevel));

                
            }
            else
                newLocation = parentNode.Location + parentNode.Size + NodeInterval;

            return newLocation;
        }

        /// <summary>
        /// 노드를 위치시킬 좌표를 계산합니다.(일괄 생성시 사용)
        /// </summary>
        /// <param name="prevSiblingNodeSize">이전 이웃 노드의 노드 크기값</param>
        /// <param name="childAreaOfPrevSiblingNode">이전 이웃 노드의 Child 노드의 영역값</param>
        /// <param name="newLocation">새 노드의 위치로 사용할 변수</param>
        /// <param name="bVertical">정렬방식이 수직방식인지에 대한 True/False</param>
        public void CalculateLocation(Size prevSiblingNodeSize, Size childAreaOfPrevSiblingNode, ref Point newLocation, bool bVertical)
        {
            // 연속된 Node의 위치값을 수직으로 증가시킬지 수평으로 증가시킬지에 따라 위치값을 수정                
            if (bVertical)
                newLocation.Y += (prevSiblingNodeSize.Height + NodeInterval.Height + childAreaOfPrevSiblingNode.Height);
            else
                newLocation.X += (prevSiblingNodeSize.Width + NodeInterval.Width + childAreaOfPrevSiblingNode.Width);                                
        }

        public Point CalculateSpace(TreeShape node, bool bVertical)
        {
            // 연속된 Node의 위치값을 수직 혹은 수평으로 증가시킬 값을 게산
            if (bVertical)
                return new Point(0, node.Height + node.GetChildArea().Height + (NodeInterval.Height * 2));
            else
                return new Point(node.Width + node.GetChildArea().Width + (nodeInterval.Width * 2), 0);

            // 연속된 Node의 위치값을 수직으로 증가시킬지 수평으로 증가시킬지에 따라 위치값을 수정
            //if (bVertical)
            //    newLocation.Y += (prevSiblingNodeSize.Height + NodeInterval.Height + childAreaOfPrevSiblingNode.Height);
            //else
            //    newLocation.X += (prevSiblingNodeSize.Width + NodeInterval.Width + childAreaOfPrevSiblingNode.Width);
        }

        /// <summary>
        /// 지정한 노드의 Child 노드들을 일정 간격으로 정렬합니다.
        /// </summary>
        /// <param name="node">정렬하고자 하는 노드</param>
        public void SortChilds(TreeShape node, bool bVertical)
        {
            if (node.HasChildNode)
            {
                TreeShape child     = null;
                TreeShape prevChild = null;
                Point newLocation;
                
                node.GetChildNode(0).Location = node.Location + node.Size + NodeInterval;

                SortChilds(node.GetChildNode(0), !bVertical);

                if (node.ChildNodesCount >= 2)
                {
                    for (int i = 1; i < node.ChildNodesCount; i++)
                    {
                        child           = node.GetChildNode(i);
                        prevChild       = child.PrevNode;
                        newLocation     = prevChild.Location;
                        CalculateLocation(prevChild.Size, prevChild.GetChildArea().Size + NodeInterval, ref newLocation, bVertical);                        
                        child.Location  = newLocation;                        

                        SortChilds(child, !bVertical);
                    }
                }
            }

            Invalidate();
        }

        /// <summary>
        /// 지정한 정보와 일치하는 노드들을 찾습니다.
        /// </summary>
        /// <param name="sKey">Key값에 해당하는 이름</param>
        /// <param name="iKey">Version이나 Sequence값</param>
        /// <param name="select">검색해서 일치하는 노드를 선택 상태로 변경할것인지에 대한 True/False</param>
        /// <returns>일치하는 노드들의 리스트</returns>
        public List<TreeShape> FindNodes(string sKey, int iKey, bool select)
        {
            List<TreeShape> returnList = new List<TreeShape>();

            foreach (TreeShape node in shapes)
            {
                if (node.StringKey == sKey && node.IntegerKey == iKey)
                {
                    returnList.Add(node);

                    if (select)
                        node.IsSelected = true;
                }
            }

            return returnList;
        }

        /// <summary>
        /// 선택된 노드들을 삭제 할 수 있는지 확인합니다.
        /// </summary>
        /// <returns></returns>
        public bool CanDeleteSelectedNodes()
        {
            List<TreeShape> topNodeList = new List<TreeShape>();

            int currentTopNodeLevel = 100;

            for (int i = 0; i < shapes.Count; i++)
            {
                if (shapes[i].IsSelected)
                {
                    if (((TreeShape)shapes[i]).NodeLevel < currentTopNodeLevel)
                    {
                        topNodeList.Clear();
                        topNodeList.Add((TreeShape)shapes[i]);
                        currentTopNodeLevel = (int)((TreeShape)shapes[i]).NodeLevel;
                    }
                    else if (((TreeShape)shapes[i]).NodeLevel == currentTopNodeLevel)
                    {
                        topNodeList.Add((TreeShape)shapes[i]);
                    }
                }
            }

            foreach (TreeShape node in topNodeList)
            {
                if (node.ParentNode != null)
                    return false;
            }

            return true;
        }        

        /// <summary>
        /// 
        /// </summary>
        /// <param name="startNode"></param>
        /// <param name="endNode"></param>
        /// <param name="isSiblingConnection"></param>
        /// <param name="bChildReGen"></param>
        /// <returns></returns>
        public virtual bool Attach(TreeShape startNode, TreeShape endNode, bool isSiblingConnection, bool bChildReGen)
        {
            return false;
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="startNode"></param>
        /// <param name="endNode"></param>
        /// <param name="isSiblingConnection"></param>
        /// <returns></returns>
        public virtual bool Detach(TreeShape startNode, TreeShape endNode, bool isSiblingConnection)
        {
            return false;
        }

        #endregion


        #region <<< [ Events       ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 
        /// </summary>
        /// <param name="e"></param>
        protected override void OnDragEnter(DragEventArgs e)
        {
            base.OnDragEnter(e);
            e.Effect = DragDropEffects.Copy;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="drgevent"></param>
        protected override void OnDragOver(DragEventArgs drgevent)
        {
            base.OnDragOver(drgevent);
            drgevent.Effect = DragDropEffects.Copy;
        }

        #endregion

    }
}
