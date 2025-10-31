using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using RawInput_dll;
using System.Windows.Forms;

namespace CUS_COM.Controls
{
    public partial class udcScanTextBox : TextBox
    {
        public bool IsCaptureFlag { get; set; }
        public RawInput ScanInput { get; set; }
        const bool CaptureOnlyInForeground = true;
        public CUS_COM.frmTranForm01 ParentForm;

        public udcScanTextBox()
        {
            InitializeComponent();
        }

        //public udcScanTextBox(IContainer container)
        //{
        //    container.Add(this);

        //    InitializeComponent();
        //}

        protected override void OnHandleCreated(EventArgs e)
        {
            base.OnHandleCreated(e);
            if (!DesignMode)
            {
                AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;

                ScanInput = new RawInput(this.Parent.Handle, CaptureOnlyInForeground);

                ScanInput.AddMessageFilter();   // Adding a message filter will cause key presses to be handled
                //Win32.DeviceAudit();            // Writes a file DeviceAudit.txt to the current directory
                ScanInput.KeyPressed += OnKeyPressed;

                IsCaptureFlag = true;

                ParentForm = GetBOIParentForm(this);
                if (ParentForm != null)
                {
                    ParentForm.ScanTextBox = this;
                    ParentForm.Activated += new EventHandler(ParentForm_Activated);
                    ParentForm.Deactivate += new EventHandler(ParentForm_Deactivate);
                }
            }
        }

        protected void ParentForm_Activated(object sender, EventArgs e)
        {
            try
            {
                AssignRawInputHandle();
            }
            catch
            {
            }
        }

        protected void ParentForm_Deactivate(object sender, EventArgs e)
        {            
            try
            {
                ReleaseRawInputHandle();
            }
            catch
            {
            }
        }       

        protected override void OnHandleDestroyed(EventArgs e)
        {
            base.OnHandleDestroyed(e);
            if (ScanInput != null)
            {
                ScanInput.KeyPressed -= OnKeyPressed;
                ScanInput.ReleaseRawInputHandle();
                ScanInput = null;
            }

            IsCaptureFlag = false;
        }
      

        protected override void OnEnter(EventArgs e)
        {
            base.OnEnter(e);
            ReleaseRawInputHandle();

        }

        protected override void OnLeave(EventArgs e)
        {
            base.OnLeave(e);
            AssignRawInputHandle();
        }


        private void OnKeyPressed(object sender, RawInputEventArg e)
        {
            if (!DesignMode)
            {
                switch (e.KeyPressEvent.Message)
                {
                    case Win32.WM_KEYDOWN:
                        if (this.Focused == false)
                        {
                            this.Text = "";
                            this.Focus();                            
                        }

                        break;
                    case Win32.WM_KEYUP:
                        break;
                }
            }
        }

        protected override void OnKeyDown(KeyEventArgs e)
        {
            if (e.KeyValue == (char)13)
            {
                this.Text = this.Text.ToUpper();
                this.SelectAll();
            }
            base.OnKeyDown(e);
        }

        protected override void OnPaint(System.Windows.Forms.PaintEventArgs pe)
        {
            base.OnPaint(pe);
        }

        private void CurrentDomain_UnhandledException(Object sender, UnhandledExceptionEventArgs e)
        {
            var ex = e.ExceptionObject as Exception;

            if (null == ex)
                return;       
        }

        public void AssignRawInputHandle()
        {
            if (!DesignMode)
            {
                if (ParentForm != null)
                {
                    if (ScanInput != null && ParentForm.IsActivated == true)
                    {
                        ScanInput.ReleaseHandle();
                        ScanInput.AssignRawInputHandle(Handle, CaptureOnlyInForeground);
                        ScanInput.AddMessageFilter();
                        ScanInput.KeyPressed += OnKeyPressed;
                        IsCaptureFlag = true;
                    }
                }
            }
        }

        public void ReleaseRawInputHandle()
        {
            if (!DesignMode)
            {
                if (ScanInput != null)
                {
                    ScanInput.KeyPressed -= OnKeyPressed;
                    ScanInput.ReleaseRawInputHandle();
                    IsCaptureFlag = false;
                }
            }
        }

        CUS_COM.frmTranForm01 GetBOIParentForm(Control control)
        {
            CUS_COM.frmTranForm01 parentForm;

            if (control is CUS_COM.frmTranForm01)
            {
                return control as CUS_COM.frmTranForm01;                
            }
            else if (control is CUS_COM.frmTranForm01)
            {
                return control as CUS_COM.frmTranForm01;
            }
            else
            {
                parentForm = GetBOIParentForm(control.Parent);
                if (parentForm != null)
                {
                    return parentForm;
                }
            }

            return null;
        }
    }
}
