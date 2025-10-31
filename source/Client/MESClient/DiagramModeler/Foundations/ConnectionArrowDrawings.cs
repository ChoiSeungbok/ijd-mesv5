// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : ConnectionArrowDrawings.cs
// 파일 설명    : 다이어그램을 구성하는 간선(edge)이 상속받아야 하는 클래스
// 최초 작성자  : 노현종(neoswirl@miracom.co.kr)
// 최초 작성일  : 2007년 5월20일
// 최종 수정일  : 2007년 5월31일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 20 : [노현종] Constructor, Properties, Event Implementation Region에 메소드 추가
// 2007. 05. 22 : [노현종] Draw 관련 메소드 추가, 프로퍼티 추가
// 2007. 05. 30 : [노현종] 주석 작업 완료
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 화살표를 그리는 클래스 입니다.
    /// </summary>
    public class ConnectionArrowDrawings : ICloneable
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 선그리기용 Pen
        /// </summary>
        static Pen linePen = new Pen(Color.Black);

        /// <summary>
        /// Solid Pen
        /// </summary>
        static Pen solidPen = new Pen(Color.Black);

        /// <summary>
        /// 흰색(밝은색) Brush
        /// </summary>
        static SolidBrush lightBrush = new SolidBrush(Color.White);

        /// <summary>
        /// 검은색(어두운색) Brush
        /// </summary>
        static SolidBrush darkBrush = new SolidBrush(Color.Black);
        
        /// <summary>
        /// 화살표의 Width
        /// </summary>
        static int arrowWidth = 10;

        /// <summary>
        /// 화살표의 Height
        /// </summary>
        static int arrowHeight = 15;

        /// <summary>
        /// Nesting 그리기에 원 그리기에서 사용되는 지름
        /// </summary>
        static int radius = 7;

        /// <summary>
        /// Nesting 그리기에서 사용되는 중앙에 십자표 크기
        /// </summary>
        static int crossSize = 6;

        /// <summary>
        /// 다이아몬드 그리기에 사용되는 좌표 배열
        /// </summary>
        static Point[] diamondPoints =  {
            new Point(0, 0),
            new Point(arrowWidth / 2, arrowHeight / 2),
            new Point(0, arrowHeight),
            new Point(-arrowWidth / 2, arrowHeight / 2)
        };
       
        /// <summary>
        /// 삼각형 그리기에 사용되는 좌표 배열
        /// </summary>
        static Point[] trianglePoints = {
            new Point(-arrowWidth / 2, arrowHeight),
            new Point(0, 0),
            new Point(arrowWidth / 2, arrowHeight)
        };

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Arrow의 가로
        /// </summary>
        public static int ArrowWidth
        {
            get { return arrowWidth;  }
            set 
            {
                if (value < 4)
                    arrowWidth = 4;
                else
                    arrowWidth = value;

                diamondPoints[1] = new Point(arrowWidth / 2, arrowHeight / 2);
                diamondPoints[3] = new Point(-arrowWidth / 2, arrowHeight / 2);
                trianglePoints[0] = new Point(-arrowWidth / 2, arrowHeight);
                trianglePoints[2] = new Point(arrowWidth / 2, arrowHeight);
            }
        }

        /// <summary>
        /// Arrow의 세로
        /// </summary>
        public static int ArrowHeight
        {
            get { return arrowHeight;  }
            set
            {
                if (value < 4)
                    arrowHeight = 4;
                else
                    arrowHeight = value;

                diamondPoints[1] = new Point(arrowWidth / 2, arrowHeight / 2);
                diamondPoints[3] = new Point(-arrowWidth / 2, arrowHeight / 2);
                trianglePoints[0] = new Point(-arrowWidth / 2, arrowHeight);
                trianglePoints[2] = new Point(arrowWidth / 2, arrowHeight);
            }

        }

        /// <summary>
        /// Nesting 표현시 사용되는 원의 지름
        /// </summary>
        public static int Radius
        {
            get { return radius; }
            set 
            {
                if (value < 4)
                    radius = 4;
                else                    
                    radius = value;

                crossSize = radius - 1;
            }
        }

        /// <summary>       
        /// 간선 Draw에 사용되는 Pen을 가져오는 프로퍼티 입니다.       
        /// </summary>       
        public static Pen LinePen
        {
            get { return linePen; }
        }
       
        /// <summary>       
        /// 간선 Draw에 사용되는 Pen을 가져오는 프로퍼티 입니다.
        /// </summary>       
        public static Pen SolidPen       
        {        
            get { return solidPen; }       
        }
       
        /// <summary>       
        /// 간선 Draw에 사용되는 Brush를 가져오는 프로퍼티 입니다.       
        /// </summary>       
        public static SolidBrush LightBrush
        {           
            get { return lightBrush; }       
        }
       
        /// <summary>       
        /// 간선 Draw에 사용되는 Brush를 가져오는 프로퍼티 입니다.       
        /// </summary>       
        public static SolidBrush DarkBrush       
        {           
            get { return darkBrush; }       
        }
       
        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// ArrowDrawings를 생성합니다.
        /// </summary>
        public ConnectionArrowDrawings()
        {
        }

        #endregion

        
        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 지정한 스타일의 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        /// <param name="style">그릴 화살표</param>
        public static void Draw(Graphics g, ArrowStyle style)
        {
            switch (style)
            {
                case ArrowStyle.Aggregation:
                    DrawAggregation(g);
                    break;
                case ArrowStyle.Composition:
                    DrawComposition(g);
                    break;
                case ArrowStyle.Dependency:
                    DrawDependency(g);
                    break;
                case ArrowStyle.Generalization:
                    DrawGeneralization(g);
                    break;
                case ArrowStyle.Nesting:
                    DrawNesting(g);
                    break;
                case ArrowStyle.Realization:
                    DrawRealization(g);
                    break;
            }
        }

        /// <summary>
        /// UML의 Aggregation관계를 나타내는 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        public static void DrawAggregation(Graphics g)
        {
            g.FillPolygon(LightBrush, diamondPoints);            
            g.DrawPolygon(SolidPen, diamondPoints);
        }

        /// <summary>
        /// UML의 Compostion관계를 나타내는 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        public static void DrawComposition(Graphics g)
        {
            g.FillPolygon(DarkBrush, diamondPoints);
        }

        /// <summary>
        /// UML의 Dependency관계를 나타내는 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        public static void DrawDependency(Graphics g)
        {
            g.DrawLine(SolidPen, arrowWidth / 2, arrowHeight, 0, 0);
            g.DrawLine(SolidPen, -arrowWidth / 2, arrowHeight, 0, 0);
        }

        /// <summary>
        /// UML의 Generalization관계를 나타내는 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        public static void DrawGeneralization(Graphics g)
        {
            g.FillPolygon(LightBrush, trianglePoints);
            g.DrawPolygon(SolidPen, trianglePoints);
        }

        /// <summary>
        /// UML의 Nesting관계를 나타내는 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        public static void DrawNesting(Graphics g)
        {
            g.FillEllipse(LightBrush, -radius, 0, radius * 2, radius * 2);
            g.DrawEllipse(SolidPen, -radius, 0, radius * 2, radius * 2);
            g.DrawLine(SolidPen, 0, radius - crossSize / 2, 0, radius + crossSize / 2);
            g.DrawLine(SolidPen, -crossSize / 2, radius, crossSize / 2, radius);
        }

        /// <summary>
        /// UML의 Realization관계를 나타내는 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        public static void DrawRealization(Graphics g)
        {
            g.FillPolygon(LightBrush, trianglePoints);
            g.DrawPolygon(SolidPen, trianglePoints);
        }

        /// <summary>
        /// 새 Object로 복사합니다.
        /// </summary>
        /// <returns>복사한 Object</returns>
        public object Clone()
        {
            return new ConnectionArrowDrawings();
        }

        #endregion

    }
}
