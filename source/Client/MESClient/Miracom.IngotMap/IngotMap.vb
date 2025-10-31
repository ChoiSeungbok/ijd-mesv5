Imports System.ComponentModel

Public Class IngotMap

#Region "Properties Implementation"

    'Ingot Map Type
    Private m_eIngotMapType As INGOT_MAP_TYPE
    Private m_sMainTitle As String = STRING_NULL_DATA
    Private m_crBGColor As Color = Color.White
    Private m_iIngotMapHeight As Integer = 50
    Private m_iVerticalBarSize As Integer = 50
    Private m_iHorizontalBarSize As Integer = 70
    Private m_iPPNQty As Integer = 0

    ' Inner Properties
    Private m_DataSet As DataSet.clsIngotMapDataSet = New DataSet.clsIngotMapDataSet(Me)
    Private m_DrawIngotMap As DrawIngotMap.clsIngotMap = New DrawIngotMap.clsIngotMap(Me)
    Private m_bPrinting As Boolean = False
    Private m_bSaveImage As Boolean = False
    Private m_bCopyImage As Boolean = False
    Private m_sSaveImageFileName As String = ""
    Private m_bAddDataFlag As Boolean = False
    Private m_bModifiedFlag As Boolean = False
    Private m_bFirstDrawFlag As Boolean = False

    Public Property IngotMapHeight() As Integer
        Get
            Return m_iIngotMapHeight
        End Get
        Set(ByVal Value As Integer)
            If m_iIngotMapHeight.Equals(Value) = False Then
                m_iIngotMapHeight = Value
            End If
        End Set
    End Property

    Public Property VerticalBarSize() As Integer
        Get
            Return m_iVerticalBarSize
        End Get
        Set(ByVal Value As Integer)
            If m_iVerticalBarSize.Equals(Value) = False Then
                m_iVerticalBarSize = Value
            End If
        End Set
    End Property

    Public Property HorizontalBarSize() As Integer
        Get
            Return m_iHorizontalBarSize
        End Get
        Set(ByVal Value As Integer)
            If m_iHorizontalBarSize.Equals(Value) = False Then
                m_iHorizontalBarSize = Value
            End If
        End Set
    End Property

    Public Property PPNQty() As Integer
        Get
            Return m_iPPNQty
        End Get
        Set(ByVal Value As Integer)
            If m_iPPNQty.Equals(Value) = False Then
                m_iPPNQty = Value
            End If
        End Set
    End Property

    Public Property IngotMapType() As INGOT_MAP_TYPE
        Get
            Return m_eIngotMapType
        End Get
        Set(ByVal Value As INGOT_MAP_TYPE)
            If m_eIngotMapType.Equals(Value) = False Then
                m_eIngotMapType = Value
            End If
        End Set
    End Property

    Public Property MainTitle() As String
        Get
            Return m_sMainTitle
        End Get
        Set(ByVal Value As String)
            If m_sMainTitle.Equals(Value) = False Then
                m_sMainTitle = Value
            End If
        End Set
    End Property

    Public Property BGColor() As Color
        Get
            Return m_crBGColor
        End Get
        Set(ByVal Value As Color)
            If m_crBGColor.Equals(Value) = False Then
                m_crBGColor = Value
            End If
        End Set
    End Property

    Public ReadOnly Property DataSet() As DataSet.clsIngotMapDataSet
        Get
            Return m_DataSet
        End Get
    End Property

    Public ReadOnly Property DrawIngotMap() As DrawIngotMap.clsIngotMap
        Get
            Return m_DrawIngotMap
        End Get
    End Property

    <Browsable(False), _
    DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)> _
    Public Property IsPrinting() As Boolean
        Get
            Return m_bPrinting
        End Get
        Set(ByVal Value As Boolean)
            If m_bPrinting.Equals(Value) = False Then
                m_bPrinting = Value
            End If
        End Set
    End Property

    <Browsable(False), _
    DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)> _
    Public Property IsSaveImage() As Boolean
        Get
            Return m_bSaveImage
        End Get
        Set(ByVal Value As Boolean)
            If m_bSaveImage.Equals(Value) = False Then
                m_bSaveImage = Value
            End If
        End Set
    End Property

    <Browsable(False), _
    DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)> _
    Public Property IsCopyImage() As Boolean
        Get
            Return m_bCopyImage
        End Get
        Set(ByVal Value As Boolean)
            If m_bCopyImage.Equals(Value) = False Then
                m_bCopyImage = Value
            End If
        End Set
    End Property

    <Browsable(False), _
    DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)> _
    Public Property SaveImageFileName() As String
        Get
            Return m_sSaveImageFileName
        End Get
        Set(ByVal Value As String)
            If m_sSaveImageFileName.Equals(Value) = False Then
                m_sSaveImageFileName = Value
            End If
        End Set
    End Property

    <Browsable(False), _
    DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)> _
    Public Property IsAddDataFlag() As Boolean
        Get
            Return m_bAddDataFlag
        End Get
        Set(ByVal Value As Boolean)
            If m_bAddDataFlag.Equals(Value) = False Then
                m_bAddDataFlag = Value
            End If
        End Set
    End Property

    <Browsable(False), _
    DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)> _
    Public Property IsModifiedFlag() As Boolean
        Get
            Return m_bModifiedFlag
        End Get
        Set(ByVal Value As Boolean)
            If m_bModifiedFlag.Equals(Value) = False Then
                m_bModifiedFlag = Value
            End If
        End Set
    End Property

    <Browsable(False), _
    DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)> _
    Public Property IsFirstDrawFlag() As Boolean
        Get
            Return m_bFirstDrawFlag
        End Get
        Set(ByVal Value As Boolean)
            If m_bFirstDrawFlag.Equals(Value) = False Then
                m_bFirstDrawFlag = Value
            End If
        End Set
    End Property

#End Region

#Region "Functions Implementation"

    Friend WithEvents pdcIngotMap As System.Drawing.Printing.PrintDocument

    Public Sub New()
        MyBase.New()

        Me.pdcIngotMap = New System.Drawing.Printing.PrintDocument

        Me.pdcIngotMap.DocumentName = "IngotMap"

        InitializeComponent()

        'InitializeComponent()를 호출한 다음에 초기화 작업을 추가하십시오.
        SetStyle(ControlStyles.ResizeRedraw, True)
        SetStyle(ControlStyles.DoubleBuffer Or ControlStyles.UserPaint Or ControlStyles.AllPaintingInWmPaint, True)

    End Sub

    Public Sub ResetMapData()

        Try
            DataSet.ResetContents()

        Catch ex As Exception
            MsgBox("IngotMap.ResetMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
        End Try

    End Sub

    Public Sub SetMainTitle(ByVal sMainTitle As String)

        Try
            MainTitle = sMainTitle

        Catch ex As Exception
            MsgBox("IngotMap.SetMainTitle()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
        End Try

    End Sub

    Public Sub SetIngotMapType(ByVal eIngotMapType As INGOT_MAP_TYPE, Optional ByVal iBarSize As Integer = INTEGER_NULL_DATA)

        Dim iSetBarSize As Integer = INTEGER_NULL_DATA

        Try
            IngotMapType = eIngotMapType

            If iBarSize = INTEGER_NULL_DATA Then
                If eIngotMapType = INGOT_MAP_TYPE.TYPE_1 Or eIngotMapType = INGOT_MAP_TYPE.TYPE_2 Then
                    iSetBarSize = 50
                Else
                    iSetBarSize = 100
                End If
            Else
                iSetBarSize = iBarSize
            End If

            If eIngotMapType = INGOT_MAP_TYPE.TYPE_1 Or eIngotMapType = INGOT_MAP_TYPE.TYPE_2 Then
                VerticalBarSize = iSetBarSize
            Else
                HorizontalBarSize = iSetBarSize
            End If

        Catch ex As Exception
            MsgBox("IngotMap.SetIngotMapType()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
        End Try

    End Sub

    Public Overloads Function AddMapData(ByVal iSeqNum As Integer, _
            ByVal sFullName As String, _
            ByVal sDisplayName As String, _
            ByVal sText As String, _
            ByVal dHeight As Double, _
            ByVal dDistance As Double, _
            ByVal eSegmentType As SEGMENT_TYPES, _
            ByVal eTPTypeFlag As TP_TYPES_FLAG, _
            ByVal iDivisionNum As Integer)

        Try
            If DataSet.AddMapData(iSeqNum, sFullName, sDisplayName, sText, dHeight, dDistance, INTEGER_NULL_DATA, eSegmentType, eTPTypeFlag, TP_SHAPE.BLANK, "", iDivisionNum) = False Then Return False
            IsModifiedFlag = True

        Catch ex As Exception
            MsgBox("IngotMap.AddMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    Public Overloads Function AddMapData(ByVal iSeqNum As Integer, _
            ByVal sFullName As String, _
            ByVal sDisplayName As String, _
            ByVal sText As String, _
            ByVal dHeight As Double, _
            ByVal dDistance As Double, _
            ByVal eSegmentType As SEGMENT_TYPES, _
            ByVal eTPTypeFlag As TP_TYPES_FLAG, _
            ByVal eTPShape As TP_SHAPE, _
            ByVal iDivisionNum As Integer) As Boolean

        Try
            If DataSet.AddMapData(iSeqNum, sFullName, sDisplayName, sText, dHeight, dDistance, INTEGER_NULL_DATA, eSegmentType, eTPTypeFlag, eTPShape, "", iDivisionNum) = False Then Return False
            IsModifiedFlag = True

        Catch ex As Exception
            MsgBox("IngotMap.AddMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    Public Overloads Function AddMapData(ByVal iSeqNum As Integer, _
            ByVal sFullName As String, _
            ByVal sDisplayName As String, _
            ByVal sText As String, _
            ByVal dHeight As Double, _
            ByVal dDistance As Double, _
            ByVal eSegmentType As SEGMENT_TYPES, _
            ByVal eTPTypeFlag As TP_TYPES_FLAG, _
            ByVal eTPShape As TP_SHAPE, _
            ByVal iPCS As Integer, _
            ByVal iDivisionNum As Integer) As Boolean

        Try
            If DataSet.AddMapData(iSeqNum, sFullName, sDisplayName, sText, dHeight, dDistance, iPCS, eSegmentType, eTPTypeFlag, eTPShape, "", iDivisionNum) = False Then Return False
            IsModifiedFlag = True

        Catch ex As Exception
            MsgBox("IngotMap.AddMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    Public Overloads Function AddMapData(ByVal iSeqNum As Integer, _
            ByVal sFullName As String, _
            ByVal sDisplayName As String, _
            ByVal sText As String, _
            ByVal dHeight As Double, _
            ByVal dDistance As Double, _
            ByVal eSegmentType As SEGMENT_TYPES, _
            ByVal eTPTypeFlag As TP_TYPES_FLAG, _
            ByVal eTPShape As TP_SHAPE, _
            ByVal sRelationTPName As String, _
            ByVal iDivisionNum As Integer) As Boolean

        Try
            If DataSet.AddMapData(iSeqNum, sFullName, sDisplayName, sText, dHeight, dDistance, INTEGER_NULL_DATA, eSegmentType, eTPTypeFlag, eTPShape, sRelationTPName, iDivisionNum) = False Then Return False
            IsModifiedFlag = True

        Catch ex As Exception
            MsgBox("IngotMap.AddMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    Public Overloads Function AddMapData(ByVal iSeqNum As Integer, _
            ByVal sFullName As String, _
            ByVal sDisplayName As String, _
            ByVal sText As String, _
            ByVal dHeight As Double, _
            ByVal dDistance As Double, _
            ByVal eSegmentType As SEGMENT_TYPES, _
            ByVal eTPTypeFlag As TP_TYPES_FLAG, _
            ByVal eTPShape As TP_SHAPE, _
            ByVal iPCS As Integer, _
            ByVal sRelationTPName As String, _
            ByVal iDivisionNum As Integer) As Boolean

        Try
            If DataSet.AddMapData(iSeqNum, sFullName, sDisplayName, sText, dHeight, dDistance, iPCS, eSegmentType, eTPTypeFlag, eTPShape, sRelationTPName, iDivisionNum) = False Then Return False
            IsModifiedFlag = True

        Catch ex As Exception
            MsgBox("IngotMap.AddMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    Public Overloads Function SetGFOPosition(ByVal dIngotLength As Double, ByVal dStartPos As Double, ByVal dGFOLength As Double) As Boolean

        Try
            If DataSet.SetGFOPosition(dIngotLength, dStartPos, dGFOLength) = False Then Return False

            IsModifiedFlag = True

        Catch ex As Exception
            MsgBox("IngotMap.SetGFOPosition()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    Public Function GetDataCount() As Integer

        Try
            Return DataSet.Count

        Catch ex As Exception
            MsgBox("IngotMap.GetDataCount()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return 0
        End Try

    End Function

    Public Function GetIngotMapData(ByVal iIndex As Integer) As Miracom.IngotMap.DataSet.clsIngotMapData

        Try

            Return CType(DataSet(iIndex), Miracom.IngotMap.DataSet.clsIngotMapData)

        Catch ex As Exception
            MsgBox("IngotMap.GetValue()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return Nothing
        End Try

    End Function

    Public Function GetIngotMapData(ByVal sFullName As String) As Miracom.IngotMap.DataSet.clsIngotMapData

        Dim i As Integer = 0
        Try
            For i = 0 To DataSet.Count - 1
                If CType(DataSet(i), Miracom.IngotMap.DataSet.clsIngotMapData).FullName = sFullName Then
                    Return CType(DataSet(i), Miracom.IngotMap.DataSet.clsIngotMapData)
                End If
            Next

        Catch ex As Exception
            MsgBox("IngotMap.GetValue()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return Nothing
        End Try

        Return Nothing

    End Function

    Public Function Print() As Boolean

        Try
            IsPrinting = True
            Me.pdcIngotMap.Print()

        Catch ex As Exception
            MsgBox("IngotMap.Print()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    <System.Runtime.InteropServices.DllImport("Gdi32.dll")> _
    Public Shared Function BitBlt(ByVal hdcDest As IntPtr, ByVal nXDest As Integer, ByVal nYDest As Integer, ByVal nWidth As Integer, ByVal nHeight As Integer, ByVal hdcSrc As IntPtr, ByVal nXSrc As Integer, ByVal nYSrc As Integer, ByVal dwRop As System.Int32) As Boolean
    End Function

    Public Function SaveImage(ByVal sFileName As String) As Boolean

        Try
            IsSaveImage = True
            SaveImageFileName = sFileName
            Me.Invalidate(False)

        Catch ex As Exception
            MsgBox("IngotMap.SaveImage()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    Public Function CopyImage() As Boolean

        Try
            IsCopyImage = True
            Me.Invalidate(False)

        Catch ex As Exception
            MsgBox("IngotMap.CopyImage()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            Return False
        End Try

        Return True

    End Function

    Public Sub DrawChart()

        Try
            IsFirstDrawFlag = True
            If DataSet.CalculationSize(Me.Parent) = False Then Return
            Me.Refresh()
            IsFirstDrawFlag = False

        Catch ex As Exception
            MsgBox("IngotMap.DrawChart()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
        End Try

    End Sub

#End Region

#Region "Events Implementation"

    Public Event MouseButtonDown As Miracom.IngotMap.DrawIngotMap.MouseButtonDownEventHandler

    <System.Runtime.InteropServices.DllImportAttribute("gdi32.dll")> _
            Private Shared Function SetPixel(ByVal hdc As IntPtr, _
                ByVal X As Integer, _
                ByVal Y As Integer, _
                ByVal crColor As Integer) As Integer
    End Function

    Protected Overrides Sub OnPaint(ByVal e As System.Windows.Forms.PaintEventArgs)
        MyBase.OnPaint(e)

        Try
            If IsModifiedFlag = True Then
                e.Graphics.PixelOffsetMode = System.Drawing.Drawing2D.PixelOffsetMode.HighSpeed
                e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias

                If DrawIngotMap.DrawIngotMap(e.Graphics, Me.ClientRectangle) = False Then
                    e.Graphics.FillRectangle(New SolidBrush(BGColor), Me.ClientRectangle)
                End If
            End If

            If IsSaveImage = True Then
                Dim g As Graphics
                Dim btmChart As Bitmap
                btmChart = New Bitmap(Me.ClientRectangle.Width, Me.ClientRectangle.Height, e.Graphics)
                g = Graphics.FromImage(btmChart)
                Dim hdc1 As IntPtr = e.Graphics.GetHdc()
                Dim hdc2 As IntPtr = g.GetHdc()
                BitBlt(hdc2, 0, 0, Me.ClientRectangle.Width, Me.ClientRectangle.Height, hdc1, 0, 0, 13369376)
                e.Graphics.ReleaseHdc(hdc1)
                g.ReleaseHdc(hdc2)
                btmChart.Save(SaveImageFileName, System.Drawing.Imaging.ImageFormat.Png)
                IsSaveImage = False
            ElseIf IsCopyImage = True Then
                Dim g As Graphics
                Dim btmChart As Bitmap
                btmChart = New Bitmap(Me.ClientRectangle.Width, Me.ClientRectangle.Height, e.Graphics)
                g = Graphics.FromImage(btmChart)
                Dim hdc1 As IntPtr = e.Graphics.GetHdc()
                Dim hdc2 As IntPtr = g.GetHdc()
                BitBlt(hdc2, 0, 0, Me.ClientRectangle.Width, Me.ClientRectangle.Height, hdc1, 0, 0, 13369376)
                e.Graphics.ReleaseHdc(hdc1)
                g.ReleaseHdc(hdc2)
                Clipboard.SetDataObject(btmChart)
                IsCopyImage = False
            End If

        Catch ex As Exception
            MsgBox("SPCControlChart.OnPaint()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
        End Try

    End Sub

    Private Sub pdcIngotMap_PrintPage(ByVal sender As Object, ByVal e As System.Drawing.Printing.PrintPageEventArgs) Handles pdcIngotMap.PrintPage

        Try
            e.Graphics.PixelOffsetMode = System.Drawing.Drawing2D.PixelOffsetMode.HighSpeed
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias

            Dim iPrintWidth As Integer
            Dim iPrintHeight As Integer

            iPrintWidth = e.MarginBounds.Width + e.MarginBounds.Left / 2
            iPrintHeight = iPrintWidth * 0.75

            Dim rcPrint As Rectangle = New Rectangle(e.MarginBounds.Left / 2, _
                                                     e.MarginBounds.Top, _
                                                     iPrintWidth, _
                                                     iPrintHeight)

            If DrawIngotMap.DrawIngotMap(e.Graphics, rcPrint) = False Then
                e.Cancel = True
            End If

            IsPrinting = False

        Catch ex As Exception
            MsgBox("IngotMap.pdcIngotMap_PrintPage()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
        End Try

    End Sub

    Protected Overrides Sub OnMouseDown(ByVal e As System.Windows.Forms.MouseEventArgs)

        Try
            Dim ptClickPos As Point = New Point(e.X, e.Y)
            Dim rcClickPos As Rectangle = New Rectangle(ptClickPos.X, ptClickPos.Y, 1, 1)

            If e.Button = System.Windows.Forms.MouseButtons.Left Then

                If DataSet.Count < 1 Then
                    MyBase.OnMouseDown(e)
                    Exit Sub
                End If

                Dim i As Integer
                Dim bSelected As Boolean = False

                For i = 0 To Me.DataSet.Count - 1
                    Dim pIngotMapData As DataSet.clsIngotMapData = CType(Me.DataSet(i), DataSet.clsIngotMapData)

                    If pIngotMapData.BarRegion.IntersectsWith(rcClickPos) = True And bSelected = False Then
                        bSelected = True
                        pIngotMapData.IsSelected = True

                        Dim eventArgs As Miracom.IngotMap.DrawIngotMap.MouseButtonDown_EventArgs = New Miracom.IngotMap.DrawIngotMap.MouseButtonDown_EventArgs(e.Button, e.Clicks, e.X, e.Y, e.Delta)
                        eventArgs.BarRegion = pIngotMapData.BarRegion
                        eventArgs.CenterPos = pIngotMapData.CenterPos
                        eventArgs.Height = pIngotMapData.Height
                        eventArgs.IngotShoulderDistance = pIngotMapData.IngotShoulderDistance
                        eventArgs.FullName = pIngotMapData.FullName
                        eventArgs.DisplayName = pIngotMapData.DisplayName
                        eventArgs.PCS = pIngotMapData.PCS
                        eventArgs.RelationTPName = pIngotMapData.RelationTPName
                        eventArgs.SegmentType = pIngotMapData.SegmentType
                        eventArgs.StartPos = pIngotMapData.StartPos
                        eventArgs.Text = pIngotMapData.Text
                        eventArgs.TPShape = pIngotMapData.TPShape
                        eventArgs.TPType = pIngotMapData.TPType
                        eventArgs.TPTypeFlag = pIngotMapData.TPTypeFlag

                        RaiseEvent MouseButtonDown(Me, eventArgs)
                    Else
                        pIngotMapData.IsSelected = False
                    End If
                Next i

            End If

            Me.Refresh()

            MyBase.OnMouseDown(e)

        Catch ex As Exception
            MsgBox("IngotMap.OnMouseDown()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
        End Try

    End Sub

    Private Sub IngotMap_Resize(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Resize

        Try
            If Not Me.Parent Is Nothing Then
                If DataSet.Count > 0 Then
                    If Me.IngotMapHeight > Me.Parent.Size.Height Then
                        Me.Size = New Size(Width, IngotMapHeight)
                        Me.Dock = DockStyle.Top
                    Else
                        Me.Dock = DockStyle.Fill
                    End If
                End If
            End If

        Catch ex As Exception
            MsgBox("IngotMap.IngotMap_Resize()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
        End Try

    End Sub

#End Region

End Class
