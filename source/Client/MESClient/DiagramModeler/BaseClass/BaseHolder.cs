// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : ConnectionArrowDrawings.cs
// 파일 설명    : 다이어그램을 구성하는 간선(edge)이 상속받아야 하는 클래스
// 최초 작성자  : 노현종(neoswirl@miracom.co.kr)
// 최초 작성일  : 2007년 5월15일
// 최종 수정일  : 2007년 5월31일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 15 : [노현종] Constructor, Properties에 메소드 추가
// 2007. 05. 22 : [노현종] 코드 작업
// 2007. 05. 31 : [노현종] 주석 작업 완료
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// 노드(도형)의 화면상에 처리시 편의를 위한 클래스입니다.
    /// </summary>
    public abstract class BaseHolder
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// ConnectionHolder를 소유하고 있는 노드(도형)
        /// </summary>
        BaseShape shape = null;

        /// <summary>
        /// 위치값
        /// </summary>
        protected int iLocation = 0;

        /// <summary>
        /// 수평여부
        /// </summary>
        bool isHorizontal = false;

        /// <summary>
        /// 변경여부
        /// </summary>
        bool isDirty = false;

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 노드(도형)를 설정하거나 가져오는 프로퍼티 입니다.
        /// </summary>
        public BaseShape Shape
        {
            get { return shape;  }
            set 
            {
                MakeHolderRelation(value);
                shape = value; 
            }
        }

        /// <summary>
        /// 상대위치값을 설정하거나 가져오는 프로퍼티 입니다.
        /// </summary>
        public virtual int RelativeLocation
        {
            get
            {
                return iLocation;
            }
            set
            {
                if (value >= 0)
                {
                    iLocation = value;
                    IsDirty = true;
                }
            }
        }

        /// <summary>
        /// 절대위치값을 가져오는 프로퍼티 입니다.
        /// </summary>
        public virtual int AbsoluteLocation
        {
            get
            {
                if (Shape != null)
                {
                    if (IsVertical)
                        return RelativeLocation + Shape.Left;
                    else
                        return RelativeLocation + Shape.Top;
                }
                else
                {
                    return 0;
                }
            }
        }

        /// <summary>
        /// 수평 여부를 가져오는 프로퍼티 입니다.
        /// </summary>
        public bool IsHorizontal
        {
            get { return isHorizontal; }
        }

        /// <summary>
        /// 수직여부에 대한 프로퍼티 입니다.
        /// </summary>
        public bool IsVertical
        {
            get { return !isHorizontal; }
        }

        /// <summary>
        /// 변경되었는지 여부를 설정하거나 가져오는 프로퍼티 입니다.
        /// </summary>
        public bool IsDirty
        {
            get { return isDirty; }
            set { isDirty = value; }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// ConnectionHolder를 생성합니다.
        /// </summary>
        public BaseHolder()
        {
        }

        /// <summary>
        /// ConnectionHolder를 생성합니다.
        /// </summary>
        /// <param name="shape">ConnectionHolder를 소유할 노드(도형)</param>
        public BaseHolder(BaseShape shape)
        {
            if (shape == null)
                throw new ArgumentNullException("shape");
            
            this.shape = shape;
            MakeHolderRelation(shape);
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 현재의 이(this) ConnectionHolder을 Shape에 추가합니다.
        /// </summary>
        /// <param name="shape">ConnectionHolder를 소유할 노드(도형)</param>
        private void MakeHolderRelation(BaseShape shape)
        {
            if (shape != null && !shape.Holders.Contains(this))
                shape.Holders.Add(this);
            IsDirty = true;
        }

        /// <summary>
        /// 현지의 이(this) ConnectionHolder을 Shape에서 제거합니다.
        /// </summary>
        /// <param name="shape">ConnectionHolder를 제거할 노드(도형)</param>
        private void RemoveHolderRelation(BaseShape shape)
        {
            if (shape != null && shape.Holders.Contains(this))
                shape.Holders.Remove(this);
        }

        /// <summary>
        /// 마우스위치를 기준으로 위치값을 설정합니다.
        /// </summary>
        /// <param name="mouseLocation">마우스 위치</param>
        /// <returns>변경이 되었는지에 대한 True/False</returns>
        public bool SetPosition(Point mouseLocation)
        {
            if (Shape == null)
                return false;

            bool column = (mouseLocation.X >= Shape.Left && mouseLocation.X < Shape.Right);
            bool row = (mouseLocation.Y >= Shape.Top && mouseLocation.Y < Shape.Bottom);
            int oldLocation = iLocation;

            if (column && row)
            {
                if (IsVertical)
                    iLocation = mouseLocation.X - Shape.Left;
                else
                    iLocation = mouseLocation.Y - Shape.Top;
            }
            else if (column)
            {
                isHorizontal = false;
                iLocation = mouseLocation.X - Shape.Left;
            }
            else if (row)
            {
                isHorizontal = true;
                iLocation = mouseLocation.Y - Shape.Top;
            }
            else
            {
                if (IsVertical)
                {
                    if (mouseLocation.X < Shape.Left)
                        iLocation = 0;
                    else
                        iLocation = Shape.Width - 1;
                }
                // IsHorizontal
                else
                {
                    if (mouseLocation.Y < Shape.Top)
                        iLocation = 0;
                    else
                        iLocation = Shape.Height - 1;
                }
            }

            if (iLocation != oldLocation)
                IsDirty = true;

            return (iLocation != oldLocation);
        }

        /// <summary>
        /// 노드에 붙는 위치가 수직인지 수평인지를 설정합니다.
        /// </summary>
        /// <param name="horizontal"></param>
        public void SetHorizontal(bool horizontal)
        {
            this.isHorizontal = horizontal;
        }

        #endregion


        #region <<< [ Abstracts    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 사용자 정의 ConnectionHolder를 내부적으로 적용해 주기위해 생성자격으로 사용되는 함수입니다.
        /// </summary>
        /// <returns></returns>
        public abstract BaseHolder CreateNew();

        /// <summary>
        /// 사용자 정의 ConnectionHolder를 내부적으로 적용해 주기위한 생성자격으로 사용되는 함수입니다.
        /// </summary>
        /// <param name="shape"></param>
        /// <returns></returns>
        public abstract BaseHolder CreateNew(BaseShape shape);

        #endregion

    }
}
