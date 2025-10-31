// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : Designer.cs
// 파일 설명    : 
// 최초 작성자  : 임혁수(maverick@miracom.co.kr)
// 최초 작성일  : 2007년 5월 7일 
// 최종 수정일  : 2007년 5월30일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 07 : [임혁수] 최초 작성
//       05. 09 : [노현종] 상속에 따른 필수 구현 추가 (Serialize, Deserialize, DiagramChanged)
//       05. 14 : [노현종] Event와 Draw 관련 메소드 추가
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Xml;

namespace Miracom.Common.DiagramModeler
{
    partial class BaseDiagramPanel
    {

        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        protected System.ComponentModel.IContainer components = null;

        #region <<< [ 디자이너 생성] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        protected virtual void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            this.AutoScroll = true;
            this.AutoSize = true;
            this.BackColor = DiagramSettings.DiagramBackColor;
            this.DiagramDesignMode = false;
            this.Enabled = false;
        }

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #endregion


        #region <<< [ 상속 구현    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Diagram이 변경됨을 나타내는 이벤트 핸들러 입니다.
        /// </summary>
        public event EventHandler DiagramChanged;

        /// <summary>
        /// 다이어그램을 XMLNode 형태로 직렬화하는 메서드입니다.
        /// </summary>
        /// <param name="node">직렬화한 정보가 저장될 XmlNode객체입니다.</param>
        public void Serialize(out XmlNode node)
        {
            throw new Exception("DiagramPanel.Designer.Serialize is not implemented.");
        }

        /// <summary>
        /// XMLNode 형태의 값을 다이어그램으로 역직렬화하는 메서드입니다.
        /// </summary>
        /// <param name="node">다이어그램 구성 요소의 정보를 가지고 있는 XmlNode객체입니다.</param>
        public void Deserialize(XmlNode node)
        {
            throw new Exception("DiagramPanel.Designer.Serialize is not implemented.");
        }

        #endregion

    }
}
