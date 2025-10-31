using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Reflection;

namespace CUS_WIP.Controls
{
    public partial class udcAddLotControl : UserControl
    {
        public udcAddLotControl()
        {
            InitializeComponent();
        }

        #region " Constant Definition "

        public string s_Oper = "";
        private string preText;
        Miracom.UI.Controls.MCCodeView.MCCodeView cdvsts;
        System.Windows.Forms.DateTimePicker dtpDate;
        System.Windows.Forms.DateTimePicker dtpTime;

        Label lblsts;

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        public bool ViewAddCondition1(Control control, string sTable_name,  string sKey_1)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "TABLE_NAME";
                dvcArgu[1].sCondition_Value = sTable_name;

                dvcArgu[2].sCondition_ID = "KEY_1";
                dvcArgu[2].sCondition_Value = sKey_1;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["KEY_2"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        public static Miracom.UI.Controls.MCCodeView.MCCodeView Gf_Get_CodeView_By_Name(string sCtrlName, Control ctrl)
        {
            Control[] cCtrl;

            cCtrl = ctrl.Controls.Find(sCtrlName, true);

            if (cCtrl == null)
                return null;
            else if (cCtrl.Length == 0)
                return null;
            else
            {
                return cCtrl[0] as Miracom.UI.Controls.MCCodeView.MCCodeView;
            }
        }

        public static System.Windows.Forms.DateTimePicker Gf_Get_DateTimePicker_By_Name(string sCtrlName, Control ctrl)
        {
            Control[] cCtrl;

            cCtrl = ctrl.Controls.Find(sCtrlName, true);

            if (cCtrl == null)
                return null;
            else if (cCtrl.Length == 0)
                return null;
            else
            {
                return cCtrl[0] as System.Windows.Forms.DateTimePicker;
            }
        }

        private void SetOperDataControl()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = s_Oper;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    cdvsts = Gf_Get_CodeView_By_Name("cdvsts" + dt.Rows[i]["SEQ"].ToString(), this);
                    dtpDate = Gf_Get_DateTimePicker_By_Name("dtpDate" + dt.Rows[i]["SEQ"].ToString(), this);
                    dtpTime = Gf_Get_DateTimePicker_By_Name("dtpTime" + dt.Rows[i]["SEQ"].ToString(), this);
                    lblsts = (this.Controls.Find("lblsts" + dt.Rows[i]["SEQ"].ToString(), true)[0] as Label);

                    lblsts.Text = MPCF.FindLanguage(dt.Rows[i]["LABEL_NAME"].ToString(), CAPTION_TYPE.LABEL);
                    cdvsts.Tag = dt.Rows[i]["COLUMN_NAME"].ToString();
                    dtpDate.Tag = dt.Rows[i]["COLUMN_NAME"].ToString();

                    //콤보박스 여부를 나타낸다.
                    //컨트롤 종류로 로직 변경. ( D:날짜 컨트롤 , Y: 버튼 컨트롤(기존 Y였기 때문), N 노말)
                    if (dt.Rows[i]["VISIBLE_BUTTON"].ToString() == "D")
                    {
                        dtpDate.Visible = true;
                        dtpTime.Visible = true;
                        cdvsts.Visible = false;
                    }
                    else
                    {                        
                        dtpDate.Visible = false;
                        dtpTime.Visible = false;
                        cdvsts.Visible = true;

                        if (dt.Rows[i]["VISIBLE_BUTTON"].ToString() == "Y")
                        {
                            
                            cdvsts.VisibleButton = true;
                            cdvsts.AccessibleName = dt.Rows[i]["USE_GCM_TABLE"].ToString();
                        }
                        else
                        {
                            cdvsts.VisibleButton = false;
                            cdvsts.AccessibleName = "";
                        }
                    }

                    //read only 옵션 여부를 나타낸다.
                    if (dt.Rows[i]["READ_ONLY_YN"].ToString() == "Y")
                    {
                        cdvsts.ReadOnly = true;
                        cdvsts.BackColor = Color.WhiteSmoke;
                    }
                    else
                    {
                        cdvsts.ReadOnly = false;
                        cdvsts.BackColor = Color.White;
                    }

                    if (dt.Rows[i]["NECESSARY_YN"].ToString() == "Y")
                    {
                        lblsts.Font = new Font(lblsts.Font, FontStyle.Bold);
                    }
                    else
                    {
                        lblsts.Font = new Font(lblsts.Font, FontStyle.Regular);
                    }

                    if (dt.Rows[i]["POPUP_YN"].ToString() == "Y")
                    {
                        lblsts.AccessibleName = dt.Rows[i]["POPUP_FORM"].ToString();
                    }
                    else
                    {
                        lblsts.AccessibleName = "";
                    }

                    if (dt.Rows[i]["NUMBER_YN"].ToString() == "Y")
                    {
                        cdvsts.GetDisplayTextBox.TextAlign = HorizontalAlignment.Right;
                        cdvsts.Text = "0";
                    }
                    else
                    {
                        cdvsts.GetDisplayTextBox.TextAlign = HorizontalAlignment.Left;
                        //cdvsts.Text = "";
                    }

                    cdvsts.Visible = true;
                    lblsts.Visible = true;
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void udcAddLotControl_Load(object sender, EventArgs e)
        {
            try
            {
                SetOperDataControl();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvsts_ButtonPress(object sender, EventArgs e)
        {
            string sFrom = "";
            string sArea = "";

            try
            {
                cdvsts = Gf_Get_CodeView_By_Name(this.ActiveControl.Name, this);
                lblsts = (this.Controls.Find("lblsts" + cdvsts.Name.Substring(6, cdvsts.Name.Length - 6) , true)[0] as Label);

                sArea = sArea_id;

                if (MPCF.Trim(lblsts.AccessibleName) != "")
                {
                    sFrom = lblsts.AccessibleName;
                    Assembly cuasm = Assembly.GetExecutingAssembly();
                    Form Mappigform = (Form)cuasm.CreateInstance(string.Format("{0}.{1}", "CUS_WIP", sFrom));
                    
                    Mappigform.StartPosition = FormStartPosition.CenterParent;
                    Mappigform.ShowInTaskbar = false;

                    if (Mappigform.ShowDialog() == DialogResult.OK)
                    {
                        //cdvsts.Text = 
                        Mappigform = null;
                    }
                    else
                        return;
                }
                else
                {
                    cdvsts.Init();
                    MPCF.InitListView(cdvsts.GetListView);
                    cdvsts.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                    cdvsts.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                    cdvsts.SelectedSubItemIndex = 0;
                    cdvsts.DisplaySubItemIndex = 1;

                    if (cdvsts.Tag.ToString() == "LOT_CMF_4")
                    {
                        if (ViewAddCondition1(cdvsts.GetListView, cdvsts.AccessibleName, sArea) == false)
                        {
                            return;
                        }
                    }
                    else
                    {
                        if (BASLIST.ViewGCMDataList(cdvsts.GetListView, '1', cdvsts.AccessibleName) == false)
                        {
                            return;
                        }
                    }

                    cdvsts.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvsts_Enter(object sender, EventArgs e)
        {
            try
            {
                cdvsts = Gf_Get_CodeView_By_Name(this.ActiveControl.Name, this);

                if (cdvsts.GetDisplayTextBox.TextAlign == HorizontalAlignment.Right)
                {
                    cdvsts.GetDisplayTextBox.SelectAll();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvsts_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                if (this.ActiveControl != null)
                {
                    cdvsts = Gf_Get_CodeView_By_Name(this.ActiveControl.Name, this);

                    if (cdvsts.GetDisplayTextBox.TextAlign == HorizontalAlignment.Right)
                    {
                        int cPosition = cdvsts.GetDisplayTextBox.SelectionStart;
                        cdvsts.Text = CheckTextNumeric(cdvsts.Text, cdvsts);
                        cdvsts.DisplayText = cdvsts.Text;
                        cdvsts.GetDisplayTextBox.Select(cPosition, 0);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvsts_TextBoxKeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                cdvsts = Gf_Get_CodeView_By_Name(this.ActiveControl.Name, this);

                if (cdvsts.GetDisplayTextBox.TextAlign == HorizontalAlignment.Right)
                {
                    preText = cdvsts.Text;
                }


                if (e.KeyCode == Keys.Enter)
                {
                    //SendKeys.Send("{TAB}");   //콤보박스때문에 사용x
                    //ParentForm.SelectNextControl(cdvsts, true, true, true, true);
                    Parent.SelectNextControl(cdvsts, true, true, true, true);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        protected string CheckTextNumeric(string text, Miracom.UI.Controls.MCCodeView.MCCodeView cdvsts)
        {
            double var = 0.0;
            bool change = double.TryParse(text, out var);

            if (preText != null)
            {
                //다 지웠을때 0으로 넣어줌
                if (text.Equals(""))
                {
                    change = true;
                    text = "";
                }
                //숫자가 아니면 이전 텍스트를 보여준다
                if (!change)
                {
                    if (text.Equals("-"))
                    {
                        text = "-0";
                    }
                    else
                    {
                        text = preText;
                    }
                }
                //숫자인 경우 0 관련 처리
                else if (cdvsts.Text.Length > 1 && !cdvsts.Text.Contains("."))
                {
                    if (cdvsts.Text.StartsWith("0"))
                    {
                        text = cdvsts.Text.Remove(0, 1);
                    }
                    else if (cdvsts.Text.StartsWith("-0") && cdvsts.Text.Length > 2)
                    {
                        text = cdvsts.Text.Remove(1, 1);
                    }
                }
            }

            return text;
        }

        #endregion

        [Browsable(false)]
        public string sArea_id
        {
            get;
            set;
        }
        [Browsable(false)]
        public string sArea_desc
        {
            get;
            set;
        }

        [Browsable(false)]
        public string sSub_Area_id
        {
            get;
            set;
        }

        [Browsable(false)]
        public string sSub_Area_desc
        {
            get;
            set;
        }

        [Browsable(false)]
        public string sOper_id
        {
            get;
            set;
        }


        [Browsable(false)]
        public string sOper_desc
        {
            get;
            set;
        }

        [Browsable(false)]
        public string sOrder
        {
            get;
            set;
        }

        [Browsable(false)]
        public string sRes_id
        {
            get;
            set;
        }
        [Browsable(false)]
        public string sRes_desc
        {
            get;
            set;
        }


    }
}
