
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Infragistics.Win.UltraWinEditors;
using Miracom.FMBUI.Controls;
using Miracom.MsgHandler;
using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBViewResourceListDetail.vb
//   Description : View Resource List Detail
//
//   FMB Version : 1.0.0
//
//   Function List
//       - View_Resource() : View Resource Information
//       - View_Factory_ResStatus() : View Factory Resource Status Prompt
//       - SetGroupCmfItem() : Set Group / Cmf Property to control
//       - InitControl() : initial Group/Cmf Control
//       - SetCmfItem() : Set Cmf Property to control
//       - SetGRPItem() : Set Group  Property to control
//
//   Detail Description
//       -
//
//   History
//       - 2005-02-17 : Created by H.K.Kim
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------
namespace Miracom.FMBCore
{
    public class frmFMBViewResourceStatus : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBViewResourceStatus()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        //Form? Dispose瑜??ъ젙?섑븯??援ъ꽦 ?붿냼 紐⑸줉???뺣━?⑸땲??
        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                if (!(components == null))
                {
                    components.Dispose();
                }
            }
            base.Dispose(disposing);
        }
        
        //Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        private System.ComponentModel.Container components = null;
        
        //李멸퀬: ?ㅼ쓬 ?꾨줈?쒖???Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        //Windows Form ?붿옄?대꼫瑜??ъ슜?섏뿬 ?섏젙?????덉뒿?덈떎.
        //肄붾뱶 ?몄쭛湲곕? ?ъ슜?섏뿬 ?섏젙?섏? 留덉떗?쒖삤.
        internal System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Panel pnlCenter;
        internal System.Windows.Forms.Panel pnlGrp;
        internal System.Windows.Forms.Panel pnlTab;
        internal System.Windows.Forms.GroupBox grpRes;
        internal UltraTextEditor txtDesc;
        internal System.Windows.Forms.Label lblDesc;
        internal System.Windows.Forms.Label lblResID;
        internal System.Windows.Forms.TabControl tabResStatus;
        internal System.Windows.Forms.TabPage tbpGeneral;
        internal System.Windows.Forms.GroupBox grpGeneral;
        internal UltraTextEditor txtProcCount;
        internal UltraTextEditor txtLastEnd;
        internal System.Windows.Forms.Label lblLastHistSeq;
        internal System.Windows.Forms.Label lblActiveHistSeq;
        internal System.Windows.Forms.Label lblLastEventTime;
        internal System.Windows.Forms.Label lblLastEvent;
        internal UltraTextEditor txtLastHistSeq;
        internal UltraTextEditor txtLastEventTime;
        internal UltraTextEditor txtLastActHistSeq;
        internal UltraTextEditor txtLastEvent;
        internal UltraTextEditor txtLastStart;
        internal System.Windows.Forms.Label lblLastEnd;
        internal System.Windows.Forms.Label lblLastStart;
        internal System.Windows.Forms.Label lblProcCount;
        internal UltraTextEditor txtPriStatus;
        internal System.Windows.Forms.Label lblPriSts;
        internal UltraTextEditor txtUpDownFlag;
        internal System.Windows.Forms.Label lblUpDownFlag;
        internal UltraTextEditor txtDelTime;
        internal System.Windows.Forms.Label lblDelTime;
        internal UltraTextEditor txtDelUser;
        internal System.Windows.Forms.Label lblDelUserID;
        internal UltraCheckEditor chkResDelFlag;
        internal UltraCheckEditor chkSecChkFlag;
        internal UltraCheckEditor chkUnitBaseStFlag;
        internal UltraCheckEditor chkPMSchEnableFlag;
        internal UltraTextEditor txtSubAreaID;
        internal UltraTextEditor txtAreaId;
        internal UltraTextEditor txtProcMode;
        internal UltraTextEditor txtResType;
        internal UltraTextEditor txtProcRule;
        internal System.Windows.Forms.Label lblUpdateTime;
        internal System.Windows.Forms.Label lblUpdateUser;
        internal System.Windows.Forms.Label lblCreateTime;
        internal System.Windows.Forms.Label lblCreateUser;
        internal UltraTextEditor txtUpdateTime;
        internal UltraTextEditor txtCreateTime;
        internal UltraTextEditor txtUpdateUser;
        internal UltraTextEditor txtCreateUser;
        internal UltraTextEditor txtLocation;
        internal UltraTextEditor txtMaxProcCount;
        internal System.Windows.Forms.Label lblProcMode;
        internal System.Windows.Forms.Label lblLocation;
        internal System.Windows.Forms.Label lblSubAreaID;
        internal System.Windows.Forms.Label lblAreaID;
        internal System.Windows.Forms.Label lblMaxProcCount;
        internal System.Windows.Forms.Label lblProcRule;
        internal System.Windows.Forms.Label lblResType;
        internal System.Windows.Forms.TabPage tbpLotList;
        internal System.Windows.Forms.GroupBox grpLotList;
        internal System.Windows.Forms.TabPage tbpResSts;
        internal System.Windows.Forms.GroupBox grpResStatus;
        internal UltraCheckEditor chkUseFacPrtFlag;
        internal UltraTextEditor txtSts10;
        internal UltraTextEditor txtSts9;
        internal UltraTextEditor txtSts8;
        internal UltraTextEditor txtSts7;
        internal UltraTextEditor txtSts6;
        internal UltraTextEditor txtSts5;
        internal UltraTextEditor txtSts4;
        internal UltraTextEditor txtSts3;
        internal UltraTextEditor txtSts2;
        internal UltraTextEditor txtSts1;
        internal System.Windows.Forms.Label lblSts10;
        internal System.Windows.Forms.Label lblSts9;
        internal System.Windows.Forms.Label lblSts8;
        internal System.Windows.Forms.Label lblSts7;
        internal System.Windows.Forms.Label lblSts6;
        internal System.Windows.Forms.Label lblSts5;
        internal System.Windows.Forms.Label lblSts4;
        internal System.Windows.Forms.Label lblSts3;
        internal System.Windows.Forms.Label lblSts2;
        internal System.Windows.Forms.Label lblSts1;
        internal System.Windows.Forms.TabPage tbpResGrp;
        internal System.Windows.Forms.GroupBox grpGrp;
        internal UltraTextEditor txtGrp10;
        internal UltraTextEditor txtGrp9;
        internal UltraTextEditor txtGrp8;
        internal UltraTextEditor txtGrp7;
        internal UltraTextEditor txtGrp6;
        internal UltraTextEditor txtGrp5;
        internal UltraTextEditor txtGrp4;
        internal UltraTextEditor txtGrp3;
        internal UltraTextEditor txtGrp2;
        internal UltraTextEditor txtGrp1;
        internal System.Windows.Forms.Label lblGrp10;
        internal System.Windows.Forms.Label lblGrp9;
        internal System.Windows.Forms.Label lblGrp8;
        internal System.Windows.Forms.Label lblGrp7;
        internal System.Windows.Forms.Label lblGrp6;
        internal System.Windows.Forms.Label lblGrp5;
        internal System.Windows.Forms.Label lblGrp4;
        internal System.Windows.Forms.Label lblGrp3;
        internal System.Windows.Forms.Label lblGrp2;
        internal System.Windows.Forms.Label lblGrp1;
        internal System.Windows.Forms.TabPage tbpCMF;
        internal System.Windows.Forms.GroupBox grpCMF;
        internal UltraTextEditor txtCMF10;
        internal UltraTextEditor txtCMF9;
        internal UltraTextEditor txtCMF8;
        internal UltraTextEditor txtCMF7;
        internal UltraTextEditor txtCMF6;
        internal UltraTextEditor txtCMF5;
        internal UltraTextEditor txtCMF4;
        internal UltraTextEditor txtCMF3;
        internal UltraTextEditor txtCMF2;
        internal UltraTextEditor txtCMF1;
        internal System.Windows.Forms.Label lblCMF10;
        internal System.Windows.Forms.Label lblCMF9;
        internal System.Windows.Forms.Label lblCMF8;
        internal System.Windows.Forms.Label lblCMF7;
        internal System.Windows.Forms.Label lblCMF6;
        internal System.Windows.Forms.Label lblCMF5;
        internal System.Windows.Forms.Label lblCMF4;
        internal System.Windows.Forms.Label lblCMF3;
        internal System.Windows.Forms.Label lblCMF2;
        internal System.Windows.Forms.Label lblCMF1;
        internal System.Windows.Forms.Button btnClose;
        internal Infragistics.Win.UltraWinEditors.UltraCheckEditor chkIncludeDeleteRes;
        internal System.Windows.Forms.TabPage tbpLocation;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtLayOut;
        internal System.Windows.Forms.Label lblLayOut;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtType;
        internal System.Windows.Forms.Label lblType;
        internal System.Windows.Forms.Label lblText;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtSize;
        internal System.Windows.Forms.Label lblTextSize;
        internal System.Windows.Forms.Label lblTextStyle;
        internal System.Windows.Forms.Label lblBack;
        internal System.Windows.Forms.Label lblTextColor;
        internal System.Windows.Forms.GroupBox grpLocation;
        internal System.Windows.Forms.Label lblHeight;
        internal System.Windows.Forms.Label lblY;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtHeight;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtY;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtStyle;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtText;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtWidth;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtX;
        internal System.Windows.Forms.Label lblWidth;
        internal System.Windows.Forms.Label lblX;
        internal System.Windows.Forms.Label lblLocUpdateTime;
        internal System.Windows.Forms.Label lblLocCreateTime;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtLocCreateTime;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtLocUpdateUser;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtLocCreateUser;
        internal System.Windows.Forms.Label lblLocUpdateUser;
        internal System.Windows.Forms.Label lblCreateUserId;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtLocUpdateTime;
        internal Miracom.UI.Controls.MCListView.MCListView lisLotList;
        internal System.Windows.Forms.ColumnHeader ColumnHeader1;
        internal System.Windows.Forms.ColumnHeader ColumnHeader2;
        internal System.Windows.Forms.ColumnHeader ColumnHeader3;
        internal System.Windows.Forms.ColumnHeader ColumnHeader4;
        internal System.Windows.Forms.ColumnHeader ColumnHeader5;
        internal System.Windows.Forms.ColumnHeader ColumnHeader6;
        internal System.Windows.Forms.ColumnHeader ColumnHeader7;
        internal System.Windows.Forms.ColumnHeader ColumnHeader8;
        internal System.Windows.Forms.ColumnHeader ColumnHeader9;
        internal System.Windows.Forms.ColumnHeader ColumnHeader10;
        internal System.Windows.Forms.ColumnHeader ColumnHeader11;
        internal System.Windows.Forms.ColumnHeader ColumnHeader12;
        internal System.Windows.Forms.ColumnHeader ColumnHeader13;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcText;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcBack;
        internal System.Windows.Forms.Label lblDeleteFlag;
        internal System.Windows.Forms.Label lblPMSchedule;
        internal System.Windows.Forms.Label lblUnitBase;
        internal System.Windows.Forms.Label lblSecurityCheck;
        internal System.Windows.Forms.Label lblUseFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtCtrlMode;
        internal System.Windows.Forms.Label lblCtrlMode;
        internal System.Windows.Forms.PictureBox pctImage;
        internal System.Windows.Forms.Label lblImage;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvResID;
        public System.Windows.Forms.Button btnView;
        internal UltraTextEditor txtCMF20;
        internal UltraTextEditor txtCMF19;
        internal UltraTextEditor txtCMF18;
        internal UltraTextEditor txtCMF17;
        internal UltraTextEditor txtCMF16;
        internal UltraTextEditor txtCMF15;
        internal UltraTextEditor txtCMF14;
        internal UltraTextEditor txtCMF13;
        internal UltraTextEditor txtCMF12;
        internal UltraTextEditor txtCMF11;
        internal Label lblCMF20;
        internal Label lblCMF19;
        internal Label lblCMF18;
        internal Label lblCMF17;
        internal Label lblCMF16;
        internal Label lblCMF15;
        internal Label lblCMF14;
        internal Label lblCMF13;
        internal Label lblCMF12;
        internal Label lblCMF11;
        private ColumnHeader columnHeader14;
        private ColumnHeader columnHeader15;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnView = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.pnlCenter = new System.Windows.Forms.Panel();
            this.pnlTab = new System.Windows.Forms.Panel();
            this.tabResStatus = new System.Windows.Forms.TabControl();
            this.tbpGeneral = new System.Windows.Forms.TabPage();
            this.grpGeneral = new System.Windows.Forms.GroupBox();
            this.txtCtrlMode = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblCtrlMode = new System.Windows.Forms.Label();
            this.lblSecurityCheck = new System.Windows.Forms.Label();
            this.lblUnitBase = new System.Windows.Forms.Label();
            this.lblPMSchedule = new System.Windows.Forms.Label();
            this.lblDeleteFlag = new System.Windows.Forms.Label();
            this.txtProcCount = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLastEnd = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblLastHistSeq = new System.Windows.Forms.Label();
            this.lblActiveHistSeq = new System.Windows.Forms.Label();
            this.lblLastEventTime = new System.Windows.Forms.Label();
            this.lblLastEvent = new System.Windows.Forms.Label();
            this.txtLastHistSeq = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLastEventTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLastActHistSeq = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLastEvent = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLastStart = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblLastEnd = new System.Windows.Forms.Label();
            this.lblLastStart = new System.Windows.Forms.Label();
            this.lblProcCount = new System.Windows.Forms.Label();
            this.txtPriStatus = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblPriSts = new System.Windows.Forms.Label();
            this.txtUpDownFlag = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblUpDownFlag = new System.Windows.Forms.Label();
            this.txtDelTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblDelTime = new System.Windows.Forms.Label();
            this.txtDelUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblDelUserID = new System.Windows.Forms.Label();
            this.chkResDelFlag = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.chkSecChkFlag = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.chkUnitBaseStFlag = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.chkPMSchEnableFlag = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.txtSubAreaID = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtAreaId = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtProcMode = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtResType = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtProcRule = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblUpdateTime = new System.Windows.Forms.Label();
            this.lblUpdateUser = new System.Windows.Forms.Label();
            this.lblCreateTime = new System.Windows.Forms.Label();
            this.lblCreateUser = new System.Windows.Forms.Label();
            this.txtUpdateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCreateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtUpdateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCreateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLocation = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtMaxProcCount = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblProcMode = new System.Windows.Forms.Label();
            this.lblLocation = new System.Windows.Forms.Label();
            this.lblSubAreaID = new System.Windows.Forms.Label();
            this.lblAreaID = new System.Windows.Forms.Label();
            this.lblMaxProcCount = new System.Windows.Forms.Label();
            this.lblProcRule = new System.Windows.Forms.Label();
            this.lblResType = new System.Windows.Forms.Label();
            this.tbpCMF = new System.Windows.Forms.TabPage();
            this.grpCMF = new System.Windows.Forms.GroupBox();
            this.txtCMF20 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF19 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF18 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF17 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF16 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF15 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF14 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF13 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF12 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF11 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblCMF20 = new System.Windows.Forms.Label();
            this.lblCMF19 = new System.Windows.Forms.Label();
            this.lblCMF18 = new System.Windows.Forms.Label();
            this.lblCMF17 = new System.Windows.Forms.Label();
            this.lblCMF16 = new System.Windows.Forms.Label();
            this.lblCMF15 = new System.Windows.Forms.Label();
            this.lblCMF14 = new System.Windows.Forms.Label();
            this.lblCMF13 = new System.Windows.Forms.Label();
            this.lblCMF12 = new System.Windows.Forms.Label();
            this.lblCMF11 = new System.Windows.Forms.Label();
            this.txtCMF10 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF9 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF8 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF7 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF6 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF5 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF4 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF3 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF2 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCMF1 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblCMF10 = new System.Windows.Forms.Label();
            this.lblCMF9 = new System.Windows.Forms.Label();
            this.lblCMF8 = new System.Windows.Forms.Label();
            this.lblCMF7 = new System.Windows.Forms.Label();
            this.lblCMF6 = new System.Windows.Forms.Label();
            this.lblCMF5 = new System.Windows.Forms.Label();
            this.lblCMF4 = new System.Windows.Forms.Label();
            this.lblCMF3 = new System.Windows.Forms.Label();
            this.lblCMF2 = new System.Windows.Forms.Label();
            this.lblCMF1 = new System.Windows.Forms.Label();
            this.tbpLotList = new System.Windows.Forms.TabPage();
            this.grpLotList = new System.Windows.Forms.GroupBox();
            this.lisLotList = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader14 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader15 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader6 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader7 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader8 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader9 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader10 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader11 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader12 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader13 = new System.Windows.Forms.ColumnHeader();
            this.tbpResSts = new System.Windows.Forms.TabPage();
            this.grpResStatus = new System.Windows.Forms.GroupBox();
            this.lblUseFactory = new System.Windows.Forms.Label();
            this.chkUseFacPrtFlag = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.txtSts10 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts9 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts8 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts7 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts6 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts5 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts4 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts3 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts2 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSts1 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblSts10 = new System.Windows.Forms.Label();
            this.lblSts9 = new System.Windows.Forms.Label();
            this.lblSts8 = new System.Windows.Forms.Label();
            this.lblSts7 = new System.Windows.Forms.Label();
            this.lblSts6 = new System.Windows.Forms.Label();
            this.lblSts5 = new System.Windows.Forms.Label();
            this.lblSts4 = new System.Windows.Forms.Label();
            this.lblSts3 = new System.Windows.Forms.Label();
            this.lblSts2 = new System.Windows.Forms.Label();
            this.lblSts1 = new System.Windows.Forms.Label();
            this.tbpResGrp = new System.Windows.Forms.TabPage();
            this.grpGrp = new System.Windows.Forms.GroupBox();
            this.txtGrp10 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp9 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp8 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp7 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp6 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp5 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp4 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp3 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp2 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGrp1 = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblGrp10 = new System.Windows.Forms.Label();
            this.lblGrp9 = new System.Windows.Forms.Label();
            this.lblGrp8 = new System.Windows.Forms.Label();
            this.lblGrp7 = new System.Windows.Forms.Label();
            this.lblGrp6 = new System.Windows.Forms.Label();
            this.lblGrp5 = new System.Windows.Forms.Label();
            this.lblGrp4 = new System.Windows.Forms.Label();
            this.lblGrp3 = new System.Windows.Forms.Label();
            this.lblGrp2 = new System.Windows.Forms.Label();
            this.lblGrp1 = new System.Windows.Forms.Label();
            this.tbpLocation = new System.Windows.Forms.TabPage();
            this.grpLocation = new System.Windows.Forms.GroupBox();
            this.pctImage = new System.Windows.Forms.PictureBox();
            this.lblImage = new System.Windows.Forms.Label();
            this.utcBack = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.utcText = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.lblLocUpdateTime = new System.Windows.Forms.Label();
            this.lblLocCreateTime = new System.Windows.Forms.Label();
            this.txtLocUpdateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLocCreateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLocUpdateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLocCreateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblLocUpdateUser = new System.Windows.Forms.Label();
            this.lblCreateUserId = new System.Windows.Forms.Label();
            this.txtSize = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblHeight = new System.Windows.Forms.Label();
            this.lblY = new System.Windows.Forms.Label();
            this.lblBack = new System.Windows.Forms.Label();
            this.lblTextStyle = new System.Windows.Forms.Label();
            this.txtHeight = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtY = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtStyle = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtType = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblType = new System.Windows.Forms.Label();
            this.lblTextSize = new System.Windows.Forms.Label();
            this.txtLayOut = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblLayOut = new System.Windows.Forms.Label();
            this.txtText = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblText = new System.Windows.Forms.Label();
            this.txtWidth = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtX = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblWidth = new System.Windows.Forms.Label();
            this.lblX = new System.Windows.Forms.Label();
            this.lblTextColor = new System.Windows.Forms.Label();
            this.pnlGrp = new System.Windows.Forms.Panel();
            this.grpRes = new System.Windows.Forms.GroupBox();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblFactory = new System.Windows.Forms.Label();
            this.chkIncludeDeleteRes = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.cdvResID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.txtDesc = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblDesc = new System.Windows.Forms.Label();
            this.lblResID = new System.Windows.Forms.Label();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTab.SuspendLayout();
            this.tabResStatus.SuspendLayout();
            this.tbpGeneral.SuspendLayout();
            this.grpGeneral.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtCtrlMode)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtProcCount)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEnd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastHistSeq)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEventTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastActHistSeq)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEvent)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastStart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPriStatus)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpDownFlag)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDelTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDelUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSubAreaID)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAreaId)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtProcMode)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtResType)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtProcRule)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocation)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtMaxProcCount)).BeginInit();
            this.tbpCMF.SuspendLayout();
            this.grpCMF.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF20)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF19)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF18)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF17)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF16)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF15)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF14)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF13)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF12)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF11)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF1)).BeginInit();
            this.tbpLotList.SuspendLayout();
            this.grpLotList.SuspendLayout();
            this.tbpResSts.SuspendLayout();
            this.grpResStatus.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts1)).BeginInit();
            this.tbpResGrp.SuspendLayout();
            this.grpGrp.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp1)).BeginInit();
            this.tbpLocation.SuspendLayout();
            this.grpLocation.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pctImage)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcBack)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcText)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocUpdateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocCreateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocUpdateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocCreateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtStyle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtType)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLayOut)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtText)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtX)).BeginInit();
            this.pnlGrp.SuspendLayout();
            this.grpRes.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvResID)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDesc)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnView);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 513);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(742, 40);
            this.pnlBottom.TabIndex = 1;
            // 
            // btnView
            // 
            this.btnView.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnView.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnView.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnView.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnView.Location = new System.Drawing.Point(579, 9);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(74, 23);
            this.btnView.TabIndex = 0;
            this.btnView.Text = "View";
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            // 
            // btnClose
            // 
            this.btnClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClose.Location = new System.Drawing.Point(659, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.pnlTab);
            this.pnlCenter.Controls.Add(this.pnlGrp);
            this.pnlCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenter.Location = new System.Drawing.Point(0, 0);
            this.pnlCenter.Name = "pnlCenter";
            this.pnlCenter.Size = new System.Drawing.Size(742, 513);
            this.pnlCenter.TabIndex = 0;
            // 
            // pnlTab
            // 
            this.pnlTab.Controls.Add(this.tabResStatus);
            this.pnlTab.Cursor = System.Windows.Forms.Cursors.Default;
            this.pnlTab.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlTab.Location = new System.Drawing.Point(0, 92);
            this.pnlTab.Name = "pnlTab";
            this.pnlTab.Padding = new System.Windows.Forms.Padding(3, 5, 3, 3);
            this.pnlTab.Size = new System.Drawing.Size(742, 421);
            this.pnlTab.TabIndex = 1;
            // 
            // tabResStatus
            // 
            this.tabResStatus.Controls.Add(this.tbpGeneral);
            this.tabResStatus.Controls.Add(this.tbpCMF);
            this.tabResStatus.Controls.Add(this.tbpLotList);
            this.tabResStatus.Controls.Add(this.tbpResSts);
            this.tabResStatus.Controls.Add(this.tbpResGrp);
            this.tabResStatus.Controls.Add(this.tbpLocation);
            this.tabResStatus.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabResStatus.ItemSize = new System.Drawing.Size(60, 18);
            this.tabResStatus.Location = new System.Drawing.Point(3, 5);
            this.tabResStatus.Name = "tabResStatus";
            this.tabResStatus.SelectedIndex = 0;
            this.tabResStatus.Size = new System.Drawing.Size(736, 413);
            this.tabResStatus.TabIndex = 1;
            this.tabResStatus.TabStop = false;
            // 
            // tbpGeneral
            // 
            this.tbpGeneral.Controls.Add(this.grpGeneral);
            this.tbpGeneral.Location = new System.Drawing.Point(4, 22);
            this.tbpGeneral.Name = "tbpGeneral";
            this.tbpGeneral.Padding = new System.Windows.Forms.Padding(3, 0, 3, 3);
            this.tbpGeneral.Size = new System.Drawing.Size(728, 387);
            this.tbpGeneral.TabIndex = 0;
            this.tbpGeneral.Text = "General";
            // 
            // grpGeneral
            // 
            this.grpGeneral.Controls.Add(this.txtCtrlMode);
            this.grpGeneral.Controls.Add(this.lblCtrlMode);
            this.grpGeneral.Controls.Add(this.lblSecurityCheck);
            this.grpGeneral.Controls.Add(this.lblUnitBase);
            this.grpGeneral.Controls.Add(this.lblPMSchedule);
            this.grpGeneral.Controls.Add(this.lblDeleteFlag);
            this.grpGeneral.Controls.Add(this.txtProcCount);
            this.grpGeneral.Controls.Add(this.txtLastEnd);
            this.grpGeneral.Controls.Add(this.lblLastHistSeq);
            this.grpGeneral.Controls.Add(this.lblActiveHistSeq);
            this.grpGeneral.Controls.Add(this.lblLastEventTime);
            this.grpGeneral.Controls.Add(this.lblLastEvent);
            this.grpGeneral.Controls.Add(this.txtLastHistSeq);
            this.grpGeneral.Controls.Add(this.txtLastEventTime);
            this.grpGeneral.Controls.Add(this.txtLastActHistSeq);
            this.grpGeneral.Controls.Add(this.txtLastEvent);
            this.grpGeneral.Controls.Add(this.txtLastStart);
            this.grpGeneral.Controls.Add(this.lblLastEnd);
            this.grpGeneral.Controls.Add(this.lblLastStart);
            this.grpGeneral.Controls.Add(this.lblProcCount);
            this.grpGeneral.Controls.Add(this.txtPriStatus);
            this.grpGeneral.Controls.Add(this.lblPriSts);
            this.grpGeneral.Controls.Add(this.txtUpDownFlag);
            this.grpGeneral.Controls.Add(this.lblUpDownFlag);
            this.grpGeneral.Controls.Add(this.txtDelTime);
            this.grpGeneral.Controls.Add(this.lblDelTime);
            this.grpGeneral.Controls.Add(this.txtDelUser);
            this.grpGeneral.Controls.Add(this.lblDelUserID);
            this.grpGeneral.Controls.Add(this.chkResDelFlag);
            this.grpGeneral.Controls.Add(this.chkSecChkFlag);
            this.grpGeneral.Controls.Add(this.chkUnitBaseStFlag);
            this.grpGeneral.Controls.Add(this.chkPMSchEnableFlag);
            this.grpGeneral.Controls.Add(this.txtSubAreaID);
            this.grpGeneral.Controls.Add(this.txtAreaId);
            this.grpGeneral.Controls.Add(this.txtProcMode);
            this.grpGeneral.Controls.Add(this.txtResType);
            this.grpGeneral.Controls.Add(this.txtProcRule);
            this.grpGeneral.Controls.Add(this.lblUpdateTime);
            this.grpGeneral.Controls.Add(this.lblUpdateUser);
            this.grpGeneral.Controls.Add(this.lblCreateTime);
            this.grpGeneral.Controls.Add(this.lblCreateUser);
            this.grpGeneral.Controls.Add(this.txtUpdateTime);
            this.grpGeneral.Controls.Add(this.txtCreateTime);
            this.grpGeneral.Controls.Add(this.txtUpdateUser);
            this.grpGeneral.Controls.Add(this.txtCreateUser);
            this.grpGeneral.Controls.Add(this.txtLocation);
            this.grpGeneral.Controls.Add(this.txtMaxProcCount);
            this.grpGeneral.Controls.Add(this.lblProcMode);
            this.grpGeneral.Controls.Add(this.lblLocation);
            this.grpGeneral.Controls.Add(this.lblSubAreaID);
            this.grpGeneral.Controls.Add(this.lblAreaID);
            this.grpGeneral.Controls.Add(this.lblMaxProcCount);
            this.grpGeneral.Controls.Add(this.lblProcRule);
            this.grpGeneral.Controls.Add(this.lblResType);
            this.grpGeneral.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpGeneral.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpGeneral.Location = new System.Drawing.Point(3, 0);
            this.grpGeneral.Name = "grpGeneral";
            this.grpGeneral.Size = new System.Drawing.Size(722, 384);
            this.grpGeneral.TabIndex = 0;
            this.grpGeneral.TabStop = false;
            // 
            // txtCtrlMode
            // 
            this.txtCtrlMode.Location = new System.Drawing.Point(120, 257);
            this.txtCtrlMode.MaxLength = 20;
            this.txtCtrlMode.Name = "txtCtrlMode";
            this.txtCtrlMode.ReadOnly = true;
            this.txtCtrlMode.Size = new System.Drawing.Size(152, 19);
            this.txtCtrlMode.TabIndex = 10;
            this.txtCtrlMode.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblCtrlMode
            // 
            this.lblCtrlMode.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCtrlMode.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblCtrlMode.Location = new System.Drawing.Point(12, 259);
            this.lblCtrlMode.Name = "lblCtrlMode";
            this.lblCtrlMode.Size = new System.Drawing.Size(106, 14);
            this.lblCtrlMode.TabIndex = 54;
            this.lblCtrlMode.Text = "Control Mode";
            // 
            // lblSecurityCheck
            // 
            this.lblSecurityCheck.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSecurityCheck.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblSecurityCheck.Location = new System.Drawing.Point(564, 91);
            this.lblSecurityCheck.Name = "lblSecurityCheck";
            this.lblSecurityCheck.Size = new System.Drawing.Size(154, 14);
            this.lblSecurityCheck.TabIndex = 26;
            this.lblSecurityCheck.Text = "Security Check Flag";
            // 
            // lblUnitBase
            // 
            this.lblUnitBase.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUnitBase.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblUnitBase.Location = new System.Drawing.Point(564, 67);
            this.lblUnitBase.Name = "lblUnitBase";
            this.lblUnitBase.Size = new System.Drawing.Size(154, 14);
            this.lblUnitBase.TabIndex = 25;
            this.lblUnitBase.Text = "Unit Base Standard Flag";
            // 
            // lblPMSchedule
            // 
            this.lblPMSchedule.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblPMSchedule.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblPMSchedule.Location = new System.Drawing.Point(564, 43);
            this.lblPMSchedule.Name = "lblPMSchedule";
            this.lblPMSchedule.Size = new System.Drawing.Size(154, 14);
            this.lblPMSchedule.TabIndex = 24;
            this.lblPMSchedule.Text = "PM Schedule Enable Flag";
            // 
            // lblDeleteFlag
            // 
            this.lblDeleteFlag.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDeleteFlag.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblDeleteFlag.Location = new System.Drawing.Point(564, 19);
            this.lblDeleteFlag.Name = "lblDeleteFlag";
            this.lblDeleteFlag.Size = new System.Drawing.Size(154, 14);
            this.lblDeleteFlag.TabIndex = 23;
            this.lblDeleteFlag.Text = "Resource Delete Flag";
            // 
            // txtProcCount
            // 
            this.txtProcCount.Location = new System.Drawing.Point(120, 64);
            this.txtProcCount.MaxLength = 3;
            this.txtProcCount.Name = "txtProcCount";
            this.txtProcCount.ReadOnly = true;
            this.txtProcCount.Size = new System.Drawing.Size(152, 19);
            this.txtProcCount.TabIndex = 2;
            this.txtProcCount.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLastEnd
            // 
            this.txtLastEnd.Location = new System.Drawing.Point(388, 40);
            this.txtLastEnd.MaxLength = 20;
            this.txtLastEnd.Name = "txtLastEnd";
            this.txtLastEnd.ReadOnly = true;
            this.txtLastEnd.Size = new System.Drawing.Size(152, 19);
            this.txtLastEnd.TabIndex = 12;
            this.txtLastEnd.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblLastHistSeq
            // 
            this.lblLastHistSeq.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastHistSeq.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLastHistSeq.Location = new System.Drawing.Point(280, 139);
            this.lblLastHistSeq.Name = "lblLastHistSeq";
            this.lblLastHistSeq.Size = new System.Drawing.Size(106, 14);
            this.lblLastHistSeq.TabIndex = 32;
            this.lblLastHistSeq.Text = "Last Hist Seq";
            // 
            // lblActiveHistSeq
            // 
            this.lblActiveHistSeq.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblActiveHistSeq.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblActiveHistSeq.Location = new System.Drawing.Point(280, 115);
            this.lblActiveHistSeq.Name = "lblActiveHistSeq";
            this.lblActiveHistSeq.Size = new System.Drawing.Size(106, 14);
            this.lblActiveHistSeq.TabIndex = 30;
            this.lblActiveHistSeq.Text = "Last Act Hist Seq";
            // 
            // lblLastEventTime
            // 
            this.lblLastEventTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastEventTime.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLastEventTime.Location = new System.Drawing.Point(280, 91);
            this.lblLastEventTime.Name = "lblLastEventTime";
            this.lblLastEventTime.Size = new System.Drawing.Size(106, 14);
            this.lblLastEventTime.TabIndex = 28;
            this.lblLastEventTime.Text = "Last Event Time";
            // 
            // lblLastEvent
            // 
            this.lblLastEvent.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastEvent.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLastEvent.Location = new System.Drawing.Point(280, 67);
            this.lblLastEvent.Name = "lblLastEvent";
            this.lblLastEvent.Size = new System.Drawing.Size(106, 14);
            this.lblLastEvent.TabIndex = 26;
            this.lblLastEvent.Text = "Last Event";
            // 
            // txtLastHistSeq
            // 
            this.txtLastHistSeq.Location = new System.Drawing.Point(388, 136);
            this.txtLastHistSeq.MaxLength = 6;
            this.txtLastHistSeq.Name = "txtLastHistSeq";
            this.txtLastHistSeq.ReadOnly = true;
            this.txtLastHistSeq.Size = new System.Drawing.Size(152, 19);
            this.txtLastHistSeq.TabIndex = 16;
            this.txtLastHistSeq.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLastEventTime
            // 
            this.txtLastEventTime.Location = new System.Drawing.Point(388, 88);
            this.txtLastEventTime.MaxLength = 20;
            this.txtLastEventTime.Name = "txtLastEventTime";
            this.txtLastEventTime.ReadOnly = true;
            this.txtLastEventTime.Size = new System.Drawing.Size(152, 19);
            this.txtLastEventTime.TabIndex = 14;
            this.txtLastEventTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLastActHistSeq
            // 
            this.txtLastActHistSeq.Location = new System.Drawing.Point(388, 112);
            this.txtLastActHistSeq.MaxLength = 6;
            this.txtLastActHistSeq.Name = "txtLastActHistSeq";
            this.txtLastActHistSeq.ReadOnly = true;
            this.txtLastActHistSeq.Size = new System.Drawing.Size(152, 19);
            this.txtLastActHistSeq.TabIndex = 15;
            this.txtLastActHistSeq.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLastEvent
            // 
            this.txtLastEvent.Location = new System.Drawing.Point(388, 64);
            this.txtLastEvent.MaxLength = 12;
            this.txtLastEvent.Name = "txtLastEvent";
            this.txtLastEvent.ReadOnly = true;
            this.txtLastEvent.Size = new System.Drawing.Size(152, 19);
            this.txtLastEvent.TabIndex = 13;
            this.txtLastEvent.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLastStart
            // 
            this.txtLastStart.Location = new System.Drawing.Point(388, 16);
            this.txtLastStart.MaxLength = 20;
            this.txtLastStart.Name = "txtLastStart";
            this.txtLastStart.ReadOnly = true;
            this.txtLastStart.Size = new System.Drawing.Size(152, 19);
            this.txtLastStart.TabIndex = 11;
            this.txtLastStart.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblLastEnd
            // 
            this.lblLastEnd.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastEnd.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLastEnd.Location = new System.Drawing.Point(280, 43);
            this.lblLastEnd.Name = "lblLastEnd";
            this.lblLastEnd.Size = new System.Drawing.Size(106, 14);
            this.lblLastEnd.TabIndex = 24;
            this.lblLastEnd.Text = "Last End Time";
            // 
            // lblLastStart
            // 
            this.lblLastStart.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastStart.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLastStart.Location = new System.Drawing.Point(280, 19);
            this.lblLastStart.Name = "lblLastStart";
            this.lblLastStart.Size = new System.Drawing.Size(106, 14);
            this.lblLastStart.TabIndex = 22;
            this.lblLastStart.Text = "Last Start Time";
            // 
            // lblProcCount
            // 
            this.lblProcCount.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblProcCount.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblProcCount.Location = new System.Drawing.Point(12, 67);
            this.lblProcCount.Name = "lblProcCount";
            this.lblProcCount.Size = new System.Drawing.Size(106, 14);
            this.lblProcCount.TabIndex = 4;
            this.lblProcCount.Text = "Proc Count";
            // 
            // txtPriStatus
            // 
            this.txtPriStatus.Location = new System.Drawing.Point(120, 16);
            this.txtPriStatus.MaxLength = 30;
            this.txtPriStatus.Name = "txtPriStatus";
            this.txtPriStatus.ReadOnly = true;
            this.txtPriStatus.Size = new System.Drawing.Size(152, 19);
            this.txtPriStatus.TabIndex = 0;
            this.txtPriStatus.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblPriSts
            // 
            this.lblPriSts.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblPriSts.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblPriSts.Location = new System.Drawing.Point(12, 19);
            this.lblPriSts.Name = "lblPriSts";
            this.lblPriSts.Size = new System.Drawing.Size(106, 14);
            this.lblPriSts.TabIndex = 0;
            this.lblPriSts.Text = "Resource Status";
            // 
            // txtUpDownFlag
            // 
            this.txtUpDownFlag.Location = new System.Drawing.Point(120, 40);
            this.txtUpDownFlag.MaxLength = 5;
            this.txtUpDownFlag.Name = "txtUpDownFlag";
            this.txtUpDownFlag.ReadOnly = true;
            this.txtUpDownFlag.Size = new System.Drawing.Size(152, 19);
            this.txtUpDownFlag.TabIndex = 1;
            this.txtUpDownFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblUpDownFlag
            // 
            this.lblUpDownFlag.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpDownFlag.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblUpDownFlag.Location = new System.Drawing.Point(12, 43);
            this.lblUpDownFlag.Name = "lblUpDownFlag";
            this.lblUpDownFlag.Size = new System.Drawing.Size(106, 14);
            this.lblUpDownFlag.TabIndex = 2;
            this.lblUpDownFlag.Text = "Up Down Flag";
            // 
            // txtDelTime
            // 
            this.txtDelTime.Location = new System.Drawing.Point(388, 184);
            this.txtDelTime.MaxLength = 20;
            this.txtDelTime.Name = "txtDelTime";
            this.txtDelTime.ReadOnly = true;
            this.txtDelTime.Size = new System.Drawing.Size(152, 19);
            this.txtDelTime.TabIndex = 18;
            this.txtDelTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblDelTime
            // 
            this.lblDelTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDelTime.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblDelTime.Location = new System.Drawing.Point(280, 187);
            this.lblDelTime.Name = "lblDelTime";
            this.lblDelTime.Size = new System.Drawing.Size(106, 14);
            this.lblDelTime.TabIndex = 36;
            this.lblDelTime.Text = "Res Delete Time";
            // 
            // txtDelUser
            // 
            this.txtDelUser.Location = new System.Drawing.Point(388, 160);
            this.txtDelUser.MaxLength = 20;
            this.txtDelUser.Name = "txtDelUser";
            this.txtDelUser.ReadOnly = true;
            this.txtDelUser.Size = new System.Drawing.Size(152, 19);
            this.txtDelUser.TabIndex = 17;
            this.txtDelUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblDelUserID
            // 
            this.lblDelUserID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDelUserID.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblDelUserID.Location = new System.Drawing.Point(280, 163);
            this.lblDelUserID.Name = "lblDelUserID";
            this.lblDelUserID.Size = new System.Drawing.Size(106, 14);
            this.lblDelUserID.TabIndex = 34;
            this.lblDelUserID.Text = "Res Delete User";
            // 
            // chkResDelFlag
            // 
            this.chkResDelFlag.Enabled = false;
            this.chkResDelFlag.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkResDelFlag.Location = new System.Drawing.Point(548, 19);
            this.chkResDelFlag.Name = "chkResDelFlag";
            this.chkResDelFlag.Size = new System.Drawing.Size(14, 14);
            this.chkResDelFlag.TabIndex = 46;
            this.chkResDelFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // chkSecChkFlag
            // 
            this.chkSecChkFlag.Enabled = false;
            this.chkSecChkFlag.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkSecChkFlag.Location = new System.Drawing.Point(548, 91);
            this.chkSecChkFlag.Name = "chkSecChkFlag";
            this.chkSecChkFlag.Size = new System.Drawing.Size(14, 14);
            this.chkSecChkFlag.TabIndex = 49;
            this.chkSecChkFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // chkUnitBaseStFlag
            // 
            this.chkUnitBaseStFlag.Enabled = false;
            this.chkUnitBaseStFlag.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkUnitBaseStFlag.Location = new System.Drawing.Point(548, 67);
            this.chkUnitBaseStFlag.Name = "chkUnitBaseStFlag";
            this.chkUnitBaseStFlag.Size = new System.Drawing.Size(14, 14);
            this.chkUnitBaseStFlag.TabIndex = 48;
            this.chkUnitBaseStFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // chkPMSchEnableFlag
            // 
            this.chkPMSchEnableFlag.Enabled = false;
            this.chkPMSchEnableFlag.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkPMSchEnableFlag.Location = new System.Drawing.Point(548, 43);
            this.chkPMSchEnableFlag.Name = "chkPMSchEnableFlag";
            this.chkPMSchEnableFlag.Size = new System.Drawing.Size(14, 14);
            this.chkPMSchEnableFlag.TabIndex = 47;
            this.chkPMSchEnableFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSubAreaID
            // 
            this.txtSubAreaID.Location = new System.Drawing.Point(120, 185);
            this.txtSubAreaID.MaxLength = 20;
            this.txtSubAreaID.Name = "txtSubAreaID";
            this.txtSubAreaID.ReadOnly = true;
            this.txtSubAreaID.Size = new System.Drawing.Size(152, 19);
            this.txtSubAreaID.TabIndex = 7;
            this.txtSubAreaID.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtAreaId
            // 
            this.txtAreaId.Location = new System.Drawing.Point(120, 161);
            this.txtAreaId.MaxLength = 20;
            this.txtAreaId.Name = "txtAreaId";
            this.txtAreaId.ReadOnly = true;
            this.txtAreaId.Size = new System.Drawing.Size(152, 19);
            this.txtAreaId.TabIndex = 6;
            this.txtAreaId.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtProcMode
            // 
            this.txtProcMode.Location = new System.Drawing.Point(120, 233);
            this.txtProcMode.MaxLength = 20;
            this.txtProcMode.Name = "txtProcMode";
            this.txtProcMode.ReadOnly = true;
            this.txtProcMode.Size = new System.Drawing.Size(152, 19);
            this.txtProcMode.TabIndex = 9;
            this.txtProcMode.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtResType
            // 
            this.txtResType.Location = new System.Drawing.Point(120, 88);
            this.txtResType.MaxLength = 20;
            this.txtResType.Name = "txtResType";
            this.txtResType.ReadOnly = true;
            this.txtResType.Size = new System.Drawing.Size(152, 19);
            this.txtResType.TabIndex = 3;
            this.txtResType.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtProcRule
            // 
            this.txtProcRule.Location = new System.Drawing.Point(120, 113);
            this.txtProcRule.MaxLength = 10;
            this.txtProcRule.Name = "txtProcRule";
            this.txtProcRule.ReadOnly = true;
            this.txtProcRule.Size = new System.Drawing.Size(152, 19);
            this.txtProcRule.TabIndex = 4;
            this.txtProcRule.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblUpdateTime
            // 
            this.lblUpdateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateTime.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblUpdateTime.Location = new System.Drawing.Point(280, 283);
            this.lblUpdateTime.Name = "lblUpdateTime";
            this.lblUpdateTime.Size = new System.Drawing.Size(106, 14);
            this.lblUpdateTime.TabIndex = 44;
            this.lblUpdateTime.Text = "Update Time";
            // 
            // lblUpdateUser
            // 
            this.lblUpdateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateUser.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblUpdateUser.Location = new System.Drawing.Point(280, 259);
            this.lblUpdateUser.Name = "lblUpdateUser";
            this.lblUpdateUser.Size = new System.Drawing.Size(106, 14);
            this.lblUpdateUser.TabIndex = 42;
            this.lblUpdateUser.Text = "Update User";
            // 
            // lblCreateTime
            // 
            this.lblCreateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateTime.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblCreateTime.Location = new System.Drawing.Point(280, 235);
            this.lblCreateTime.Name = "lblCreateTime";
            this.lblCreateTime.Size = new System.Drawing.Size(106, 14);
            this.lblCreateTime.TabIndex = 40;
            this.lblCreateTime.Text = "Create Time";
            // 
            // lblCreateUser
            // 
            this.lblCreateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateUser.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblCreateUser.Location = new System.Drawing.Point(280, 211);
            this.lblCreateUser.Name = "lblCreateUser";
            this.lblCreateUser.Size = new System.Drawing.Size(106, 14);
            this.lblCreateUser.TabIndex = 38;
            this.lblCreateUser.Text = "Create User";
            // 
            // txtUpdateTime
            // 
            this.txtUpdateTime.Location = new System.Drawing.Point(388, 280);
            this.txtUpdateTime.MaxLength = 20;
            this.txtUpdateTime.Name = "txtUpdateTime";
            this.txtUpdateTime.ReadOnly = true;
            this.txtUpdateTime.Size = new System.Drawing.Size(152, 19);
            this.txtUpdateTime.TabIndex = 22;
            this.txtUpdateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCreateTime
            // 
            this.txtCreateTime.Location = new System.Drawing.Point(388, 232);
            this.txtCreateTime.MaxLength = 20;
            this.txtCreateTime.Name = "txtCreateTime";
            this.txtCreateTime.ReadOnly = true;
            this.txtCreateTime.Size = new System.Drawing.Size(152, 19);
            this.txtCreateTime.TabIndex = 20;
            this.txtCreateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtUpdateUser
            // 
            this.txtUpdateUser.Location = new System.Drawing.Point(388, 256);
            this.txtUpdateUser.MaxLength = 20;
            this.txtUpdateUser.Name = "txtUpdateUser";
            this.txtUpdateUser.ReadOnly = true;
            this.txtUpdateUser.Size = new System.Drawing.Size(152, 19);
            this.txtUpdateUser.TabIndex = 21;
            this.txtUpdateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCreateUser
            // 
            this.txtCreateUser.Location = new System.Drawing.Point(388, 208);
            this.txtCreateUser.MaxLength = 20;
            this.txtCreateUser.Name = "txtCreateUser";
            this.txtCreateUser.ReadOnly = true;
            this.txtCreateUser.Size = new System.Drawing.Size(152, 19);
            this.txtCreateUser.TabIndex = 19;
            this.txtCreateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLocation
            // 
            this.txtLocation.Location = new System.Drawing.Point(120, 209);
            this.txtLocation.MaxLength = 20;
            this.txtLocation.Name = "txtLocation";
            this.txtLocation.ReadOnly = true;
            this.txtLocation.Size = new System.Drawing.Size(152, 19);
            this.txtLocation.TabIndex = 8;
            this.txtLocation.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtMaxProcCount
            // 
            this.txtMaxProcCount.Location = new System.Drawing.Point(120, 137);
            this.txtMaxProcCount.MaxLength = 3;
            this.txtMaxProcCount.Name = "txtMaxProcCount";
            this.txtMaxProcCount.ReadOnly = true;
            this.txtMaxProcCount.Size = new System.Drawing.Size(152, 19);
            this.txtMaxProcCount.TabIndex = 5;
            this.txtMaxProcCount.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblProcMode
            // 
            this.lblProcMode.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblProcMode.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblProcMode.Location = new System.Drawing.Point(12, 235);
            this.lblProcMode.Name = "lblProcMode";
            this.lblProcMode.Size = new System.Drawing.Size(106, 14);
            this.lblProcMode.TabIndex = 20;
            this.lblProcMode.Text = "Proc Mode";
            // 
            // lblLocation
            // 
            this.lblLocation.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLocation.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLocation.Location = new System.Drawing.Point(12, 211);
            this.lblLocation.Name = "lblLocation";
            this.lblLocation.Size = new System.Drawing.Size(106, 14);
            this.lblLocation.TabIndex = 18;
            this.lblLocation.Text = "Location";
            // 
            // lblSubAreaID
            // 
            this.lblSubAreaID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSubAreaID.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblSubAreaID.Location = new System.Drawing.Point(12, 187);
            this.lblSubAreaID.Name = "lblSubAreaID";
            this.lblSubAreaID.Size = new System.Drawing.Size(106, 14);
            this.lblSubAreaID.TabIndex = 16;
            this.lblSubAreaID.Text = "Sub Area ID";
            // 
            // lblAreaID
            // 
            this.lblAreaID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblAreaID.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblAreaID.Location = new System.Drawing.Point(12, 163);
            this.lblAreaID.Name = "lblAreaID";
            this.lblAreaID.Size = new System.Drawing.Size(106, 14);
            this.lblAreaID.TabIndex = 14;
            this.lblAreaID.Text = "Area ID";
            // 
            // lblMaxProcCount
            // 
            this.lblMaxProcCount.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblMaxProcCount.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblMaxProcCount.Location = new System.Drawing.Point(12, 139);
            this.lblMaxProcCount.Name = "lblMaxProcCount";
            this.lblMaxProcCount.Size = new System.Drawing.Size(106, 14);
            this.lblMaxProcCount.TabIndex = 12;
            this.lblMaxProcCount.Text = "Max Proc Count";
            // 
            // lblProcRule
            // 
            this.lblProcRule.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblProcRule.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblProcRule.Location = new System.Drawing.Point(12, 115);
            this.lblProcRule.Name = "lblProcRule";
            this.lblProcRule.Size = new System.Drawing.Size(106, 14);
            this.lblProcRule.TabIndex = 10;
            this.lblProcRule.Text = "Process Rule";
            // 
            // lblResType
            // 
            this.lblResType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResType.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblResType.Location = new System.Drawing.Point(12, 91);
            this.lblResType.Name = "lblResType";
            this.lblResType.Size = new System.Drawing.Size(106, 14);
            this.lblResType.TabIndex = 6;
            this.lblResType.Text = "Resource Type";
            // 
            // tbpCMF
            // 
            this.tbpCMF.Controls.Add(this.grpCMF);
            this.tbpCMF.Location = new System.Drawing.Point(4, 22);
            this.tbpCMF.Name = "tbpCMF";
            this.tbpCMF.Padding = new System.Windows.Forms.Padding(3, 0, 3, 3);
            this.tbpCMF.Size = new System.Drawing.Size(728, 387);
            this.tbpCMF.TabIndex = 2;
            this.tbpCMF.Text = "Customized Field";
            this.tbpCMF.Visible = false;
            // 
            // grpCMF
            // 
            this.grpCMF.Controls.Add(this.txtCMF20);
            this.grpCMF.Controls.Add(this.txtCMF19);
            this.grpCMF.Controls.Add(this.txtCMF18);
            this.grpCMF.Controls.Add(this.txtCMF17);
            this.grpCMF.Controls.Add(this.txtCMF16);
            this.grpCMF.Controls.Add(this.txtCMF15);
            this.grpCMF.Controls.Add(this.txtCMF14);
            this.grpCMF.Controls.Add(this.txtCMF13);
            this.grpCMF.Controls.Add(this.txtCMF12);
            this.grpCMF.Controls.Add(this.txtCMF11);
            this.grpCMF.Controls.Add(this.lblCMF20);
            this.grpCMF.Controls.Add(this.lblCMF19);
            this.grpCMF.Controls.Add(this.lblCMF18);
            this.grpCMF.Controls.Add(this.lblCMF17);
            this.grpCMF.Controls.Add(this.lblCMF16);
            this.grpCMF.Controls.Add(this.lblCMF15);
            this.grpCMF.Controls.Add(this.lblCMF14);
            this.grpCMF.Controls.Add(this.lblCMF13);
            this.grpCMF.Controls.Add(this.lblCMF12);
            this.grpCMF.Controls.Add(this.lblCMF11);
            this.grpCMF.Controls.Add(this.txtCMF10);
            this.grpCMF.Controls.Add(this.txtCMF9);
            this.grpCMF.Controls.Add(this.txtCMF8);
            this.grpCMF.Controls.Add(this.txtCMF7);
            this.grpCMF.Controls.Add(this.txtCMF6);
            this.grpCMF.Controls.Add(this.txtCMF5);
            this.grpCMF.Controls.Add(this.txtCMF4);
            this.grpCMF.Controls.Add(this.txtCMF3);
            this.grpCMF.Controls.Add(this.txtCMF2);
            this.grpCMF.Controls.Add(this.txtCMF1);
            this.grpCMF.Controls.Add(this.lblCMF10);
            this.grpCMF.Controls.Add(this.lblCMF9);
            this.grpCMF.Controls.Add(this.lblCMF8);
            this.grpCMF.Controls.Add(this.lblCMF7);
            this.grpCMF.Controls.Add(this.lblCMF6);
            this.grpCMF.Controls.Add(this.lblCMF5);
            this.grpCMF.Controls.Add(this.lblCMF4);
            this.grpCMF.Controls.Add(this.lblCMF3);
            this.grpCMF.Controls.Add(this.lblCMF2);
            this.grpCMF.Controls.Add(this.lblCMF1);
            this.grpCMF.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpCMF.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpCMF.Location = new System.Drawing.Point(3, 0);
            this.grpCMF.Name = "grpCMF";
            this.grpCMF.Size = new System.Drawing.Size(722, 384);
            this.grpCMF.TabIndex = 0;
            this.grpCMF.TabStop = false;
            // 
            // txtCMF20
            // 
            this.txtCMF20.Location = new System.Drawing.Point(523, 233);
            this.txtCMF20.MaxLength = 30;
            this.txtCMF20.Name = "txtCMF20";
            this.txtCMF20.ReadOnly = true;
            this.txtCMF20.Size = new System.Drawing.Size(179, 19);
            this.txtCMF20.TabIndex = 33;
            this.txtCMF20.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF19
            // 
            this.txtCMF19.Location = new System.Drawing.Point(523, 209);
            this.txtCMF19.MaxLength = 30;
            this.txtCMF19.Name = "txtCMF19";
            this.txtCMF19.ReadOnly = true;
            this.txtCMF19.Size = new System.Drawing.Size(179, 19);
            this.txtCMF19.TabIndex = 32;
            this.txtCMF19.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF18
            // 
            this.txtCMF18.Location = new System.Drawing.Point(523, 185);
            this.txtCMF18.MaxLength = 30;
            this.txtCMF18.Name = "txtCMF18";
            this.txtCMF18.ReadOnly = true;
            this.txtCMF18.Size = new System.Drawing.Size(179, 19);
            this.txtCMF18.TabIndex = 30;
            this.txtCMF18.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF17
            // 
            this.txtCMF17.Location = new System.Drawing.Point(523, 161);
            this.txtCMF17.MaxLength = 30;
            this.txtCMF17.Name = "txtCMF17";
            this.txtCMF17.ReadOnly = true;
            this.txtCMF17.Size = new System.Drawing.Size(179, 19);
            this.txtCMF17.TabIndex = 29;
            this.txtCMF17.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF16
            // 
            this.txtCMF16.Location = new System.Drawing.Point(523, 137);
            this.txtCMF16.MaxLength = 30;
            this.txtCMF16.Name = "txtCMF16";
            this.txtCMF16.ReadOnly = true;
            this.txtCMF16.Size = new System.Drawing.Size(179, 19);
            this.txtCMF16.TabIndex = 27;
            this.txtCMF16.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF15
            // 
            this.txtCMF15.Location = new System.Drawing.Point(523, 113);
            this.txtCMF15.MaxLength = 30;
            this.txtCMF15.Name = "txtCMF15";
            this.txtCMF15.ReadOnly = true;
            this.txtCMF15.Size = new System.Drawing.Size(179, 19);
            this.txtCMF15.TabIndex = 26;
            this.txtCMF15.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF14
            // 
            this.txtCMF14.Location = new System.Drawing.Point(523, 89);
            this.txtCMF14.MaxLength = 30;
            this.txtCMF14.Name = "txtCMF14";
            this.txtCMF14.ReadOnly = true;
            this.txtCMF14.Size = new System.Drawing.Size(179, 19);
            this.txtCMF14.TabIndex = 24;
            this.txtCMF14.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF13
            // 
            this.txtCMF13.Location = new System.Drawing.Point(523, 65);
            this.txtCMF13.MaxLength = 30;
            this.txtCMF13.Name = "txtCMF13";
            this.txtCMF13.ReadOnly = true;
            this.txtCMF13.Size = new System.Drawing.Size(179, 19);
            this.txtCMF13.TabIndex = 22;
            this.txtCMF13.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF12
            // 
            this.txtCMF12.Location = new System.Drawing.Point(523, 41);
            this.txtCMF12.MaxLength = 30;
            this.txtCMF12.Name = "txtCMF12";
            this.txtCMF12.ReadOnly = true;
            this.txtCMF12.Size = new System.Drawing.Size(179, 19);
            this.txtCMF12.TabIndex = 21;
            this.txtCMF12.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF11
            // 
            this.txtCMF11.Location = new System.Drawing.Point(523, 17);
            this.txtCMF11.MaxLength = 30;
            this.txtCMF11.Name = "txtCMF11";
            this.txtCMF11.ReadOnly = true;
            this.txtCMF11.Size = new System.Drawing.Size(179, 19);
            this.txtCMF11.TabIndex = 19;
            this.txtCMF11.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblCMF20
            // 
            this.lblCMF20.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF20.Location = new System.Drawing.Point(367, 236);
            this.lblCMF20.Name = "lblCMF20";
            this.lblCMF20.Size = new System.Drawing.Size(150, 14);
            this.lblCMF20.TabIndex = 38;
            // 
            // lblCMF19
            // 
            this.lblCMF19.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF19.Location = new System.Drawing.Point(367, 212);
            this.lblCMF19.Name = "lblCMF19";
            this.lblCMF19.Size = new System.Drawing.Size(150, 14);
            this.lblCMF19.TabIndex = 37;
            // 
            // lblCMF18
            // 
            this.lblCMF18.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF18.Location = new System.Drawing.Point(367, 188);
            this.lblCMF18.Name = "lblCMF18";
            this.lblCMF18.Size = new System.Drawing.Size(150, 14);
            this.lblCMF18.TabIndex = 36;
            // 
            // lblCMF17
            // 
            this.lblCMF17.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF17.Location = new System.Drawing.Point(367, 164);
            this.lblCMF17.Name = "lblCMF17";
            this.lblCMF17.Size = new System.Drawing.Size(150, 14);
            this.lblCMF17.TabIndex = 35;
            // 
            // lblCMF16
            // 
            this.lblCMF16.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF16.Location = new System.Drawing.Point(367, 140);
            this.lblCMF16.Name = "lblCMF16";
            this.lblCMF16.Size = new System.Drawing.Size(150, 14);
            this.lblCMF16.TabIndex = 34;
            // 
            // lblCMF15
            // 
            this.lblCMF15.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF15.Location = new System.Drawing.Point(367, 116);
            this.lblCMF15.Name = "lblCMF15";
            this.lblCMF15.Size = new System.Drawing.Size(150, 14);
            this.lblCMF15.TabIndex = 31;
            // 
            // lblCMF14
            // 
            this.lblCMF14.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF14.Location = new System.Drawing.Point(367, 92);
            this.lblCMF14.Name = "lblCMF14";
            this.lblCMF14.Size = new System.Drawing.Size(150, 14);
            this.lblCMF14.TabIndex = 28;
            // 
            // lblCMF13
            // 
            this.lblCMF13.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF13.Location = new System.Drawing.Point(367, 68);
            this.lblCMF13.Name = "lblCMF13";
            this.lblCMF13.Size = new System.Drawing.Size(150, 14);
            this.lblCMF13.TabIndex = 25;
            // 
            // lblCMF12
            // 
            this.lblCMF12.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF12.Location = new System.Drawing.Point(367, 44);
            this.lblCMF12.Name = "lblCMF12";
            this.lblCMF12.Size = new System.Drawing.Size(150, 14);
            this.lblCMF12.TabIndex = 23;
            // 
            // lblCMF11
            // 
            this.lblCMF11.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF11.Location = new System.Drawing.Point(366, 20);
            this.lblCMF11.Name = "lblCMF11";
            this.lblCMF11.Size = new System.Drawing.Size(150, 14);
            this.lblCMF11.TabIndex = 20;
            // 
            // txtCMF10
            // 
            this.txtCMF10.Location = new System.Drawing.Point(172, 232);
            this.txtCMF10.MaxLength = 30;
            this.txtCMF10.Name = "txtCMF10";
            this.txtCMF10.ReadOnly = true;
            this.txtCMF10.Size = new System.Drawing.Size(179, 19);
            this.txtCMF10.TabIndex = 9;
            this.txtCMF10.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF9
            // 
            this.txtCMF9.Location = new System.Drawing.Point(172, 208);
            this.txtCMF9.MaxLength = 30;
            this.txtCMF9.Name = "txtCMF9";
            this.txtCMF9.ReadOnly = true;
            this.txtCMF9.Size = new System.Drawing.Size(179, 19);
            this.txtCMF9.TabIndex = 8;
            this.txtCMF9.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF8
            // 
            this.txtCMF8.Location = new System.Drawing.Point(172, 184);
            this.txtCMF8.MaxLength = 30;
            this.txtCMF8.Name = "txtCMF8";
            this.txtCMF8.ReadOnly = true;
            this.txtCMF8.Size = new System.Drawing.Size(179, 19);
            this.txtCMF8.TabIndex = 7;
            this.txtCMF8.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF7
            // 
            this.txtCMF7.Location = new System.Drawing.Point(172, 160);
            this.txtCMF7.MaxLength = 30;
            this.txtCMF7.Name = "txtCMF7";
            this.txtCMF7.ReadOnly = true;
            this.txtCMF7.Size = new System.Drawing.Size(179, 19);
            this.txtCMF7.TabIndex = 6;
            this.txtCMF7.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF6
            // 
            this.txtCMF6.Location = new System.Drawing.Point(172, 136);
            this.txtCMF6.MaxLength = 30;
            this.txtCMF6.Name = "txtCMF6";
            this.txtCMF6.ReadOnly = true;
            this.txtCMF6.Size = new System.Drawing.Size(179, 19);
            this.txtCMF6.TabIndex = 5;
            this.txtCMF6.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF5
            // 
            this.txtCMF5.Location = new System.Drawing.Point(172, 112);
            this.txtCMF5.MaxLength = 30;
            this.txtCMF5.Name = "txtCMF5";
            this.txtCMF5.ReadOnly = true;
            this.txtCMF5.Size = new System.Drawing.Size(179, 19);
            this.txtCMF5.TabIndex = 4;
            this.txtCMF5.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF4
            // 
            this.txtCMF4.Location = new System.Drawing.Point(172, 88);
            this.txtCMF4.MaxLength = 30;
            this.txtCMF4.Name = "txtCMF4";
            this.txtCMF4.ReadOnly = true;
            this.txtCMF4.Size = new System.Drawing.Size(179, 19);
            this.txtCMF4.TabIndex = 3;
            this.txtCMF4.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF3
            // 
            this.txtCMF3.Location = new System.Drawing.Point(172, 64);
            this.txtCMF3.MaxLength = 30;
            this.txtCMF3.Name = "txtCMF3";
            this.txtCMF3.ReadOnly = true;
            this.txtCMF3.Size = new System.Drawing.Size(179, 19);
            this.txtCMF3.TabIndex = 2;
            this.txtCMF3.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF2
            // 
            this.txtCMF2.Location = new System.Drawing.Point(172, 40);
            this.txtCMF2.MaxLength = 30;
            this.txtCMF2.Name = "txtCMF2";
            this.txtCMF2.ReadOnly = true;
            this.txtCMF2.Size = new System.Drawing.Size(179, 19);
            this.txtCMF2.TabIndex = 1;
            this.txtCMF2.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCMF1
            // 
            this.txtCMF1.Location = new System.Drawing.Point(172, 16);
            this.txtCMF1.MaxLength = 30;
            this.txtCMF1.Name = "txtCMF1";
            this.txtCMF1.ReadOnly = true;
            this.txtCMF1.Size = new System.Drawing.Size(179, 19);
            this.txtCMF1.TabIndex = 0;
            this.txtCMF1.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblCMF10
            // 
            this.lblCMF10.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF10.Location = new System.Drawing.Point(16, 235);
            this.lblCMF10.Name = "lblCMF10";
            this.lblCMF10.Size = new System.Drawing.Size(150, 14);
            this.lblCMF10.TabIndex = 18;
            // 
            // lblCMF9
            // 
            this.lblCMF9.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF9.Location = new System.Drawing.Point(16, 211);
            this.lblCMF9.Name = "lblCMF9";
            this.lblCMF9.Size = new System.Drawing.Size(150, 14);
            this.lblCMF9.TabIndex = 16;
            // 
            // lblCMF8
            // 
            this.lblCMF8.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF8.Location = new System.Drawing.Point(16, 187);
            this.lblCMF8.Name = "lblCMF8";
            this.lblCMF8.Size = new System.Drawing.Size(150, 14);
            this.lblCMF8.TabIndex = 14;
            // 
            // lblCMF7
            // 
            this.lblCMF7.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF7.Location = new System.Drawing.Point(16, 163);
            this.lblCMF7.Name = "lblCMF7";
            this.lblCMF7.Size = new System.Drawing.Size(150, 14);
            this.lblCMF7.TabIndex = 12;
            // 
            // lblCMF6
            // 
            this.lblCMF6.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF6.Location = new System.Drawing.Point(16, 139);
            this.lblCMF6.Name = "lblCMF6";
            this.lblCMF6.Size = new System.Drawing.Size(150, 14);
            this.lblCMF6.TabIndex = 10;
            // 
            // lblCMF5
            // 
            this.lblCMF5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF5.Location = new System.Drawing.Point(16, 115);
            this.lblCMF5.Name = "lblCMF5";
            this.lblCMF5.Size = new System.Drawing.Size(150, 14);
            this.lblCMF5.TabIndex = 8;
            // 
            // lblCMF4
            // 
            this.lblCMF4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF4.Location = new System.Drawing.Point(16, 91);
            this.lblCMF4.Name = "lblCMF4";
            this.lblCMF4.Size = new System.Drawing.Size(150, 14);
            this.lblCMF4.TabIndex = 6;
            // 
            // lblCMF3
            // 
            this.lblCMF3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF3.Location = new System.Drawing.Point(16, 67);
            this.lblCMF3.Name = "lblCMF3";
            this.lblCMF3.Size = new System.Drawing.Size(150, 14);
            this.lblCMF3.TabIndex = 4;
            // 
            // lblCMF2
            // 
            this.lblCMF2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF2.Location = new System.Drawing.Point(16, 43);
            this.lblCMF2.Name = "lblCMF2";
            this.lblCMF2.Size = new System.Drawing.Size(150, 14);
            this.lblCMF2.TabIndex = 2;
            // 
            // lblCMF1
            // 
            this.lblCMF1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCMF1.Location = new System.Drawing.Point(15, 19);
            this.lblCMF1.Name = "lblCMF1";
            this.lblCMF1.Size = new System.Drawing.Size(150, 14);
            this.lblCMF1.TabIndex = 0;
            // 
            // tbpLotList
            // 
            this.tbpLotList.Controls.Add(this.grpLotList);
            this.tbpLotList.Location = new System.Drawing.Point(4, 22);
            this.tbpLotList.Name = "tbpLotList";
            this.tbpLotList.Padding = new System.Windows.Forms.Padding(3, 0, 3, 3);
            this.tbpLotList.Size = new System.Drawing.Size(728, 387);
            this.tbpLotList.TabIndex = 4;
            this.tbpLotList.Text = "Lot List";
            this.tbpLotList.Visible = false;
            // 
            // grpLotList
            // 
            this.grpLotList.Controls.Add(this.lisLotList);
            this.grpLotList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpLotList.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpLotList.Location = new System.Drawing.Point(3, 0);
            this.grpLotList.Name = "grpLotList";
            this.grpLotList.Size = new System.Drawing.Size(722, 384);
            this.grpLotList.TabIndex = 0;
            this.grpLotList.TabStop = false;
            // 
            // lisLotList
            // 
            this.lisLotList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader1,
            this.ColumnHeader2,
            this.ColumnHeader3,
            this.columnHeader14,
            this.ColumnHeader4,
            this.columnHeader15,
            this.ColumnHeader5,
            this.ColumnHeader6,
            this.ColumnHeader7,
            this.ColumnHeader8,
            this.ColumnHeader9,
            this.ColumnHeader10,
            this.ColumnHeader11,
            this.ColumnHeader12,
            this.ColumnHeader13});
            this.lisLotList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisLotList.EnableSort = true;
            this.lisLotList.EnableSortIcon = true;
            this.lisLotList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisLotList.FullRowSelect = true;
            this.lisLotList.Location = new System.Drawing.Point(3, 16);
            this.lisLotList.Name = "lisLotList";
            this.lisLotList.Size = new System.Drawing.Size(716, 365);
            this.lisLotList.TabIndex = 0;
            this.lisLotList.Tag = "True";
            this.lisLotList.UseCompatibleStateImageBehavior = false;
            this.lisLotList.View = System.Windows.Forms.View.Details;
            this.lisLotList.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(this.lisLotList_ColumnClick);
            // 
            // ColumnHeader1
            // 
            this.ColumnHeader1.Text = "Lot ID";
            this.ColumnHeader1.Width = 100;
            // 
            // ColumnHeader2
            // 
            this.ColumnHeader2.Text = "Lot Status";
            this.ColumnHeader2.Width = 70;
            // 
            // ColumnHeader3
            // 
            this.ColumnHeader3.Text = "Material ID";
            this.ColumnHeader3.Width = 115;
            // 
            // columnHeader14
            // 
            this.columnHeader14.Text = "Material Version";
            this.columnHeader14.Width = 100;
            // 
            // ColumnHeader4
            // 
            this.ColumnHeader4.Text = "Flow";
            this.ColumnHeader4.Width = 80;
            // 
            // columnHeader15
            // 
            this.columnHeader15.Text = "Flow Sequence Number";
            // 
            // ColumnHeader5
            // 
            this.ColumnHeader5.Text = "Operation";
            this.ColumnHeader5.Width = 80;
            // 
            // ColumnHeader6
            // 
            this.ColumnHeader6.Text = "Qty1";
            this.ColumnHeader6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // ColumnHeader7
            // 
            this.ColumnHeader7.Text = "Qty2";
            this.ColumnHeader7.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // ColumnHeader8
            // 
            this.ColumnHeader8.Text = "Qty3";
            this.ColumnHeader8.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // ColumnHeader9
            // 
            this.ColumnHeader9.Text = "Lot Type";
            // 
            // ColumnHeader10
            // 
            this.ColumnHeader10.Text = "Lot Priority";
            this.ColumnHeader10.Width = 80;
            // 
            // ColumnHeader11
            // 
            this.ColumnHeader11.Text = "Create Code";
            this.ColumnHeader11.Width = 90;
            // 
            // ColumnHeader12
            // 
            this.ColumnHeader12.Text = "Owner Code";
            this.ColumnHeader12.Width = 90;
            // 
            // ColumnHeader13
            // 
            this.ColumnHeader13.Text = "Hold Code";
            this.ColumnHeader13.Width = 90;
            // 
            // tbpResSts
            // 
            this.tbpResSts.Controls.Add(this.grpResStatus);
            this.tbpResSts.Location = new System.Drawing.Point(4, 22);
            this.tbpResSts.Name = "tbpResSts";
            this.tbpResSts.Padding = new System.Windows.Forms.Padding(3, 0, 3, 3);
            this.tbpResSts.Size = new System.Drawing.Size(728, 387);
            this.tbpResSts.TabIndex = 3;
            this.tbpResSts.Text = "Resource Status";
            this.tbpResSts.Visible = false;
            // 
            // grpResStatus
            // 
            this.grpResStatus.Controls.Add(this.lblUseFactory);
            this.grpResStatus.Controls.Add(this.chkUseFacPrtFlag);
            this.grpResStatus.Controls.Add(this.txtSts10);
            this.grpResStatus.Controls.Add(this.txtSts9);
            this.grpResStatus.Controls.Add(this.txtSts8);
            this.grpResStatus.Controls.Add(this.txtSts7);
            this.grpResStatus.Controls.Add(this.txtSts6);
            this.grpResStatus.Controls.Add(this.txtSts5);
            this.grpResStatus.Controls.Add(this.txtSts4);
            this.grpResStatus.Controls.Add(this.txtSts3);
            this.grpResStatus.Controls.Add(this.txtSts2);
            this.grpResStatus.Controls.Add(this.txtSts1);
            this.grpResStatus.Controls.Add(this.lblSts10);
            this.grpResStatus.Controls.Add(this.lblSts9);
            this.grpResStatus.Controls.Add(this.lblSts8);
            this.grpResStatus.Controls.Add(this.lblSts7);
            this.grpResStatus.Controls.Add(this.lblSts6);
            this.grpResStatus.Controls.Add(this.lblSts5);
            this.grpResStatus.Controls.Add(this.lblSts4);
            this.grpResStatus.Controls.Add(this.lblSts3);
            this.grpResStatus.Controls.Add(this.lblSts2);
            this.grpResStatus.Controls.Add(this.lblSts1);
            this.grpResStatus.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpResStatus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpResStatus.Location = new System.Drawing.Point(3, 0);
            this.grpResStatus.Name = "grpResStatus";
            this.grpResStatus.Size = new System.Drawing.Size(722, 384);
            this.grpResStatus.TabIndex = 0;
            this.grpResStatus.TabStop = false;
            // 
            // lblUseFactory
            // 
            this.lblUseFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUseFactory.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblUseFactory.Location = new System.Drawing.Point(32, 19);
            this.lblUseFactory.Name = "lblUseFactory";
            this.lblUseFactory.Size = new System.Drawing.Size(154, 14);
            this.lblUseFactory.TabIndex = 0;
            this.lblUseFactory.Text = "Use Factory Prompt Flag";
            // 
            // chkUseFacPrtFlag
            // 
            this.chkUseFacPrtFlag.Enabled = false;
            this.chkUseFacPrtFlag.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkUseFacPrtFlag.Location = new System.Drawing.Point(15, 19);
            this.chkUseFacPrtFlag.Name = "chkUseFacPrtFlag";
            this.chkUseFacPrtFlag.Size = new System.Drawing.Size(13, 14);
            this.chkUseFacPrtFlag.TabIndex = 0;
            this.chkUseFacPrtFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts10
            // 
            this.txtSts10.Location = new System.Drawing.Point(172, 256);
            this.txtSts10.MaxLength = 30;
            this.txtSts10.Name = "txtSts10";
            this.txtSts10.ReadOnly = true;
            this.txtSts10.Size = new System.Drawing.Size(200, 19);
            this.txtSts10.TabIndex = 10;
            this.txtSts10.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts9
            // 
            this.txtSts9.Location = new System.Drawing.Point(172, 232);
            this.txtSts9.MaxLength = 30;
            this.txtSts9.Name = "txtSts9";
            this.txtSts9.ReadOnly = true;
            this.txtSts9.Size = new System.Drawing.Size(200, 19);
            this.txtSts9.TabIndex = 9;
            this.txtSts9.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts8
            // 
            this.txtSts8.Location = new System.Drawing.Point(172, 208);
            this.txtSts8.MaxLength = 30;
            this.txtSts8.Name = "txtSts8";
            this.txtSts8.ReadOnly = true;
            this.txtSts8.Size = new System.Drawing.Size(200, 19);
            this.txtSts8.TabIndex = 8;
            this.txtSts8.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts7
            // 
            this.txtSts7.Location = new System.Drawing.Point(172, 184);
            this.txtSts7.MaxLength = 30;
            this.txtSts7.Name = "txtSts7";
            this.txtSts7.ReadOnly = true;
            this.txtSts7.Size = new System.Drawing.Size(200, 19);
            this.txtSts7.TabIndex = 7;
            this.txtSts7.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts6
            // 
            this.txtSts6.Location = new System.Drawing.Point(172, 160);
            this.txtSts6.MaxLength = 30;
            this.txtSts6.Name = "txtSts6";
            this.txtSts6.ReadOnly = true;
            this.txtSts6.Size = new System.Drawing.Size(200, 19);
            this.txtSts6.TabIndex = 6;
            this.txtSts6.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts5
            // 
            this.txtSts5.Location = new System.Drawing.Point(172, 136);
            this.txtSts5.MaxLength = 30;
            this.txtSts5.Name = "txtSts5";
            this.txtSts5.ReadOnly = true;
            this.txtSts5.Size = new System.Drawing.Size(200, 19);
            this.txtSts5.TabIndex = 5;
            this.txtSts5.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts4
            // 
            this.txtSts4.Location = new System.Drawing.Point(172, 112);
            this.txtSts4.MaxLength = 30;
            this.txtSts4.Name = "txtSts4";
            this.txtSts4.ReadOnly = true;
            this.txtSts4.Size = new System.Drawing.Size(200, 19);
            this.txtSts4.TabIndex = 4;
            this.txtSts4.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts3
            // 
            this.txtSts3.Location = new System.Drawing.Point(172, 88);
            this.txtSts3.MaxLength = 30;
            this.txtSts3.Name = "txtSts3";
            this.txtSts3.ReadOnly = true;
            this.txtSts3.Size = new System.Drawing.Size(200, 19);
            this.txtSts3.TabIndex = 3;
            this.txtSts3.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts2
            // 
            this.txtSts2.Location = new System.Drawing.Point(172, 64);
            this.txtSts2.MaxLength = 30;
            this.txtSts2.Name = "txtSts2";
            this.txtSts2.ReadOnly = true;
            this.txtSts2.Size = new System.Drawing.Size(200, 19);
            this.txtSts2.TabIndex = 2;
            this.txtSts2.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSts1
            // 
            this.txtSts1.Location = new System.Drawing.Point(172, 40);
            this.txtSts1.MaxLength = 30;
            this.txtSts1.Name = "txtSts1";
            this.txtSts1.ReadOnly = true;
            this.txtSts1.Size = new System.Drawing.Size(200, 19);
            this.txtSts1.TabIndex = 1;
            this.txtSts1.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblSts10
            // 
            this.lblSts10.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts10.Location = new System.Drawing.Point(16, 259);
            this.lblSts10.Name = "lblSts10";
            this.lblSts10.Size = new System.Drawing.Size(150, 14);
            this.lblSts10.TabIndex = 19;
            // 
            // lblSts9
            // 
            this.lblSts9.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts9.Location = new System.Drawing.Point(16, 235);
            this.lblSts9.Name = "lblSts9";
            this.lblSts9.Size = new System.Drawing.Size(150, 14);
            this.lblSts9.TabIndex = 17;
            // 
            // lblSts8
            // 
            this.lblSts8.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts8.Location = new System.Drawing.Point(16, 211);
            this.lblSts8.Name = "lblSts8";
            this.lblSts8.Size = new System.Drawing.Size(150, 14);
            this.lblSts8.TabIndex = 15;
            // 
            // lblSts7
            // 
            this.lblSts7.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts7.Location = new System.Drawing.Point(16, 187);
            this.lblSts7.Name = "lblSts7";
            this.lblSts7.Size = new System.Drawing.Size(150, 14);
            this.lblSts7.TabIndex = 13;
            // 
            // lblSts6
            // 
            this.lblSts6.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts6.Location = new System.Drawing.Point(16, 163);
            this.lblSts6.Name = "lblSts6";
            this.lblSts6.Size = new System.Drawing.Size(150, 14);
            this.lblSts6.TabIndex = 11;
            // 
            // lblSts5
            // 
            this.lblSts5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts5.Location = new System.Drawing.Point(16, 139);
            this.lblSts5.Name = "lblSts5";
            this.lblSts5.Size = new System.Drawing.Size(150, 14);
            this.lblSts5.TabIndex = 9;
            // 
            // lblSts4
            // 
            this.lblSts4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts4.Location = new System.Drawing.Point(16, 115);
            this.lblSts4.Name = "lblSts4";
            this.lblSts4.Size = new System.Drawing.Size(150, 14);
            this.lblSts4.TabIndex = 7;
            // 
            // lblSts3
            // 
            this.lblSts3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts3.Location = new System.Drawing.Point(16, 91);
            this.lblSts3.Name = "lblSts3";
            this.lblSts3.Size = new System.Drawing.Size(150, 14);
            this.lblSts3.TabIndex = 5;
            // 
            // lblSts2
            // 
            this.lblSts2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts2.Location = new System.Drawing.Point(16, 67);
            this.lblSts2.Name = "lblSts2";
            this.lblSts2.Size = new System.Drawing.Size(150, 14);
            this.lblSts2.TabIndex = 3;
            // 
            // lblSts1
            // 
            this.lblSts1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSts1.Location = new System.Drawing.Point(15, 43);
            this.lblSts1.Name = "lblSts1";
            this.lblSts1.Size = new System.Drawing.Size(150, 14);
            this.lblSts1.TabIndex = 1;
            // 
            // tbpResGrp
            // 
            this.tbpResGrp.Controls.Add(this.grpGrp);
            this.tbpResGrp.Location = new System.Drawing.Point(4, 22);
            this.tbpResGrp.Name = "tbpResGrp";
            this.tbpResGrp.Padding = new System.Windows.Forms.Padding(3, 0, 3, 3);
            this.tbpResGrp.Size = new System.Drawing.Size(728, 387);
            this.tbpResGrp.TabIndex = 1;
            this.tbpResGrp.Text = "Resource Group";
            this.tbpResGrp.Visible = false;
            // 
            // grpGrp
            // 
            this.grpGrp.Controls.Add(this.txtGrp10);
            this.grpGrp.Controls.Add(this.txtGrp9);
            this.grpGrp.Controls.Add(this.txtGrp8);
            this.grpGrp.Controls.Add(this.txtGrp7);
            this.grpGrp.Controls.Add(this.txtGrp6);
            this.grpGrp.Controls.Add(this.txtGrp5);
            this.grpGrp.Controls.Add(this.txtGrp4);
            this.grpGrp.Controls.Add(this.txtGrp3);
            this.grpGrp.Controls.Add(this.txtGrp2);
            this.grpGrp.Controls.Add(this.txtGrp1);
            this.grpGrp.Controls.Add(this.lblGrp10);
            this.grpGrp.Controls.Add(this.lblGrp9);
            this.grpGrp.Controls.Add(this.lblGrp8);
            this.grpGrp.Controls.Add(this.lblGrp7);
            this.grpGrp.Controls.Add(this.lblGrp6);
            this.grpGrp.Controls.Add(this.lblGrp5);
            this.grpGrp.Controls.Add(this.lblGrp4);
            this.grpGrp.Controls.Add(this.lblGrp3);
            this.grpGrp.Controls.Add(this.lblGrp2);
            this.grpGrp.Controls.Add(this.lblGrp1);
            this.grpGrp.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpGrp.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpGrp.Location = new System.Drawing.Point(3, 0);
            this.grpGrp.Name = "grpGrp";
            this.grpGrp.Size = new System.Drawing.Size(722, 384);
            this.grpGrp.TabIndex = 0;
            this.grpGrp.TabStop = false;
            // 
            // txtGrp10
            // 
            this.txtGrp10.Location = new System.Drawing.Point(172, 232);
            this.txtGrp10.MaxLength = 20;
            this.txtGrp10.Name = "txtGrp10";
            this.txtGrp10.ReadOnly = true;
            this.txtGrp10.Size = new System.Drawing.Size(200, 19);
            this.txtGrp10.TabIndex = 9;
            this.txtGrp10.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp9
            // 
            this.txtGrp9.Location = new System.Drawing.Point(172, 208);
            this.txtGrp9.MaxLength = 20;
            this.txtGrp9.Name = "txtGrp9";
            this.txtGrp9.ReadOnly = true;
            this.txtGrp9.Size = new System.Drawing.Size(200, 19);
            this.txtGrp9.TabIndex = 8;
            this.txtGrp9.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp8
            // 
            this.txtGrp8.Location = new System.Drawing.Point(172, 184);
            this.txtGrp8.MaxLength = 20;
            this.txtGrp8.Name = "txtGrp8";
            this.txtGrp8.ReadOnly = true;
            this.txtGrp8.Size = new System.Drawing.Size(200, 19);
            this.txtGrp8.TabIndex = 7;
            this.txtGrp8.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp7
            // 
            this.txtGrp7.Location = new System.Drawing.Point(172, 160);
            this.txtGrp7.MaxLength = 20;
            this.txtGrp7.Name = "txtGrp7";
            this.txtGrp7.ReadOnly = true;
            this.txtGrp7.Size = new System.Drawing.Size(200, 19);
            this.txtGrp7.TabIndex = 6;
            this.txtGrp7.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp6
            // 
            this.txtGrp6.Location = new System.Drawing.Point(172, 136);
            this.txtGrp6.MaxLength = 20;
            this.txtGrp6.Name = "txtGrp6";
            this.txtGrp6.ReadOnly = true;
            this.txtGrp6.Size = new System.Drawing.Size(200, 19);
            this.txtGrp6.TabIndex = 5;
            this.txtGrp6.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp5
            // 
            this.txtGrp5.Location = new System.Drawing.Point(172, 112);
            this.txtGrp5.MaxLength = 20;
            this.txtGrp5.Name = "txtGrp5";
            this.txtGrp5.ReadOnly = true;
            this.txtGrp5.Size = new System.Drawing.Size(200, 19);
            this.txtGrp5.TabIndex = 4;
            this.txtGrp5.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp4
            // 
            this.txtGrp4.Location = new System.Drawing.Point(172, 88);
            this.txtGrp4.MaxLength = 20;
            this.txtGrp4.Name = "txtGrp4";
            this.txtGrp4.ReadOnly = true;
            this.txtGrp4.Size = new System.Drawing.Size(200, 19);
            this.txtGrp4.TabIndex = 3;
            this.txtGrp4.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp3
            // 
            this.txtGrp3.Location = new System.Drawing.Point(172, 64);
            this.txtGrp3.MaxLength = 20;
            this.txtGrp3.Name = "txtGrp3";
            this.txtGrp3.ReadOnly = true;
            this.txtGrp3.Size = new System.Drawing.Size(200, 19);
            this.txtGrp3.TabIndex = 2;
            this.txtGrp3.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp2
            // 
            this.txtGrp2.Location = new System.Drawing.Point(172, 40);
            this.txtGrp2.MaxLength = 20;
            this.txtGrp2.Name = "txtGrp2";
            this.txtGrp2.ReadOnly = true;
            this.txtGrp2.Size = new System.Drawing.Size(200, 19);
            this.txtGrp2.TabIndex = 1;
            this.txtGrp2.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGrp1
            // 
            this.txtGrp1.Location = new System.Drawing.Point(172, 16);
            this.txtGrp1.MaxLength = 20;
            this.txtGrp1.Name = "txtGrp1";
            this.txtGrp1.ReadOnly = true;
            this.txtGrp1.Size = new System.Drawing.Size(200, 19);
            this.txtGrp1.TabIndex = 0;
            this.txtGrp1.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblGrp10
            // 
            this.lblGrp10.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp10.Location = new System.Drawing.Point(15, 235);
            this.lblGrp10.Name = "lblGrp10";
            this.lblGrp10.Size = new System.Drawing.Size(150, 14);
            this.lblGrp10.TabIndex = 18;
            // 
            // lblGrp9
            // 
            this.lblGrp9.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp9.Location = new System.Drawing.Point(15, 211);
            this.lblGrp9.Name = "lblGrp9";
            this.lblGrp9.Size = new System.Drawing.Size(150, 14);
            this.lblGrp9.TabIndex = 16;
            // 
            // lblGrp8
            // 
            this.lblGrp8.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp8.Location = new System.Drawing.Point(15, 187);
            this.lblGrp8.Name = "lblGrp8";
            this.lblGrp8.Size = new System.Drawing.Size(150, 14);
            this.lblGrp8.TabIndex = 14;
            // 
            // lblGrp7
            // 
            this.lblGrp7.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp7.Location = new System.Drawing.Point(15, 163);
            this.lblGrp7.Name = "lblGrp7";
            this.lblGrp7.Size = new System.Drawing.Size(150, 14);
            this.lblGrp7.TabIndex = 12;
            // 
            // lblGrp6
            // 
            this.lblGrp6.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp6.Location = new System.Drawing.Point(15, 139);
            this.lblGrp6.Name = "lblGrp6";
            this.lblGrp6.Size = new System.Drawing.Size(150, 14);
            this.lblGrp6.TabIndex = 10;
            // 
            // lblGrp5
            // 
            this.lblGrp5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp5.Location = new System.Drawing.Point(15, 115);
            this.lblGrp5.Name = "lblGrp5";
            this.lblGrp5.Size = new System.Drawing.Size(150, 14);
            this.lblGrp5.TabIndex = 8;
            // 
            // lblGrp4
            // 
            this.lblGrp4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp4.Location = new System.Drawing.Point(15, 91);
            this.lblGrp4.Name = "lblGrp4";
            this.lblGrp4.Size = new System.Drawing.Size(150, 14);
            this.lblGrp4.TabIndex = 6;
            // 
            // lblGrp3
            // 
            this.lblGrp3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp3.Location = new System.Drawing.Point(15, 67);
            this.lblGrp3.Name = "lblGrp3";
            this.lblGrp3.Size = new System.Drawing.Size(150, 14);
            this.lblGrp3.TabIndex = 4;
            // 
            // lblGrp2
            // 
            this.lblGrp2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp2.Location = new System.Drawing.Point(15, 43);
            this.lblGrp2.Name = "lblGrp2";
            this.lblGrp2.Size = new System.Drawing.Size(150, 14);
            this.lblGrp2.TabIndex = 2;
            // 
            // lblGrp1
            // 
            this.lblGrp1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGrp1.Location = new System.Drawing.Point(15, 19);
            this.lblGrp1.Name = "lblGrp1";
            this.lblGrp1.Size = new System.Drawing.Size(150, 14);
            this.lblGrp1.TabIndex = 0;
            // 
            // tbpLocation
            // 
            this.tbpLocation.Controls.Add(this.grpLocation);
            this.tbpLocation.Location = new System.Drawing.Point(4, 22);
            this.tbpLocation.Name = "tbpLocation";
            this.tbpLocation.Size = new System.Drawing.Size(728, 387);
            this.tbpLocation.TabIndex = 5;
            this.tbpLocation.Text = "Location Info";
            // 
            // grpLocation
            // 
            this.grpLocation.Controls.Add(this.pctImage);
            this.grpLocation.Controls.Add(this.lblImage);
            this.grpLocation.Controls.Add(this.utcBack);
            this.grpLocation.Controls.Add(this.utcText);
            this.grpLocation.Controls.Add(this.lblLocUpdateTime);
            this.grpLocation.Controls.Add(this.lblLocCreateTime);
            this.grpLocation.Controls.Add(this.txtLocUpdateTime);
            this.grpLocation.Controls.Add(this.txtLocCreateTime);
            this.grpLocation.Controls.Add(this.txtLocUpdateUser);
            this.grpLocation.Controls.Add(this.txtLocCreateUser);
            this.grpLocation.Controls.Add(this.lblLocUpdateUser);
            this.grpLocation.Controls.Add(this.lblCreateUserId);
            this.grpLocation.Controls.Add(this.txtSize);
            this.grpLocation.Controls.Add(this.lblHeight);
            this.grpLocation.Controls.Add(this.lblY);
            this.grpLocation.Controls.Add(this.lblBack);
            this.grpLocation.Controls.Add(this.lblTextStyle);
            this.grpLocation.Controls.Add(this.txtHeight);
            this.grpLocation.Controls.Add(this.txtY);
            this.grpLocation.Controls.Add(this.txtStyle);
            this.grpLocation.Controls.Add(this.txtType);
            this.grpLocation.Controls.Add(this.lblType);
            this.grpLocation.Controls.Add(this.lblTextSize);
            this.grpLocation.Controls.Add(this.txtLayOut);
            this.grpLocation.Controls.Add(this.lblLayOut);
            this.grpLocation.Controls.Add(this.txtText);
            this.grpLocation.Controls.Add(this.lblText);
            this.grpLocation.Controls.Add(this.txtWidth);
            this.grpLocation.Controls.Add(this.txtX);
            this.grpLocation.Controls.Add(this.lblWidth);
            this.grpLocation.Controls.Add(this.lblX);
            this.grpLocation.Controls.Add(this.lblTextColor);
            this.grpLocation.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpLocation.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpLocation.Location = new System.Drawing.Point(0, 0);
            this.grpLocation.Name = "grpLocation";
            this.grpLocation.Size = new System.Drawing.Size(728, 387);
            this.grpLocation.TabIndex = 0;
            this.grpLocation.TabStop = false;
            // 
            // pctImage
            // 
            this.pctImage.Location = new System.Drawing.Point(120, 209);
            this.pctImage.Name = "pctImage";
            this.pctImage.Size = new System.Drawing.Size(32, 32);
            this.pctImage.TabIndex = 57;
            this.pctImage.TabStop = false;
            // 
            // lblImage
            // 
            this.lblImage.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblImage.Location = new System.Drawing.Point(12, 209);
            this.lblImage.Name = "lblImage";
            this.lblImage.Size = new System.Drawing.Size(60, 14);
            this.lblImage.TabIndex = 56;
            this.lblImage.Text = "Image";
            // 
            // utcBack
            // 
            this.utcBack.Location = new System.Drawing.Point(388, 89);
            this.utcBack.Name = "utcBack";
            this.utcBack.ReadOnly = true;
            this.utcBack.Size = new System.Drawing.Size(152, 19);
            this.utcBack.TabIndex = 6;
            this.utcBack.Text = "Control";
            this.utcBack.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // utcText
            // 
            this.utcText.Location = new System.Drawing.Point(120, 89);
            this.utcText.Name = "utcText";
            this.utcText.ReadOnly = true;
            this.utcText.Size = new System.Drawing.Size(152, 19);
            this.utcText.TabIndex = 5;
            this.utcText.Text = "Control";
            this.utcText.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblLocUpdateTime
            // 
            this.lblLocUpdateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLocUpdateTime.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLocUpdateTime.Location = new System.Drawing.Point(280, 186);
            this.lblLocUpdateTime.Name = "lblLocUpdateTime";
            this.lblLocUpdateTime.Size = new System.Drawing.Size(100, 14);
            this.lblLocUpdateTime.TabIndex = 40;
            this.lblLocUpdateTime.Text = "Loc Update Time";
            // 
            // lblLocCreateTime
            // 
            this.lblLocCreateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLocCreateTime.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLocCreateTime.Location = new System.Drawing.Point(280, 162);
            this.lblLocCreateTime.Name = "lblLocCreateTime";
            this.lblLocCreateTime.Size = new System.Drawing.Size(100, 14);
            this.lblLocCreateTime.TabIndex = 38;
            this.lblLocCreateTime.Text = "Loc Create Time";
            // 
            // txtLocUpdateTime
            // 
            this.txtLocUpdateTime.Location = new System.Drawing.Point(388, 184);
            this.txtLocUpdateTime.MaxLength = 20;
            this.txtLocUpdateTime.Name = "txtLocUpdateTime";
            this.txtLocUpdateTime.ReadOnly = true;
            this.txtLocUpdateTime.Size = new System.Drawing.Size(152, 19);
            this.txtLocUpdateTime.TabIndex = 14;
            this.txtLocUpdateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLocCreateTime
            // 
            this.txtLocCreateTime.Location = new System.Drawing.Point(388, 160);
            this.txtLocCreateTime.MaxLength = 20;
            this.txtLocCreateTime.Name = "txtLocCreateTime";
            this.txtLocCreateTime.ReadOnly = true;
            this.txtLocCreateTime.Size = new System.Drawing.Size(152, 19);
            this.txtLocCreateTime.TabIndex = 12;
            this.txtLocCreateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLocUpdateUser
            // 
            this.txtLocUpdateUser.Location = new System.Drawing.Point(120, 184);
            this.txtLocUpdateUser.MaxLength = 20;
            this.txtLocUpdateUser.Name = "txtLocUpdateUser";
            this.txtLocUpdateUser.ReadOnly = true;
            this.txtLocUpdateUser.Size = new System.Drawing.Size(152, 19);
            this.txtLocUpdateUser.TabIndex = 13;
            this.txtLocUpdateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLocCreateUser
            // 
            this.txtLocCreateUser.Location = new System.Drawing.Point(120, 160);
            this.txtLocCreateUser.MaxLength = 20;
            this.txtLocCreateUser.Name = "txtLocCreateUser";
            this.txtLocCreateUser.ReadOnly = true;
            this.txtLocCreateUser.Size = new System.Drawing.Size(152, 19);
            this.txtLocCreateUser.TabIndex = 11;
            this.txtLocCreateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblLocUpdateUser
            // 
            this.lblLocUpdateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLocUpdateUser.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLocUpdateUser.Location = new System.Drawing.Point(12, 186);
            this.lblLocUpdateUser.Name = "lblLocUpdateUser";
            this.lblLocUpdateUser.Size = new System.Drawing.Size(100, 14);
            this.lblLocUpdateUser.TabIndex = 36;
            this.lblLocUpdateUser.Text = "Loc Update User ID";
            // 
            // lblCreateUserId
            // 
            this.lblCreateUserId.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateUserId.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblCreateUserId.Location = new System.Drawing.Point(12, 162);
            this.lblCreateUserId.Name = "lblCreateUserId";
            this.lblCreateUserId.Size = new System.Drawing.Size(100, 14);
            this.lblCreateUserId.TabIndex = 34;
            this.lblCreateUserId.Text = "Loc Create User ID";
            // 
            // txtSize
            // 
            this.txtSize.Location = new System.Drawing.Point(120, 64);
            this.txtSize.MaxLength = 3;
            this.txtSize.Name = "txtSize";
            this.txtSize.ReadOnly = true;
            this.txtSize.Size = new System.Drawing.Size(152, 19);
            this.txtSize.TabIndex = 3;
            this.txtSize.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblHeight
            // 
            this.lblHeight.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHeight.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblHeight.Location = new System.Drawing.Point(280, 139);
            this.lblHeight.Name = "lblHeight";
            this.lblHeight.Size = new System.Drawing.Size(100, 14);
            this.lblHeight.TabIndex = 32;
            this.lblHeight.Text = "Height";
            // 
            // lblY
            // 
            this.lblY.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblY.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblY.Location = new System.Drawing.Point(280, 115);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(100, 14);
            this.lblY.TabIndex = 30;
            this.lblY.Text = "Location Y";
            // 
            // lblBack
            // 
            this.lblBack.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblBack.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblBack.Location = new System.Drawing.Point(280, 91);
            this.lblBack.Name = "lblBack";
            this.lblBack.Size = new System.Drawing.Size(100, 14);
            this.lblBack.TabIndex = 28;
            this.lblBack.Text = "Back Color";
            // 
            // lblTextStyle
            // 
            this.lblTextStyle.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTextStyle.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblTextStyle.Location = new System.Drawing.Point(280, 67);
            this.lblTextStyle.Name = "lblTextStyle";
            this.lblTextStyle.Size = new System.Drawing.Size(100, 14);
            this.lblTextStyle.TabIndex = 26;
            this.lblTextStyle.Text = "Text Style";
            // 
            // txtHeight
            // 
            this.txtHeight.Location = new System.Drawing.Point(388, 136);
            this.txtHeight.MaxLength = 6;
            this.txtHeight.Name = "txtHeight";
            this.txtHeight.ReadOnly = true;
            this.txtHeight.Size = new System.Drawing.Size(152, 19);
            this.txtHeight.TabIndex = 10;
            this.txtHeight.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtY
            // 
            this.txtY.Location = new System.Drawing.Point(388, 112);
            this.txtY.MaxLength = 6;
            this.txtY.Name = "txtY";
            this.txtY.ReadOnly = true;
            this.txtY.Size = new System.Drawing.Size(152, 19);
            this.txtY.TabIndex = 8;
            this.txtY.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtStyle
            // 
            this.txtStyle.Location = new System.Drawing.Point(388, 64);
            this.txtStyle.MaxLength = 20;
            this.txtStyle.Name = "txtStyle";
            this.txtStyle.ReadOnly = true;
            this.txtStyle.Size = new System.Drawing.Size(152, 19);
            this.txtStyle.TabIndex = 4;
            this.txtStyle.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtType
            // 
            this.txtType.Location = new System.Drawing.Point(388, 16);
            this.txtType.MaxLength = 10;
            this.txtType.Name = "txtType";
            this.txtType.ReadOnly = true;
            this.txtType.Size = new System.Drawing.Size(152, 19);
            this.txtType.TabIndex = 1;
            this.txtType.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblType
            // 
            this.lblType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblType.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblType.Location = new System.Drawing.Point(280, 19);
            this.lblType.Name = "lblType";
            this.lblType.Size = new System.Drawing.Size(100, 14);
            this.lblType.TabIndex = 22;
            this.lblType.Text = "Type";
            // 
            // lblTextSize
            // 
            this.lblTextSize.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTextSize.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblTextSize.Location = new System.Drawing.Point(12, 67);
            this.lblTextSize.Name = "lblTextSize";
            this.lblTextSize.Size = new System.Drawing.Size(100, 14);
            this.lblTextSize.TabIndex = 4;
            this.lblTextSize.Text = "Text Font Size";
            // 
            // txtLayOut
            // 
            this.txtLayOut.Location = new System.Drawing.Point(120, 16);
            this.txtLayOut.MaxLength = 20;
            this.txtLayOut.Name = "txtLayOut";
            this.txtLayOut.ReadOnly = true;
            this.txtLayOut.Size = new System.Drawing.Size(152, 19);
            this.txtLayOut.TabIndex = 0;
            this.txtLayOut.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblLayOut
            // 
            this.lblLayOut.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLayOut.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblLayOut.Location = new System.Drawing.Point(12, 19);
            this.lblLayOut.Name = "lblLayOut";
            this.lblLayOut.Size = new System.Drawing.Size(100, 14);
            this.lblLayOut.TabIndex = 0;
            this.lblLayOut.Text = "LayOut ID";
            // 
            // txtText
            // 
            this.txtText.Location = new System.Drawing.Point(120, 40);
            this.txtText.MaxLength = 40;
            this.txtText.Name = "txtText";
            this.txtText.ReadOnly = true;
            this.txtText.Size = new System.Drawing.Size(420, 19);
            this.txtText.TabIndex = 2;
            this.txtText.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblText
            // 
            this.lblText.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblText.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblText.Location = new System.Drawing.Point(12, 43);
            this.lblText.Name = "lblText";
            this.lblText.Size = new System.Drawing.Size(100, 14);
            this.lblText.TabIndex = 2;
            this.lblText.Text = "Text";
            // 
            // txtWidth
            // 
            this.txtWidth.Location = new System.Drawing.Point(120, 136);
            this.txtWidth.MaxLength = 6;
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.ReadOnly = true;
            this.txtWidth.Size = new System.Drawing.Size(152, 19);
            this.txtWidth.TabIndex = 9;
            this.txtWidth.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtX
            // 
            this.txtX.Location = new System.Drawing.Point(120, 112);
            this.txtX.MaxLength = 6;
            this.txtX.Name = "txtX";
            this.txtX.ReadOnly = true;
            this.txtX.Size = new System.Drawing.Size(152, 19);
            this.txtX.TabIndex = 7;
            this.txtX.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblWidth
            // 
            this.lblWidth.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblWidth.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblWidth.Location = new System.Drawing.Point(12, 139);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(100, 14);
            this.lblWidth.TabIndex = 10;
            this.lblWidth.Text = "Width";
            // 
            // lblX
            // 
            this.lblX.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblX.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblX.Location = new System.Drawing.Point(12, 115);
            this.lblX.Name = "lblX";
            this.lblX.Size = new System.Drawing.Size(100, 14);
            this.lblX.TabIndex = 8;
            this.lblX.Text = "Location X";
            // 
            // lblTextColor
            // 
            this.lblTextColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTextColor.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblTextColor.Location = new System.Drawing.Point(12, 91);
            this.lblTextColor.Name = "lblTextColor";
            this.lblTextColor.Size = new System.Drawing.Size(100, 14);
            this.lblTextColor.TabIndex = 6;
            this.lblTextColor.Text = "Text Color";
            // 
            // pnlGrp
            // 
            this.pnlGrp.Controls.Add(this.grpRes);
            this.pnlGrp.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlGrp.Location = new System.Drawing.Point(0, 0);
            this.pnlGrp.Name = "pnlGrp";
            this.pnlGrp.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlGrp.Size = new System.Drawing.Size(742, 92);
            this.pnlGrp.TabIndex = 0;
            // 
            // grpRes
            // 
            this.grpRes.Controls.Add(this.cdvFactory);
            this.grpRes.Controls.Add(this.lblFactory);
            this.grpRes.Controls.Add(this.chkIncludeDeleteRes);
            this.grpRes.Controls.Add(this.cdvResID);
            this.grpRes.Controls.Add(this.txtDesc);
            this.grpRes.Controls.Add(this.lblDesc);
            this.grpRes.Controls.Add(this.lblResID);
            this.grpRes.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpRes.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpRes.Location = new System.Drawing.Point(3, 0);
            this.grpRes.Name = "grpRes";
            this.grpRes.Size = new System.Drawing.Size(736, 92);
            this.grpRes.TabIndex = 1;
            this.grpRes.TabStop = false;
            // 
            // cdvFactory
            // 
            this.cdvFactory.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvFactory.BorderHotColor = System.Drawing.Color.Black;
            this.cdvFactory.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvFactory.BtnToolTipText = "";
            this.cdvFactory.DescText = "";
            this.cdvFactory.DisplaySubItemIndex = -1;
            this.cdvFactory.DisplayText = "";
            this.cdvFactory.Focusing = null;
            this.cdvFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvFactory.Index = 0;
            this.cdvFactory.IsViewBtnImage = false;
            this.cdvFactory.Location = new System.Drawing.Point(120, 17);
            this.cdvFactory.MaxLength = 10;
            this.cdvFactory.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.Name = "cdvFactory";
            this.cdvFactory.ReadOnly = false;
            this.cdvFactory.SearchSubItemIndex = 0;
            this.cdvFactory.SelectedDescIndex = -1;
            this.cdvFactory.SelectedSubItemIndex = -1;
            this.cdvFactory.SelectionStart = 0;
            this.cdvFactory.Size = new System.Drawing.Size(200, 20);
            this.cdvFactory.SmallImageList = null;
            this.cdvFactory.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvFactory.TabIndex = 0;
            this.cdvFactory.TextBoxToolTipText = "";
            this.cdvFactory.TextBoxWidth = 200;
            this.cdvFactory.VisibleButton = true;
            this.cdvFactory.VisibleColumnHeader = false;
            this.cdvFactory.VisibleDescription = false;
            this.cdvFactory.TextBoxTextChanged += new System.EventHandler(this.cdvFactory_TextBoxTextChanged);
            this.cdvFactory.ButtonPress += new System.EventHandler(this.cdvFactory_ButtonPress);
            this.cdvFactory.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvFactory_SelectedItemChanged);
            // 
            // lblFactory
            // 
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblFactory.Location = new System.Drawing.Point(15, 20);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(100, 14);
            this.lblFactory.TabIndex = 48;
            this.lblFactory.Text = "Factory";
            // 
            // chkIncludeDeleteRes
            // 
            this.chkIncludeDeleteRes.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkIncludeDeleteRes.Location = new System.Drawing.Point(556, 38);
            this.chkIncludeDeleteRes.Name = "chkIncludeDeleteRes";
            this.chkIncludeDeleteRes.Size = new System.Drawing.Size(172, 14);
            this.chkIncludeDeleteRes.TabIndex = 2;
            this.chkIncludeDeleteRes.Text = "Include deleted resource";
            this.chkIncludeDeleteRes.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // cdvResID
            // 
            this.cdvResID.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvResID.BorderHotColor = System.Drawing.Color.Black;
            this.cdvResID.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvResID.BtnToolTipText = "";
            this.cdvResID.DescText = "";
            this.cdvResID.DisplaySubItemIndex = -1;
            this.cdvResID.DisplayText = "";
            this.cdvResID.Focusing = null;
            this.cdvResID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvResID.Index = 0;
            this.cdvResID.IsViewBtnImage = false;
            this.cdvResID.Location = new System.Drawing.Point(120, 41);
            this.cdvResID.MaxLength = 20;
            this.cdvResID.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvResID.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvResID.Name = "cdvResID";
            this.cdvResID.ReadOnly = false;
            this.cdvResID.SearchSubItemIndex = 0;
            this.cdvResID.SelectedDescIndex = -1;
            this.cdvResID.SelectedSubItemIndex = -1;
            this.cdvResID.SelectionStart = 0;
            this.cdvResID.Size = new System.Drawing.Size(200, 20);
            this.cdvResID.SmallImageList = null;
            this.cdvResID.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvResID.TabIndex = 1;
            this.cdvResID.TextBoxToolTipText = "";
            this.cdvResID.TextBoxWidth = 200;
            this.cdvResID.VisibleButton = true;
            this.cdvResID.VisibleColumnHeader = false;
            this.cdvResID.VisibleDescription = false;
            this.cdvResID.TextBoxTextChanged += new System.EventHandler(this.cdvResID_TextBoxTextChanged);
            this.cdvResID.ButtonPress += new System.EventHandler(this.cdvResID_ButtonPress);
            this.cdvResID.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvResID_SelectedItemChanged);
            // 
            // txtDesc
            // 
            this.txtDesc.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.txtDesc.Location = new System.Drawing.Point(120, 66);
            this.txtDesc.MaxLength = 50;
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.ReadOnly = true;
            this.txtDesc.Size = new System.Drawing.Size(611, 19);
            this.txtDesc.TabIndex = 3;
            this.txtDesc.TabStop = false;
            this.txtDesc.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblDesc
            // 
            this.lblDesc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDesc.Location = new System.Drawing.Point(15, 68);
            this.lblDesc.Name = "lblDesc";
            this.lblDesc.Size = new System.Drawing.Size(100, 14);
            this.lblDesc.TabIndex = 2;
            this.lblDesc.Text = "Description";
            // 
            // lblResID
            // 
            this.lblResID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblResID.Location = new System.Drawing.Point(15, 44);
            this.lblResID.Name = "lblResID";
            this.lblResID.Size = new System.Drawing.Size(100, 14);
            this.lblResID.TabIndex = 0;
            this.lblResID.Text = "Resource ID";
            // 
            // frmFMBViewResourceStatus
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Controls.Add(this.pnlCenter);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBViewResourceStatus";
            this.Tag = "FMB3001";
            this.Text = "View Resource Status";
            this.Activated += new System.EventHandler(this.frmFMBViewResourceStatus_Activated);
            this.Load += new System.EventHandler(this.frmFMBViewResourceStatus_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTab.ResumeLayout(false);
            this.tabResStatus.ResumeLayout(false);
            this.tbpGeneral.ResumeLayout(false);
            this.grpGeneral.ResumeLayout(false);
            this.grpGeneral.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtCtrlMode)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtProcCount)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEnd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastHistSeq)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEventTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastActHistSeq)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEvent)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastStart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPriStatus)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpDownFlag)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDelTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDelUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSubAreaID)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAreaId)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtProcMode)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtResType)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtProcRule)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocation)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtMaxProcCount)).EndInit();
            this.tbpCMF.ResumeLayout(false);
            this.grpCMF.ResumeLayout(false);
            this.grpCMF.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF20)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF19)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF18)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF17)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF16)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF15)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF14)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF13)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF12)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF11)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCMF1)).EndInit();
            this.tbpLotList.ResumeLayout(false);
            this.grpLotList.ResumeLayout(false);
            this.tbpResSts.ResumeLayout(false);
            this.grpResStatus.ResumeLayout(false);
            this.grpResStatus.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSts1)).EndInit();
            this.tbpResGrp.ResumeLayout(false);
            this.grpGrp.ResumeLayout(false);
            this.grpGrp.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGrp1)).EndInit();
            this.tbpLocation.ResumeLayout(false);
            this.grpLocation.ResumeLayout(false);
            this.grpLocation.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pctImage)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcBack)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcText)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocUpdateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocCreateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocUpdateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLocCreateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtStyle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtType)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLayOut)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtText)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtX)).EndInit();
            this.pnlGrp.ResumeLayout(false);
            this.grpRes.ResumeLayout(false);
            this.grpRes.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvResID)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDesc)).EndInit();
            this.ResumeLayout(false);

        }
        
        #endregion
        
        #region " Variable Definition "
        
        private bool b_load_flag;
        private ImageList imlRes;
        
        #endregion
        
        #region " Function Implementations"
        
        // View_Resource()
        //       -  View Resource
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       -
        private bool View_Resource()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_Resource_In");
                TRSNode out_node = new TRSNode("View_Resource_Out");

                udcCtrlResource ctrlRes = new udcCtrlResource(modGlobalVariable.gimlResource);
                imlRes = ctrlRes.imlResource;
                
                MPCF.FieldClear(this, cdvResID, cdvFactory, null, null, null, false);
                InitControl("lblSts", "txtSts", grpResStatus);
                InitControl("lblGrp", "txtGrp", grpGrp);
                InitControl("lblCMF", "txtCMF", grpCMF);
                MPCR.SetInMsg(in_node);
                in_node.Factory = cdvFactory.Text;
                in_node.ProcStep = '1';
                in_node.AddString("RES_ID", cdvResID.Text);

                if (MPCR.CallService("FMB", "FMB_View_Resource", in_node, ref out_node) == false)
                {
                    return false;
                }

                  SetGroupCmfItem();

                txtDesc.Text = MPCF.RTrim(out_node.GetString("RES_DESC"));
                txtResType.Text = MPCF.RTrim(out_node.GetString("RES_TYPE"));

                if (out_node.GetChar("PROC_RULE") == 'S')
                {
                    txtProcRule.Text = "SERIAL";
                }
                else if (out_node.GetChar("PROC_RULE") == 'B')
                {
                    txtProcRule.Text = "BATCH";
                }
                else
                {
                    txtProcRule.Text = "NORMAL";
                }
                txtMaxProcCount.Text = out_node.GetInt("MAX_PROC_COUNT").ToString();

                if (MPCF.Trim(out_node.GetString("RES_PROC_MODE")) != "")
                {
                    if (out_node.GetString("RES_PROC_MODE").PadLeft(1, ' ').Substring(0, 1) == "M")
                    {
                        txtProcMode.Text = "MANUAL";
                    }
                    else if (out_node.GetString("RES_PROC_MODE").PadLeft(1, ' ').Substring(0, 1) == "S")
                    {
                        txtProcMode.Text = "SEMI AUTO";
                    }
                    else if (out_node.GetString("RES_PROC_MODE").PadLeft(1, ' ').Substring(0, 1) == "F")
                    {
                        txtProcMode.Text = "FULL AUTO";
                    }
                }

                if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")) != "")
                {
                    if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OL")
                    {
                        txtCtrlMode.Text = "ON LINE";
                    }
                    else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OR")
                    {
                        txtCtrlMode.Text = "ON LINE REAL";
                    }
                    else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OF")
                    {
                        txtCtrlMode.Text = "OFF LINE";
                    }
                }
                txtAreaId.Text = MPCF.RTrim(out_node.GetString("AREA_ID"));
                txtSubAreaID.Text = MPCF.RTrim(out_node.GetString("SUB_AREA_ID"));
                txtLocation.Text = MPCF.RTrim(out_node.GetString("RES_LOCATION"));
                txtCreateUser.Text = MPCF.RTrim(out_node.GetString("RES_CREATE_USER_ID"));
                txtCreateTime.Text = MPCF.MakeDateFormat(out_node.GetString("RES_CREATE_TIME"), DATE_TIME_FORMAT.NONE);
                txtUpdateUser.Text = MPCF.RTrim(out_node.GetString("RES_UPDATE_USER_ID"));
                txtUpdateTime.Text = MPCF.MakeDateFormat(out_node.GetString("RES_UPDATE_TIME"), DATE_TIME_FORMAT.NONE);
                txtDelUser.Text = MPCF.RTrim(out_node.GetString("DELETE_USER_ID"));
                txtDelTime.Text = MPCF.MakeDateFormat(out_node.GetString("DELETE_TIME"), DATE_TIME_FORMAT.NONE);

                if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "U")
                {
                    txtUpDownFlag.Text = "UP";
                }
                else if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "D")
                {
                    txtUpDownFlag.Text = "DOWN";
                }
                txtPriStatus.Text = MPCF.RTrim(out_node.GetString("RES_PRI_STS"));
                txtProcCount.Text = out_node.GetInt("PROC_COUNT").ToString();
                txtLastStart.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_START_TIME"), DATE_TIME_FORMAT.NONE);
                txtLastEnd.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_END_TIME"), DATE_TIME_FORMAT.NONE);
                txtLastEvent.Text = MPCF.RTrim(out_node.GetString("LAST_EVENT_ID"));
                txtLastEventTime.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_EVENT_TIME"), DATE_TIME_FORMAT.NONE);
                txtLastHistSeq.Text = out_node.GetInt("LAST_HIST_SEQ").ToString();
                txtLastActHistSeq.Text = out_node.GetInt("LAST_ACTIVE_HIST_SEQ").ToString();

                if (MPCF.RTrim(out_node.GetChar("DELETE_FLAG")) == "Y")
                {
                    chkResDelFlag.Checked = true;
                }
                else
                {
                    chkResDelFlag.Checked = false;
                }
                if (MPCF.RTrim(out_node.GetChar("PM_SCH_ENABLE_FLAG")) == "Y")
                {
                    chkPMSchEnableFlag.Checked = true;
                }
                else
                {
                    chkPMSchEnableFlag.Checked = false;
                }
                
                if (MPCF.RTrim(out_node.GetChar("UNIT_BASE_ST_FLAG")) == "Y")
                {
                    chkUnitBaseStFlag.Checked = true;
                }
                else
                {
                    chkUnitBaseStFlag.Checked = false;
                }

                if (MPCF.RTrim(out_node.GetChar("SEC_CHK_FLAG")) == "Y")
                {
                    chkSecChkFlag.Checked = true;
                }
                else
                {
                    chkSecChkFlag.Checked = false;
                }
                if (MPCF.RTrim(out_node.GetChar("USE_FAC_PRT_FLAG")) == "Y")
                {
                    chkUseFacPrtFlag.Checked = true;
                }
                else
                {
                    chkUseFacPrtFlag.Checked = false;
                }

                txtGrp1.Text = MPCF.RTrim(out_node.GetString("RES_GRP_1"));
                txtGrp2.Text = MPCF.RTrim(out_node.GetString("RES_GRP_2"));
                txtGrp3.Text = MPCF.RTrim(out_node.GetString("RES_GRP_3"));
                txtGrp4.Text = MPCF.RTrim(out_node.GetString("RES_GRP_4"));
                txtGrp5.Text = MPCF.RTrim(out_node.GetString("RES_GRP_5"));
                txtGrp6.Text = MPCF.RTrim(out_node.GetString("RES_GRP_6"));
                txtGrp7.Text = MPCF.RTrim(out_node.GetString("RES_GRP_7"));
                txtGrp8.Text = MPCF.RTrim(out_node.GetString("RES_GRP_8"));
                txtGrp9.Text = MPCF.RTrim(out_node.GetString("RES_GRP_9"));
                txtGrp10.Text = MPCF.RTrim(out_node.GetString("RES_GRP_10"));

                txtCMF1.Text = MPCF.RTrim(out_node.GetString("RES_CMF_1"));
                txtCMF2.Text = MPCF.RTrim(out_node.GetString("RES_CMF_2"));
                txtCMF3.Text = MPCF.RTrim(out_node.GetString("RES_CMF_3"));
                txtCMF4.Text = MPCF.RTrim(out_node.GetString("RES_CMF_4"));
                txtCMF5.Text = MPCF.RTrim(out_node.GetString("RES_CMF_5"));
                txtCMF6.Text = MPCF.RTrim(out_node.GetString("RES_CMF_6"));
                txtCMF7.Text = MPCF.RTrim(out_node.GetString("RES_CMF_7"));
                txtCMF8.Text = MPCF.RTrim(out_node.GetString("RES_CMF_8"));
                txtCMF9.Text = MPCF.RTrim(out_node.GetString("RES_CMF_9"));
                txtCMF10.Text = MPCF.RTrim(out_node.GetString("RES_CMF_10"));
                txtCMF11.Text = MPCF.RTrim(out_node.GetString("RES_CMF_11"));
                txtCMF12.Text = MPCF.RTrim(out_node.GetString("RES_CMF_12"));
                txtCMF13.Text = MPCF.RTrim(out_node.GetString("RES_CMF_13"));
                txtCMF14.Text = MPCF.RTrim(out_node.GetString("RES_CMF_14"));
                txtCMF15.Text = MPCF.RTrim(out_node.GetString("RES_CMF_15"));
                txtCMF16.Text = MPCF.RTrim(out_node.GetString("RES_CMF_16"));
                txtCMF17.Text = MPCF.RTrim(out_node.GetString("RES_CMF_17"));
                txtCMF18.Text = MPCF.RTrim(out_node.GetString("RES_CMF_18"));
                txtCMF19.Text = MPCF.RTrim(out_node.GetString("RES_CMF_19"));
                txtCMF20.Text = MPCF.RTrim(out_node.GetString("RES_CMF_20"));



                if (MPCF.RTrim(out_node.GetChar("USE_FAC_PRT_FLAG")) != "Y")
                {
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_1")) != "")
                    {
                        lblSts1.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_1"));
                        lblSts1.Visible = true;
                        txtSts1.Visible = true;
                    }
                    else
                    {
                        lblSts1.Visible = false;
                        txtSts1.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_2")) != "")
                    {
                        lblSts2.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_2"));
                        lblSts2.Visible = true;
                        txtSts2.Visible = true;
                    }
                    else
                    {
                        lblSts2.Visible = false;
                        txtSts2.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_3")) != "")
                    {
                        lblSts3.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_3"));
                        lblSts3.Visible = true;
                        txtSts3.Visible = true;
                    }
                    else
                    {
                        lblSts3.Visible = false;
                        txtSts3.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_4")) != "")
                    {
                        lblSts4.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_4"));
                        lblSts4.Visible = true;
                        txtSts4.Visible = true;
                    }
                    else
                    {
                        lblSts4.Visible = false;
                        txtSts4.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_5")) != "")
                    {
                        lblSts5.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_5"));
                        lblSts5.Visible = true;
                        txtSts5.Visible = true;
                    }
                    else
                    {
                        lblSts5.Visible = false;
                        txtSts5.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_6")) != "")
                    {
                        lblSts6.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_6"));
                        lblSts6.Visible = true;
                        txtSts6.Visible = true;
                    }
                    else
                    {
                        lblSts6.Visible = false;
                        txtSts6.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_7")) != "")
                    {
                        lblSts7.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_7"));
                        lblSts7.Visible = true;
                        txtSts7.Visible = true;
                    }
                    else
                    {
                        lblSts7.Visible = false;
                        txtSts7.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_8")) != "")
                    {
                        lblSts8.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_8"));
                        lblSts8.Visible = true;
                        txtSts8.Visible = true;
                    }
                    else
                    {
                        lblSts8.Visible = false;
                        txtSts8.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_9")) != "")
                    {
                        lblSts9.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_9"));
                        lblSts9.Visible = true;
                        txtSts9.Visible = true;
                    }
                    else
                    {
                        lblSts9.Visible = false;
                        txtSts9.Visible = false;
                    }
                    if (MPCF.RTrim(out_node.GetString("RES_STS_PRT_10")) != "")
                    {
                        lblSts10.Text = MPCF.RTrim(out_node.GetString("RES_STS_PRT_10"));
                        lblSts10.Visible = true;
                        txtSts10.Visible = true;
                    }
                    else
                    {
                        lblSts10.Visible = false;
                        txtSts10.Visible = false;
                    }
                }
                else
                {
                    View_Factory_ResStatus();
                }
                
                txtSts1.Text =  MPCF.RTrim(out_node.GetString("RES_STS_1"));
                txtSts2.Text =  MPCF.RTrim(out_node.GetString("RES_STS_2"));
                txtSts3.Text =  MPCF.RTrim(out_node.GetString("RES_STS_3"));
                txtSts4.Text =  MPCF.RTrim(out_node.GetString("RES_STS_4"));
                txtSts5.Text =  MPCF.RTrim(out_node.GetString("RES_STS_5"));
                txtSts6.Text =  MPCF.RTrim(out_node.GetString("RES_STS_6"));
                txtSts7.Text =  MPCF.RTrim(out_node.GetString("RES_STS_7"));
                txtSts8.Text =  MPCF.RTrim(out_node.GetString("RES_STS_8"));
                txtSts9.Text =  MPCF.RTrim(out_node.GetString("RES_STS_9"));
                txtSts10.Text =  MPCF.RTrim(out_node.GetString("RES_STS_10"));

                txtLayOut.Text =  MPCF.RTrim(out_node.GetString("LAYOUT_ID"));
                txtType.Text =  MPCF.RTrim(out_node.GetChar("RES_TAG_FLAG"));
                txtText.Text =  MPCF.RTrim(out_node.GetString("TEXT"));
                txtSize.Text = MPCF.Trim( out_node.GetInt("TEXT_SIZE"));

                if (MPCF.Trim(out_node.GetChar("TEXT_STYLE")) != "")
                {
                    txtStyle.Text = @Enum.GetName(typeof(FontStyle), @Enum.GetValues(typeof(FontStyle)).GetValue(MPCF.ToInt(out_node.GetChar("TEXT_STYLE").ToString())));
                }
                if (out_node.GetInt("TEXT_COLOR") < 0)
                {
                    utcText.Color = Color.FromArgb(out_node.GetInt("TEXT_COLOR"));
                }
                else if (out_node.GetInt("TEXT_COLOR") > 0)
                {
                    utcText.Color = Color.FromKnownColor((KnownColor)out_node.GetInt("TEXT_COLOR"));
                }
                else
                {
                    utcText.Color = SystemColors.WindowText;
                }
                
                if (out_node.GetInt("BACK_COLOR") < 0)
                {
                    utcBack.Color = Color.FromArgb(out_node.GetInt("BACK_COLOR"));
                }
                else if (out_node.GetInt("BACK_COLOR") > 0)
                {
                    utcBack.Color = Color.FromKnownColor((KnownColor)out_node.GetInt("BACK_COLOR"));
                }
                else
                {
                    utcBack.Color = SystemColors.Control;
                }
                
                txtX.Text = out_node.GetInt("LOC_X").ToString();
                txtY.Text = out_node.GetInt("LOC_Y").ToString();
                txtWidth.Text = out_node.GetInt("LOC_WIDTH").ToString();
                txtHeight.Text = out_node.GetInt("LOC_HEIGHT").ToString();

                txtLocCreateUser.Text =  MPCF.RTrim(out_node.GetString("CREATE_USER_ID"));
                txtLocCreateTime.Text =  MPCF.MakeDateFormat(out_node.GetString("CREATE_TIME"), DATE_TIME_FORMAT.NONE);
                txtLocUpdateUser.Text =  MPCF.RTrim(out_node.GetString("UPDATE_USER_ID"));
                txtLocUpdateTime.Text =  MPCF.MakeDateFormat(out_node.GetString("UPDATE_TIME"), DATE_TIME_FORMAT.NONE);
                
                if (out_node.GetInt("IMAGE_IDX") != - 1 && imlRes.Images.Count > out_node.GetInt("IMAGE_IDX"))
                {
                    pctImage.Image = imlRes.Images[out_node.GetInt("IMAGE_IDX")];
                }
                else
                {
                    pctImage.Image = null;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.View_Resource()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // View_Factory_ResStatus()
        //       -  View Factory Resource Status Prompt
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       -
        //
        private bool View_Factory_ResStatus()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_Factory_In");
                TRSNode out_node = new TRSNode("View_Factory_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = cdvFactory.Text;

                if (MPCR.CallService("WIP", "WIP_View_Factory", in_node, ref out_node) == false)
                {
                    return false;
                }

                if (MPCF.RTrim(out_node.GetString("RES_STS_1")) != "")
                {
                    lblSts1.Text = MPCF.RTrim(out_node.GetString("RES_STS_1"));
                    lblSts1.Visible = true;
                    txtSts1.Visible = true;
                }
                else
                {
                    lblSts1.Visible = false;
                    txtSts1.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_2")) != "")
                {
                    lblSts2.Text = MPCF.RTrim(out_node.GetString("RES_STS_2"));
                    lblSts2.Visible = true;
                    txtSts2.Visible = true;
                }
                else
                {
                    lblSts2.Visible = false;
                    txtSts2.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_3")) != "")
                {
                    lblSts3.Text = MPCF.RTrim(out_node.GetString("RES_STS_3"));
                    lblSts3.Visible = true;
                    txtSts3.Visible = true;
                }
                else
                {
                    lblSts3.Visible = false;
                    txtSts3.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_4")) != "")
                {
                    lblSts4.Text = MPCF.RTrim(out_node.GetString("RES_STS_4"));
                    lblSts4.Visible = true;
                    txtSts4.Visible = true;
                }
                else
                {
                    lblSts4.Visible = false;
                    txtSts4.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_5")) != "")
                {
                    lblSts5.Text = MPCF.RTrim(out_node.GetString("RES_STS_5"));
                    lblSts5.Visible = true;
                    txtSts5.Visible = true;
                }
                else
                {
                    lblSts5.Visible = false;
                    txtSts5.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_6")) != "")
                {
                    lblSts6.Text = MPCF.RTrim(out_node.GetString("RES_STS_6"));
                    lblSts6.Visible = true;
                    txtSts6.Visible = true;
                }
                else
                {
                    lblSts6.Visible = false;
                    txtSts6.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_7")) != "")
                {
                    lblSts7.Text = MPCF.RTrim(out_node.GetString("RES_STS_7"));
                    lblSts7.Visible = true;
                    txtSts7.Visible = true;
                }
                else
                {
                    lblSts7.Visible = false;
                    txtSts7.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_8")) != "")
                {
                    lblSts8.Text = MPCF.RTrim(out_node.GetString("RES_STS_8"));
                    lblSts8.Visible = true;
                    txtSts8.Visible = true;
                }
                else
                {
                    lblSts8.Visible = false;
                    txtSts8.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_9")) != "")
                {
                    lblSts9.Text = MPCF.RTrim(out_node.GetString("RES_STS_9"));
                    lblSts9.Visible = true;
                    txtSts9.Visible = true;
                }
                else
                {
                    lblSts9.Visible = false;
                    txtSts9.Visible = false;
                }
                if (MPCF.RTrim(out_node.GetString("RES_STS_10")) != "")
                {
                    lblSts10.Text = MPCF.RTrim(out_node.GetString("RES_STS_10"));
                    lblSts10.Visible = true;
                    txtSts10.Visible = true;
                }
                else
                {
                    lblSts10.Visible = false;
                    txtSts10.Visible = false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.View_Factory_ResStatus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // SetGroupCmfItem()
        //       - Set Group / Cmf Property to control
        // Return Value
        //       -
        // Arguments
        //        -
        //
        private void SetGroupCmfItem()
        {
            
            try
            {
                string[] sGrpTableName = new string[10];
                
                sGrpTableName[0] = modGlobalConstant.MP_GCM_RES_GRP_1;
                sGrpTableName[1] = modGlobalConstant.MP_GCM_RES_GRP_2;
                sGrpTableName[2] = modGlobalConstant.MP_GCM_RES_GRP_3;
                sGrpTableName[3] = modGlobalConstant.MP_GCM_RES_GRP_4;
                sGrpTableName[4] = modGlobalConstant.MP_GCM_RES_GRP_5;
                sGrpTableName[5] = modGlobalConstant.MP_GCM_RES_GRP_6;
                sGrpTableName[6] = modGlobalConstant.MP_GCM_RES_GRP_7;
                sGrpTableName[7] = modGlobalConstant.MP_GCM_RES_GRP_8;
                sGrpTableName[8] = modGlobalConstant.MP_GCM_RES_GRP_9;
                sGrpTableName[9] = modGlobalConstant.MP_GCM_RES_GRP_10;
                
                SetGRPItem(sGrpTableName);
                SetCmfItem();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.SetGroupCmfItem()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        // InitControl()
        //       - initial Group/Cmf Control
        // Return Value
        //       -
        // Arguments
        //       - ByVal sLabelName As String            : Label Control Prefix Name
        //        - ByVal sTextboxName As String            : Textbox Control Prefix Name
        //        - ByVal parentControl As Control        : ParentControl
        //
        private void InitControl(string sLabelName, string sTextboxName, Control parentControl)
        {
            
            try
            {
                ArrayList controls;
                int i;
                
                controls = FMBCF.GetIndexedControl(sLabelName, parentControl);
                for (i = 0; i <= controls.Count - 1; i++)
                {
                    ((Label) controls[i]).Visible = false;
                    ((Label) controls[i]).Text = "";
                }
                
                controls = FMBCF.GetIndexedControl(sTextboxName, parentControl);
                for (i = 0; i <= controls.Count - 1; i++)
                {
                    ((UltraTextEditor) controls[i]).Visible = false;
                    ((UltraTextEditor) controls[i]).Text = "";
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.InitControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        // SetCmfItem()
        //       - Set Cmf Property to control
        // Return Value
        //       -
        // Arguments
        //        -
        private void SetCmfItem()
        {
            
            try
            {
                TRSNode out_node = new TRSNode("View_FacCmf_Item_Out"); 
                
                ArrayList lblList;
                ArrayList txtList;
                Label lblTemp;
                UltraTextEditor txtTemp;
                int i;
                
                InitControl("lblCMF", "txtCMF", grpCMF);

                if (WIPLIST.ViewFactoryCmfData('1', modGlobalConstant.MP_CMF_RESOURCE, ref out_node, cdvFactory.Text, false) == false)
                {
                    return;
                }
                
                lblList = FMBCF.GetIndexedControl("lblCmf", grpCMF);
                txtList = FMBCF.GetIndexedControl("txtCmf", grpCMF);

                for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                {
                    lblTemp = (Label) lblList[i];
                    txtTemp = (UltraTextEditor) txtList[i];

                    lblTemp.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("PROMPT"));
                    if (lblTemp.Text != "")
                    {
                        lblTemp.Visible = true;
                        txtTemp.Visible = true;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.SetCmfItem()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        // SetGRPItem()
        //       - Set Group  Property to control
        // Return Value
        //       -
        // Arguments
        //        -
        //
        private void SetGRPItem(params string[] sGrpTableName)
        {
            
            try
            {
                TRSNode out_node = new TRSNode("View_FacCmf_Item_Out");
                
                ArrayList lblList;
                ArrayList txtList;
                Label lblTemp;
                UltraTextEditor txtTemp;
                int i;
                
                InitControl("lblGrp", "txtGrp", grpGrp);

                if (modListRoutine.ViewFacCmfData('1', modGlobalConstant.MP_GRP_RESOURCE, ref out_node, cdvFactory.Text, false) == false)
                {
                    return;
                }
                
                lblList = FMBCF.GetIndexedControl("lblGrp", grpGrp);
                txtList = FMBCF.GetIndexedControl("txtGrp", grpGrp);
                
                for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                {
                    lblTemp = (Label) lblList[i];
                    txtTemp = (UltraTextEditor) txtList[i];

                    lblTemp.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("PROMPT"));
                    if (lblTemp.Text != "")
                    {
                        lblTemp.Visible = true;
                        txtTemp.Tag = "A" + sGrpTableName[i];
                        txtTemp.Visible = true;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.SetGRPItem()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
        #region " Event Implementations "
        
        private void frmFMBViewResourceStatus_Activated(object sender, System.EventArgs e)
        {
            
            try
            {
                if (b_load_flag == false)
                {
                    MPCF.InitListView(lisLotList);
                    cdvResID.Focus();
                    InitControl("lblSts", "txtSts", grpResStatus);
                    InitControl("lblGrp", "txtGrp", grpGrp);
                    InitControl("lblCMF", "txtCMF", grpCMF);
                    b_load_flag = true;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.frmFMBViewResourceStatus_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnView_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(this, cdvResID, cdvFactory, null, null, null, false);
                if (cdvFactory.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    cdvFactory.Focus();
                    return;
                }
                if (cdvResID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    cdvResID.Focus();
                    return;
                }
                if (View_Resource() == false)
                {
                    return;
                }
                if (modListRoutine.ViewResLotList(lisLotList, '1', cdvResID.Text, cdvFactory.Text, "", false) == false)
                {
                    return;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.btnView_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvResID_SelectedItemChanged(System.Object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(this, cdvResID, cdvFactory, null, null, null, false);
                lisLotList.Items.Clear();
                utcText.Color = SystemColors.WindowText;
                utcBack.Color = SystemColors.Control;
                pctImage.Image = null;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.cdvResID_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvResID_ButtonPress(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (cdvFactory.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    cdvFactory.Focus();
                    return;
                }
                cdvResID.Init();
                cdvResID.Columns.Add("ResID", 50, HorizontalAlignment.Left);
                cdvResID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResID.SelectedSubItemIndex = 0;
                cdvResID.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (chkIncludeDeleteRes.Checked == true)
                {
                    RASLIST.ViewResourceList(cdvResID.GetListView, '2',"","","","","",0,"","",' ',"",true,null, cdvFactory.Text);
                }
                else
                {
                    RASLIST.ViewResourceList(cdvResID.GetListView, '2', "", "", "", "", "", 0, "", "", ' ', "", false, null, cdvFactory.Text);
                }
                cdvResID.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.cdvResID_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvResID_TextBoxTextChanged(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(this, cdvResID, cdvFactory, null, null, null, false);
                lisLotList.Items.Clear();
                InitControl("lblSts", "txtSts", grpResStatus);
                InitControl("lblGrp", "txtGrp", grpGrp);
                InitControl("lblCMF", "txtCMF", grpCMF);
                utcText.Color = SystemColors.WindowText;
                utcBack.Color = SystemColors.Control;
                pctImage.Image = null;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.cdvResID_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnClose_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                this.Dispose();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_ButtonPress(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                cdvFactory.Init();
                cdvFactory.Columns.Add("Factory", 100, HorizontalAlignment.Left);
                cdvFactory.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFactory.SelectedSubItemIndex = 0;
                cdvFactory.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                WIPLIST.ViewFactoryList(cdvFactory.GetListView, '1',null);
                cdvFactory.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_SelectedItemChanged(System.Object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(this, cdvFactory, null, null, null, null, false);
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.cdvFactory_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_TextBoxTextChanged(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(this, cdvFactory, null, null, null, null, false);
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.cdvFactory_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void lisLotList_ColumnClick(object sender, System.Windows.Forms.ColumnClickEventArgs e)
        {
            
            try
            {
                if (MPCF.RTrim(lisLotList.Tag.ToString()) == "True")
                {
                    lisLotList.Tag = false;
                }
                else
                {
                    lisLotList.Tag = true;
                }

                this.lisLotList.ListViewItemSorter = new ListViewItemComparer(e.Column, ((bool)lisLotList.Tag == true ? SortOrder.Descending : SortOrder.Ascending), ListViewItemComparer.SORTING_OPTION.STRING_TYPE);
                lisLotList.Sort();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.lisLotList_ColumnClick()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBViewResourceStatus_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                //MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                
                FMBCF.CheckAllFactoryOption(cdvFactory);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceStatus.frmFMBViewResourceStatus_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion

    }
    
}
