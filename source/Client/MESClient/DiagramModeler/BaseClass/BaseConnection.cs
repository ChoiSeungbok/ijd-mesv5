// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : BaseElement.cs
// 파일 설명    : 다이어그램을 구성하는 간선(edge)이 상속받아야 하는 클래스
// 최초 작성자  : 임혁수(maverick@miracom.co.kr)
// 최초 작성일  : 2007년 5월 8일
// 최종 수정일  : 2007년 5월30일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 08 : [임혁수] 최초 작성
// 2007. 05. 11 : [노현종] Constructor, Properties, Event Implementation Region에 메소드 추가
// 2007. 05. 14 : [노현종] Draw 관련 메소드 추가, 프로퍼티 추가
// 2007. 05. 15 : [임혁수] 객체 관리를 위한 클래스 수정
// -----------------------------------------------------------------------------------------------------------

using System.Drawing;
using System;
using System.Drawing.Drawing2D;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 다이어그램을 구성하는 간선이 상속받아야 하는 클래스입니다.
    /// </summary>
    public abstract class BaseConnection : BaseElement
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 연결 가능한지에 대한 값입니다.
        /// </summary>
        protected bool isConnectable = true;

        /// <summary>
        /// 여백 크기 입니다.
        /// </summary>
        public const int iMarginSize = 10;

        /// <summary>
        /// 최대 간선 Point 갯수 입니다.
        /// </summary>
        const int iMaxConnectionPoints = 5;

        /// <summary>
        /// Precision 크기 입니다.
        /// </summary>
        const int PrecisionSize = 2;

        /// <summary>
        /// 간선 Point 배열 입니다.
        /// </summary>
        Point[] linePoints = new Point[iMaxConnectionPoints];

        /// <summary>
        /// 간선 Point의 갯수 입니다.
        /// </summary>
        int iConnectionPointCount;

        /// <summary>
        /// 시작점 연결 Holder 입니다.
        /// </summary>
        internal BaseHolder startHolder;

        /// <summary>
        /// 끝점 연결 Holder 입니다.
        /// </summary>
        internal BaseHolder endHolder;

        /// <summary>
        /// 간선의 속성값들 입니다.
        /// </summary>
        ConnectionProperty connectionProperty;

        /// <summary>
        /// 내용 변경에 대한 이벤트 핸들러 입니다.
        /// </summary>
        public event EventHandler ContentsChanged;

        /// <summary>
        /// 선택 변경에 대한 이벤트 핸들러 입니다.
        /// </summary>
        public new event EventHandler SelectionChanged;

        /// <summary>
        /// 삭제에 대한 이벤트 핸들러 입니다.
        /// </summary>
        public new event EventHandler ElementDeleted;

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        protected Point[] LinePoints
        {
            get { return linePoints; }
        }

        /// <summary>
        /// 내용 Object 입니다.
        /// </summary>
        public override object ContentObject
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        /// <summary>
        /// 내용 Object의 Type 입니다.
        /// </summary>
        public override Type ContentObjectType
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        /// <summary>
        /// 연결 가능한지를 설정하거나 가져오는 프로퍼티 입니다.
        /// </summary>
        public bool IsConnectable
        {
            get { return isConnectable;  }
            set { isConnectable = value; }
        }

        /// <summary>
        /// 간선의 속성값을 설정하거나 가져오는 프로퍼티 입니다.
        /// </summary>
        public ConnectionProperty ConnectionProperty
        {
            get { return connectionProperty;  }
            set { connectionProperty = value; }
        }

        /// <summary>
        /// 간선이 연결하고 있는 시작점 Holder를 가져오는 프로퍼티 입니다.
        /// </summary>
        public BaseHolder StartHolder
        {
            get { return startHolder; }
        }

        /// <summary>
        /// 간선이 연결하고 있는 끝점 Holder를 가져오는 프로퍼티 입니다.
        /// </summary>
        public BaseHolder EndHolder
        {
            get { return endHolder; }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// BaseConnection을 생성합니다.
        /// </summary>
        protected BaseConnection()
        {
            // 새로 생성되는 BaseConnection은 DiagramSettings에서 관리하고 있는 
            // ConnectionProperty Object를 복사하여 입력한다.
            // 이 방법을 통해 새로 생성되는 BaseConnection의 생성시의 ConnectionProperty를 
            // 한곳에서 관리하고자 한다.
            this.ConnectionProperty = (ConnectionProperty)DiagramSettings.ConnectionProperty.Clone();
        }

        /// <summary>
        /// BaseConnection을 생성합니다.
        /// </summary>
        /// <param name="previewStartHolder">간선의 시작점 Holder</param>
        /// <param name="previewEndHolder">간선의 끝점 Holder</param>
        public BaseConnection(BaseHolder startHolder, BaseHolder endHolder) : this()
        {
            if (startHolder == null)
                throw new ArgumentNullException("startHolder");
            if (endHolder == null)
                throw new ArgumentNullException("endHolder");

            this.startHolder = startHolder;
            this.endHolder = endHolder;
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 시작점과 끝점 Holder를 교체합니다.
        /// </summary>
        /// <param name="previewStartHolder">간선의 시작점 Holder</param>
        /// <param name="previewEndHolder">간선의 끝점 Holder</param>
        public void ReplaceHolder(BaseHolder startHolder, BaseHolder endHolder)
        {   
            if (startHolder != null)
                this.startHolder = startHolder;
            if (endHolder != null)
                this.endHolder = endHolder;
        }

        /// <summary>
        /// 선택되었을때 추가 작업을 수행합니다.
        /// </summary>
        /// <param name="value">선택/해제의 True/False값</param>
        protected override void ToggleSelected(bool value)
        {
            OnSelectionChanged(EventArgs.Empty);

            this.BringToFront();
            
            // 선택된 상태와 보통 상태의 간선의 두께를 조절
            if (value == true)
                this.ConnectionProperty.PenWidth = DiagramSettings.ConnectionProperty.DrawPen.Width * 2;
            else
                this.ConnectionProperty.PenWidth = DiagramSettings.ConnectionProperty.DrawPen.Width;
        }

        /// <summary>
        /// 간선의 경로를 계산합니다.
        /// </summary>
        private void CalculateConnectionPoints()
        {
            if (StartHolder.Shape != null && EndHolder.Shape != null &&
                (StartHolder.IsDirty || EndHolder.IsDirty))
            {
                if (StartHolder.IsHorizontal == EndHolder.IsHorizontal)
                    ParallelCalculation();
                else
                    PerpendicularCalculation();

                StartHolder.IsDirty = false;
                EndHolder.IsDirty = false;
            }
        }

        /// <summary>
        /// 간선의 경로를 항상 4점으로 구성하도록 만듭니다.
        /// </summary>
        /// <param name="iX">노드간의 수평 간격</param>
        /// <param name="iY">노드간의 수직 간격</param>
        private void MakeConnection4Points(int iX, int iY)
        {
            if (StartHolder.Shape != null && EndHolder.Shape != null &&
                (StartHolder.IsDirty || EndHolder.IsDirty))
            {
                iConnectionPointCount = 4;

                BaseShape startShape = StartHolder.Shape;
                BaseShape endShape = EndHolder.Shape;

                Point startTopCenter = new Point(startShape.Location.X + startShape.Width / 2, startShape.Top);
                Point startBottomCenter = new Point(startShape.Location.X + startShape.Width / 2, startShape.Bottom);

                Point endTopCenter = new Point(endShape.Location.X + endShape.Width / 2, endShape.Top);
                Point endBottomCenter = new Point(endShape.Location.X + endShape.Width / 2, endShape.Bottom);

                Point startLeftMiddle = new Point(startShape.Left, startShape.Location.Y + startShape.Height / 2);
                Point startRightMiddle = new Point(startShape.Right, startShape.Location.Y + startShape.Height / 2);

                Point endLeftMiddle = new Point(endShape.Left, endShape.Location.Y + endShape.Height / 2);
                Point endRightMiddle = new Point(endShape.Right, endShape.Location.Y + endShape.Height / 2);
                

                if (StartHolder.IsHorizontal == EndHolder.IsHorizontal == true)
                {
                    #region <<< Horizontal, Horizontal >>>
                    
                    if (startShape.Left - iX * 2 > endShape.Right) // 왼쪽, 오른쪽
                    {
                        linePoints[0] = linePoints[1] = startLeftMiddle;
                        linePoints[1].X -= iX;
                        linePoints[2] = linePoints[3] = endRightMiddle;
                        linePoints[2].X += iX;
                    }
                    else if (startShape.Left > endShape.Right) // 왼쪽, 왼쪽
                    {
                        linePoints[0] = linePoints[1] = startLeftMiddle;
                        linePoints[1].X -= iX;
                        linePoints[2] = linePoints[3] = endLeftMiddle;
                        linePoints[2].X -= iX;
                    }
                    else if (startShape.Right + iX * 2 > endShape.Left) // 오른쪽, 오른쪽
                    {
                        linePoints[0] = linePoints[1] = startRightMiddle;
                        linePoints[1].X += iX;
                        linePoints[2] = linePoints[3] = endRightMiddle;
                        linePoints[2].X += iX;
                    }
                    else // 오른쪽, 왼쪽
                    {
                        linePoints[0] = linePoints[1] = startRightMiddle;
                        linePoints[1].X += iX;
                        linePoints[2] = linePoints[3] = endLeftMiddle;
                        linePoints[2].X -= iX;
                    }

                    #endregion
                }
                else if (StartHolder.IsHorizontal == EndHolder.IsHorizontal == false)
                {
                    #region <<< Vertical, Vertical >>>

                    if (startShape.Top - iY * 2 > endShape.Bottom) // 위, 아래
                    {
                        linePoints[0] = linePoints[1] = startTopCenter;
                        linePoints[1].Y -= iY;
                        linePoints[2] = linePoints[3] = endBottomCenter;
                        linePoints[2].Y += iY;
                    }
                    else if (startShape.Top - iY * 2 > endShape.Bottom) // 위, 위
                    {
                        linePoints[0] = linePoints[1] = startTopCenter;
                        linePoints[1].Y -= iY;
                        linePoints[2] = linePoints[3] = endTopCenter;
                        linePoints[2].Y -= iY;
                    }
                    else if (startShape.Bottom + iY * 2 > endShape.Top) // 아래, 아래
                    {
                        linePoints[0] = linePoints[1] = startBottomCenter;
                        linePoints[1].Y += iY;
                        linePoints[2] = linePoints[3] = endBottomCenter;
                        linePoints[2].Y += iY;
                    }
                    else // 아래, 위
                    {
                        linePoints[0] = linePoints[1] = startBottomCenter;
                        linePoints[1].Y += iY;
                        linePoints[2] = linePoints[3] = endTopCenter;
                        linePoints[2].Y -= iY;
                    }

                    #endregion
                }
                else
                {
                    if (startHolder.IsHorizontal)
                    {
                        #region <<< Horizontal, Vertical >>>

                        Point basePoint = new Point(startLeftMiddle.X - iX*2, startLeftMiddle.Y - iY*2);

                        if (basePoint.X >= endBottomCenter.X) // 왼쪽
                        {
                            linePoints[0] = linePoints[1] = startLeftMiddle;
                            linePoints[1].X -= iX;

                            if (basePoint.Y >= endBottomCenter.Y) // 아래
                            {
                                linePoints[3] = linePoints[4] = endBottomCenter;
                                linePoints[3].Y += iY;                            
                            }
                            else // 위
                            {
                                linePoints[3] = linePoints[4] = endTopCenter;
                                linePoints[3].Y -= iY;                            
                            }
                        }
                        else // 오른쪽
                        {
                            linePoints[0] = linePoints[1] = startRightMiddle;
                            linePoints[1].X += iX;

                            if (basePoint.Y >= endBottomCenter.Y) // 아래
                            {
                                linePoints[3] = linePoints[4] = endBottomCenter;
                                linePoints[3].Y += iY;
                            }
                            else // 위
                            {
                                linePoints[3] = linePoints[4] = endTopCenter;
                                linePoints[3].Y -= iY;
                            }
                        }

                        #endregion
                    }
                    else
                    {
                        #region <<< Vertical, Horizontal >>>

                        Point basePoint = new Point(endLeftMiddle.X - iX*2, endLeftMiddle.Y - iY*2);

                        if (basePoint.X > endRightMiddle.X) // 오른쪽
                        {
                            linePoints[0] = linePoints[1] = endRightMiddle;
                            linePoints[1].X += iX;

                            if (basePoint.Y > endRightMiddle.Y) // 위
                            {
                                linePoints[2] = linePoints[3] = startTopCenter;
                                linePoints[2].Y -= iY;
                            }
                            else
                            {
                                linePoints[2] = linePoints[3] = startBottomCenter;
                                linePoints[2].Y += iY;
                            }
                        }
                        else // 왼쪽
                        {
                            linePoints[0] = linePoints[1] = endLeftMiddle;
                            linePoints[1].X -= iX;

                            if (basePoint.Y > endRightMiddle.Y) // 위
                            {
                                linePoints[2] = linePoints[3] = startTopCenter;
                                linePoints[2].Y -= iY;
                            }
                            else
                            {
                                linePoints[2] = linePoints[3] = startBottomCenter;
                                linePoints[2].Y += iY;
                            }
                        }

                        #endregion
                    }
                }

                linePoints[4] = linePoints[3];

                StartHolder.IsDirty = false;
                EndHolder.IsDirty = false;
            }

        }
      
        /// <summary>
        /// 간선의 병렬 경로를 계산합니다.
        /// </summary>
        private void ParallelCalculation()
        {
            if (startHolder.Shape == null || endHolder.Shape == null)
                return;

            BaseShape startShape = StartHolder.Shape;
            BaseShape endShape = EndHolder.Shape;

            iConnectionPointCount = 4;

            if (StartHolder.IsVertical) // 시작점 Holder가 Node의 수직선상에 위치한 경우
            {
                linePoints[0].X = linePoints[1].X = StartHolder.AbsoluteLocation;
                linePoints[2].X = linePoints[3].X = EndHolder.AbsoluteLocation;

                if (endShape.Top - startShape.Bottom >= 2 * iMarginSize ||
                    startShape.Top - endShape.Bottom >= 2 * iMarginSize)
                {
                    if (startShape.Top < endShape.Top)
                    {
                        int semiLength = (endShape.Top - startShape.Bottom) / 2;

                        linePoints[0].Y = startShape.Bottom;
                        linePoints[1].Y = startShape.Bottom + semiLength;
                        linePoints[2].Y = startShape.Bottom + semiLength;
                        linePoints[3].Y = endShape.Top - 1;
                    }
                    else
                    {
                        int semiLength = (startShape.Top - endShape.Bottom) / 2;

                        linePoints[0].Y = startShape.Top - 1;
                        linePoints[1].Y = endShape.Bottom + semiLength;
                        linePoints[2].Y = endShape.Bottom + semiLength;
                        linePoints[3].Y = endShape.Bottom;
                    }
                }
                else
                {
                    BaseShape bottomShape = (startShape.Top < endShape.Top) ?
                        endShape : startShape;

                    linePoints[0].Y = startShape.Bottom;
                    linePoints[1].Y = bottomShape.Bottom + iMarginSize;
                    linePoints[2].Y = bottomShape.Bottom + iMarginSize;
                    linePoints[3].Y = endShape.Bottom;
                }
            }
            else // 간선의 시작점 Holder가 노드의 수평선 상에 위치한 경우
            { 
                linePoints[0].Y = linePoints[1].Y = StartHolder.AbsoluteLocation;
                linePoints[2].Y = linePoints[3].Y = EndHolder.AbsoluteLocation;

                if (endShape.Left - startShape.Right >= 2 * iMarginSize ||
                    startShape.Left - endShape.Right >= 2 * iMarginSize)
                {
                    if (startShape.Left < endShape.Left)
                    {
                        int semiLength = (endShape.Left - startShape.Right) / 2;

                        linePoints[0].X = startShape.Right;
                        linePoints[1].X = startShape.Right + semiLength;
                        linePoints[2].X = startShape.Right + semiLength;
                        linePoints[3].X = endShape.Left - 1;
                    }
                    else
                    {
                        int semiLength = (startShape.Left - endShape.Right) / 2;

                        linePoints[0].X = startShape.Left - 1;
                        linePoints[1].X = endShape.Right + semiLength;
                        linePoints[2].X = endShape.Right + semiLength;
                        linePoints[3].X = endShape.Right;
                    }
                }
                else
                {
                    BaseShape rightShape = (startShape.Left < endShape.Left) ?
                        endShape : startShape;

                    linePoints[0].X = startShape.Right;
                    linePoints[1].X = rightShape.Right + iMarginSize;
                    linePoints[2].X = rightShape.Right + iMarginSize;
                    linePoints[3].X = endShape.Right;
                }
            }
        }

        /// <summary>
        /// 간선의 수직 경로를 계산합니다.
        /// </summary>
        private void PerpendicularCalculation()
        {
            if (startHolder.Shape == null || endHolder.Shape == null)
                return;

            BaseShape startShape = StartHolder.Shape;
            BaseShape endShape = EndHolder.Shape;

            if (StartHolder.IsVertical)
            {
                linePoints[0].X = StartHolder.AbsoluteLocation;

                if ((StartHolder.AbsoluteLocation < endShape.Left - iMarginSize ||
                    StartHolder.AbsoluteLocation >= endShape.Right + iMarginSize) &&
                    (EndHolder.AbsoluteLocation < startShape.Top - iMarginSize ||
                    EndHolder.AbsoluteLocation >= startShape.Bottom + iMarginSize))
                {
                    iConnectionPointCount = 3;

                    if (startShape.Top < endShape.Top)
                        linePoints[0].Y = startShape.Bottom;
                    else
                        linePoints[0].Y = startShape.Top - 1;

                    if (startShape.Left < endShape.Left)
                        linePoints[2].X = endShape.Left - 1;
                    else
                        linePoints[2].X = endShape.Right;

                    linePoints[1] = new Point(StartHolder.AbsoluteLocation, EndHolder.AbsoluteLocation);
                    linePoints[2].Y = EndHolder.AbsoluteLocation;
                }
                else
                {
                    Point connector = new Point();
                    bool vertical = StartHolder.AbsoluteLocation >= endShape.Left - iMarginSize &&
                        StartHolder.AbsoluteLocation < endShape.Right + iMarginSize;

                    iConnectionPointCount = 5;

                    if (StartHolder.AbsoluteLocation < (endShape.Left + endShape.Right) / 2 &&
                        vertical || (!vertical && endShape.Left > startShape.Left))
                    {
                        connector.X = endShape.Left - iMarginSize - 1;
                        linePoints[4].X = endShape.Left - 1;
                    }
                    else
                    {
                        connector.X = endShape.Right + iMarginSize;
                        linePoints[4].X = endShape.Right;
                    }

                    if (EndHolder.AbsoluteLocation < (startShape.Top + startShape.Bottom) / 2 &&
                        !vertical || (vertical && startShape.Top >= endShape.Top))
                    {
                        connector.Y = startShape.Top - iMarginSize - 1;
                        linePoints[0].Y = startShape.Top - 1;
                    }
                    else
                    {
                        connector.Y = startShape.Bottom + iMarginSize;
                        linePoints[0].Y = startShape.Bottom;
                    }

                    linePoints[1] = new Point(StartHolder.AbsoluteLocation, connector.Y);
                    linePoints[2] = connector;
                    linePoints[3] = new Point(connector.X, EndHolder.AbsoluteLocation);
                    linePoints[4].Y = EndHolder.AbsoluteLocation;
                }
            }
            else
            { // previewStartHolder.IsHorizontal
                linePoints[0].Y = StartHolder.AbsoluteLocation;

                if ((StartHolder.AbsoluteLocation < endShape.Top - iMarginSize ||
                    StartHolder.AbsoluteLocation >= endShape.Bottom + iMarginSize) &&
                    (EndHolder.AbsoluteLocation < startShape.Left - iMarginSize ||
                    EndHolder.AbsoluteLocation >= startShape.Right + iMarginSize))
                {
                    iConnectionPointCount = 3;

                    if (startShape.Left < endShape.Left)
                        linePoints[0].X = startShape.Right;
                    else
                        linePoints[0].X = startShape.Left - 1;

                    if (startShape.Top < endShape.Top)
                        linePoints[2].Y = endShape.Top - 1;
                    else
                        linePoints[2].Y = endShape.Bottom;

                    linePoints[1] = new Point(EndHolder.AbsoluteLocation, StartHolder.AbsoluteLocation);
                    linePoints[2].X = EndHolder.AbsoluteLocation;
                }
                else
                {
                    Point connector = new Point();
                    bool horizontal = StartHolder.AbsoluteLocation >= endShape.Top - iMarginSize &&
                        StartHolder.AbsoluteLocation < endShape.Bottom + iMarginSize;

                    iConnectionPointCount = 5;

                    if (StartHolder.AbsoluteLocation < (endShape.Top + endShape.Bottom) / 2 &&
                        horizontal || (!horizontal && endShape.Top > startShape.Top))
                    {
                        connector.Y = endShape.Top - iMarginSize - 1;
                        linePoints[4].Y = endShape.Top - 1;
                    }
                    else
                    {
                        connector.Y = endShape.Bottom + iMarginSize;
                        linePoints[4].Y = endShape.Bottom;
                    }

                    if (EndHolder.AbsoluteLocation < (startShape.Left + startShape.Right) / 2 &&
                        !horizontal || (horizontal && startShape.Left >= endShape.Left))
                    {
                        connector.X = startShape.Left - iMarginSize - 1;
                        linePoints[0].X = startShape.Left - 1;
                    }
                    else
                    {
                        connector.X = startShape.Right + iMarginSize;
                        linePoints[0].X = startShape.Right;
                    }

                    linePoints[1] = new Point(connector.X, StartHolder.AbsoluteLocation);
                    linePoints[2] = connector;
                    linePoints[3] = new Point(EndHolder.AbsoluteLocation, connector.Y);
                    linePoints[4].X = EndHolder.AbsoluteLocation;
                }
            }
        }

        /// <summary>
        /// 선택 영역안에 선택될 수 있는 영역에 위치해 있는지 판단합니다.
        /// </summary>
        /// <param name="selectionRectangle">선택영역을 나타내는 Rectangle 입니다</param>
        /// <returns>선택될수 있는지에 대한 Bool값 입니다</returns>
        public bool IsSelectable(Rectangle selectionRectangle)
        {
            if (StartHolder == null || EndHolder == null)
                return false;

            // Visable하지 않고, Enable 하지 않으면 선택 가능하지 않음
            if (!this.Visible && !this.Enabled)
                return false;

            for (int i = 0; i < iConnectionPointCount - 1; i++)
            {
                if (Intersects(selectionRectangle, linePoints[i], linePoints[i + 1]))
                    return true;
            }
            return false;
        }

        /// <summary>
        /// 마우스 포인트를 기준으로 선택될 수 있는 지점에 있는지 판단합니다.
        /// </summary>
        /// <param name="mouseLocation">마우스 위치</param>
        /// <returns>선택가능한지에 대한 True/False</returns>
        public bool IsSelectable(Point mouseLocation)
        {
            if (StartHolder == null || EndHolder == null)
                return false;

            // Visable하지 않고, Enable 하지 않으면 선택 가능하지 않음
            if (!this.Visible && !this.Enabled)
                return false;

            for (int i = 0; i < iConnectionPointCount - 1; i++)
            {
                if (Intersects(mouseLocation, linePoints[i], linePoints[i + 1]))
                    return true;
            }
            return false;
        }

        /// <summary>
        /// 선택영역에서 선택될 수 있는지 여부를 판단하여 선택 가능하면 선택 상태로 변경합니다.
        /// </summary>
        /// <param name="selectionRectangle">선택영역 Rectangle</param>
        public void TrySelect(Rectangle selectionRectangle)
        {
            if (IsSelectable(selectionRectangle))
                IsSelected = true;
        }

        /// <summary>
        /// 마우스 포인트를 기준으로 선택될 수 있는 지점에 있는지 판단하여 선택 상태로 변경합니다.
        /// </summary>
        /// <param name="mouseLocation">마위스 위치</param>
        public void TrySelect(Point mouseLocation)
        {
            if (IsSelectable(mouseLocation))
                IsSelected = true;
        }
        
        /// <summary>
        /// 지정한 포인트가 두점을 기준으로 생성한 영역에 포함되는지 판단합니다.
        /// </summary>
        /// <param name="point">판단의 대상이 되는 포인트</param>
        /// <param name="startPoint">시작점</param>
        /// <param name="endPoint">끝점</param>
        /// <returns>교차점인지에 대한 True/False</returns>
        private static bool Intersects(Point point, Point startPoint, Point endPoint)
        {
            Rectangle line = CreateRectangleByTwoPoints(startPoint, endPoint);
            return line.Contains(point);
        }

        /// <summary>
        /// 지정한 영역이 두 점을 기준으로 생성한 영역과 겹치는 영역이 있는지 판단합니다.
        /// </summary>
        /// <param name="rectangle">판단의 대상이 되는 영역</param>
        /// <param name="startPoint">시작점</param>
        /// <param name="endPoint">끝점</param>
        /// <returns>교차하는지에 대한 True/False</returns>
        private static bool Intersects(Rectangle rectangle, Point startPoint, Point endPoint)
        {
            Rectangle line = CreateRectangleByTwoPoints(startPoint, endPoint);
            return line.IntersectsWith(rectangle);
        }

        /// <summary>
        /// 두 점을 지나는 사각형 영역을 생성합니다.
        /// </summary>
        /// <param name="startPoint">시작점</param>
        /// <param name="endPoint">끝점</param>
        /// <returns>생성된 영역 Rectangle</returns>
        private static Rectangle CreateRectangleByTwoPoints(Point startPoint, Point endPoint)
        {
            if (startPoint.X == endPoint.X)
            { // Vertical line
                if (startPoint.Y < endPoint.Y)
                {
                    return Rectangle.FromLTRB(startPoint.X - PrecisionSize, startPoint.Y,
                        startPoint.X + PrecisionSize + 1, endPoint.Y);
                }
                else
                {
                    return Rectangle.FromLTRB(startPoint.X - PrecisionSize, endPoint.Y,
                        startPoint.X + PrecisionSize + 1, startPoint.Y);
                }
            }
            else if (startPoint.Y == endPoint.Y)
            { // Horizontal line
                if (startPoint.X < endPoint.X)
                {
                    return Rectangle.FromLTRB(startPoint.X, startPoint.Y - PrecisionSize,
                        endPoint.X, startPoint.Y + PrecisionSize + 1);
                }
                else
                {
                    return Rectangle.FromLTRB(endPoint.X, startPoint.Y - PrecisionSize,
                        startPoint.X, startPoint.Y + PrecisionSize + 1);
                }
            }
            else
            {
                return Rectangle.Empty;
            }
        }

        /// <summary>
        /// 포이트들의 저장 순서를 역순으로 변경합니다.
        /// </summary>
        protected void ReverseConnectionPoints()
        {
            int length = linePoints.Length;

            for (int i = 0; i < length / 2; i++)
            {
                Point temp = linePoints[i];
                linePoints[i] = linePoints[length - i - 1];
                linePoints[length - i - 1] = temp;
            }
        }

        /// <summary>
        /// 저장된 포인트(간선을 구성하는 포인트) 들을 따라 선 그리기를 수행합니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected virtual void DrawLines(Graphics g)
        {
            if (Visible == false)
                return;

            if (iConnectionPointCount >= 2)
            {          

                for (int i = iConnectionPointCount; i < linePoints.Length; i++)
                    linePoints[i] = linePoints[i - 1];

                ReverseConnectionPoints();

                // 간선의 LineStyle에 따라서 선을 그려줍니다.
                switch (this.ConnectionProperty.LineStyle)
                {                        
                    case LineStyle.Polyline:
                        g.DrawLines(this.ConnectionProperty.DrawPen, linePoints);       // 직선으로 간선을 그립니다
                        break;
                    case LineStyle.PolyCurveline:
                        g.DrawCurve(this.ConnectionProperty.DrawPen, linePoints, 0.2f); // 곡선으로 간선을 그립니다.
                        break;
                    case LineStyle.Singleline:
                        g.DrawLine(this.ConnectionProperty.DrawPen, linePoints[0], linePoints[linePoints.Length - 1]);
                        break;
                    case LineStyle.SigleCurveline:
                        //g.DrawLine(this.ConnectionProperty.DrawPen, linePoints[0], linePoints[1]);
                        g.DrawLines(this.connectionProperty.DrawPen, new Point[] {  linePoints[1], linePoints[2] });

                        //g.DrawLine(this.ConnectionProperty.DrawPen, linePoints[3], linePoints[4]);

                        //g.DrawCurve(this.ConnectionProperty.DrawPen, new Point[] { linePoints[1], linePoints[2], linePoints[3], linePoints[4] }, 0.1f);
                        //g.DrawLine(this.ConnectionProperty.DrawPen, linePoints[0], linePoints[1]);
                        //g.DrawCurve(this.ConnectionProperty.DrawPen, new Point[] { linePoints[0], linePoints[ (int)(linePoints.Length / 2)], linePoints[linePoints.Length -1] });
                        break;                        
                }

                ReverseConnectionPoints();

            }            
        }
        
        /// <summary>
        /// 간선 전체를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="position">간선의 화면상의 시작점</param>
        public void DrawOnScreen(Graphics g, Point position)
        {
            Draw(g, position, DiagramSettings.Zoom, true);
        }

        /// <summary>
        /// 간선 전체를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="position">간선의 화면상의 시작점</param>
        /// <param name="zoom">Zoom 배율</param>
        public void DrawOnScreen(Graphics g, Point position, float zoom)
        {
            Draw(g, position, zoom, true);
        }

        /// <summary>
        /// 간선 전체를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="position">간선의 화면상의 시작점</param>
        public void Draw(Graphics g, Point position)
        {
            Draw(g, position, DiagramSettings.Zoom, false);
        }

        /// <summary>
        /// 간선 전체를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="position">간선의 화면상의 시작점</param>
        /// <param name="zoom">Zoom 배율</param>
        public void Draw(Graphics g, Point position, float zoom)
        {
            Draw(g, position, zoom, false);
        }

        /// <summary>
        /// 간선 전체를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="position">간선의 화면상의 시작점</param>
        /// <param name="zoom">Zoom 배율</param>
        /// <param name="onScreen">화면상에 그리는가에 대한 True/False</param>
        private void Draw(Graphics g, Point position, float zoom, bool onScreen)
        {
            if (StartHolder != null && EndHolder != null)
            {
                if (zoom == 1)
                    g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;

                g.ScaleTransform(zoom, zoom);

                g.TranslateTransform(position.X, position.Y);

                //MakeConnection4Points(5, 5);               
                CalculateConnectionPoints();
                

                DrawLines(g);
                DrawStartSign(g);
                DrawEndSign(g);

                g.ResetTransform();
            }
        }

        /// <summary>
        /// Connection으로 연결된 두 노드(도형)간의 관계에 따른 시작점의 표시를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected virtual void DrawRelativeStartSign(Graphics g)
        {
            // DefaultConnection 유형을 정하고 그에따라 필요한 DefaultConnection 모양을 그려줍니다.
        }

        /// <summary>
        /// Connection으로 연결된 두 노드(도형)간의 관계에 따른 끔점의 표시를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected virtual void DrawRelativeEndSign(Graphics g)
        {
            // DefaultConnection 유형을 정하고 그에따라 필요한 DefaultConnection 모양을 그려줍니다.
        }

        /// <summary>
        /// 시작점의 표시를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        private void DrawStartSign(Graphics g)
        {
            if (Enabled == false)
                return;

            if (iConnectionPointCount >= 2)
            {
                int angle = GetStartSignRotationAngle();

                g.TranslateTransform(linePoints[0].X, linePoints[0].Y);
                g.RotateTransform(angle);
                DrawRelativeStartSign(g);
                g.RotateTransform(-angle);
                g.TranslateTransform(-linePoints[0].X, -linePoints[0].Y);
            }
        }

        /// <summary>
        /// 끝점의 표시를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        private void DrawEndSign(Graphics g)
        {
            if (Visible == false)
                return;

            if (iConnectionPointCount >= 2)
            {
                int angle = GetEndSignRotationAngle();

                g.TranslateTransform(linePoints[iConnectionPointCount - 1].X, linePoints[iConnectionPointCount - 1].Y);
                g.RotateTransform(angle);                
                DrawRelativeEndSign(g);
                g.RotateTransform(-angle);
                g.TranslateTransform(-linePoints[iConnectionPointCount - 1].X, -linePoints[iConnectionPointCount - 1].Y);
            }
        }

        /// <summary>
        /// 시작점 표시만을 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="mouseLocation">마우스의 위치값</param>
        public virtual void DrawOnlyStartSign(Graphics g, Point mouseLocation)
        {
            // Preview Connection에서 미리보기 기능 지원에 필요한 시작점 사인 그리기의 Virtual 구현입니다.
            // 실 구현은 PreviewConnection 클래스에 override 되어 있습니다.
        }

        /// <summary>
        /// 두 점 사이의 각도를 구합니다.
        /// </summary>
        /// <param name="point1">좌표 1</param>
        /// <param name="point2">좌표 2</param>
        /// <returns>계산된 각도</returns>
        private int Angle(Point point1, Point point2)
        {
            return (int)Math.Acos(point1.Y / Math.Sqrt(Math.Pow(point2.X,2) - Math.Pow(point2.Y,2) ));
        }


        /// <summary>
        /// 시작점 표시의 회전 각도를 계산합니다.
        /// </summary>
        /// <returns>회전 각도</returns>
        private int GetStartSignRotationAngle()
        {
            if (iConnectionPointCount >= 2)
            {
                if (linePoints[0].X == linePoints[1].X)
                { // Vertical
                    if (linePoints[0].Y < linePoints[1].Y)
                        return 0;
                    else
                        return 180;
                }
                else
                { // Horizontal
                    if (linePoints[0].X < linePoints[1].X)
                        return 270;
                    else
                        return 90;
                }
            }

            return 0;
        }

        /// <summary>
        /// 끝점 표시의 회전 각도를 계산합니다.
        /// </summary>
        /// <returns>회전 각도</returns>
        private int GetEndSignRotationAngle()
        {
            if (iConnectionPointCount >= 2)
            {
                if (linePoints[iConnectionPointCount - 1].X == linePoints[iConnectionPointCount - 2].X)
                { // Vertical
                    if (linePoints[iConnectionPointCount - 1].Y < linePoints[iConnectionPointCount - 2].Y)
                        return 0;
                    else
                        return 180;
                }
                else
                { // Horizontal
                    if (linePoints[iConnectionPointCount - 1].X < linePoints[iConnectionPointCount - 2].X)
                        return 270;
                    else
                        return 90;
                }
            }

            return 0;
        }

        /// <summary>
        /// 마우스 위치에 위치한 Holder를 얻어옵니다.
        /// </summary>
        /// <param name="mouseLocation">마우스 위치</param>
        /// <returns>DefaultHolder</returns>
        public BaseHolder GetHolder(Point mouseLocation)
        {
            if (!IsSelectable(mouseLocation))
                return null;

            if (StartHolder.IsHorizontal &&
                Math.Abs(linePoints[0].X - mouseLocation.X) <= iMarginSize &&
                Math.Abs(linePoints[0].Y - mouseLocation.Y) <= PrecisionSize
                ||
                StartHolder.IsVertical &&
                Math.Abs(linePoints[0].Y - mouseLocation.Y) <= iMarginSize &&
                Math.Abs(linePoints[0].X - mouseLocation.X) <= PrecisionSize)
            {
                return StartHolder;
            }

            if (EndHolder.IsHorizontal &&
                Math.Abs(linePoints[iConnectionPointCount - 1].X - mouseLocation.X) <= iMarginSize &&
                Math.Abs(linePoints[iConnectionPointCount - 1].Y - mouseLocation.Y) <= PrecisionSize
                ||
                EndHolder.IsVertical &&
                Math.Abs(linePoints[iConnectionPointCount - 1].Y - mouseLocation.Y) <= iMarginSize &&
                Math.Abs(linePoints[iConnectionPointCount - 1].X - mouseLocation.X) <= PrecisionSize)
            {
                return EndHolder;
            }

            return null;
        }

        #endregion


        #region <<< [ Events       ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 간선의 컨텐츠가 변경된 이벤트 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected virtual void OnContentsChanged(EventArgs e)
        {
            if (ContentsChanged != null)
                ContentsChanged(this, e);
        }

        /// <summary>
        /// 간선의 선택 상태가 변경된 이벤트 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected virtual void OnSelectionChanged(EventArgs e)
        {
            if (SelectionChanged != null)
                SelectionChanged(this, e);
        }

        /// <summary>
        /// 간선의 삭제에 대한 이벤트 입니다.
        /// </summary>
        /// <param name="e">EventArgs</param>
        protected virtual void OnElementDeleted(EventArgs e)
        {
            if (ElementDeleted != null)
                ElementDeleted(this, e);
        }

        #endregion        

        
        #region <<< [ Abstracts    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 사용자 정의 Connection을 내부적으로 적용해 주기 위해 생성자격으로 사용해 주는 함수입니다.
        /// </summary>
        /// <returns></returns>
        public abstract BaseConnection CreateNew();

        /// <summary>
        /// 사용자 정의 Connection을 내부적으로 적용해 주기 위해 생성자격으로 사용해 주는 함수입니다.
        /// </summary>
        /// <param name="startHolder"></param>
        /// <param name="endHolder"></param>
        /// <returns></returns>
        public abstract BaseConnection CreateNew(BaseHolder startHolder, BaseHolder endHolder);

        #endregion

    }
}
