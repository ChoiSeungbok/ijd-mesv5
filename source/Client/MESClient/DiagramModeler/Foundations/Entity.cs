using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// Shape의 유일성 판단의 재료로 사용하는 클래스 입니다. ( 실 구현 내용이 없음 )
    /// </summary>
    public abstract class Entity
    {

        #region <<< [ Abstracts    ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 직렬화 작업을 수행합니다.
        /// </summary>
        /// <param name="node"></param>
        internal abstract void Serialize(XmlNode node);
        
        /// <summary>
        /// 역직렬화 작업을 수행합니다.
        /// </summary>
        /// <param name="node"></param>
        internal abstract void Deserialize(XmlNode node);

        #endregion

    }
}
