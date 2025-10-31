using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Miracom.UI;
using Miracom.CliFrx;

namespace CUS_COM.Controls
{
    public partial class udcCodeReg : Miracom.UI.Controls.MCCodeView.MCCodeView
    {
        public udcCodeReg()
        {
            InitializeComponent();

            Init();
        }

        [Category("Save Registry"), Description("레지스트리 저장")]
        public bool SaveRegistry
        {
            get;
            set;
        }

        public bool CheckValue()
        {
            return MPCF.CheckValue(this.cdvCodeReg, 1);
        }

        public void ClearField()
        {
            cdvCodeReg.Text = "";
        }
    }
}
