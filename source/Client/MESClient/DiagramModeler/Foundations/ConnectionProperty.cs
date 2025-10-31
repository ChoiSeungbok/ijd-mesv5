// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : ConnectionProperty.cs
// 파일 설명    : 
// 최초 작성자  : 노현종(neoswirl@miracom.co.kr)
// 최초 작성일  : 2007년 5월 10일
// 최종 수정일  : 2007년 5월 31일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 10 : [노현종] 최초 작성, 생성자, 기본 프로퍼티
// 2007. 05. 22 : [노현종] 클래스 명 Line에서 ConnectionProperty로 변경
// 2007. 05. 27 : [노현종] 코드 작성 완료
// 2007. 05. 31 : [노현종] 주석 작업 완료
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Schema;
using System.Xml.Serialization;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// Link에서 활용하게 되는 Line에 대한 정보를 관리하는 클래스 입니다.
    /// </summary>
    public class ConnectionProperty : ICloneable, IXmlSerializable
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Line 그리기에 사용될 Pen
        /// </summary>
        Pen pen;

        /// <summary>
        /// Line의 Style
        /// </summary>
        LineStyle lineStyle = LineStyle.Polyline;        

        /// <summary>
        /// 시작점 화살표 형태
        /// </summary>
        ArrowStyle startArrow = ArrowStyle.None;

        /// <summary>
        /// 끝점 화살표 형태
        /// </summary>
        ArrowStyle endArrow = ArrowStyle.None;

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 라인의 스타일을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public LineStyle LineStyle
        {
            get { return lineStyle;  }
            set { lineStyle = value; }
        }

        /// <summary>
        /// 라인의 Dash 스타일을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public DashStyle DashStyle
        {
            get { return pen.DashStyle;  }
            set { pen.DashStyle = value; }
        }

        /// <summary>
        /// 라인의 색상을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public Color LineColor
        {
            get { return pen.Color;  }
            set { pen.Color = value; }
        }

        /// <summary>
        /// 라인의 시작점 화살표 형태를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public ArrowStyle StartArrow
        {
            get { return startArrow;        }
            set { this.startArrow = value;  }
        }

        /// <summary>
        /// 라인의 끝점 화살표 형태를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public ArrowStyle EndArrow
        {
            get { return endArrow;          }
            set { this.endArrow = value;    }
        }

        /// <summary>
        /// 라인의 Width를 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public float PenWidth
        {
            get { return pen.Width;  }
            set { pen.Width = value; }
        }

        /// <summary>
        /// 라인을 그릴 Pen을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public Pen DrawPen
        {
            get { return pen;  }
            set { pen = value; }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// ConnectionProperty를 생성합니다.
        /// </summary>
        public ConnectionProperty()
        {
            pen = new Pen(Color.Black);
            pen.DashStyle = DashStyle.DashDotDot;
        }

        /// <summary>
        /// ConnectionProperty를 생성합니다.
        /// </summary>
        /// <param name="pen">Line을 그리는데 사용할 Pen</param>
        public ConnectionProperty(Pen pen)
        {
            if( pen == null)
                throw new Exception("Drawing Pen is null");

            this.pen = pen;
        }

        /// <summary>
        /// ConnectionProperty를 생성합니다.
        /// </summary>
        /// <param name="lineStyle">Line의 Style</param>
        /// <param name="pen">Line을 그리는데 사용할 Pen</param>
        public ConnectionProperty(LineStyle lineStyle, Pen pen)
        {
            if (pen == null)
                throw new Exception("Drawing Pen is null");

            this.lineStyle = lineStyle;
            this.pen = pen;
        }

        /// <summary>
        /// ConnectionProperty를 생성합니다.
        /// </summary>
        /// <param name="start">시작점의 화살표 형태</param>
        /// <param name="end">끝점의 화살표 형태</param>
        public ConnectionProperty(ArrowStyle start, ArrowStyle end) : this()
        {
            StartArrow = start;
            EndArrow = end;
        }

        /// <summary>
        /// ConnectionProperty를 생성합니다.
        /// </summary>
        /// <param name="lineStyle">Line의 Style</param>
        /// <param name="pen">Line을 그리는데 사용할 Pen</param>
        /// <param name="start">시작점의 화살표 형태</param>
        /// <param name="end">끝점의 화살표 형태</param>
        public ConnectionProperty(LineStyle lineStyle, Pen pen, ArrowStyle start, ArrowStyle end)
        {
            this.pen = pen;
            this.lineStyle = lineStyle;
            this.startArrow = start;
            this.endArrow = end;
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        #region ICloneable >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// ConnectionProperty를 복재하여 새 Object를 만듭니다.
        /// </summary>
        /// <returns>복사된 ConnectionProperty Object</returns>
        public object Clone()
        {
            return new ConnectionProperty(this.lineStyle, (Pen)this.pen.Clone(), this.startArrow, this.endArrow);
        }

        #endregion

        #region XML >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// XmlSchema를 얻어옵니다.
        /// </summary>
        /// <returns></returns>
        public XmlSchema GetSchema()
        {
            return null;
        }

        /// <summary>
        /// Xml을 읽어옵니다.
        /// </summary>
        /// <param name="reader"></param>
        public void ReadXml(XmlReader reader)
        {
            throw new Exception("Shape.ReadXml is not implemented.");
        }

        /// <summary>
        /// Xml로 작성합니다.
        /// </summary>
        /// <param name="writer"></param>
        public void WriteXml(XmlWriter writer)
        {
            throw new Exception("Shape.WriteXml is not implemented.");
        }

        #endregion

        #endregion

    }
}
