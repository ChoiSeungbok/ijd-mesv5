using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RPTServer
{
    public partial class clsRPTBASCallback : RPTBASSkeleton
    {

        private frmH101Svr m_frmH101Svr = null;

        #region Class Construction and Destruction

        public clsRPTBASCallback(
            frmH101Svr mainCore
            ) : base(mainCore.h101Stub)
        {
            m_frmH101Svr = mainCore;
        }

        #endregion
    }
}
