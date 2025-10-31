namespace Admin.RPTCore
{
    partial class frmDBReplicationTest
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        //Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
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

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.pnlCenter = new System.Windows.Forms.Panel();
            this.rtxProgress = new System.Windows.Forms.RichTextBox();
            this.lisColList = new System.Windows.Forms.ListView();
            this.ColSel = new System.Windows.Forms.ColumnHeader();
            this.ColA = new System.Windows.Forms.ColumnHeader();
            this.ColB = new System.Windows.Forms.ColumnHeader();
            this.ColC = new System.Windows.Forms.ColumnHeader();
            this.ColD = new System.Windows.Forms.ColumnHeader();
            this.ColE = new System.Windows.Forms.ColumnHeader();
            this.ColF = new System.Windows.Forms.ColumnHeader();
            this.ColG = new System.Windows.Forms.ColumnHeader();
            this.ColH = new System.Windows.Forms.ColumnHeader();
            this.ColI = new System.Windows.Forms.ColumnHeader();
            this.ColJ = new System.Windows.Forms.ColumnHeader();
            this.ColK = new System.Windows.Forms.ColumnHeader();
            this.ColL = new System.Windows.Forms.ColumnHeader();
            this.ColM = new System.Windows.Forms.ColumnHeader();
            this.ColN = new System.Windows.Forms.ColumnHeader();
            this.ColO = new System.Windows.Forms.ColumnHeader();
            this.ColP = new System.Windows.Forms.ColumnHeader();
            this.ColQ = new System.Windows.Forms.ColumnHeader();
            this.ColR = new System.Windows.Forms.ColumnHeader();
            this.ColS = new System.Windows.Forms.ColumnHeader();
            this.colNo = new System.Windows.Forms.ColumnHeader();
            this.colFieldName = new System.Windows.Forms.ColumnHeader();
            this.colPK = new System.Windows.Forms.ColumnHeader();
            this.colNumericScale = new System.Windows.Forms.ColumnHeader();
            this.colDataType = new System.Windows.Forms.ColumnHeader();
            this.colSize = new System.Windows.Forms.ColumnHeader();
            this.colNull = new System.Windows.Forms.ColumnHeader();
            this.pnlLeft = new System.Windows.Forms.Panel();
            this.lisTable = new System.Windows.Forms.ListView();
            this.ColHead1 = new System.Windows.Forms.ColumnHeader();
            this.ColHead2 = new System.Windows.Forms.ColumnHeader();
            this.ColHead3 = new System.Windows.Forms.ColumnHeader();
            this.ColHead4 = new System.Windows.Forms.ColumnHeader();
            this.pnlTop = new System.Windows.Forms.Panel();
            this.txtChannel = new System.Windows.Forms.TextBox();
            this.lblChannelId = new System.Windows.Forms.Label();
            this.colPrecision = new System.Windows.Forms.ColumnHeader();
            this.grpGenInfo = new System.Windows.Forms.GroupBox();
            this.txtSeq = new System.Windows.Forms.TextBox();
            this.txtCount = new System.Windows.Forms.MaskedTextBox();
            this.btnFileDialog = new System.Windows.Forms.Button();
            this.txtFileName = new System.Windows.Forms.TextBox();
            this.lblOpenFile = new System.Windows.Forms.Label();
            this.lblCount = new System.Windows.Forms.Label();
            this.txtLotId = new System.Windows.Forms.TextBox();
            this.btnLoad = new System.Windows.Forms.Button();
            this.lblLotId = new System.Windows.Forms.Label();
            this.btnRun = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnView = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.pnlCenter.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.grpGenInfo.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.rtxProgress);
            this.pnlCenter.Controls.Add(this.lisColList);
            this.pnlCenter.Location = new System.Drawing.Point(260, 36);
            this.pnlCenter.Name = "pnlCenter";
            this.pnlCenter.Padding = new System.Windows.Forms.Padding(0, 0, 5, 5);
            this.pnlCenter.Size = new System.Drawing.Size(618, 453);
            this.pnlCenter.TabIndex = 27;
            // 
            // rtxProgress
            // 
            this.rtxProgress.Location = new System.Drawing.Point(-1, 3);
            this.rtxProgress.Name = "rtxProgress";
            this.rtxProgress.Size = new System.Drawing.Size(614, 447);
            this.rtxProgress.TabIndex = 4;
            this.rtxProgress.Text = "";
            this.rtxProgress.Visible = false;
            // 
            // lisColList
            // 
            this.lisColList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColSel,
            this.ColA,
            this.ColB,
            this.ColC,
            this.ColD,
            this.ColE,
            this.ColF,
            this.ColG,
            this.ColH,
            this.ColI,
            this.ColJ,
            this.ColK,
            this.ColL,
            this.ColM,
            this.ColN,
            this.ColO,
            this.ColP,
            this.ColQ,
            this.ColR,
            this.ColS});
            this.lisColList.FullRowSelect = true;
            this.lisColList.Location = new System.Drawing.Point(4, 3);
            this.lisColList.Name = "lisColList";
            this.lisColList.Size = new System.Drawing.Size(609, 447);
            this.lisColList.TabIndex = 3;
            this.lisColList.UseCompatibleStateImageBehavior = false;
            this.lisColList.View = System.Windows.Forms.View.Details;
            // 
            // ColSel
            // 
            this.ColSel.Text = "Sel";
            this.ColSel.Width = 30;
            // 
            // ColA
            // 
            this.ColA.Text = "A";
            this.ColA.Width = 30;
            // 
            // ColB
            // 
            this.ColB.Text = "B";
            this.ColB.Width = 30;
            // 
            // ColC
            // 
            this.ColC.Text = "C";
            this.ColC.Width = 30;
            // 
            // ColD
            // 
            this.ColD.Text = "D";
            this.ColD.Width = 30;
            // 
            // ColE
            // 
            this.ColE.Text = "E";
            this.ColE.Width = 30;
            // 
            // ColF
            // 
            this.ColF.Text = "F";
            this.ColF.Width = 30;
            // 
            // ColG
            // 
            this.ColG.Text = "G";
            this.ColG.Width = 30;
            // 
            // ColH
            // 
            this.ColH.Text = "H";
            this.ColH.Width = 30;
            // 
            // ColI
            // 
            this.ColI.Text = "I";
            this.ColI.Width = 30;
            // 
            // ColJ
            // 
            this.ColJ.Text = "J";
            this.ColJ.Width = 30;
            // 
            // ColK
            // 
            this.ColK.Text = "K";
            this.ColK.Width = 30;
            // 
            // ColL
            // 
            this.ColL.Text = "L";
            this.ColL.Width = 30;
            // 
            // ColM
            // 
            this.ColM.Text = "M";
            this.ColM.Width = 30;
            // 
            // ColN
            // 
            this.ColN.Text = "N";
            this.ColN.Width = 30;
            // 
            // ColO
            // 
            this.ColO.Text = "O";
            this.ColO.Width = 30;
            // 
            // ColP
            // 
            this.ColP.Text = "P";
            this.ColP.Width = 30;
            // 
            // ColQ
            // 
            this.ColQ.Text = "Q";
            this.ColQ.Width = 30;
            // 
            // ColR
            // 
            this.ColR.Text = "R";
            this.ColR.Width = 30;
            // 
            // ColS
            // 
            this.ColS.Text = "S";
            this.ColS.Width = 30;
            // 
            // colNo
            // 
            this.colNo.Text = "No.";
            this.colNo.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.colNo.Width = 39;
            // 
            // colFieldName
            // 
            this.colFieldName.Text = "Field Name";
            this.colFieldName.Width = 166;
            // 
            // colPK
            // 
            this.colPK.Text = "PK";
            this.colPK.Width = 47;
            // 
            // colNumericScale
            // 
            this.colNumericScale.Text = "Numeric Scale";
            this.colNumericScale.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.colNumericScale.Width = 97;
            // 
            // colDataType
            // 
            this.colDataType.Text = "Data Type";
            this.colDataType.Width = 77;
            // 
            // colSize
            // 
            this.colSize.Text = "Size";
            this.colSize.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.colSize.Width = 53;
            // 
            // colNull
            // 
            this.colNull.Text = "Null?";
            this.colNull.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.colNull.Width = 42;
            // 
            // pnlLeft
            // 
            this.pnlLeft.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.pnlLeft.Controls.Add(this.lisTable);
            this.pnlLeft.Location = new System.Drawing.Point(0, 36);
            this.pnlLeft.Name = "pnlLeft";
            this.pnlLeft.Padding = new System.Windows.Forms.Padding(5, 0, 0, 5);
            this.pnlLeft.Size = new System.Drawing.Size(256, 453);
            this.pnlLeft.TabIndex = 25;
            // 
            // lisTable
            // 
            this.lisTable.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.lisTable.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColHead1,
            this.ColHead2,
            this.ColHead3,
            this.ColHead4});
            this.lisTable.FullRowSelect = true;
            this.lisTable.HideSelection = false;
            this.lisTable.Location = new System.Drawing.Point(3, 3);
            this.lisTable.MultiSelect = false;
            this.lisTable.Name = "lisTable";
            this.lisTable.Size = new System.Drawing.Size(250, 447);
            this.lisTable.TabIndex = 1;
            this.lisTable.UseCompatibleStateImageBehavior = false;
            this.lisTable.View = System.Windows.Forms.View.Details;
            this.lisTable.Click += new System.EventHandler(this.lisTable_Click);
            // 
            // ColHead1
            // 
            this.ColHead1.Text = "File Name";
            this.ColHead1.Width = 116;
            // 
            // ColHead2
            // 
            this.ColHead2.Text = "LotId";
            // 
            // ColHead3
            // 
            this.ColHead3.Text = "Seq";
            this.ColHead3.Width = 35;
            // 
            // ColHead4
            // 
            this.ColHead4.Text = "Cnt";
            this.ColHead4.Width = 35;
            // 
            // pnlTop
            // 
            this.pnlTop.Controls.Add(this.txtChannel);
            this.pnlTop.Controls.Add(this.lblChannelId);
            this.pnlTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTop.Location = new System.Drawing.Point(0, 0);
            this.pnlTop.Name = "pnlTop";
            this.pnlTop.Padding = new System.Windows.Forms.Padding(5, 3, 5, 5);
            this.pnlTop.Size = new System.Drawing.Size(878, 36);
            this.pnlTop.TabIndex = 24;
            // 
            // txtChannel
            // 
            this.txtChannel.Location = new System.Drawing.Point(83, 6);
            this.txtChannel.Name = "txtChannel";
            this.txtChannel.Size = new System.Drawing.Size(487, 20);
            this.txtChannel.TabIndex = 8;
            this.txtChannel.Text = "Siltronic.TSK1.LW.MES.MESServer.Command.>";
            // 
            // lblChannelId
            // 
            this.lblChannelId.AutoSize = true;
            this.lblChannelId.Location = new System.Drawing.Point(19, 9);
            this.lblChannelId.Name = "lblChannelId";
            this.lblChannelId.Size = new System.Drawing.Size(58, 13);
            this.lblChannelId.TabIndex = 7;
            this.lblChannelId.Text = "Channel Id";
            this.lblChannelId.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // colPrecision
            // 
            this.colPrecision.Text = "Precision";
            this.colPrecision.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.colPrecision.Width = 69;
            // 
            // grpGenInfo
            // 
            this.grpGenInfo.Controls.Add(this.txtSeq);
            this.grpGenInfo.Controls.Add(this.txtCount);
            this.grpGenInfo.Controls.Add(this.btnFileDialog);
            this.grpGenInfo.Controls.Add(this.txtFileName);
            this.grpGenInfo.Controls.Add(this.lblOpenFile);
            this.grpGenInfo.Controls.Add(this.lblCount);
            this.grpGenInfo.Controls.Add(this.txtLotId);
            this.grpGenInfo.Controls.Add(this.btnLoad);
            this.grpGenInfo.Controls.Add(this.lblLotId);
            this.grpGenInfo.Location = new System.Drawing.Point(3, 0);
            this.grpGenInfo.Name = "grpGenInfo";
            this.grpGenInfo.Size = new System.Drawing.Size(870, 71);
            this.grpGenInfo.TabIndex = 9;
            this.grpGenInfo.TabStop = false;
            // 
            // txtSeq
            // 
            this.txtSeq.Location = new System.Drawing.Point(201, 16);
            this.txtSeq.Name = "txtSeq";
            this.txtSeq.Size = new System.Drawing.Size(49, 20);
            this.txtSeq.TabIndex = 12;
            this.txtSeq.Text = "001";
            this.txtSeq.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtSeq_KeyPress);
            // 
            // txtCount
            // 
            this.txtCount.Location = new System.Drawing.Point(442, 16);
            this.txtCount.Name = "txtCount";
            this.txtCount.Size = new System.Drawing.Size(42, 20);
            this.txtCount.TabIndex = 11;
            this.txtCount.Text = "5";
            this.txtCount.ValidatingType = typeof(int);
            this.txtCount.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtCount_KeyPress);
            // 
            // btnFileDialog
            // 
            this.btnFileDialog.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnFileDialog.Location = new System.Drawing.Point(393, 42);
            this.btnFileDialog.Name = "btnFileDialog";
            this.btnFileDialog.Size = new System.Drawing.Size(23, 20);
            this.btnFileDialog.TabIndex = 10;
            this.btnFileDialog.Text = "...";
            this.btnFileDialog.UseVisualStyleBackColor = true;
            this.btnFileDialog.Click += new System.EventHandler(this.btnFileDialog_Click);
            // 
            // txtFileName
            // 
            this.txtFileName.Location = new System.Drawing.Point(78, 42);
            this.txtFileName.Name = "txtFileName";
            this.txtFileName.Size = new System.Drawing.Size(315, 20);
            this.txtFileName.TabIndex = 9;
            this.txtFileName.Text = "c:\\SampleWorksheet.xls";
            // 
            // lblOpenFile
            // 
            this.lblOpenFile.AutoSize = true;
            this.lblOpenFile.Location = new System.Drawing.Point(16, 46);
            this.lblOpenFile.Name = "lblOpenFile";
            this.lblOpenFile.Size = new System.Drawing.Size(52, 13);
            this.lblOpenFile.TabIndex = 6;
            this.lblOpenFile.Text = "Open File";
            this.lblOpenFile.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblCount
            // 
            this.lblCount.AutoSize = true;
            this.lblCount.Location = new System.Drawing.Point(401, 19);
            this.lblCount.Name = "lblCount";
            this.lblCount.Size = new System.Drawing.Size(35, 13);
            this.lblCount.TabIndex = 5;
            this.lblCount.Text = "Count";
            this.lblCount.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtLotId
            // 
            this.txtLotId.Location = new System.Drawing.Point(78, 16);
            this.txtLotId.Name = "txtLotId";
            this.txtLotId.Size = new System.Drawing.Size(117, 20);
            this.txtLotId.TabIndex = 4;
            this.txtLotId.Text = "lotidabc";
            // 
            // btnLoad
            // 
            this.btnLoad.Location = new System.Drawing.Point(800, 35);
            this.btnLoad.Name = "btnLoad";
            this.btnLoad.Size = new System.Drawing.Size(70, 24);
            this.btnLoad.TabIndex = 3;
            this.btnLoad.Text = "Load";
            this.btnLoad.Click += new System.EventHandler(this.btnLoad_Click);
            // 
            // lblLotId
            // 
            this.lblLotId.AutoSize = true;
            this.lblLotId.Location = new System.Drawing.Point(16, 19);
            this.lblLotId.Name = "lblLotId";
            this.lblLotId.Size = new System.Drawing.Size(36, 13);
            this.lblLotId.TabIndex = 2;
            this.lblLotId.Text = "Lot ID";
            this.lblLotId.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnRun
            // 
            this.btnRun.Location = new System.Drawing.Point(623, 72);
            this.btnRun.Name = "btnRun";
            this.btnRun.Size = new System.Drawing.Size(70, 24);
            this.btnRun.TabIndex = 3;
            this.btnRun.Text = "Run";
            this.btnRun.Click += new System.EventHandler(this.btnExecute_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(803, 72);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(70, 24);
            this.btnClose.TabIndex = 10;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.pnlBottom.Controls.Add(this.btnView);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Controls.Add(this.btnRun);
            this.pnlBottom.Controls.Add(this.grpGenInfo);
            this.pnlBottom.Location = new System.Drawing.Point(0, 492);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(878, 99);
            this.pnlBottom.TabIndex = 28;
            // 
            // btnView
            // 
            this.btnView.Location = new System.Drawing.Point(714, 72);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(70, 24);
            this.btnView.TabIndex = 11;
            this.btnView.Text = "View Log";
            this.btnView.UseVisualStyleBackColor = true;
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // frmDBReplicationTest
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(878, 592);
            this.Controls.Add(this.pnlCenter);
            this.Controls.Add(this.pnlTop);
            this.Controls.Add(this.pnlLeft);
            this.Controls.Add(this.pnlBottom);
            this.MinimumSize = new System.Drawing.Size(644, 626);
            this.Name = "frmDBReplicationTest";
            this.Text = "frmDBReplicationTest";
            this.Activated += new System.EventHandler(this.frmDBReplicationTest_Activated);
            this.Load += new System.EventHandler(this.frmDBReplicationTest_Load);
            this.pnlCenter.ResumeLayout(false);
            this.pnlLeft.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlTop.PerformLayout();
            this.grpGenInfo.ResumeLayout(false);
            this.grpGenInfo.PerformLayout();
            this.pnlBottom.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        internal System.Windows.Forms.Panel pnlCenter;
        internal System.Windows.Forms.ColumnHeader colNo;
        internal System.Windows.Forms.ColumnHeader colFieldName;
        internal System.Windows.Forms.ColumnHeader colPK;
        internal System.Windows.Forms.ColumnHeader colNumericScale;
        internal System.Windows.Forms.ColumnHeader colDataType;
        internal System.Windows.Forms.ColumnHeader colSize;
        internal System.Windows.Forms.ColumnHeader colNull;
        internal System.Windows.Forms.Panel pnlLeft;
        internal System.Windows.Forms.ListView lisTable;
        internal System.Windows.Forms.ColumnHeader ColHead1;
        internal System.Windows.Forms.ColumnHeader ColHead2;
        internal System.Windows.Forms.Panel pnlTop;
        internal System.Windows.Forms.ColumnHeader colPrecision;
        internal System.Windows.Forms.GroupBox grpGenInfo;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.TextBox txtLotId;
        internal System.Windows.Forms.Button btnLoad;
        internal System.Windows.Forms.Button btnRun;
        internal System.Windows.Forms.Label lblLotId;
        internal System.Windows.Forms.ListView lisColList;
        internal System.Windows.Forms.ColumnHeader ColSel;
        internal System.Windows.Forms.ColumnHeader ColB;
        internal System.Windows.Forms.ColumnHeader ColC;
        internal System.Windows.Forms.ColumnHeader ColD;
        internal System.Windows.Forms.ColumnHeader ColE;
        internal System.Windows.Forms.ColumnHeader ColF;
        internal System.Windows.Forms.ColumnHeader ColG;
        internal System.Windows.Forms.ColumnHeader ColH;
        private System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Label lblCount;
        internal System.Windows.Forms.Label lblOpenFile;
        internal System.Windows.Forms.Label lblChannelId;
        internal System.Windows.Forms.TextBox txtChannel;
        internal System.Windows.Forms.TextBox txtFileName;
        internal System.Windows.Forms.ColumnHeader ColHead3;
        internal System.Windows.Forms.ColumnHeader ColHead4;
        private System.Windows.Forms.ColumnHeader ColA;
        private System.Windows.Forms.ColumnHeader ColI;
        private System.Windows.Forms.ColumnHeader ColJ;
        private System.Windows.Forms.ColumnHeader ColK;
        private System.Windows.Forms.ColumnHeader ColL;
        private System.Windows.Forms.ColumnHeader ColM;
        private System.Windows.Forms.ColumnHeader ColN;
        private System.Windows.Forms.ColumnHeader ColO;
        private System.Windows.Forms.ColumnHeader ColP;
        private System.Windows.Forms.ColumnHeader ColQ;
        private System.Windows.Forms.ColumnHeader ColR;
        private System.Windows.Forms.ColumnHeader ColS;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button btnFileDialog;
        private System.Windows.Forms.MaskedTextBox txtCount;
        private System.Windows.Forms.TextBox txtSeq;
        private System.Windows.Forms.RichTextBox rtxProgress;
        private System.Windows.Forms.Button btnView;
    }
}