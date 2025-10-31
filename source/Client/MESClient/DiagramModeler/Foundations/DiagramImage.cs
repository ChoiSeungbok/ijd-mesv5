// -----------------------------------------------------------------------------------------------------------
// Copyright(c) Miracom, Inc. All rights reserved.
// -----------------------------------------------------------------------------------------------------------
// 프로젝트명   : DiagramModeler (Miracom.Common.DiagramModeler)
// 파일명       : DiagramImage.cs
// 파일 설명    : 다이어그램을 구성하는 간선(edge)이 상속받아야 하는 클래스
// 최초 작성자  : 노현종(neoswirl@miracom.co.kr)
// 최초 작성일  : 2007년 5월25일
// 최종 수정일  : 2007년 5월31일
// -----------------------------------------------------------------------------------------------------------
// 특기 사항    : 없음
// -----------------------------------------------------------------------------------------------------------
// 2007. 05. 25 : [노현종] 클래스 추가및 코드 작업 완료
// 2007. 05. 31 : [노현종] 주석 작업 완료
// -----------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// Diagram 내에 이미지를 올리고자 할때 사용되는 클래스 입니다.
    /// </summary>
    internal class DiagramImage
    {

        #region <<< [ Variables    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 이미지 Object
        /// </summary>
        Image image;

        /// <summary>
        /// 이미지 URL
        /// </summary>
        string sUrl;

        #endregion


        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// Image Object 프로퍼티 입니다.
        /// </summary>
        public Image Image
        {
            get { return image;  }
            set 
            { 
                image = value;
            }
        }
        
        /// <summary>
        /// Image의 URL을 가져오거나 설정하는 프로퍼티 입니다.
        /// </summary>
        public string Url
        {
            get { return sUrl;  }
            set 
            { 
                sUrl = value;
            }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 생성자 입니다.
        /// </summary>
        public DiagramImage()
        {
        }

        /// <summary>
        /// 변환 생성자 입니다.
        /// </summary>
        /// <param name="image">이미지 Object</param>
        public DiagramImage(Image image)
        {
            this.image = image;
        }

        /// <summary>
        /// 변환 생성자 입니다.
        /// </summary>
        /// <param name="sUrl">이미지 URL</param>
        public DiagramImage(string url)
        {
            this.sUrl = url;
        }

        #endregion

    }
}
