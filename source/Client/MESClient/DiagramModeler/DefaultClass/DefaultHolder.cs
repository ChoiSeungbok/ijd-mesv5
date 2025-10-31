using System;
using System.Collections.Generic;
using System.Text;

namespace Miracom.Common.DiagramModeler
{
    internal class DefaultHolder : BaseHolder
    {

        #region <<< [ Constructors ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        public DefaultHolder() : base()
        {
        }

        public DefaultHolder(BaseShape shape)
            : base(shape)
        {
        }

        #endregion


        #region <<< [ Methods      ] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        public override BaseHolder CreateNew()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public override BaseHolder CreateNew(BaseShape shape)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        #endregion

    }
}
