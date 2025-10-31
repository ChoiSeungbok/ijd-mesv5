// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : ShapeDrawings.cs
// 파일 설명    : 노드(Node)가 표현할 도형을 GraphicsPath에 정의하여 Return합니다.
// 최초 작성자  : 노현종(neoswirl@miracom.co.kr)
// 최초 작성일  : 2007년 5월 10일
// 최종 수정일  : 2007년 5월 31일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 10 : [노현종] 최초 작성, 생성자 추가, 기본 도형 Method 추가
// 2007. 05. 23 : Shape에서 ShapeDrawings로 클래스 이름 변경
// 2007. 05. 31 : 불필요 변수 및 Method 정리. 주석 작업 완료
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
using System.Xml.Schema;
using System.Drawing.Drawing2D;
using System.Drawing;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 노드(Node)가 표현할 도형을 그려 GraphicsPath로 정의하여 Return하는 클래스 .
    /// </summary>
    public class ShapeDrawings
    {

        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Shape 클래스의 기본 생성자 .
        /// </summary>
        public ShapeDrawings()
        {
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 지정된 스타일에 해당되는 Shape의 GraphicsPath를 생성합니다.
        /// </summary>
        /// <param name="shapeStyle">생성하고자 하는 ShapeStyle </param>
        /// <param name="rectangleF">생성하고자 하는 영역 RectangleF</param>
        /// <returns>지정된 Shape의 GraphicsPath </returns>
        public static GraphicsPath GeneratePath(ShapeStyle shapeStyle, RectangleF rectangleF)
        {
            GraphicsPath path = new GraphicsPath();
            switch (shapeStyle)
            {
                case ShapeStyle.CogWheel:
                    {
                        CogWheel(path, rectangleF);
                        break;
                    }
                case ShapeStyle.Pentagon:
                    {
                        Pentagon(path, rectangleF);
                        break;
                    }
                case ShapeStyle.Cross:
                    {
                        Cross(path, rectangleF);
                        break;
                    }
                case ShapeStyle.Rectangle:
                    {
                        path.AddRectangle(rectangleF);
                        break;
                    }
                //case ShapeStyle.AlternateProcess:
                case ShapeStyle.RoundRect:
                    {
                        RoundRect(path,rectangleF, new SizeF(rectangleF.Width / 2, rectangleF.Height / 2));
                        break;
                    }
                case ShapeStyle.Ellipse:
                    {
                        path.AddEllipse(rectangleF);
                        break;
                    }
                //case ShapeStyle.Or:
                case ShapeStyle.SummingJunction:
                    {
                        SummingJunction(path, rectangleF, shapeStyle);
                        break;
                    }
                case ShapeStyle.Delay:
                    {
                        Delay(path, rectangleF);
                        break;
                    }
                case ShapeStyle.Display:
                    {
                        Display(path, rectangleF);
                        break;
                    }
                case ShapeStyle.Document:
                    {
                        Document(path, rectangleF);
                        break;
                    }
                case ShapeStyle.Hexagon:
                    {
                        Hexagon(path, rectangleF);
                        break;
                    }
                case ShapeStyle.MagneticDisk:
                    {
                        if (rectangleF.Width > 0f)
                        {
                            if (rectangleF.Height <= 0f)
                            {
                                return path;
                            }
                            path.FillMode = FillMode.Winding;
                            path.AddLine(rectangleF.Right, rectangleF.Top + (rectangleF.Height / 8f), rectangleF.Right, rectangleF.Bottom - (rectangleF.Height / 4f));
                            path.AddArc(rectangleF.Left, rectangleF.Bottom - (rectangleF.Height / 4f), rectangleF.Width, rectangleF.Height / 4f, 0f, 180f);
                            path.AddLine(rectangleF.Left, rectangleF.Bottom - (rectangleF.Height / 4f), rectangleF.Left, rectangleF.Top + (rectangleF.Height / 8f));
                            path.AddArc(rectangleF.Left, rectangleF.Top, rectangleF.Width, rectangleF.Height / 4f, 180f, 180f);
                            path.AddArc(rectangleF.Left, rectangleF.Top, rectangleF.Width, rectangleF.Height / 4f, 0f, 180f);
                        }
                        break;
                    }
                case ShapeStyle.Merge:
                    {
                        path.AddLine(rectangleF.Left, rectangleF.Top, rectangleF.Right, rectangleF.Top);
                        path.AddLine(rectangleF.Right, rectangleF.Top, rectangleF.Left + (rectangleF.Width / 2f), rectangleF.Bottom);
                        path.CloseFigure();
                        break;
                    }
                case ShapeStyle.MultiDocument:
                    {
                        MultiDocument(path, rectangleF);
                        break;
                    }
                case ShapeStyle.OrGate:
                    {
                        OrGate(path, rectangleF);
                        break;
                    }
                case ShapeStyle.PunchedTape:
                    {
                        PunchedTape(path, rectangleF);
                        break;
                    }
                case ShapeStyle.StoredData:
                    {
                        if (rectangleF.Width > 0f)
                        {
                            if (rectangleF.Height <= 0f)
                            {
                                break;
                            }
                            path.AddLine(rectangleF.Left, rectangleF.Top, rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Top);
                            path.AddArc(rectangleF.Right - (rectangleF.Width / 2f), rectangleF.Top, rectangleF.Width / 2f, rectangleF.Height, 270f, 180f);
                            path.AddLine(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Bottom, rectangleF.Left, rectangleF.Bottom);
                            path.AddArc(rectangleF.Left - (rectangleF.Width / 4f), rectangleF.Top, rectangleF.Width / 2f, rectangleF.Height, 90f, -180f);
                        }
                        break;
                    }
                case ShapeStyle.Termination:
                    {
                        if (rectangleF.Width > 0f)
                        {
                            if (rectangleF.Height <= 0f)
                            {
                                break;
                            }
                            path.AddArc(rectangleF.Left + (rectangleF.Width / 2f), rectangleF.Top, rectangleF.Width / 2f, rectangleF.Height, -90f, 180f);
                            path.AddArc(rectangleF.Left, rectangleF.Top, rectangleF.Width / 2f, rectangleF.Height, 90f, 180f);
                            path.CloseFigure();
                        }
                        break;
                    }
                case ShapeStyle.Transport:
                    {
                        Transport(path, rectangleF);
                        break;
                    }
                //case ShapeStyle.TriangleRectangle:
                //   break;
                default:
                    RoundRect(path, rectangleF, new SizeF(rectangleF.Width / 2, rectangleF.Height / 2));
                    break;
                    
            }
            // 컴파일 에러를 막아놓기 위한 임시 코드
            return path;
        }

        /// <summary>
        /// 지정한 스타일에 해당되는 Shape를 구성하는 PointF의 Array를 생성합니다.
        /// </summary>
        /// <param name="shapeStyle">생성하고자 하는 ShapeStyle </param>
        /// <param name="rectangleF">생성하고자 하는 Shape가 그려질 영역 Rectangle </param>
        /// <returns>생성한 Shape의 PointF Array</returns>
        private static PointF[] GenerateShapePointArray(ShapeStyle shapeStyle, RectangleF rectangleF)
        {
            float num;
            float num2;
            float num4;
            PointF[] tfArray;
            int num5;
            ShapeStyle style = shapeStyle;
            if (style > ShapeStyle.ProcessIso9000)
            {
                if (style == ShapeStyle.SequentialAccessStorage)
                {
                    tfArray = new PointF[0x18];
                    num4 = 0.01745333f;
                    num = -45f;
                    for (int i = 0; i < 0x16; i++)
                    {
                        num2 = num * num4;
                        tfArray[i].X = (rectangleF.Left + (rectangleF.Width / 2f)) + ((rectangleF.Width / 2f) * ((float)Math.Cos((double)num2)));
                        tfArray[i].Y = (rectangleF.Top + (rectangleF.Height / 2f)) - ((rectangleF.Height / 2f) * ((float)Math.Sin((double)num2)));
                        num += 15f;
                    }
                    tfArray[0x16].X = rectangleF.Left + rectangleF.Width;
                    tfArray[0x16].Y = tfArray[0x15].Y;
                    tfArray[0x17].X = rectangleF.Left + rectangleF.Width;
                    tfArray[0x17].Y = tfArray[0].Y;
                    return tfArray;
                }
                if (style != ShapeStyle.Sort)
                {
                    goto Label_048F;
                }
                goto Label_04D4;
            }
            switch (style)
            {
                case ShapeStyle.Card:
                    tfArray = new PointF[5];
                    tfArray[0].X = rectangleF.Left + (rectangleF.Width / 6f);
                    tfArray[0].Y = rectangleF.Top;
                    tfArray[1].X = rectangleF.Left + rectangleF.Width;
                    tfArray[1].Y = rectangleF.Top;
                    tfArray[2].X = rectangleF.Left + rectangleF.Width;
                    tfArray[2].Y = rectangleF.Top + rectangleF.Height;
                    tfArray[3].X = rectangleF.Left;
                    tfArray[3].Y = rectangleF.Top + rectangleF.Height;
                    tfArray[4].X = rectangleF.Left;
                    tfArray[4].Y = rectangleF.Top + (rectangleF.Height / 6f);
                    return tfArray;

                case ShapeStyle.Collate:
                    tfArray = new PointF[5];
                    tfArray[0].X = rectangleF.Left;
                    tfArray[0].Y = rectangleF.Top;
                    tfArray[1].X = rectangleF.Left + rectangleF.Width;
                    tfArray[1].Y = rectangleF.Top;
                    tfArray[2].X = rectangleF.Left;
                    tfArray[2].Y = rectangleF.Top + rectangleF.Height;
                    tfArray[3].X = rectangleF.Left + rectangleF.Width;
                    tfArray[3].Y = rectangleF.Top + rectangleF.Height;
                    tfArray[4].X = rectangleF.Left;
                    tfArray[4].Y = rectangleF.Top;
                    return tfArray;

                case ShapeStyle.Connector:
                case ShapeStyle.Custom:
                    goto Label_048F;

                case ShapeStyle.Data:
                    tfArray = new PointF[4];
                    tfArray[0].X = rectangleF.Left + (rectangleF.Width / 4f);
                    tfArray[0].Y = rectangleF.Top;
                    tfArray[1].X = rectangleF.Left + rectangleF.Width;
                    tfArray[1].Y = rectangleF.Top;
                    tfArray[2].X = (rectangleF.Left + rectangleF.Width) - (rectangleF.Width / 4f);
                    tfArray[2].Y = rectangleF.Top + rectangleF.Height;
                    tfArray[3].X = rectangleF.Left;
                    tfArray[3].Y = rectangleF.Top + rectangleF.Height;
                    return tfArray;

                case ShapeStyle.Decision:
                    goto Label_04D4;

                default:
                    switch (style)
                    {
                        case ShapeStyle.Hexagon:
                        case ShapeStyle.Losange:
                        case ShapeStyle.Octogon:
                        case ShapeStyle.Pentagon:
                        case ShapeStyle.Preparation:
                            goto Label_04D4;

                        case ShapeStyle.InternalStorage:
                        case ShapeStyle.MagneticDisk:
                        case ShapeStyle.Merge:
                        case ShapeStyle.MultiDocument:
                        case ShapeStyle.Or:
                        case ShapeStyle.OrGate:
                        case ShapeStyle.PredefinedProcess:
                        case ShapeStyle.Process:
                            goto Label_048F;

                        case ShapeStyle.ManualInput:
                            tfArray = new PointF[4];
                            tfArray[0].X = rectangleF.Left;
                            tfArray[0].Y = rectangleF.Top + (rectangleF.Height / 5f);
                            tfArray[1].X = rectangleF.Left + rectangleF.Width;
                            tfArray[1].Y = rectangleF.Top;
                            tfArray[2].X = rectangleF.Left + rectangleF.Width;
                            tfArray[2].Y = rectangleF.Top + rectangleF.Height;
                            tfArray[3].X = rectangleF.Left;
                            tfArray[3].Y = rectangleF.Top + rectangleF.Height;
                            return tfArray;

                        case ShapeStyle.ManualOperation:
                            tfArray = new PointF[4];
                            tfArray[0].X = rectangleF.Left;
                            tfArray[0].Y = rectangleF.Top;
                            tfArray[1].X = rectangleF.Left + rectangleF.Width;
                            tfArray[1].Y = rectangleF.Top + (rectangleF.Height / 5f);
                            tfArray[2].X = rectangleF.Left + rectangleF.Width;
                            tfArray[2].Y = (rectangleF.Top + rectangleF.Height) - (rectangleF.Height / 5f);
                            tfArray[3].X = rectangleF.Left;
                            tfArray[3].Y = rectangleF.Top + rectangleF.Height;
                            return tfArray;

                        case ShapeStyle.OffPageConnection:
                            tfArray = new PointF[5];
                            tfArray[0].X = rectangleF.Left + rectangleF.Width;
                            tfArray[0].Y = rectangleF.Top + (rectangleF.Height / 2f);
                            tfArray[1].X = rectangleF.Left + (rectangleF.Width / 2f);
                            tfArray[1].Y = rectangleF.Top + rectangleF.Height;
                            tfArray[2].X = rectangleF.Left;
                            tfArray[2].Y = rectangleF.Top + rectangleF.Height;
                            tfArray[3].X = rectangleF.Left;
                            tfArray[3].Y = rectangleF.Top;
                            tfArray[4].X = rectangleF.Left + (rectangleF.Width / 2f);
                            tfArray[4].Y = rectangleF.Top;
                            return tfArray;

                        case ShapeStyle.ProcessIso9000:
                            tfArray = new PointF[6];
                            tfArray[0].X = rectangleF.Left + rectangleF.Width;
                            tfArray[0].Y = rectangleF.Top + (rectangleF.Height / 2f);
                            tfArray[1].X = (rectangleF.Left + rectangleF.Width) - (rectangleF.Width / 4f);
                            tfArray[1].Y = rectangleF.Top + rectangleF.Height;
                            tfArray[2].X = rectangleF.Left;
                            tfArray[2].Y = rectangleF.Top + rectangleF.Height;
                            tfArray[3].X = rectangleF.Left + (rectangleF.Width / 4f);
                            tfArray[3].Y = rectangleF.Top + (rectangleF.Height / 2f);
                            tfArray[4].X = rectangleF.Left;
                            tfArray[4].Y = rectangleF.Top;
                            tfArray[5].X = (rectangleF.Left + rectangleF.Width) - (rectangleF.Width / 4f);
                            tfArray[5].Y = rectangleF.Top;
                            return tfArray;
                    }
                    goto Label_048F;
            }
        Label_03FC:
            num4 = 0.01745333f;
            float num3 = 360 / num5;
            for (int j = 0; j < num5; j++)
            {
                num2 = num * num4;
                tfArray[j].X = (rectangleF.Left + (rectangleF.Width / 2f)) + ((rectangleF.Width / 2f) * ((float)Math.Sin((double)num2)));
                tfArray[j].Y = (rectangleF.Top + (rectangleF.Height / 2f)) + ((rectangleF.Height / 2f) * ((float)Math.Cos((double)num2)));
                num += num3;
            }
            return tfArray;
        Label_048F:
            return null;
        Label_04D4:
            num = 0f;
            num5 = 0;
            ShapeStyle style2 = shapeStyle;
            if (style2 > ShapeStyle.Losange)
            {
                switch (style2)
                {
                    case ShapeStyle.Pentagon:
                        num5 = 5;
                        tfArray = new PointF[num5];
                        num = 90f;
                        goto Label_03FC;

                    case ShapeStyle.PredefinedProcess:
                        goto Label_0963;

                    case ShapeStyle.Preparation:
                        goto Label_0725;

                    case ShapeStyle.Octogon:
                        num5 = 8;
                        tfArray = new PointF[num5];
                        goto Label_03FC;
                }
                if (style2 != ShapeStyle.Sort)
                {
                    goto Label_0963;
                }
            }
            else if (style2 != ShapeStyle.Decision)
            {
                switch (style2)
                {
                    case ShapeStyle.Hexagon:
                        goto Label_0725;

                    case ShapeStyle.InternalStorage:
                        goto Label_0963;

                    case ShapeStyle.Losange:
                        goto Label_0714;

                    default:
                        goto Label_0963;
                }
            }
        Label_0714:
            num5 = 4;
            tfArray = new PointF[num5];
            goto Label_03FC;
        Label_0725:
            num5 = 6;
            tfArray = new PointF[num5];
            num = 90f;
            goto Label_03FC;
        Label_0963:
            num5 = 0;
            tfArray = null;
            goto Label_03FC;
        }

        #region Shapes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


        private static RectangleF GetRectangleF(PointF p1, PointF p2)
        {
            PointF tempP1 = p1, tempP2 = p2;

            if (p1.X > p2.X)
            {
                tempP1.X = p2.X;
                tempP2.X = p1.X;
            }

            if (p1.Y > p2.Y)
            {
                tempP1.Y = p2.Y;
                tempP2.Y = p1.Y;
            }

            return new RectangleF(tempP1, new SizeF(tempP2.X - tempP1.X, tempP2.Y - tempP1.Y));
            
        }

        private static void CogWheel(GraphicsPath path, RectangleF rectangeF)
        {
            PointF p1       = new PointF(rectangeF.Left + rectangeF.Width * (5f / 13f), rectangeF.Top + rectangeF.Height / 8f);
            PointF p2       = new PointF(rectangeF.Left + rectangeF.Width * (5f / 13f), rectangeF.Top);
            PointF p3       = new PointF(rectangeF.Left + rectangeF.Width * (8f / 13f), rectangeF.Top);
            PointF p4       = new PointF(rectangeF.Left + rectangeF.Width * (8f / 13f), rectangeF.Top + rectangeF.Height / 8f);
            PointF center   = new PointF(rectangeF.Left + rectangeF.Width / 2f, rectangeF.Top + rectangeF.Height / 2f);

            path.AddLine(p1, p2);
            path.AddLine(p2, p3);
            path.AddLine(p3, p4);

            p1 = RotatePoint(p1, center, -45);
            path.AddLine(p4, p1);
            
            p2 = RotatePoint(p2, center, -45);
            p3 = RotatePoint(p3, center, -45);
            p4 = RotatePoint(p4, center, -45);
            path.AddLine(p1, p2);
            path.AddLine(p2, p3);
            path.AddLine(p3, p4);

            p1 = RotatePoint(p1, center, -45);
            path.AddLine(p4, p1);

            p2 = RotatePoint(p2, center, -45);
            p3 = RotatePoint(p3, center, -45);
            p4 = RotatePoint(p4, center, -45);
            path.AddLine(p1, p2);
            path.AddLine(p2, p3);
            path.AddLine(p3, p4);

            p1 = RotatePoint(p1, center, -45);
            path.AddLine(p4, p1);

            p2 = RotatePoint(p2, center, -45);
            p3 = RotatePoint(p3, center, -45);
            p4 = RotatePoint(p4, center, -45);
            path.AddLine(p1, p2);
            path.AddLine(p2, p3);
            path.AddLine(p3, p4);

            p1 = RotatePoint(p1, center, -45);
            path.AddLine(p4, p1);

            p2 = RotatePoint(p2, center, -45);
            p3 = RotatePoint(p3, center, -45);
            p4 = RotatePoint(p4, center, -45);
            path.AddLine(p1, p2);
            path.AddLine(p2, p3);
            path.AddLine(p3, p4);

            p1 = RotatePoint(p1, center, -45);
            path.AddLine(p4, p1);

            p2 = RotatePoint(p2, center, -45);
            p3 = RotatePoint(p3, center, -45);
            p4 = RotatePoint(p4, center, -45);
            path.AddLine(p1, p2);
            path.AddLine(p2, p3);
            path.AddLine(p3, p4);

            p1 = RotatePoint(p1, center, -45);
            path.AddLine(p4, p1);

            p2 = RotatePoint(p2, center, -45);
            p3 = RotatePoint(p3, center, -45);
            p4 = RotatePoint(p4, center, -45);
            path.AddLine(p1, p2);
            path.AddLine(p2, p3);
            path.AddLine(p3, p4);

            p1 = RotatePoint(p1, center, -45);
            path.AddLine(p4, p1);

            p2 = RotatePoint(p2, center, -45);
            p3 = RotatePoint(p3, center, -45);
            p4 = RotatePoint(p4, center, -45);
            path.AddLine(p1, p2);
            path.AddLine(p2, p3);
            path.AddLine(p3, p4);

            p1 = RotatePoint(p1, center, -45);
            path.AddLine(p4, p1);

        }

        private static void Hexagon0(GraphicsPath path, RectangleF rectangleF)
        {
            if (rectangleF.Width > 0f)
            {
                if (rectangleF.Height <= 0f)
                {
                    return;
                }

                //float x = rectangleF.Width - ( Math.Sqrt(3f) * rectangleF.Height)


            }
        }

        private static void Pentagon(GraphicsPath path, RectangleF rectangleF)
        {
            if (rectangleF.Width > 0f)
            {
                if (rectangleF.Height <= 0f)
                {
                    return;
                }

                if (rectangleF.Width == rectangleF.Height)
                {
                    PointF edge = new PointF(rectangleF.Left + rectangleF.Width / 2.0f, rectangleF.Top);
                    PointF center = new PointF(rectangleF.Left + rectangleF.Width / 2.0f, rectangleF.Top + rectangleF.Height / 2.0f);

                    for (int i = 1; i < 6; i++)
                    {
                        PointF temp = RotatePoint(edge, center, 72);
                        path.AddLine(edge, temp);
                        edge = temp;
                    }
                }
                else
                {
                    path.AddLine(rectangleF.Left + rectangleF.Width / 2.0f, rectangleF.Top, rectangleF.Right, rectangleF.Top + rectangleF.Height / 3f);
                    path.AddLine(rectangleF.Right, rectangleF.Top + rectangleF.Height / 3f, rectangleF.Right - rectangleF.Width / 3f, rectangleF.Bottom);
                    path.AddLine(rectangleF.Right - rectangleF.Width / 3f, rectangleF.Bottom, rectangleF.Left + rectangleF.Width / 3f, rectangleF.Bottom);
                    path.AddLine(rectangleF.Left + rectangleF.Width / 3f, rectangleF.Bottom, rectangleF.Left, rectangleF.Top + rectangleF.Height / 3f);
                    path.AddLine(rectangleF.Left, rectangleF.Top + rectangleF.Height / 3f, rectangleF.Left + rectangleF.Width / 2.0f, rectangleF.Top);
                }
            }
        }

        private static PointF RotatePoint(PointF ptOrg, PointF ptCenter, int angle)
        {
            float r = (float)(Math.PI * angle) / 180f;
            float x = ptOrg.X - ptCenter.X, y = ptOrg.Y - ptCenter.Y;
            return new PointF((float)(y * Math.Sin(r) + x * Math.Cos(r)) + ptCenter.X, (float)(y * Math.Cos(r) - x * Math.Sin(r)) + ptCenter.Y);
        }

        public static Point Rotate(PointF poBegin, PointF poEnd, float angle)
        {
            float fDx, fDy, fSlope, fAngle, fSinAngle;
            float iAddAngle;
            float RAD = 0.017453293f;

            fDx = poEnd.X - poBegin.X;
            fDy = poEnd.Y - poBegin.Y;

            if (fDx == 0) 
                fSlope = 0;
            else 
                fSlope = fDy / fDx;    //기울기를 구한다.

            fAngle = (float)Math.Atan(fSlope) / (float)(180 / Math.PI);        //기울기에서 실제적인 각도를 계산해 낸다.

            iAddAngle = 0;                    //4분 영역에서 각도를 추가하여 완전하게 한다.
            if (poBegin.X >= poEnd.X && poBegin.Y < poEnd.Y) 
                iAddAngle = 90;
            if (poBegin.X > poEnd.X && poBegin.Y >= poEnd.Y) 
                iAddAngle = 180;
            if (poBegin.X <= poEnd.X && poBegin.Y > poEnd.Y) 
                iAddAngle = 270;

            if (fAngle >= 0) 
                fSinAngle = iAddAngle + fAngle;
            else 
                fSinAngle = iAddAngle + (90 + fAngle);  //dAngledl  -값이면 90도를 더해주어 보정한다.

            float wAngle = fSinAngle + angle;
            wAngle %= 360;

            float iDx, iDy, iLen;
            iDx = fDx;
            iDy = fDy;

            iLen = (float)Math.Sqrt((iDx * iDx) + (iDy * iDy));

            Point pRet = new Point();
            pRet.X = (int)(poBegin.X + (iLen * (float)Math.Cos(RAD * wAngle)));
            pRet.Y = (int)(poBegin.Y + (iLen * (float)Math.Sin(RAD * wAngle)));

            return pRet;
        }

        /// <summary>
        ///  Rectangle을 PointF로 변경
        /// </summary>
        /// <param name="rectangleF">변겨할 RectangleF</param>
        /// <returns>변경된 PointF</returns>
        private static PointF Shift(RectangleF rectangleF)
        {
            return new PointF(rectangleF.Left + (rectangleF.Width / 2f), rectangleF.Top + (rectangleF.Height / 2f));
        }

        /// <summary>
        /// Display를 상징하는 형태의 GraphicsPath를 저장합니다.
        /// </summary>
        /// <param name="path">Shape를 저장할 GraphicsPath</param>
        /// <param name="rectangleF">생성하고자 하는 Shape의 영역 Rectangle</param>
        private static void Display(GraphicsPath path, RectangleF rectangleF)
        {
            if (rectangleF.Width > 0f)
            {
                if (rectangleF.Height <= 0f)
                {
                    return;
                }
                path.AddLine(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Bottom, rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Bottom);
                path.AddLine(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Bottom, rectangleF.Left, rectangleF.Top + (rectangleF.Height / 2f));
                path.AddLine(rectangleF.Left, rectangleF.Top + (rectangleF.Height / 2f), rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Top);
                path.AddLine(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Top, rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Top);
                path.AddArc(rectangleF.Right - (rectangleF.Width / 2f), rectangleF.Top, rectangleF.Width / 2f, rectangleF.Height, 270f, 180f);
            }
        }

        /// <summary>
        /// Display를 상징하는 형태의 GraphicsPath를 저장합니다.
        /// </summary>
        /// <param name="path">Shape를 저장할 GraphicsPath</param>
        /// <param name="rectangleF">생성하고자 하는 Shape의 영역 Rectangle</param>
        private static void Hexagon(GraphicsPath path, RectangleF rectangleF)
        {
            if (rectangleF.Width > 0f)
            {
                if (rectangleF.Height <= 0f)
                {
                    return;
                }

                if (rectangleF.Width == rectangleF.Height)
                {
                    PointF edge = new PointF(rectangleF.Left, rectangleF.Top + rectangleF.Height / 2.0f);
                    PointF center = new PointF(rectangleF.Left + rectangleF.Width / 2.0f, rectangleF.Top + rectangleF.Height / 2.0f);

                    for (int i = 0; i < 6; i++)
                    {
                        PointF temp = RotatePoint(edge, center, 60);
                        path.AddLine(edge, temp);
                        edge = temp;
                    }
                }
                else
                {
                    float x = rectangleF.Width / 4f;
                    float y = rectangleF.Height / 2f;

                    path.AddLine(rectangleF.Right - x, rectangleF.Bottom, rectangleF.Left + x, rectangleF.Bottom);
                    path.AddLine(rectangleF.Left + x, rectangleF.Bottom, rectangleF.Left, rectangleF.Top + y);
                    path.AddLine(rectangleF.Left, rectangleF.Top + y, rectangleF.Left + x, rectangleF.Top);
                    path.AddLine(rectangleF.Left + x, rectangleF.Top, rectangleF.Right - x, rectangleF.Top);
                    path.AddLine(rectangleF.Right - x, rectangleF.Top, rectangleF.Right, rectangleF.Top + y);
                    path.AddLine(rectangleF.Right, rectangleF.Top + y, rectangleF.Right - x, rectangleF.Bottom);
                }
            }
        }

        private static void Cross(GraphicsPath path, RectangleF rectangleF)
        {
            if (rectangleF.Width > 0f)
            {
                if (rectangleF.Height <= 0f)
                {
                    return;
                }
                path.AddLine(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Bottom, rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Bottom);
                path.AddLine(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Bottom, rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Bottom - (rectangleF.Height / 4f));
                path.AddLine(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Bottom - (rectangleF.Height / 4f), rectangleF.Left, rectangleF.Bottom - (rectangleF.Height / 4f));
                path.AddLine(rectangleF.Left, rectangleF.Bottom - (rectangleF.Height / 4f), rectangleF.Left, rectangleF.Top + (rectangleF.Height / 4f));
                path.AddLine(rectangleF.Left, rectangleF.Top + (rectangleF.Height / 4f), rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Top + (rectangleF.Height / 4f));
                path.AddLine(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Top + (rectangleF.Height / 4f), rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Top);
                path.AddLine(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Top, rectangleF.Right - ( rectangleF.Width / 4f ), rectangleF.Top);
                path.AddLine(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Top, rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Top + (rectangleF.Height / 4f));
                path.AddLine(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Top + (rectangleF.Height / 4f), rectangleF.Right, rectangleF.Top + (rectangleF.Height / 4f));
                path.AddLine(rectangleF.Right, rectangleF.Top + (rectangleF.Height / 4f), rectangleF.Right, rectangleF.Bottom - (rectangleF.Height / 4f));
                path.AddLine(rectangleF.Right, rectangleF.Bottom - (rectangleF.Height / 4f), rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Bottom - (rectangleF.Height / 4f));
                path.AddLine(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Bottom - (rectangleF.Height / 4f), rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Bottom);
            }
        }

        /// <summary>
        /// Delay를 상징하는 형태의 GraphicsPath에 저장합니다.
        /// </summary>
        /// <param name="graphicsPath">Shape를 저장할 GraphicsPath </param>
        /// <param name="rectangleF">생성하고자 하는Shape의 영역 Rectangle </param>
        private static void Delay(GraphicsPath graphicsPath, RectangleF rectangleF)
        {
            if ((rectangleF.Width > 0f) && (rectangleF.Height > 0f))
            {
                graphicsPath.AddLine(rectangleF.Left + (rectangleF.Width / 2f), rectangleF.Bottom, rectangleF.Left, rectangleF.Bottom);
                graphicsPath.AddLine(rectangleF.Left, rectangleF.Bottom, rectangleF.Left, rectangleF.Top);
                graphicsPath.AddLine(rectangleF.Left, rectangleF.Top, rectangleF.Left + (rectangleF.Width / 2f), rectangleF.Top);
                graphicsPath.AddArc(rectangleF.Left, rectangleF.Top, rectangleF.Width, rectangleF.Height, 270f, 180f);
            }
        }

        /// <summary>
        /// 문서(Document)상징하는 형태의 GraphicsPath에 저장합니다.
        /// </summary>
        /// <param name="graphicsPath">Shape를 저장할 GraphicsPath </param>
        /// <param name="rectangleF">생성하고자 하는Shape의 영역 Rectangle </param>
        private static void Document(GraphicsPath graphicsPath, RectangleF rectangleF)
        {
            graphicsPath.AddLine(rectangleF.Left, rectangleF.Bottom - (rectangleF.Height / 16f), rectangleF.Left, rectangleF.Top);
            graphicsPath.AddLine(rectangleF.Left, rectangleF.Top, rectangleF.Right, rectangleF.Top);
            graphicsPath.AddLine(rectangleF.Right, rectangleF.Top, rectangleF.Right, rectangleF.Bottom - (rectangleF.Height / 16f));
            PointF pointF1 = new PointF(rectangleF.Right, rectangleF.Bottom - (rectangleF.Height / 16f));
            PointF pointF2 = new PointF(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Bottom - (rectangleF.Height / 4f));
            PointF pointF3 = new PointF(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Bottom + (rectangleF.Height / 8f));
            PointF pointF4 = new PointF(rectangleF.Left, rectangleF.Bottom - (rectangleF.Height / 16f));
            graphicsPath.AddBezier(pointF1, pointF2, pointF3, pointF4);
            graphicsPath.CloseFigure();
        }

        /// <summary>
        /// 다중문서(MultiDocument)를 상징하는 형태의 GraphicsPath에 저장합니다.
        /// </summary>
        /// <param name="graphicsPath">Shape를 저장할 GraphicsPath </param>
        /// <param name="rectangleF">생성하고자 하는Shape의 영역 Rectangle </param>
        private static void MultiDocument(GraphicsPath graphicsPath, RectangleF rectangleF)
        {
            PointF[] sourceArray = new PointF[15];
            sourceArray[0].X = rectangleF.Left;
            sourceArray[0].Y = rectangleF.Bottom - (rectangleF.Height / 16f);
            sourceArray[1].X = rectangleF.Left;
            sourceArray[1].Y = rectangleF.Top + (rectangleF.Height / 4f);
            sourceArray[2].X = rectangleF.Left + (rectangleF.Width / 8f);
            sourceArray[2].Y = rectangleF.Top + (rectangleF.Height / 4f);
            sourceArray[3].X = rectangleF.Left + (rectangleF.Width / 8f);
            sourceArray[3].Y = (rectangleF.Top + (rectangleF.Height / 4f)) - (rectangleF.Height / 8f);
            sourceArray[4].X = rectangleF.Left + (rectangleF.Width / 4f);
            sourceArray[4].Y = (rectangleF.Top + (rectangleF.Height / 4f)) - (rectangleF.Height / 8f);
            sourceArray[5].X = rectangleF.Left + (rectangleF.Width / 4f);
            sourceArray[5].Y = rectangleF.Top;
            sourceArray[6].X = rectangleF.Right;
            sourceArray[6].Y = rectangleF.Top;
            sourceArray[7].X = rectangleF.Right;
            sourceArray[7].Y = rectangleF.Bottom - (rectangleF.Height / 4f);
            sourceArray[8].X = rectangleF.Right - (rectangleF.Width / 8f);
            sourceArray[8].Y = rectangleF.Bottom - (rectangleF.Height / 4f);
            sourceArray[9].X = rectangleF.Right - (rectangleF.Width / 8f);
            sourceArray[9].Y = rectangleF.Bottom - (rectangleF.Height / 8f);
            sourceArray[10].X = rectangleF.Right - (rectangleF.Width / 4f);
            sourceArray[10].Y = rectangleF.Bottom - (rectangleF.Height / 8f);
            sourceArray[11].X = rectangleF.Right - (rectangleF.Width / 4f);
            sourceArray[11].Y = rectangleF.Bottom - ((3f * rectangleF.Height) / 64f);
            sourceArray[12].X = (rectangleF.Right - (rectangleF.Width / 4f)) - ((3f * rectangleF.Width) / 16f);
            sourceArray[12].Y = rectangleF.Bottom - ((3f * rectangleF.Height) / 32f);
            sourceArray[13].X = rectangleF.Left + ((3f * rectangleF.Width) / 16f);
            sourceArray[13].Y = rectangleF.Bottom;
            sourceArray[14].X = rectangleF.Left;
            sourceArray[14].Y = rectangleF.Bottom - ((3f * rectangleF.Height) / 64f);
            sourceArray[12].Y -= (3f * rectangleF.Height) / 32f;
            sourceArray[13].Y += (3f * rectangleF.Height) / 32f;
            PointF[] destinationArray = new PointF[12];
            Array.Copy(sourceArray, destinationArray, 12);
            graphicsPath.AddLines(destinationArray);
            graphicsPath.AddBezier(sourceArray[11], sourceArray[12], sourceArray[13], sourceArray[14]);
            graphicsPath.StartFigure();
            graphicsPath.AddLine(sourceArray[2].X, sourceArray[2].Y, sourceArray[10].X, sourceArray[2].Y);
            graphicsPath.StartFigure();
            graphicsPath.AddLine(sourceArray[10].X, sourceArray[2].Y, sourceArray[10].X, sourceArray[10].Y);
            graphicsPath.StartFigure();
            graphicsPath.AddLine(sourceArray[4].X, sourceArray[4].Y, sourceArray[8].X, sourceArray[4].Y);
            graphicsPath.StartFigure();
            graphicsPath.AddLine(sourceArray[8].X, sourceArray[4].Y, sourceArray[8].X, sourceArray[8].Y);
        }

        /// <summary>
        /// OrGate를 상징하는 형태의 GraphicsPath에 저장합니다.
        /// </summary>
        /// <param name="graphicsPath">Shape를 저장할 GraphicsPath </param>
        /// <param name="rectangleF">생성하고자 하는Shape의 영역 Rectangle </param>
        private static void OrGate(GraphicsPath graphicsPath, RectangleF rectangleF)
        {
            PointF pointF1 = new PointF(rectangleF.Left, rectangleF.Top);
            PointF pointF2 = new PointF((rectangleF.Left + rectangleF.Width) + (rectangleF.Width / 3f), rectangleF.Top);
            PointF pointF3 = new PointF((rectangleF.Left + rectangleF.Width) + (rectangleF.Width / 3f), rectangleF.Top + rectangleF.Height);
            PointF pointF4 = new PointF(rectangleF.Left, rectangleF.Top + rectangleF.Height);
            PointF pointF5 = new PointF(rectangleF.Left + ((8f * rectangleF.Width) / 15f), (rectangleF.Top + rectangleF.Height) - (rectangleF.Height / 6f));
            PointF pointF6 = new PointF(rectangleF.Left + ((8f * rectangleF.Width) / 15f), rectangleF.Top + (rectangleF.Height / 6f));
            graphicsPath.AddBezier(pointF1, pointF2, pointF3, pointF4);
            graphicsPath.AddBezier(pointF4, pointF5, pointF6, pointF1);
            graphicsPath.CloseFigure();
        }

        /// <summary>
        /// PunchedTape를 상징하는 형태의 GraphicsPath에 저장합니다.
        /// </summary>
        /// <param name="graphicsPath">Shape를 저장할 GraphicsPath </param>
        /// <param name="rectangleF">생성하고자 하는Shape의 영역 Rectangle </param>
        private static void PunchedTape(GraphicsPath graphicsPath, RectangleF rectangleF)
        {
            PointF pointF1 = new PointF(rectangleF.Left, rectangleF.Top + (rectangleF.Height / 16f));
            PointF pointF2 = new PointF(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Top + (rectangleF.Height / 4f));
            PointF pointF3 = new PointF(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Top - (rectangleF.Height / 8f));
            PointF pointF4 = new PointF(rectangleF.Right, rectangleF.Top + (rectangleF.Height / 16f));
            PointF pointF5 = new PointF(rectangleF.Right, rectangleF.Bottom - (rectangleF.Height / 16f));
            PointF pointF6 = new PointF(rectangleF.Right - (rectangleF.Width / 4f), rectangleF.Bottom - (rectangleF.Height / 4f));
            PointF pointF7 = new PointF(rectangleF.Left + (rectangleF.Width / 4f), rectangleF.Bottom + (rectangleF.Height / 8f));
            PointF pointF8 = new PointF(rectangleF.Left, rectangleF.Bottom - (rectangleF.Height / 16f));
            graphicsPath.AddLine(rectangleF.Left, rectangleF.Bottom - (rectangleF.Height / 16f), rectangleF.Left, rectangleF.Top + (rectangleF.Height / 16f));
            graphicsPath.AddBezier(pointF1, pointF2, pointF3, pointF4);
            graphicsPath.AddLine(rectangleF.Right, rectangleF.Top + (rectangleF.Height / 16f), rectangleF.Right, rectangleF.Bottom - (rectangleF.Height / 16f));
            graphicsPath.AddBezier(pointF5, pointF6, pointF7, pointF8);
        }

        /// <summary>
        /// 모서리가 둥근 사각형의 형태를 GraphicsPath에 저장합니다.
        /// </summary>
        /// <param name="graphicsPath">Shape를 저장할 GraphicsPath </param>
        /// <param name="rectangleF">생성하고자 하는Shape의 영역 Rectangle </param>
        /// <param name="sizeF"></param>
        private static void RoundRect(GraphicsPath graphicsPath, RectangleF rectangleF, SizeF sizeF)
        {
            if (rectangleF.Width > 0f)
            {
                while (rectangleF.Height > 0f)
                {
                    graphicsPath.AddArc(rectangleF.Right - sizeF.Width, rectangleF.Top, sizeF.Width, sizeF.Height, 270f, 90f);
                    graphicsPath.AddArc(rectangleF.Right - sizeF.Width, rectangleF.Bottom - sizeF.Height, sizeF.Width, sizeF.Height, 0f, 90f);
                    graphicsPath.AddArc(rectangleF.Left, rectangleF.Bottom - sizeF.Height, sizeF.Width, sizeF.Height, 90f, 90f);
                    graphicsPath.AddArc(rectangleF.Left, rectangleF.Top, sizeF.Width, sizeF.Height, 180f, 90f);
                    graphicsPath.CloseFigure();
                    break;
                }
            }
        }

        /// <summary>
        /// SummingJunction을 상징하는 형태의 GraphicsPath에 저장합니다.
        /// </summary>
        /// <param name="graphicsPath">Shape를 저장할 GraphicsPath </param>
        /// <param name="rectangleF">생성하고자 하는Shape의 영역 Rectangle </param>
        /// <param name="style"></param>
        private static void SummingJunction(GraphicsPath graphicsPath, RectangleF rectangleF, ShapeStyle style)
        {
            graphicsPath.AddEllipse(rectangleF);
            if (style != ShapeStyle.Or)
            {
                if (style == ShapeStyle.SummingJunction)
                {
                    PointF pointF2 = Shift(rectangleF);
                    float num = (rectangleF.Width / 2f) * 0.707f;
                    float num2 = (rectangleF.Height / 2f) * 0.707f;
                    graphicsPath.AddLine((float)(pointF2.X - num), (float)(pointF2.Y - num2), (float)(pointF2.X + num), (float)(pointF2.Y + num2));
                    graphicsPath.StartFigure();
                    graphicsPath.AddLine((float)(pointF2.X + num), (float)(pointF2.Y - num2), (float)(pointF2.X - num), (float)(pointF2.Y + num2));
                }
            }
            else
            {
                PointF pointF1 = Shift(rectangleF);
                graphicsPath.AddLine(pointF1.X, rectangleF.Top, pointF1.X, rectangleF.Bottom);
                graphicsPath.StartFigure();
                graphicsPath.AddLine(rectangleF.Left, pointF1.Y, rectangleF.Right, pointF1.Y);
            }
        }

        /// <summary>
        /// 전송(Transport)를 상징하는 형태의 GraphicsPath에 저장합니다.
        /// </summary>
        /// <param name="graphicsPath">Shape를 저장할 GraphicsPath .</param>
        /// <param name="rectangleF">생성하고자 하는Shape의 영역 Rectangle .</param>
        private static void Transport(GraphicsPath graphicsPath, RectangleF rectangleF)
        {
            PointF[] points = new PointF[10];
            points[0].X = rectangleF.Left;
            points[0].Y = rectangleF.Top + (rectangleF.Height / 2f);
            points[1].X = rectangleF.Left + (rectangleF.Width / 4f);
            points[1].Y = rectangleF.Top;
            points[2].X = rectangleF.Left + (rectangleF.Width / 4f);
            points[2].Y = rectangleF.Top + (rectangleF.Height / 4f);
            points[3].X = rectangleF.Right - (rectangleF.Width / 4f);
            points[3].Y = rectangleF.Top + (rectangleF.Height / 4f);
            points[4].X = rectangleF.Right - (rectangleF.Width / 4f);
            points[4].Y = rectangleF.Top;
            points[5].X = rectangleF.Right;
            points[5].Y = rectangleF.Top + (rectangleF.Height / 2f);
            points[6].X = rectangleF.Right - (rectangleF.Width / 4f);
            points[6].Y = rectangleF.Bottom;
            points[7].X = rectangleF.Right - (rectangleF.Width / 4f);
            points[7].Y = rectangleF.Bottom - (rectangleF.Height / 4f);
            points[8].X = rectangleF.Left + (rectangleF.Width / 4f);
            points[8].Y = rectangleF.Bottom - (rectangleF.Height / 4f);
            points[9].X = rectangleF.Left + (rectangleF.Width / 4f);
            points[9].Y = rectangleF.Bottom;
            graphicsPath.AddLines(points);
            graphicsPath.CloseFigure();
        }

        #endregion

        #endregion

    }
}
