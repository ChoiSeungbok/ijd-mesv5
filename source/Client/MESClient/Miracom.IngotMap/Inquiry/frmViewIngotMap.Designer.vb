<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmViewIngotMap
    Inherits System.Windows.Forms.Form

    'Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows Form 디자이너에 필요합니다.
    Private components As System.ComponentModel.IContainer

    '참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
    '수정하려면 Windows Form 디자이너를 사용하십시오.  
    '코드 편집기를 사용하여 수정하지 마십시오.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmViewIngotMap))
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.txtClickInfo = New System.Windows.Forms.TextBox
        Me.btnPrint3 = New System.Windows.Forms.Button
        Me.btnSaveImage3 = New System.Windows.Forms.Button
        Me.btnCopyImage3 = New System.Windows.Forms.Button
        Me.btnPrint2 = New System.Windows.Forms.Button
        Me.btnSaveImage2 = New System.Windows.Forms.Button
        Me.btnCopyImage2 = New System.Windows.Forms.Button
        Me.btnPrint1 = New System.Windows.Forms.Button
        Me.btnSaveImage1 = New System.Windows.Forms.Button
        Me.btnCopyImage1 = New System.Windows.Forms.Button
        Me.btnClose = New System.Windows.Forms.Button
        Me.btnView = New System.Windows.Forms.Button
        Me.SplitContainer1 = New System.Windows.Forms.SplitContainer
        Me.TableLayoutPanel1 = New System.Windows.Forms.TableLayoutPanel
        Me.IngotMap1 = New Miracom.IngotMap.IngotMap
        Me.IngotMap3 = New Miracom.IngotMap.IngotMap
        Me.IngotMap2 = New Miracom.IngotMap.IngotMap
        Me.Panel1.SuspendLayout()
        Me.SplitContainer1.Panel1.SuspendLayout()
        Me.SplitContainer1.Panel2.SuspendLayout()
        Me.SplitContainer1.SuspendLayout()
        Me.TableLayoutPanel1.SuspendLayout()
        Me.SuspendLayout()
        '
        'Panel1
        '
        Me.Panel1.Controls.Add(Me.txtClickInfo)
        Me.Panel1.Controls.Add(Me.btnPrint3)
        Me.Panel1.Controls.Add(Me.btnSaveImage3)
        Me.Panel1.Controls.Add(Me.btnCopyImage3)
        Me.Panel1.Controls.Add(Me.btnPrint2)
        Me.Panel1.Controls.Add(Me.btnSaveImage2)
        Me.Panel1.Controls.Add(Me.btnCopyImage2)
        Me.Panel1.Controls.Add(Me.btnPrint1)
        Me.Panel1.Controls.Add(Me.btnSaveImage1)
        Me.Panel1.Controls.Add(Me.btnCopyImage1)
        Me.Panel1.Controls.Add(Me.btnClose)
        Me.Panel1.Controls.Add(Me.btnView)
        Me.Panel1.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.Panel1.Location = New System.Drawing.Point(0, 565)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(758, 44)
        Me.Panel1.TabIndex = 0
        '
        'txtClickInfo
        '
        Me.txtClickInfo.Location = New System.Drawing.Point(324, 14)
        Me.txtClickInfo.Name = "txtClickInfo"
        Me.txtClickInfo.Size = New System.Drawing.Size(205, 20)
        Me.txtClickInfo.TabIndex = 18
        '
        'btnPrint3
        '
        Me.btnPrint3.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnPrint3.Image = CType(resources.GetObject("btnPrint3.Image"), System.Drawing.Image)
        Me.btnPrint3.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnPrint3.Location = New System.Drawing.Point(249, 10)
        Me.btnPrint3.Name = "btnPrint3"
        Me.btnPrint3.Size = New System.Drawing.Size(21, 26)
        Me.btnPrint3.TabIndex = 17
        '
        'btnSaveImage3
        '
        Me.btnSaveImage3.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnSaveImage3.Image = CType(resources.GetObject("btnSaveImage3.Image"), System.Drawing.Image)
        Me.btnSaveImage3.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnSaveImage3.Location = New System.Drawing.Point(225, 10)
        Me.btnSaveImage3.Name = "btnSaveImage3"
        Me.btnSaveImage3.Size = New System.Drawing.Size(21, 26)
        Me.btnSaveImage3.TabIndex = 16
        '
        'btnCopyImage3
        '
        Me.btnCopyImage3.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnCopyImage3.Image = CType(resources.GetObject("btnCopyImage3.Image"), System.Drawing.Image)
        Me.btnCopyImage3.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnCopyImage3.Location = New System.Drawing.Point(201, 10)
        Me.btnCopyImage3.Name = "btnCopyImage3"
        Me.btnCopyImage3.Size = New System.Drawing.Size(21, 26)
        Me.btnCopyImage3.TabIndex = 15
        '
        'btnPrint2
        '
        Me.btnPrint2.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnPrint2.Image = CType(resources.GetObject("btnPrint2.Image"), System.Drawing.Image)
        Me.btnPrint2.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnPrint2.Location = New System.Drawing.Point(154, 10)
        Me.btnPrint2.Name = "btnPrint2"
        Me.btnPrint2.Size = New System.Drawing.Size(21, 26)
        Me.btnPrint2.TabIndex = 14
        '
        'btnSaveImage2
        '
        Me.btnSaveImage2.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnSaveImage2.Image = CType(resources.GetObject("btnSaveImage2.Image"), System.Drawing.Image)
        Me.btnSaveImage2.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnSaveImage2.Location = New System.Drawing.Point(130, 10)
        Me.btnSaveImage2.Name = "btnSaveImage2"
        Me.btnSaveImage2.Size = New System.Drawing.Size(21, 26)
        Me.btnSaveImage2.TabIndex = 13
        '
        'btnCopyImage2
        '
        Me.btnCopyImage2.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnCopyImage2.Image = CType(resources.GetObject("btnCopyImage2.Image"), System.Drawing.Image)
        Me.btnCopyImage2.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnCopyImage2.Location = New System.Drawing.Point(106, 10)
        Me.btnCopyImage2.Name = "btnCopyImage2"
        Me.btnCopyImage2.Size = New System.Drawing.Size(21, 26)
        Me.btnCopyImage2.TabIndex = 12
        '
        'btnPrint1
        '
        Me.btnPrint1.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnPrint1.Image = CType(resources.GetObject("btnPrint1.Image"), System.Drawing.Image)
        Me.btnPrint1.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnPrint1.Location = New System.Drawing.Point(58, 10)
        Me.btnPrint1.Name = "btnPrint1"
        Me.btnPrint1.Size = New System.Drawing.Size(21, 26)
        Me.btnPrint1.TabIndex = 11
        '
        'btnSaveImage1
        '
        Me.btnSaveImage1.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnSaveImage1.Image = CType(resources.GetObject("btnSaveImage1.Image"), System.Drawing.Image)
        Me.btnSaveImage1.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnSaveImage1.Location = New System.Drawing.Point(34, 10)
        Me.btnSaveImage1.Name = "btnSaveImage1"
        Me.btnSaveImage1.Size = New System.Drawing.Size(21, 26)
        Me.btnSaveImage1.TabIndex = 10
        '
        'btnCopyImage1
        '
        Me.btnCopyImage1.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnCopyImage1.Image = CType(resources.GetObject("btnCopyImage1.Image"), System.Drawing.Image)
        Me.btnCopyImage1.ImeMode = System.Windows.Forms.ImeMode.NoControl
        Me.btnCopyImage1.Location = New System.Drawing.Point(10, 10)
        Me.btnCopyImage1.Name = "btnCopyImage1"
        Me.btnCopyImage1.Size = New System.Drawing.Size(21, 26)
        Me.btnCopyImage1.TabIndex = 9
        '
        'btnClose
        '
        Me.btnClose.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btnClose.Location = New System.Drawing.Point(667, 8)
        Me.btnClose.Name = "btnClose"
        Me.btnClose.Size = New System.Drawing.Size(81, 28)
        Me.btnClose.TabIndex = 1
        Me.btnClose.Text = "Close"
        Me.btnClose.UseVisualStyleBackColor = True
        '
        'btnView
        '
        Me.btnView.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.btnView.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btnView.Location = New System.Drawing.Point(581, 8)
        Me.btnView.Name = "btnView"
        Me.btnView.Size = New System.Drawing.Size(81, 28)
        Me.btnView.TabIndex = 0
        Me.btnView.Text = "View"
        Me.btnView.UseVisualStyleBackColor = True
        '
        'SplitContainer1
        '
        Me.SplitContainer1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.SplitContainer1.Location = New System.Drawing.Point(0, 0)
        Me.SplitContainer1.Name = "SplitContainer1"
        '
        'SplitContainer1.Panel1
        '
        Me.SplitContainer1.Panel1.Controls.Add(Me.IngotMap1)
        '
        'SplitContainer1.Panel2
        '
        Me.SplitContainer1.Panel2.Controls.Add(Me.TableLayoutPanel1)
        Me.SplitContainer1.Size = New System.Drawing.Size(758, 565)
        Me.SplitContainer1.SplitterDistance = 292
        Me.SplitContainer1.SplitterWidth = 3
        Me.SplitContainer1.TabIndex = 1
        '
        'TableLayoutPanel1
        '
        Me.TableLayoutPanel1.ColumnCount = 1
        Me.TableLayoutPanel1.ColumnStyles.Add(New System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50.0!))
        Me.TableLayoutPanel1.Controls.Add(Me.IngotMap3, 0, 1)
        Me.TableLayoutPanel1.Controls.Add(Me.IngotMap2, 0, 0)
        Me.TableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.TableLayoutPanel1.Location = New System.Drawing.Point(0, 0)
        Me.TableLayoutPanel1.Name = "TableLayoutPanel1"
        Me.TableLayoutPanel1.RowCount = 2
        Me.TableLayoutPanel1.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50.0!))
        Me.TableLayoutPanel1.RowStyles.Add(New System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50.0!))
        Me.TableLayoutPanel1.Size = New System.Drawing.Size(463, 565)
        Me.TableLayoutPanel1.TabIndex = 2
        '
        'IngotMap1
        '
        Me.IngotMap1.BGColor = System.Drawing.Color.WhiteSmoke
        Me.IngotMap1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.IngotMap1.IngotMapType = Miracom.IngotMap.modEnums.INGOT_MAP_TYPE.TYPE_1
        Me.IngotMap1.Location = New System.Drawing.Point(0, 0)
        Me.IngotMap1.MainTitle = ""
        Me.IngotMap1.Name = "IngotMap1"
        Me.IngotMap1.Size = New System.Drawing.Size(292, 565)
        Me.IngotMap1.TabIndex = 0
        '
        'IngotMap3
        '
        Me.IngotMap3.BGColor = System.Drawing.Color.WhiteSmoke
        Me.IngotMap3.Dock = System.Windows.Forms.DockStyle.Fill
        Me.IngotMap3.IngotMapType = Miracom.IngotMap.modEnums.INGOT_MAP_TYPE.TYPE_1
        Me.IngotMap3.Location = New System.Drawing.Point(0, 282)
        Me.IngotMap3.MainTitle = ""
        Me.IngotMap3.Margin = New System.Windows.Forms.Padding(0)
        Me.IngotMap3.Name = "IngotMap3"
        Me.IngotMap3.Size = New System.Drawing.Size(463, 283)
        Me.IngotMap3.TabIndex = 2
        '
        'IngotMap2
        '
        Me.IngotMap2.BGColor = System.Drawing.Color.WhiteSmoke
        Me.IngotMap2.Dock = System.Windows.Forms.DockStyle.Fill
        Me.IngotMap2.IngotMapType = Miracom.IngotMap.modEnums.INGOT_MAP_TYPE.TYPE_1
        Me.IngotMap2.Location = New System.Drawing.Point(0, 0)
        Me.IngotMap2.MainTitle = ""
        Me.IngotMap2.Margin = New System.Windows.Forms.Padding(0)
        Me.IngotMap2.Name = "IngotMap2"
        Me.IngotMap2.Size = New System.Drawing.Size(463, 282)
        Me.IngotMap2.TabIndex = 1
        '
        'frmViewIngotMap
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(758, 609)
        Me.Controls.Add(Me.SplitContainer1)
        Me.Controls.Add(Me.Panel1)
        Me.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!)
        Me.Name = "frmViewIngotMap"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
        Me.Text = "View Ingot Map"
        Me.Panel1.ResumeLayout(False)
        Me.Panel1.PerformLayout()
        Me.SplitContainer1.Panel1.ResumeLayout(False)
        Me.SplitContainer1.Panel2.ResumeLayout(False)
        Me.SplitContainer1.ResumeLayout(False)
        Me.TableLayoutPanel1.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents SplitContainer1 As System.Windows.Forms.SplitContainer
    Friend WithEvents IngotMap1 As Miracom.IngotMap.IngotMap
    Friend WithEvents IngotMap2 As Miracom.IngotMap.IngotMap
    Friend WithEvents btnClose As System.Windows.Forms.Button
    Friend WithEvents btnView As System.Windows.Forms.Button
    Friend WithEvents TableLayoutPanel1 As System.Windows.Forms.TableLayoutPanel
    Friend WithEvents IngotMap3 As Miracom.IngotMap.IngotMap
    Friend WithEvents btnPrint1 As System.Windows.Forms.Button
    Friend WithEvents btnSaveImage1 As System.Windows.Forms.Button
    Friend WithEvents btnCopyImage1 As System.Windows.Forms.Button
    Friend WithEvents btnSaveImage2 As System.Windows.Forms.Button
    Friend WithEvents btnCopyImage2 As System.Windows.Forms.Button
    Friend WithEvents btnPrint3 As System.Windows.Forms.Button
    Friend WithEvents btnSaveImage3 As System.Windows.Forms.Button
    Friend WithEvents btnCopyImage3 As System.Windows.Forms.Button
    Friend WithEvents btnPrint2 As System.Windows.Forms.Button
    Friend WithEvents txtClickInfo As System.Windows.Forms.TextBox
End Class
