// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : PreviewConnection.cs
// 파일 설명    : Base
// 최초 작성자  : 노현종(neoswirl@miracom.co.kr)
// 최초 작성일  : 2007년 5월14일 
// 최종 수정일  : 2007년 5월30일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 14 : [노현종] 최초 작성, 생성자
//       05. 30 : [노현종] 주석 변경 및 최종 작성
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 연결 미리보기에 사용되는 간선 클래스. ( BaseConnection의 상속 클래스 )
    /// </summary>
    internal class PreviewConnection : BaseConnection
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 시작점 선택여부
        /// </summary>
        bool bStartChosen = false;

        /// <summary>
        /// 끝점 선택여부
        /// </summary>
        bool bEndChosen = false;

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 시작점 선택여부를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public bool StartChosen
        {
            get { return bStartChosen; }
            set { bStartChosen = value; }
        }

        /// <summary>
        /// 끝점 선택여부를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public bool EndChosen
        {
            get { return bEndChosen; }
            set { bEndChosen = value; }
        }

        /// <summary>
        /// Connection이 다루고 있는 데이터의 Object를 가져오는 프로퍼티 입니다.
        /// </summary>
        public override object ContentObject
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        /// <summary>
        /// Connection이 다루고 있는 데이터의 Type을 가져오는 프로퍼티 입니다.
        /// </summary>
        public override Type ContentObjectType
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// PreviewConnection을 생성합니다.
        /// </summary>
        /// <param name="previewStartHolder">시작점 Holder</param>
        /// <param name="previewEndHolder">끝점 Holder</param>
        internal PreviewConnection(BaseHolder startHolder, BaseHolder endHolder)
        {
            if (startHolder == null)
                throw new ArgumentNullException("startHolder");
            if (endHolder == null)
                throw new ArgumentNullException("endHolder");

            this.startHolder = startHolder;
            this.endHolder = endHolder;

            this.ConnectionProperty = DiagramSettings.PreviewConnectionProperty;
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 시작점 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected override void DrawRelativeStartSign(Graphics g)
        {
            ConnectionArrowDrawings.LightBrush.Color = ConnectionProperty.LineColor;
            ConnectionArrowDrawings.SolidPen.Color = ConnectionProperty.LineColor;
            ConnectionArrowDrawings.Draw(g, ConnectionProperty.StartArrow);
        }

        /// <summary>
        /// 끝점 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected override void DrawRelativeEndSign(Graphics g)
        {
            ConnectionArrowDrawings.LightBrush.Color = ConnectionProperty.LineColor;
            ConnectionArrowDrawings.SolidPen.Color = ConnectionProperty.LineColor;
            ConnectionArrowDrawings.Draw(g, ConnectionProperty.StartArrow);
        }

        /// <summary>
        /// 시작점 화살표만을 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="mouseLocation">마우스 위치</param>
        public override void DrawOnlyStartSign(Graphics g, Point mouseLocation)
        {
            BaseHolder holder = StartHolder;

            if (holder != null)
            {
                Point position;
                int angle;

                if (StartHolder.IsHorizontal)
                {
                    if (mouseLocation.X < holder.Shape.Left + holder.Shape.Width / 2)
                    {
                        position = new Point(holder.Shape.Left - 1, StartHolder.AbsoluteLocation);
                        angle = 90;
                    }
                    else
                    {
                        position = new Point(holder.Shape.Right, StartHolder.AbsoluteLocation);
                        angle = 270;
                    }
                }
                else
                {
                    if (mouseLocation.Y < holder.Shape.Top + holder.Shape.Height / 2)
                    {
                        position = new Point(StartHolder.AbsoluteLocation, holder.Shape.Top - 1);
                        angle = 180;
                    }
                    else
                    {
                        position = new Point(StartHolder.AbsoluteLocation, holder.Shape.Bottom);
                        angle = 0;
                    }
                }
                g.ScaleTransform(DiagramSettings.Zoom, DiagramSettings.Zoom);
                g.TranslateTransform(position.X, position.Y);
                g.RotateTransform(angle);
                DrawRelativeStartSign(g);
                g.RotateTransform(-angle);
                g.TranslateTransform(-position.X, -position.Y);
                g.ResetTransform();
            }
        }

        public override BaseConnection CreateNew()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public override BaseConnection CreateNew(BaseHolder startHolder, BaseHolder endHolder)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        #endregion

    }
}
