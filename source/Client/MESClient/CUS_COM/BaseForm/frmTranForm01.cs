//-----------------------------------------------------------------------------
//
//   System      : MES
//   File Name   : frmTranForm01.cs
//   Description :
//
//   MES Version : 5.3.0.0
//
//   Function List
//       - 
//
//   Detail Description
//       -
//
//   History
//       - **** Do Not Modify in Site!!! ****
//       - 2017-01-14 : Created by Aiden
//
//
//   Copyright(C) 1998-2017 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

using System;
using System.Windows.Forms;
using Miracom.CliFrx;
using Miracom.MESCore;
using System.Drawing;
using System.Runtime.InteropServices;

using Miracom.TRSCore;
using Miracom.DNMCore;
using System.Data;


namespace CUS_COM
{
    public partial class frmTranForm01 : Miracom.CliFrx.BaseForm03
    {
        [DllImport("User32.dll")]
        static extern void mouse_event(uint dwFlags, uint dx, uint dy, uint dwData, int dwExtraInfo);

        [DllImport("User32.dll")]
        static extern int SetCursorPos(int x, int y);


        private const uint MOUSEEVENTF_LEFTDOWN = 0x0002;      // The left button is down.
        private const uint MOUSEEVENTF_LEFTUP = 0x0004;        // The left button is up

        public frmTranForm01()
        {
            InitializeComponent();

            chkFavorite.Anchor = AnchorStyles.Top | AnchorStyles.Left;
        }

        public bool IsActivated { get; set; }
        public Controls.udcScanTextBox ScanTextBox { get; set; }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void lblFormName_DoubleClick(object sender, EventArgs e)
        {
            string formName = this.Name;
            //Clipboard.SetText(formName);
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }

                //특정 사업부인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvDept.Tag) != "")
                {
                    for (int i = cdvDept.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvDept.GetListView.Items[i - 1].SubItems[0].Text != cdvDept.Tag.ToString())
                        {
                            cdvDept.GetListView.Items[i - 1].Remove();
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvWorkPlace.Text = "";
                cdvOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                //특정 사업장인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvWorkPlace.Tag) != "")
                {
                    for (int i = cdvWorkPlace.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvWorkPlace.GetListView.Items[i - 1].SubItems[0].Text != cdvWorkPlace.Tag.ToString())
                        {
                            cdvWorkPlace.GetListView.Items[i - 1].Remove();
                        }
                    }
                }

                cdvWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranForm01_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!SaveRegistry.ContainsKey(cdvDept.Name))
                this.SaveRegistry.Add(cdvDept.Name, cdvDept.Text + ';' + cdvDept.DisplayText);

            if (!SaveRegistry.ContainsKey(cdvWorkPlace.Name))
                this.SaveRegistry.Add(cdvWorkPlace.Name, cdvWorkPlace.Text + ';' + cdvWorkPlace.DisplayText);

            if (!SaveRegistry.ContainsKey(cdvOper.Name))
                this.SaveRegistry.Add(cdvOper.Name, cdvOper.Text + ';' + cdvOper.DisplayText);
        }

        protected override void OnActivated(EventArgs e)
        {
            IsActivated = true;
            base.OnActivated(e);

            DataTable dt = null;
            FuncNameSearch(ref dt, ' ');
            chkFavorite.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            this.chkFavorite.CheckedChanged += new System.EventHandler(this.chkFavorite_CheckedChanged);
        }

        protected override void OnDeactivate(EventArgs e)
        {
            try
            {
                IsActivated = false;
                base.OnDeactivate(e);


            }
            catch
            {
            }
        }



        #region " Favorite add "
        //20210712 즐겨찾기 추가
        private void chkFavorite_CheckedChanged(object sender, EventArgs e)
        {
            if (chkFavorite.Checked == true)
            {
                Update_Favorites(MPGC.MP_STEP_CREATE);
            }
            else
            {
                Update_Favorites(MPGC.MP_STEP_DELETE);
            }

            //Add by J.S. 2009.02.13
            //favorites수정시 LotListMain, ResourceListMain시 submenu를 refresh하기위한 변수 
            MPGV.gbFavoriteChangeForLotListMain = true;
            MPGV.gbFavoriteChangeForResourceListMain = true;

            MPGV.gIMdiForm.FavoritesRefresh();
        }



        private void FuncNameSearch(ref DataTable dt, char cStep_Flag)
        {
            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FUNC_NAME";
                dvcArgu[1].sCondition_Value = this.Name.ToString();



                dvcArgu[2].sCondition_ID = "PROGRAM_ID";
                dvcArgu[2].sCondition_Value = MPGV.gsProgramID;

                dvcArgu[3].sCondition_ID = "USER_ID";
                dvcArgu[3].sCondition_Value = MPGV.gsUserID;


                if (TPDR.GetDataOne("", ref dt, "BAS-03", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    if (cStep_Flag != MPGC.MP_STEP_CREATE && cStep_Flag != MPGC.MP_STEP_DELETE)
                    {
                        chkFavorite.Checked = false;
                    }
                    return;
                }

                if (cStep_Flag != MPGC.MP_STEP_CREATE && cStep_Flag != MPGC.MP_STEP_DELETE)
                {
                    if (MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) > 0)
                    {
                        chkFavorite.Checked = true;
                    }
                    else
                    {
                        chkFavorite.Checked = false;
                    }
                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void Update_Favorites(char cStep_Flag)
        {
            try
            {

                string sPgmID = MPGV.gsProgramID;
                DataTable dt = null;

                TRSNode in_node = new TRSNode("UPDATE_FAVORITES_IN");
                TRSNode out_node = new TRSNode("CMN_OUT");

                //System.Windows.Forms.ColumnHeader;



                FuncNameSearch(ref dt, cStep_Flag);

                //MPGC.MP_STEP_DELETE
                //MPGC.MP_STEP_CREATE;

                if (cStep_Flag == MPGC.MP_STEP_CREATE && MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) > 0)
                {
                    //이미 즐겨찾기 되어있음 리턴.
                    return;
                }

                if (cStep_Flag == MPGC.MP_STEP_DELETE && MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) == 0)
                {
                    //이미 즐겨찾기 없음 리턴.
                    return;
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = cStep_Flag;
                in_node.AddString("PROGRAM_ID", sPgmID);
                in_node.AddInt("SEQ_NUM", MPCF.ToInt(dt.Rows[0]["SEQ_NUM"]));
                in_node.AddString("FUNC_NAME", dt.Rows[0]["FUNC_NAME"]);
                in_node.AddString("USER_FUNC_DESC", dt.Rows[0]["USER_FUNC_DESC"]);



                if (MPCR.CallService("SEC", "SEC_Update_Favorites", in_node, ref out_node) == false)
                {
                    return;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }
        #endregion

        private void frmTranForm01_KeyPress(object sender, KeyPressEventArgs e)
        {
            //20240306 단축키 넣어달라고해서.. (요청 성충헌)
            //조회쪽만 조회 삭제 넣음..
            //화면들에 일일어 넣기 뭐하구, 상속 이벤트 호출잘안되서...하여 마우스 이벤트로 단축기능만듬.


            int ix = Cursor.Position.X;
            int iy = Cursor.Position.Y;

            //Ctrl + q  조회 
            if (e.KeyChar == 17)

            {



                btnView.Focus();

                this.ActiveControl = btnView;

                Point controlLocation = this.Parent.PointToScreen(new Point(this.Left, this.Bottom));
                // Point parentLocation = btnView.Parent.PointToScreen(new Point(btnView.ClientRectangle.Left, btnView.Parent.ClientRectangle.Bottom));
                SetCursorPos(controlLocation.X + btnView.Location.X + (btnView.Width / 2), controlLocation.Y - btnView.Parent.ClientRectangle.Bottom + (btnView.Height / 2));

                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                SetCursorPos(ix, iy);

            }
            //ctrl + D  closed
            else if (e.KeyChar == 4)
            {


                btnClose.Focus();

                this.ActiveControl = btnClose;

                Point controlLocation = this.Parent.PointToScreen(new Point(this.Left, this.Bottom));
                //   Point parentLocation = btnClose.Parent.PointToScreen(new Point(btnClose.ClientRectangle.Left, btnClose.Parent.ClientRectangle.Bottom));
                SetCursorPos(controlLocation.X + btnClose.Location.X + (btnClose.Width / 2), controlLocation.Y - btnClose.Parent.ClientRectangle.Bottom + (btnClose.Height / 2));

                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                SetCursorPos(ix, iy);
            }
            //ctrl + S 저장
            else if (e.KeyChar == 19)

            {

                btnProcess.Focus();

                this.ActiveControl = btnProcess;

                Point controlLocation = this.Parent.PointToScreen(new Point(this.Left, this.Bottom));
                //   Point parentLocation = btnClose.Parent.PointToScreen(new Point(btnClose.ClientRectangle.Left, btnClose.Parent.ClientRectangle.Bottom));
                SetCursorPos(controlLocation.X + btnProcess.Location.X + (btnProcess.Width / 2), controlLocation.Y - btnProcess.Parent.ClientRectangle.Bottom + (btnProcess.Height / 2));

                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                SetCursorPos(ix, iy);
            }

        }

        private void btnView_MouseHover(object sender, EventArgs e)
        {
            ToolTip toolTip1 = new ToolTip();
            toolTip1.ShowAlways = true;
            toolTip1.SetToolTip(btnView, "CTRL + Q");
        }

        private void btnProcess_MouseHover(object sender, EventArgs e)
        {
            ToolTip toolTip1 = new ToolTip();
            toolTip1.ShowAlways = true;
            toolTip1.SetToolTip(btnProcess, "CTRL + S");
        }

        private void btnClose_MouseHover(object sender, EventArgs e)
        {
            ToolTip toolTip1 = new ToolTip();
            toolTip1.ShowAlways = true;
            toolTip1.SetToolTip(btnClose, "CTRL + D");
        }
    }
}