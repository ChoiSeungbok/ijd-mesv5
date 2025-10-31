// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : BaseDiagramPanel.cs
// 파일 설명    : 다이어그램을 보여주거나 편집할 수 있는 컨테이너(Container) 컨트롤의 구현
// 최초 작성자  : 노현종(neoswirl@miracom.co.kr)
// 최초 작성일  : 2007년 5월27일 
// 최종 수정일  : 2007년 5월31일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 07 : [노현종] 최초 작성및 작성 완료
// 2007. 05. 31 : [노현종] 주석 작업 완료
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace Miracom.Common.DiagramModeler
{

    /// <summary>
    /// Grid를 그리기 위한 클래스 입니다.
    /// </summary>
    public class DiagramGrid : ICloneable
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 잡아 끌기에 대한 설정값
        /// </summary>
        bool snap = false;

        /// <summary>
        /// Grid의 스타일
        /// </summary>
        GridStyle gridStyle = GridStyle.DottedLines;

        /// <summary>
        /// Grid의 생상
        /// </summary>
        Color color;

        /// <summary>
        /// Grid의 Size
        /// </summary>
        Size size;

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Grid의 색상을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public Color Color
        {
            get { return color; }
            set { color = value; }
        }

        /// <summary>
        /// Grid의 Size를 설정하거나 가져요는 프로퍼티 입니다.
        /// </summary>
        public Size Size
        {
            get { return size; }
            set { size = value; }
        }

        /// <summary>
        /// Grid의 Snap을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public bool Snap
        {
            get { return snap; }
            set { snap = value; }
        }

        /// <summary>
        /// Grid의 Style을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public GridStyle Style
        {
            get { return gridStyle; }
            set { gridStyle = value; }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Grid를 생성합니다.
        /// </summary>
        public DiagramGrid()
        {
            this.Reset();
        }

        /// <summary>
        /// Grid를 생성합니다.
        /// </summary>
        /// <param name="snap">잡아끌기 여부</param>
        /// <param name="style">DiagramGrid Style</param>
        /// <param name="color">DiagramGrid 색상</param>
        /// <param name="size">DiagramGrid Size</param>
        public DiagramGrid(bool snap, GridStyle style, Color color, Size size)
        {
            if ((size.Width < 0) || (size.Height < 0))
            {
                throw new Exception("Width, Height Value Exception");
            }

            this.snap = snap;
            this.gridStyle = style;
            this.color = color;
            this.size = size;
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Grid를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="rectangle">Grid를 그려줄 영역의 크기</param>
        internal void DrawGrid(Graphics g, Rectangle rectangle)
        {
            if (DiagramSettings.UseDiagramGrid != true)
                return;

            if ((this.size.Width != 0) && (this.size.Height != 0))
            {
                System.Drawing.Size s = this.size;
                Pen pen = new Pen(this.color);
                float num = (rectangle.Left / s.Width) * s.Width;
                float num2 = (rectangle.Top / s.Height) * s.Height;
                float right = rectangle.Right;
                float bottom = rectangle.Bottom;
                switch (this.gridStyle)
                {
                    case GridStyle.Pixels:
                        pen.DashPattern = new float[] { 1f, (float)(s.Height - 1) };
                        for (float i = num; i <= right; i += s.Width)
                        {
                            g.DrawLine(pen, i, num2, i, bottom);
                        }
                        return;

                    case GridStyle.Lines:
                        pen.Width = 0f;
                        for (float j = num; j <= right; j += s.Width)
                        {
                            g.DrawLine(pen, j, num2, j, bottom);
                        }
                        for (float k = num2; k <= bottom; k += s.Height)
                        {
                            g.DrawLine(pen, num, k, right, k);
                        }
                        return;

                    case GridStyle.DottedLines:
                        pen.Width = 0f;
                        pen.DashStyle = DashStyle.Dot;
                        for (float m = num; m <= right; m += s.Width)
                        {
                            g.DrawLine(pen, m, num2, m, bottom);
                        }
                        for (float n = num2; n <= bottom; n += s.Height)
                        {
                            g.DrawLine(pen, num, n, right, n);
                        }
                        return;
                }
            }
        }

        /// <summary>
        /// DiagramGrid 설정을 초기화 합니다.
        /// </summary>
        internal void Reset()
        {
            this.snap = false;
            this.gridStyle = GridStyle.DottedLines;
            this.color = SystemColors.GrayText;
            this.size = new System.Drawing.Size(0x10, 0x10);
        }

        /// <summary>
        /// 복사하여 DiagramGrid Object를 만듭니다.
        /// </summary>
        /// <returns></returns>
        public object Clone()
        {
            return new DiagramGrid(this.snap, this.gridStyle, this.color, this.size);
        }

        /// <summary>
        /// 색상을 초기화 합니다.
        /// </summary>
        public void ResetColor()
        {
            this.color = SystemColors.GrayText;
        }

        /// <summary>
        /// 크기를 초기화 합니다.
        /// </summary>
        public void ResetSize()
        {
            this.size.Width = 0x10;
            this.size.Height = 0x10;
        }

        #endregion

    }
}
