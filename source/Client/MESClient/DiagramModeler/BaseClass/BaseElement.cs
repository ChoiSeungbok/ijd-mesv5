// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : BaseElement.cs
// 파일 설명    : 다이어그램을 구성하는 요소(노드(node), 간선(edge))가 상속받아야 하는 클래스
// 최초 작성자  : 임혁수(maverick@miracom.co.kr)
// 최초 작성일  : 2007년 5월 7일
// 최종 수정일  : 2007년 5월 7일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 07 : [임혁수] 최초 작성 
//       05. 11 : [노현종] protected abstract void ToggleSelected() 에 파라메터 bool value를 받도록 수정
// 2007. 05. 15 : [임혁수] 객체 관리를 위한 클래스 수정
// 2007. 05. 31 : [노현종] 주석 추가 작업
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Miracom.Common.DiagramModeler
{
    public abstract partial class BaseElement : Control, IDiagramElement
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 선택여부
        /// </summary>
        private bool isSelected;

        /// <summary>
        /// 다이어그램을 구성하는 요소의 선택 여부가 변경되었을 경우에 발생하는 이벤트입니다.
        /// </summary>
        public event EventHandler SelectionChanged;

        /// <summary>
        /// 다이어그램 구성 요소가 표현하고 있는 실제 데이터가 변경되었을 경우에 발생하는 이벤트입니다.
        /// </summary>
        public event EventHandler ContentChanged;

        /// <summary>
        /// 다이어그램을 구성하는 요소가 삭제되었을 경우 발생하는 이벤트입니다.
        /// </summary>
        public event EventHandler ElementDeleted;

        #endregion

        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 다이어그램 구성 요소가 선택되었는지 여부를 가져오거나 설정합니다.
        /// </summary>
        public bool IsSelected
        {
            get
            {
                return this.isSelected;
            }
            set
            {
                if (value != this.isSelected)
                {
                    this.isSelected = value;
                    ToggleSelected(value);
                }
            }
        }

        /// <summary>
        /// Content를 Object 타입으로 가져오는 프로퍼티 입니다.
        /// </summary>
        public abstract object ContentObject
        {
            get;
        }

        /// <summary>
        /// Content의 타입을 가져오는 프로퍼티 입니다.
        /// </summary>
        public abstract Type ContentObjectType
        {
            get;
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// BaseElement를 생성합니다.
        /// </summary>
        public BaseElement()
        {
            InitializeComponent();
        }

        #endregion


        #region <<< [ Abstracts    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 다이어그램 구성 요소의 선택 여부가 변경되었을 경우에 처리해야 하는 내용을 정의한 메서드입니다.
        /// </summary>
        protected abstract void ToggleSelected(bool value);

        private object dumy(int i)
        {
            switch(i)
            {
                case 0:
                    return (object)SelectionChanged;
                case 1:
                    return (object)ContentChanged;
                case 2:
                    return (object)ElementDeleted;
            }
            return null;
        }

        #endregion

    }
}
