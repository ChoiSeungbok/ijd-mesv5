// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : DefaultConnection.cs
// 파일 설명    : 다이어그램을 구성하는 간선(edge)을 상속받아 구현한 클래스
// 최초 작성자  : 노현종(neoswirl@miracom.co.kr)
// 최초 작성일  : 2007년 5월15일
// 최종 수정일  : 2007년 5월15일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 15 : [노현종] 최초 작성 및 작성 완료
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// DefaultConnection 클래스 입니다. ( BaseConnection의 상속 클래스 )
    /// </summary>
    internal class DefaultConnection : BaseConnection
    {

        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Connection을 생성합니다.
        /// </summary>
        /// <param name="previewStartHolder">시작점 Holder</param>
        /// <param name="previewEndHolder">끝점 Holder</param>
        public DefaultConnection(BaseHolder startHolder, BaseHolder endHolder)
            : base(startHolder, endHolder)
        {
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 시작점 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected override void DrawRelativeStartSign(System.Drawing.Graphics g)
        {
            base.DrawRelativeStartSign(g);
            ConnectionArrowDrawings.Draw(g,ConnectionProperty.StartArrow);
        }

        /// <summary>
        /// 끝점 화살표를 그립니다.
        /// </summary>
        /// <param name="g">GDI+ Graphics</param>
        protected override void DrawRelativeEndSign(System.Drawing.Graphics g)
        {
            base.DrawRelativeEndSign(g);
            ConnectionArrowDrawings.Draw(g, ConnectionProperty.EndArrow);
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
