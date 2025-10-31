using System;
using System.Collections.Generic;
using System.Text;

namespace Miracom.Common.DiagramModeler
{
    /// <summary>
    /// Connection을 Shape 의 Center 위치에 Hold하도록 하는 클래스 입니다.
    /// </summary>
    public class TreeHolder : BaseHolder
    {

        #region <<< [ Properties   ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 상태위치값을 설정하거나 가져오는 프로퍼티 입니다.
        /// </summary>
        public override int RelativeLocation
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
        public override int AbsoluteLocation
        {
            get
            {
                if (Shape != null)
                {
                    if (IsVertical)
                        return Shape.Left + (Shape.Width / 2);
                    else
                        return Shape.Top + (Shape.Height / 2);
                }
                else
                {
                    return 0;
                }
            }
        }

        #endregion


        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// FixedHolder를 생성합니다
        /// </summary>
        public TreeHolder()
            : base()
        {
        }

        /// <summary>
        /// FixedHolder를 생성합니다.
        /// </summary>
        /// <param name="shape">Connection을 Hold할 노드</param>
        public TreeHolder(BaseShape shape)
            : base(shape)
        {
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public override BaseHolder CreateNew()
        {
            return new TreeHolder();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="shape"></param>
        /// <returns></returns>
        public override BaseHolder CreateNew(BaseShape shape)
        {
            return new TreeHolder(shape);
        }

        #endregion

    }
}
