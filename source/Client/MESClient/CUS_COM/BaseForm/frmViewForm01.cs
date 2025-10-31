//-----------------------------------------------------------------------------
//
//   System      : MES
//   File Name   : frmTranForm02.cs
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
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using Miracom.CliFrx;
using System.Runtime.InteropServices;


using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.DNMCore;
using DevExpress.CodeParser;
using FarPoint.Win.Spread.UndoRedo;
using DevExpress.Pdf.Native.BouncyCastle.Asn1.Ocsp;
using Infragistics.Win.Misc;
using static DevExpress.Xpo.DB.DataStoreLongrunnersWatch;
using System.Reflection;
using DevExpress.Utils.Extensions;

namespace CUS_COM
{
    public partial class frmViewForm01 : Miracom.CliFrx.BaseForm03
    {

        [DllImport("User32.dll")]
        static extern void mouse_event(uint dwFlags, uint dx, uint dy, uint dwData, int dwExtraInfo);

        [DllImport("User32.dll")]
        static extern int SetCursorPos(int x, int y);



        private const uint MOUSEEVENTF_LEFTDOWN = 0x0002;      // The left button is down.
        private const uint MOUSEEVENTF_LEFTUP = 0x0004;        // The left button is up



        public frmViewForm01()
        {
            InitializeComponent();
            chkFavorite.Anchor = AnchorStyles.Top | AnchorStyles.Left;


            //20240220 단축키 조회 기능 넣어달라고 해서 Ctrl+Q
            KeyPreview = true;
            
        }
        private void frmViewForm01_KeyDown(object sender, KeyEventArgs e)
        {

            /*
            if(e.Modifiers == Keys.Control && e.KeyCode == Keys.Q)
            {

                this.btnView_Click(this, e);

            }
            */


        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void brnProcess_Click(object sender, EventArgs e)
        {

        }

        private void lblFormName_DoubleClick(object sender, EventArgs e)
        {
            string formName = this.Name;
            //Clipboard.SetText(formName);
        }

        protected override void OnActivated(EventArgs e)
        {

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

        private void btnView_Click(object sender, EventArgs e)
        {
            //btnView_Click(this.ActiveMdiChild, e);
        }

        private void frmViewForm01_KeyUp(object sender, KeyEventArgs e)
        {

 
        }

        private void frmViewForm01_KeyPress(object sender, KeyPressEventArgs e)
        {

            //20240306 단축키 넣어달라고해서.. (요청 성충헌)
            //조회쪽만 조회 삭제 넣음..
  

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

        }

        private void btnView_MouseHover(object sender, EventArgs e)
        {
            ToolTip toolTip1 = new ToolTip();
            toolTip1.ShowAlways = true;
            toolTip1.SetToolTip(btnView, "CTRL + Q");
        }

        private void btnClose_MouseHover(object sender, EventArgs e)
        {
            ToolTip toolTip1 = new ToolTip();
            toolTip1.ShowAlways = true;
            toolTip1.SetToolTip(btnClose, "CTRL + D");
        }
    }

}