Namespace DrawIngotMap

    Public Class clsIngotMap

#Region "Properties Implementation"

        Private m_pParentControl As IngotMap = Nothing
        Private m_rcDrawRegion As Rectangle = Rectangle.Empty
        Private m_rcTitleRegion As Rectangle = Rectangle.Empty
        Private m_rcMapRegion As Rectangle = Rectangle.Empty

        Private m_iPosDistance As Integer = INTEGER_NULL_DATA
        Private m_iPosPCS As Integer = INTEGER_NULL_DATA
        Private m_iPosArrow As Integer = INTEGER_NULL_DATA
        Private m_iPosBar As Integer = INTEGER_NULL_DATA
        Private m_iPosShape As Integer = INTEGER_NULL_DATA
        Private m_iPosName As Integer = INTEGER_NULL_DATA
        Private m_iPosRelationTPName As Integer = INTEGER_NULL_DATA
        Private m_iPosUpperArrow As Integer = INTEGER_NULL_DATA
        Private m_iPosHeight As Integer = INTEGER_NULL_DATA
        Private m_bModifiedFlag As Boolean = False

        Public ReadOnly Property ParentControl() As IngotMap
            Get
                Return m_pParentControl
            End Get
        End Property

        Public Property DrawRegion() As Rectangle
            Get
                Return m_rcDrawRegion
            End Get
            Set(ByVal Value As Rectangle)
                If m_rcDrawRegion.Equals(Value) = False Then
                    m_rcDrawRegion = Value
                End If
            End Set
        End Property

        Public Property TitleRegion() As Rectangle
            Get
                Return m_rcTitleRegion
            End Get
            Set(ByVal Value As Rectangle)
                If m_rcTitleRegion.Equals(Value) = False Then
                    m_rcTitleRegion = Value
                End If
            End Set
        End Property

        Public Property MapRegion() As Rectangle
            Get
                Return m_rcMapRegion
            End Get
            Set(ByVal Value As Rectangle)
                If m_rcMapRegion.Equals(Value) = False Then
                    m_rcMapRegion = Value
                End If
            End Set
        End Property

        Public Property PosDistance() As Integer
            Get
                Return m_iPosDistance
            End Get
            Set(ByVal Value As Integer)
                If m_iPosDistance.Equals(Value) = False Then
                    m_iPosDistance = Value
                End If
            End Set
        End Property

        Public Property PosPCS() As Integer
            Get
                Return m_iPosPCS
            End Get
            Set(ByVal Value As Integer)
                If m_iPosPCS.Equals(Value) = False Then
                    m_iPosPCS = Value
                End If
            End Set
        End Property

        Public Property PosArrow() As Integer
            Get
                Return m_iPosArrow
            End Get
            Set(ByVal Value As Integer)
                If m_iPosArrow.Equals(Value) = False Then
                    m_iPosArrow = Value
                End If
            End Set
        End Property

        Public Property PosBar() As Integer
            Get
                Return m_iPosBar
            End Get
            Set(ByVal Value As Integer)
                If m_iPosBar.Equals(Value) = False Then
                    m_iPosBar = Value
                End If
            End Set
        End Property

        Public Property PosShape() As Integer
            Get
                Return m_iPosShape
            End Get
            Set(ByVal Value As Integer)
                If m_iPosShape.Equals(Value) = False Then
                    m_iPosShape = Value
                End If
            End Set
        End Property

        Public Property PosName() As Integer
            Get
                Return m_iPosName
            End Get
            Set(ByVal Value As Integer)
                If m_iPosName.Equals(Value) = False Then
                    m_iPosName = Value
                End If
            End Set
        End Property

        Public Property PosRelationTPName() As Integer
            Get
                Return m_iPosRelationTPName
            End Get
            Set(ByVal Value As Integer)
                If m_iPosRelationTPName.Equals(Value) = False Then
                    m_iPosRelationTPName = Value
                End If
            End Set
        End Property

        Public Property PosUpperArrow() As Integer
            Get
                Return m_iPosUpperArrow
            End Get
            Set(ByVal Value As Integer)
                If m_iPosUpperArrow.Equals(Value) = False Then
                    m_iPosUpperArrow = Value
                End If
            End Set
        End Property

        Public Property PosHeight() As Integer
            Get
                Return m_iPosHeight
            End Get
            Set(ByVal Value As Integer)
                If m_iPosHeight.Equals(Value) = False Then
                    m_iPosHeight = Value
                End If
            End Set
        End Property

        Public Property ModifiedFlag() As Boolean
            Get
                Return m_bModifiedFlag
            End Get
            Set(ByVal Value As Boolean)
                If m_bModifiedFlag.Equals(Value) = False Then
                    m_bModifiedFlag = Value
                End If
            End Set
        End Property

#End Region

#Region "Functions Implementation"

        Public Sub New(ByRef pParentControl As IngotMap)

            Try
                SetParentControl(pParentControl)

            Catch ex As Exception
                MsgBox("clsIngotMap.New()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Sub SetParentControl(ByRef pParentControl As IngotMap)

            Try
                m_pParentControl = pParentControl

            Catch ex As Exception
                MsgBox("clsIngotMap.SetParentControl()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Function DrawIngotMap(ByRef g As Graphics, ByVal rcOriginDraw As Rectangle) As Boolean

            Dim i As Integer = 0
            Dim pIngotMapData As DataSet.clsIngotMapData = Nothing
            Dim ptLocation1 As Point = Point.Empty
            Dim ptLocation2 As Point = Point.Empty

            Dim rcDraw As Rectangle = New Rectangle(rcOriginDraw.Left, rcOriginDraw.Top, rcOriginDraw.Width, rcOriginDraw.Height)

            Try
                If ParentControl.GetDataCount() < 1 Then
                    Return False
                End If

                If ParentControl.IsPrinting = True Then
                    g.DrawRectangle(New Pen(Color.Black), rcDraw)
                Else
                    g.FillRectangle(New SolidBrush(ParentControl.BGColor), rcDraw)
                End If

                If SetupRegion(g, rcDraw) = False Then Return False

                If CalIngotMapData(g) = False Then Return False

                If ParentControl.IngotMapType <> INGOT_MAP_TYPE.TYPE_3 Then
                    If DrawTitle(g) = False Then Return False
                End If

                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_3 Or ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_4 Then
                    If DrawCone(g) = False Then Return False
                    If DrawTail(g) = False Then Return False
                End If

                For i = 0 To ParentControl.DataSet.Count - 1

                    pIngotMapData = CType(ParentControl.DataSet(i), DataSet.clsIngotMapData)

                    If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Or ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then

                        If DrawDistance(g, pIngotMapData) = False Then Return False
                        If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then
                            If DrawPCS(g, pIngotMapData) = False Then Return False
                        End If

                        ptLocation1 = New Point(PosArrow, pIngotMapData.BarRegion.Y)

                        If DrawArrow(g, ptLocation1, pIngotMapData) = False Then Return False
                        If DrawBar(g, pIngotMapData) = False Then Return False
                        If DrawShape(g, pIngotMapData) = False Then Return False
                        If DrawName(g, pIngotMapData) = False Then Return False
                    ElseIf ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_3 Then
                        If pIngotMapData.SegmentType = SEGMENT_TYPES.GFO Then

                            If DrawDistance(g, pIngotMapData) = False Then Return False

                            ptLocation1 = New Point(pIngotMapData.BarRegion.X, PosArrow)
                            If DrawArrow(g, ptLocation1, pIngotMapData) = False Then Return False

                            ptLocation1 = New Point(pIngotMapData.BarRegion.X, PosUpperArrow)
                            ptLocation2 = New Point(pIngotMapData.BarRegion.X + pIngotMapData.BarRegion.Width, PosUpperArrow)
                            If DrawUpperArrow(g, pIngotMapData, ptLocation1, ptLocation2) = False Then Return False
                        End If
                        If DrawBar(g, pIngotMapData) = False Then Return False
                    Else
                        If DrawGFOPosition(g) = False Then Return False
                    End If
                Next i


            Catch ex As Exception
                MsgBox("clsIngotMap.DrawIngotMap()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function SetupRegion(ByRef g As Graphics, ByRef rcDraw As Rectangle) As Boolean

            Try
                Dim ptLocation As Point = New Point(rcDraw.Left + MAP_BORDER_PIXELS, rcDraw.Top + MAP_BORDER_PIXELS)
                Dim szSize As Size = New Size(rcDraw.Right - ptLocation.X - MAP_BORDER_PIXELS, rcDraw.Height - ptLocation.Y - MAP_BORDER_PIXELS + rcDraw.Top)
                DrawRegion = New Rectangle(ptLocation, szSize)

                g.FillRectangle(New SolidBrush(Color.White), DrawRegion)
                g.DrawRectangle(Pens.Black, DrawRegion)

            Catch ex As Exception
                MsgBox("clsIngotMap.SetupRegion()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawCone(ByRef g As Graphics) As Boolean

            Dim fontLabel As Font

            Try
                fontLabel = New Font(ParentControl.Font.FontFamily, 9, FontStyle.Bold)

                Dim ptLocation1 As Point = New Point(DrawRegion.X + MAP_LEFT_GAP_PIXELS / 2, DrawRegion.Y + DrawRegion.Height / 2 - 4)
                Dim ptLocation2 As Point = New Point(DrawRegion.X + MAP_LEFT_GAP_PIXELS / 2 + MAP_CONE_SIZE_PIXELS, DrawRegion.Y + DrawRegion.Height / 2 - ParentControl.HorizontalBarSize / 2 - 5 - 4)
                Dim ptLocation3 As Point = New Point(DrawRegion.X + MAP_LEFT_GAP_PIXELS / 2 + MAP_CONE_SIZE_PIXELS, DrawRegion.Y + DrawRegion.Height / 2 + ParentControl.HorizontalBarSize / 2 + 5 - 4)

                Dim pathArrow As System.Drawing.Drawing2D.GraphicsPath = New System.Drawing.Drawing2D.GraphicsPath()
                pathArrow.AddLine(ptLocation1, ptLocation2)
                pathArrow.AddLine(ptLocation2, ptLocation3)
                pathArrow.AddLine(ptLocation3, ptLocation1)
                g.FillPath(Brushes.Goldenrod, pathArrow)

                Dim rcText As Rectangle = New Rectangle(DrawRegion.X + MAP_LEFT_GAP_PIXELS / 2, DrawRegion.Y + DrawRegion.Height / 2 - ParentControl.HorizontalBarSize / 2 - 4, MAP_CONE_SIZE_PIXELS - 2, ParentControl.HorizontalBarSize - 4)
                Dim st As StringFormat = New StringFormat()
                st.LineAlignment = StringAlignment.Far
                st.Alignment = StringAlignment.Center
                st.FormatFlags = StringFormatFlags.DirectionRightToLeft
                st.FormatFlags = StringFormatFlags.DirectionVertical

                g.DrawString("CONE", fontLabel, Brushes.Black, rcText, st)

            Catch ex As Exception
                MsgBox("clsIngotMap.SetupRegion()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawTail(ByRef g As Graphics) As Boolean

            Dim fontLabel As Font

            Try
                fontLabel = New Font(ParentControl.Font.FontFamily, 9, FontStyle.Bold)

                Dim ptLocation1 As Point = New Point(DrawRegion.X + DrawRegion.Width - MAP_LEFT_GAP_PIXELS / 2, DrawRegion.Y + DrawRegion.Height / 2 - 4)
                Dim ptLocation2 As Point = New Point(DrawRegion.X + DrawRegion.Width - MAP_LEFT_GAP_PIXELS / 2 - MAP_CONE_SIZE_PIXELS, DrawRegion.Y + DrawRegion.Height / 2 - ParentControl.HorizontalBarSize / 2 - 5 - 4)
                Dim ptLocation3 As Point = New Point(DrawRegion.X + DrawRegion.Width - MAP_LEFT_GAP_PIXELS / 2 - MAP_CONE_SIZE_PIXELS, DrawRegion.Y + DrawRegion.Height / 2 + ParentControl.HorizontalBarSize / 2 + 5 - 4)

                Dim pathArrow As System.Drawing.Drawing2D.GraphicsPath = New System.Drawing.Drawing2D.GraphicsPath()
                pathArrow.AddLine(ptLocation1, ptLocation2)
                pathArrow.AddLine(ptLocation2, ptLocation3)
                pathArrow.AddLine(ptLocation3, ptLocation1)
                g.FillPath(Brushes.Goldenrod, pathArrow)

                Dim rcText As Rectangle = New Rectangle(DrawRegion.X + DrawRegion.Width - MAP_LEFT_GAP_PIXELS / 2 - MAP_CONE_SIZE_PIXELS, DrawRegion.Y + DrawRegion.Height / 2 - ParentControl.HorizontalBarSize / 2 - 4, MAP_CONE_SIZE_PIXELS, ParentControl.HorizontalBarSize - 4)
                Dim st As StringFormat = New StringFormat()
                st.LineAlignment = StringAlignment.Near
                st.Alignment = StringAlignment.Center
                st.FormatFlags = StringFormatFlags.DirectionRightToLeft
                st.FormatFlags = StringFormatFlags.DirectionVertical

                g.DrawString("TAIL", fontLabel, Brushes.Black, rcText, st)

            Catch ex As Exception
                MsgBox("clsIngotMap.SetupRegion()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawTitle(ByRef g As Graphics) As Boolean

            Try
                If ParentControl.MainTitle <> STRING_NULL_DATA Then

                    Dim fontTitle As Font = New Font(ParentControl.Font.FontFamily, 12, FontStyle.Bold)
                    Dim fmtTitle As StringFormat = New StringFormat

                    g.FillRectangle(Brushes.Beige, TitleRegion)
                    g.DrawLine(Pens.Black, DrawRegion.X, MapRegion.Y - MAP_TOP_GAP_PIXELS, DrawRegion.X + DrawRegion.Width, MapRegion.Y - MAP_TOP_GAP_PIXELS)

                    fmtTitle.LineAlignment = StringAlignment.Center
                    fmtTitle.Alignment = StringAlignment.Center
                    g.DrawString(ParentControl.MainTitle, _
                        fontTitle, _
                        New SolidBrush(Color.Blue), _
                        TitleRegion, _
                        fmtTitle)

                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawTitle()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function CalIngotMapData(ByRef g As Graphics) As Boolean

            Dim szText As SizeF
            Dim fontLabel As Font
            Dim i As Integer
            Dim iCnt As Integer
            Dim pIngotMapData As DataSet.clsIngotMapData
            Dim iSumSize As Integer
            Dim iPos As Integer
            Dim iBarSize As Integer = 0
            Dim iSumTPSize As Integer = 0
            Dim iPixelSize As Integer = 0

            Try
                If ParentControl.DataSet.Count < 1 Then
                    Return False
                End If

                fontLabel = New Font(ParentControl.Font.FontFamily, 9, FontStyle.Bold)

                If ParentControl.MainTitle <> STRING_NULL_DATA And ParentControl.IngotMapType <> INGOT_MAP_TYPE.TYPE_3 Then
                    Dim fontTitle As Font = New Font(ParentControl.Font.FontFamily, 12, FontStyle.Bold)
                    szText = g.MeasureString(ParentControl.MainTitle, fontTitle)

                    Dim ptLocation As Point = New Point(DrawRegion.Left + 1, DrawRegion.Top + 1)

                    TitleRegion = New Rectangle(ptLocation, New Size(DrawRegion.Width - 2, szText.Height))

                    If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_3 Or ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_4 Then
                        MapRegion = New Rectangle(DrawRegion.X + MAP_LEFT_GAP_PIXELS + MAP_CONE_SIZE_PIXELS, _
                        TitleRegion.Y + TitleRegion.Height + MAP_TOP_GAP_PIXELS, _
                        DrawRegion.Width - MAP_LEFT_GAP_PIXELS - MAP_RIGHT_GAP_PIXELS - MAP_CONE_SIZE_PIXELS * 2, _
                        DrawRegion.Height - TitleRegion.Height - MAP_TOP_GAP_PIXELS - MAP_BOTTOM_GAP_PIXELS - MAP_BORDER_PIXELS - MAP_GAP_PIXELS)
                    Else
                        MapRegion = New Rectangle(DrawRegion.X + MAP_LEFT_GAP_PIXELS, _
                        TitleRegion.Y + TitleRegion.Height + MAP_TOP_GAP_PIXELS, _
                        DrawRegion.Width - MAP_LEFT_GAP_PIXELS - MAP_RIGHT_GAP_PIXELS, _
                        DrawRegion.Height - TitleRegion.Height - MAP_TOP_GAP_PIXELS - MAP_BOTTOM_GAP_PIXELS - MAP_BORDER_PIXELS - MAP_GAP_PIXELS)
                    End If

                Else
                    If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_3 Then
                        MapRegion = New Rectangle(DrawRegion.X + MAP_LEFT_GAP_PIXELS + MAP_CONE_SIZE_PIXELS, _
                        DrawRegion.Y + MAP_TOP_GAP_PIXELS, _
                        DrawRegion.Width - MAP_LEFT_GAP_PIXELS - MAP_RIGHT_GAP_PIXELS - MAP_CONE_SIZE_PIXELS * 2, _
                        DrawRegion.Height - MAP_TOP_GAP_PIXELS - MAP_BOTTOM_GAP_PIXELS)
                    ElseIf ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_4 Then
                        MapRegion = New Rectangle(DrawRegion.X + MAP_LEFT_GAP_PIXELS + MAP_CONE_SIZE_PIXELS, _
                        DrawRegion.Y + MAP_TOP_GAP_PIXELS, _
                        DrawRegion.Width - MAP_LEFT_GAP_PIXELS - MAP_RIGHT_GAP_PIXELS - MAP_CONE_SIZE_PIXELS * 2, _
                        DrawRegion.Height - MAP_TOP_GAP_PIXELS - MAP_BOTTOM_GAP_PIXELS)
                    Else
                        MapRegion = New Rectangle(DrawRegion.X + MAP_LEFT_GAP_PIXELS, _
                        DrawRegion.Y + MAP_TOP_GAP_PIXELS, _
                        DrawRegion.Width - MAP_LEFT_GAP_PIXELS - MAP_RIGHT_GAP_PIXELS, _
                        DrawRegion.Height - MAP_TOP_GAP_PIXELS - MAP_BOTTOM_GAP_PIXELS)
                    End If
                End If

                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Or ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then
                    
                    If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then
                        PosShape = MapRegion.X + MapRegion.Width / 2.1 + MAP_GAP_STEP_PIXELS
                        PosName = PosShape + MAP_SHAPE_SIZE_PIXELS + MAP_GAP_STEP_PIXELS
                        szText = g.MeasureString("MM00M", fontLabel)
                        PosRelationTPName = PosName + szText.Width + MAP_GAP_STEP_PIXELS

                        PosBar = PosShape - ParentControl.VerticalBarSize - MAP_GAP_STEP_PIXELS
                        PosArrow = PosBar - MAP_ARROW_SIZE_PIXELS - MAP_GAP_STEP_PIXELS
                        szText = g.MeasureString("900", fontLabel)
                        PosPCS = PosArrow - MAP_GAP_STEP_PIXELS
                        PosDistance = PosPCS - szText.Width
                    Else
                        PosShape = MapRegion.X + MapRegion.Width / 2 - MAP_GAP_STEP_PIXELS
                        PosName = PosShape + MAP_SHAPE_SIZE_PIXELS + MAP_GAP_STEP_PIXELS
                        szText = g.MeasureString("MM00M", fontLabel)
                        PosRelationTPName = PosName + szText.Width + MAP_GAP_STEP_PIXELS

                        PosBar = PosShape - ParentControl.VerticalBarSize - MAP_GAP_STEP_PIXELS
                        PosArrow = PosBar - MAP_ARROW_SIZE_PIXELS - MAP_GAP_STEP_PIXELS
                        PosPCS = INTEGER_NULL_DATA
                        PosDistance = PosArrow - MAP_GAP_STEP_PIXELS
                    End If

                    For i = 0 To ParentControl.DataSet.Count - 1
                        pIngotMapData = CType(ParentControl.DataSet(i), DataSet.clsIngotMapData)

                        If i = 0 Then
                            iPos = MapRegion.Y
                        Else

                            iPos = (CType(ParentControl.DataSet(i - 1), DataSet.clsIngotMapData).BarRegion.Y + CType(ParentControl.DataSet(i - 1), DataSet.clsIngotMapData).BarRegion.Height) + MAP_GAP_BAR_PIXELS

                            If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Then

                                If CType(ParentControl.DataSet(i - 1), DataSet.clsIngotMapData).DivisionNum <> pIngotMapData.DivisionNum Then

                                    g.DrawLine(Pens.Gray, CInt(DrawRegion.X), CInt(iPos + MAP_BAR_HEIGHT_PIXELS / 2), CInt(DrawRegion.X + DrawRegion.Width), CInt(iPos + MAP_BAR_HEIGHT_PIXELS / 2))

                                    iPos += MAP_BAR_HEIGHT_PIXELS
                                End If

                            End If

                            End If

                            If pIngotMapData.SegmentType = SEGMENT_TYPES.TP Or pIngotMapData.SegmentType = SEGMENT_TYPES.VTP Then
                                iBarSize = MAP_BAR_HEIGHT_PIXELS
                            Else

                                If pIngotMapData.SegmentType = SEGMENT_TYPES.SCRAP Then

                                    If pIngotMapData.Text = "TS" Then
                                        iBarSize = MAP_BAR_HEIGHT_PIXELS
                                    Else
                                        iBarSize = MAP_SCRAP_HEIGHT_PIXELS
                                    End If
                                Else

                                    iBarSize = MAP_GFO_HEIGHT_PIXELS
                                End If

                            End If

                            pIngotMapData.BarRegion = New Rectangle(PosBar, iPos, ParentControl.VerticalBarSize, iBarSize)
                            pIngotMapData.CenterPos = iPos + (iBarSize / 2)
                    Next

                ElseIf ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_3 Then
                    PosBar = DrawRegion.Y + DrawRegion.Height / 2 - ParentControl.HorizontalBarSize / 2 - 4
                    PosArrow = PosBar + MAP_GAP_STEP_PIXELS + ParentControl.HorizontalBarSize
                    PosDistance = PosArrow + MAP_GAP_STEP_PIXELS + MAP_H_ARROW_SIZE_PIXELS - 7
                    PosUpperArrow = PosBar - MAP_GAP_STEP_PIXELS
                    PosHeight = PosUpperArrow - MAP_GAP_STEP_PIXELS - MAP_H_ARROW_SIZE_PIXELS + 5

                    iSumSize = 0
                    iSumTPSize = 0
                    For i = 0 To ParentControl.DataSet.Count - 1
                        pIngotMapData = CType(ParentControl.DataSet(i), DataSet.clsIngotMapData)

                        If pIngotMapData.SegmentType = SEGMENT_TYPES.VTP Then
                            Continue For
                        End If

                        If pIngotMapData.SegmentType = SEGMENT_TYPES.TP Then
                            iSumTPSize += (MAP_H_BAR_WIDTH_PIXELS + MAP_GAP_BAR_PIXELS)
                        Else
                            If pIngotMapData.Height < MAP_H_BAR_WIDTH_PIXELS + MAP_GAP_BAR_PIXELS Then
                                iSumTPSize += (MAP_H_BAR_WIDTH_PIXELS + MAP_GAP_BAR_PIXELS)
                            Else
                                iSumSize += pIngotMapData.Height
                                iSumTPSize += MAP_GAP_BAR_PIXELS
                            End If
                        End If
                    Next

                    iSumTPSize -= MAP_GAP_BAR_PIXELS
                    iPixelSize = MapRegion.Width - iSumTPSize
                    iCnt = 0

                    For i = 0 To ParentControl.DataSet.Count - 1
                        pIngotMapData = CType(ParentControl.DataSet(i), DataSet.clsIngotMapData)

                        If pIngotMapData.SegmentType = SEGMENT_TYPES.VTP Then
                            Continue For
                        End If

                        If i = 0 Then
                            iPos = MapRegion.X
                        Else
                            iPos = (CType(ParentControl.DataSet(i - 1), DataSet.clsIngotMapData).BarRegion.X + CType(ParentControl.DataSet(i - 1), DataSet.clsIngotMapData).BarRegion.Width) + MAP_GAP_BAR_PIXELS
                        End If

                        If pIngotMapData.SegmentType = SEGMENT_TYPES.TP Then
                            iBarSize = MAP_H_BAR_WIDTH_PIXELS
                        Else
                            If iSumSize <= 0 Then
                                Return False
                            End If

                            If pIngotMapData.Height < MAP_H_BAR_WIDTH_PIXELS + MAP_GAP_BAR_PIXELS Then
                                iBarSize = MAP_H_BAR_WIDTH_PIXELS
                            Else
                                iBarSize = ((iPixelSize * CInt(pIngotMapData.Height)) / iSumSize)
                            End If

                        End If

                        pIngotMapData.BarRegion = New Rectangle(iPos, PosBar, iBarSize, ParentControl.HorizontalBarSize)
                        pIngotMapData.CenterPos = iPos + (iBarSize / 2)

                        iCnt += 1
                    Next

                ElseIf ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_4 Then
                    PosBar = DrawRegion.Y + DrawRegion.Height / 2 - ParentControl.HorizontalBarSize / 2 + 4
                    PosArrow = PosBar + MAP_GAP_STEP_PIXELS + ParentControl.HorizontalBarSize
                    PosDistance = PosArrow + MAP_GAP_STEP_PIXELS + MAP_H_ARROW_SIZE_PIXELS
                    PosUpperArrow = PosBar - MAP_GAP_STEP_PIXELS
                    PosHeight = PosUpperArrow - MAP_GAP_STEP_PIXELS - MAP_H_ARROW_SIZE_PIXELS

                    iSumSize = ParentControl.DataSet.IngotLength
                    iPixelSize = MapRegion.Width

                    For i = 0 To ParentControl.DataSet.Count - 1
                        pIngotMapData = CType(ParentControl.DataSet(i), DataSet.clsIngotMapData)
                        iPos = MapRegion.X + ((pIngotMapData.IngotShoulderDistance - 0) * iPixelSize) / iSumSize
                        If iSumSize <= 0 Then
                            Return False
                        End If
                        iBarSize = ((iPixelSize * CInt(pIngotMapData.Height)) / iSumSize)
                        pIngotMapData.BarRegion = New Rectangle(iPos, PosBar, iBarSize, ParentControl.HorizontalBarSize)
                        pIngotMapData.CenterPos = iPos + (iBarSize / 2)
                    Next

                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.CalIngotMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawDistance(ByRef g As Graphics, ByRef pIngotMapData As DataSet.clsIngotMapData) As Boolean

            Dim fmtTitle As StringFormat = New StringFormat
            Dim fontText As Font
            Dim sText As String = ""

            Try
                fontText = New Font(ParentControl.Font.FontFamily, 8, FontStyle.Regular)

                ' Distance
                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Or ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then
                    If pIngotMapData.SegmentType <> SEGMENT_TYPES.VTP And Not (pIngotMapData.SegmentType = SEGMENT_TYPES.GFO And ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2) Then
                        fmtTitle.LineAlignment = StringAlignment.Center
                        fmtTitle.Alignment = StringAlignment.Far

                        If pIngotMapData.IngotShoulderDistance = 0 Then
                            sText = "0.0"
                        Else
                            sText = pIngotMapData.IngotShoulderDistance.ToString("####.0")
                        End If

                        g.DrawString(sText, _
                        fontText, _
                        New SolidBrush(Color.Black), _
                        PosDistance, _
                        pIngotMapData.BarRegion.Y + 1, _
                        fmtTitle)
                    End If
                    
                ElseIf ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_3 Then

                    fmtTitle.LineAlignment = StringAlignment.Near
                    fmtTitle.Alignment = StringAlignment.Center

                    If pIngotMapData.IngotShoulderDistance = 0 Then
                        sText = "0.00"
                    Else
                        sText = pIngotMapData.IngotShoulderDistance.ToString("####.00")
                    End If

                    g.DrawString(sText, _
                    fontText, _
                    New SolidBrush(Color.Black), _
                    pIngotMapData.BarRegion.X, _
                    PosDistance - 3, _
                    fmtTitle)
                ElseIf ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_4 Then
                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawDistance()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawPCS(ByRef g As Graphics, ByRef pIngotMapData As DataSet.clsIngotMapData) As Boolean

            Dim fmtTitle As StringFormat = New StringFormat
            Dim fontText As Font

            Try
                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then

                    fontText = New Font(ParentControl.Font.FontFamily, 8, FontStyle.Regular)

                    fmtTitle.LineAlignment = StringAlignment.Center
                    fmtTitle.Alignment = StringAlignment.Far

                    ' PCS
                    g.DrawString(pIngotMapData.PCS.ToString("###"), _
                        fontText, _
                        New SolidBrush(Color.Black), _
                        PosPCS, _
                        pIngotMapData.BarRegion.Y + 1, _
                        fmtTitle)
                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawPCS()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawArrow(ByRef g As Graphics, ByVal ptLocation As Point, ByRef pIngotMapData As DataSet.clsIngotMapData) As Boolean

            Dim pt1 As Point = Point.Empty
            Dim pt2 As Point = Point.Empty
            Dim pt3 As Point = Point.Empty
            Dim pathArrow As System.Drawing.Drawing2D.GraphicsPath

            Try
                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Or ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then
                    If pIngotMapData.SegmentType <> SEGMENT_TYPES.VTP Then
                        pt1 = New Point(ptLocation.X, ptLocation.Y - MAP_ARROW_SIZE_PIXELS / 2)
                        pt2 = New Point(ptLocation.X, ptLocation.Y + MAP_ARROW_SIZE_PIXELS / 2)
                        pt3 = New Point(ptLocation.X + MAP_ARROW_SIZE_PIXELS, ptLocation.Y)

                        pathArrow = New System.Drawing.Drawing2D.GraphicsPath()
                        pathArrow.AddLine(pt1, pt2)
                        pathArrow.AddLine(pt2, pt3)
                        pathArrow.AddLine(pt3, pt1)
                        g.FillPath(Brushes.SteelBlue, pathArrow)
                    End If

                ElseIf ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_3 Then
                    pt1 = New Point(ptLocation.X - MAP_ARROW_SIZE_PIXELS / 2, ptLocation.Y + MAP_ARROW_SIZE_PIXELS)
                    pt2 = New Point(ptLocation.X + MAP_ARROW_SIZE_PIXELS / 2, ptLocation.Y + MAP_ARROW_SIZE_PIXELS)
                    pt3 = New Point(ptLocation.X, ptLocation.Y)

                    pathArrow = New System.Drawing.Drawing2D.GraphicsPath()
                    pathArrow.AddLine(pt1, pt2)
                    pathArrow.AddLine(pt2, pt3)
                    pathArrow.AddLine(pt3, pt1)
                    g.FillPath(Brushes.SteelBlue, pathArrow)

                    g.DrawLine(Pens.SteelBlue, ptLocation.X, ptLocation.Y + MAP_ARROW_SIZE_PIXELS, ptLocation.X, PosDistance - MAP_GAP_STEP_PIXELS)

                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawArrow()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawUpperArrow(ByRef g As Graphics, ByRef pIngotMapData As DataSet.clsIngotMapData, ByVal ptLocation1 As Point, ByVal ptLocation2 As Point) As Boolean

            Dim pt1 As Point = Point.Empty
            Dim pt2 As Point = Point.Empty
            Dim pt3 As Point = Point.Empty
            Dim pathArrow As System.Drawing.Drawing2D.GraphicsPath
            Dim fontText As Font
            Dim fmtTitle As StringFormat = New StringFormat
            Dim sText As String = ""

            Try
                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_3 Then
                    pt1 = New Point(ptLocation1.X - MAP_ARROW_SIZE_PIXELS / 2, ptLocation1.Y - MAP_ARROW_SIZE_PIXELS)
                    pt2 = New Point(ptLocation1.X + MAP_ARROW_SIZE_PIXELS / 2, ptLocation1.Y - MAP_ARROW_SIZE_PIXELS)
                    pt3 = New Point(ptLocation1.X, ptLocation1.Y)

                    pathArrow = New System.Drawing.Drawing2D.GraphicsPath()
                    pathArrow.AddLine(pt1, pt2)
                    pathArrow.AddLine(pt2, pt3)
                    pathArrow.AddLine(pt3, pt1)
                    g.FillPath(Brushes.SteelBlue, pathArrow)

                    g.DrawLine(Pens.SteelBlue, ptLocation1.X, ptLocation1.Y - MAP_ARROW_SIZE_PIXELS, ptLocation1.X, PosHeight + MAP_GAP_STEP_PIXELS)

                    pt1 = New Point(ptLocation2.X - MAP_ARROW_SIZE_PIXELS / 2, ptLocation2.Y - MAP_ARROW_SIZE_PIXELS)
                    pt2 = New Point(ptLocation2.X + MAP_ARROW_SIZE_PIXELS / 2, ptLocation2.Y - MAP_ARROW_SIZE_PIXELS)
                    pt3 = New Point(ptLocation2.X, ptLocation2.Y)

                    pathArrow = New System.Drawing.Drawing2D.GraphicsPath()
                    pathArrow.AddLine(pt1, pt2)
                    pathArrow.AddLine(pt2, pt3)
                    pathArrow.AddLine(pt3, pt1)
                    g.FillPath(Brushes.SteelBlue, pathArrow)

                    g.DrawLine(Pens.SteelBlue, ptLocation2.X, ptLocation2.Y - MAP_ARROW_SIZE_PIXELS, ptLocation2.X, PosHeight + MAP_GAP_STEP_PIXELS)

                    g.DrawLine(Pens.SteelBlue, ptLocation1.X, PosHeight + CInt(MAP_H_ARROW_SIZE_PIXELS / 2), ptLocation2.X, PosHeight + CInt(MAP_H_ARROW_SIZE_PIXELS / 2))

                    fontText = New Font(ParentControl.Font.FontFamily, 8, FontStyle.Regular)

                    fmtTitle.LineAlignment = StringAlignment.Near
                    fmtTitle.Alignment = StringAlignment.Center

                    If pIngotMapData.Height = 0 Then
                        sText = "0.00"
                    Else
                        sText = pIngotMapData.Height.ToString("####.00")
                    End If

                    g.DrawString(sText, _
                        fontText, _
                        New SolidBrush(Color.Black), _
                        pIngotMapData.CenterPos, _
                        PosHeight, _
                        fmtTitle)

                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawUpperArrow()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawBar(ByRef g As Graphics, ByRef pIngotMapData As DataSet.clsIngotMapData) As Boolean

            Dim penBar As Pen
            Dim brushBar As Brush = Brushes.White
            Dim fmtTitle As StringFormat = New StringFormat
            Dim fontText As Font
            Dim sText As String = STRING_NULL_DATA

            Try
                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Or ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then
                    If pIngotMapData.TPType = TP_TYPES.BLACK Then
                        If pIngotMapData.Text = "TS" Then
                            brushBar = Brushes.SteelBlue
                        Else
                            brushBar = Brushes.Black
                        End If
                    ElseIf pIngotMapData.TPType = TP_TYPES.DARK_GRAY Then
                        brushBar = Brushes.Gray
                    ElseIf pIngotMapData.TPType = TP_TYPES.GRAY Then
                        brushBar = Brushes.Gainsboro
                    ElseIf pIngotMapData.TPType = TP_TYPES.GREEN Then
                        brushBar = Brushes.Lime
                    ElseIf pIngotMapData.TPType = TP_TYPES.LIGHT_GREEN Then
                        brushBar = Brushes.PaleGreen
                    ElseIf pIngotMapData.TPType = TP_TYPES.ORANGE Then
                        brushBar = Brushes.Orange
                    ElseIf pIngotMapData.TPType = TP_TYPES.RED Then
                        brushBar = Brushes.Red
                    ElseIf pIngotMapData.TPType = TP_TYPES.WHITE Then
                        brushBar = Brushes.White
                    ElseIf pIngotMapData.TPType = TP_TYPES.YELLOW Then
                        brushBar = Brushes.Yellow
                    End If

                    If pIngotMapData.IsSelected = True Then
                        penBar = New Pen(Color.Red)
                        penBar.DashStyle = Drawing2D.DashStyle.Solid
                        penBar.Width = 3
                    Else
                        If pIngotMapData.SegmentType = SEGMENT_TYPES.VTP Then
                            penBar = New Pen(Color.Black)
                            penBar.DashStyle = Drawing2D.DashStyle.Dot
                            penBar.Width = 2
                        Else
                            penBar = New Pen(Color.Black)
                            penBar.DashStyle = Drawing2D.DashStyle.Solid
                            penBar.Width = 1
                        End If
                    End If

                    If pIngotMapData.SegmentType = SEGMENT_TYPES.GFO Then
                        fontText = New Font(ParentControl.Font.FontFamily, 9, FontStyle.Bold)
                    ElseIf pIngotMapData.SegmentType = SEGMENT_TYPES.SCRAP Then
                        fontText = New Font(ParentControl.Font.FontFamily, 7, FontStyle.Bold)
                    Else
                        fontText = New Font(ParentControl.Font.FontFamily, 7, FontStyle.Regular)
                    End If

                    g.FillRectangle(brushBar, pIngotMapData.BarRegion)
                    g.DrawRectangle(penBar, pIngotMapData.BarRegion)

                    If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Then
                        else 
                    End If

                    ' Evaluation Item
                    If pIngotMapData.SegmentType = SEGMENT_TYPES.SCRAP Then
                        fmtTitle.LineAlignment = StringAlignment.Center
                        fmtTitle.Alignment = StringAlignment.Center

                        g.DrawString(pIngotMapData.Text, _
                            fontText, _
                            New SolidBrush(Color.White), _
                            pIngotMapData.BarRegion, _
                            fmtTitle)
                    Else

                        If pIngotMapData.SegmentType = SEGMENT_TYPES.GFO Then

                            If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Then
                                fmtTitle.LineAlignment = StringAlignment.Near
                                fmtTitle.Alignment = StringAlignment.Center

                                sText = pIngotMapData.Text

                                g.DrawString(sText, _
                                    fontText, _
                                    New SolidBrush(Color.Black), _
                                    pIngotMapData.BarRegion, _
                                    fmtTitle)

                                fontText = New Font(ParentControl.Font.FontFamily, 8, FontStyle.Regular)

                                fmtTitle.LineAlignment = StringAlignment.Far
                                fmtTitle.Alignment = StringAlignment.Center

                                sText = pIngotMapData.Height.ToString("####.0")
                                g.DrawString(sText, _
                                fontText, _
                                New SolidBrush(Color.Black), _
                                pIngotMapData.BarRegion, _
                                fmtTitle)
                            Else
                                fmtTitle.LineAlignment = StringAlignment.Center
                                fmtTitle.Alignment = StringAlignment.Center

                                sText = pIngotMapData.Height.ToString("####")
                                g.DrawString(sText, _
                                fontText, _
                                New SolidBrush(Color.Black), _
                                pIngotMapData.BarRegion, _
                                fmtTitle)
                            End If
                            

                        Else
                            fmtTitle.LineAlignment = StringAlignment.Center
                            fmtTitle.Alignment = StringAlignment.Center

                            sText = pIngotMapData.Text

                            g.DrawString(sText, _
                                fontText, _
                                New SolidBrush(Color.Black), _
                                pIngotMapData.BarRegion, _
                                fmtTitle)

                        End If

                    End If
                Else
                    If pIngotMapData.SegmentType = SEGMENT_TYPES.VTP Then
                        Return True
                    End If

                    If pIngotMapData.SegmentType = SEGMENT_TYPES.GFO Then
                        brushBar = Brushes.Gainsboro
                    ElseIf pIngotMapData.SegmentType = SEGMENT_TYPES.SCRAP Then
                        If pIngotMapData.Text = "TS" Then
                            brushBar = Brushes.DimGray
                        Else
                            brushBar = Brushes.Black
                        End If
                    Else
                        brushBar = New SolidBrush(GetBarColor(pIngotMapData.Text))
                    End If


                    If pIngotMapData.IsSelected = True Then
                        penBar = New Pen(Color.Red)
                        penBar.DashStyle = Drawing2D.DashStyle.Solid
                        penBar.Width = 3
                    Else
                        penBar = New Pen(Color.Black)
                        penBar.DashStyle = Drawing2D.DashStyle.Solid
                        penBar.Width = 1
                    End If

                    If pIngotMapData.SegmentType = SEGMENT_TYPES.GFO Then
                        fontText = New Font(ParentControl.Font.FontFamily, 15, FontStyle.Bold)
                    ElseIf pIngotMapData.SegmentType = SEGMENT_TYPES.SCRAP Then
                        fontText = New Font(ParentControl.Font.FontFamily, 7, FontStyle.Bold)
                    Else
                        fontText = New Font(ParentControl.Font.FontFamily, 7, FontStyle.Regular)
                    End If

                    g.FillRectangle(brushBar, pIngotMapData.BarRegion)
                    g.DrawRectangle(penBar, pIngotMapData.BarRegion)

                    Dim st As StringFormat = New StringFormat()
                    st.LineAlignment = StringAlignment.Center
                    st.Alignment = StringAlignment.Center
                    st.FormatFlags = StringFormatFlags.DirectionRightToLeft
                    st.FormatFlags = StringFormatFlags.DirectionVertical

                    ' Evaluation Item
                    If pIngotMapData.SegmentType = SEGMENT_TYPES.SCRAP Then
                        g.DrawString(pIngotMapData.Text, _
                            fontText, _
                            New SolidBrush(Color.White), _
                            pIngotMapData.BarRegion, _
                            st)
                    Else
                        If pIngotMapData.SegmentType = SEGMENT_TYPES.GFO Then
                            fmtTitle.LineAlignment = StringAlignment.Center
                            fmtTitle.Alignment = StringAlignment.Center
                            sText = pIngotMapData.Text
                            g.DrawString(sText, _
                               fontText, _
                               New SolidBrush(Color.Black), _
                               pIngotMapData.BarRegion, _
                               fmtTitle)
                        Else
                            sText = pIngotMapData.Text
                            g.DrawString(sText, _
                               fontText, _
                               New SolidBrush(Color.Black), _
                               pIngotMapData.BarRegion, _
                               st)
                        End If


                    End If
                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawBar()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawShape(ByRef g As Graphics, ByRef pIngotMapData As DataSet.clsIngotMapData) As Boolean

            Dim ptLocation As Point = Point.Empty

            Try
                ptLocation = New Point(PosShape, pIngotMapData.CenterPos)

                If pIngotMapData.TPShape = TP_SHAPE.BLANK Then
                    ' Nothing
                ElseIf pIngotMapData.TPShape = TP_SHAPE.CIRCLE Then
                    Dim rcShape As Rectangle = New Rectangle(ptLocation.X, ptLocation.Y - MAP_SHAPE_SIZE_PIXELS / 2, MAP_SHAPE_SIZE_PIXELS, MAP_SHAPE_SIZE_PIXELS)
                    g.DrawEllipse(Pens.Black, rcShape)

                ElseIf pIngotMapData.TPShape = TP_SHAPE.DASH Then
                    g.DrawLine(Pens.Black, ptLocation, New Point(ptLocation.X + MAP_SHAPE_SIZE_PIXELS, ptLocation.Y))

                ElseIf pIngotMapData.TPShape = TP_SHAPE.EQUAL Then
                    g.DrawLine(Pens.Black, New Point(ptLocation.X, ptLocation.Y - MAP_SHAPE_SIZE_PIXELS / 4), New Point(ptLocation.X + MAP_SHAPE_SIZE_PIXELS, ptLocation.Y - MAP_SHAPE_SIZE_PIXELS / 4))
                    g.DrawLine(Pens.Black, New Point(ptLocation.X, ptLocation.Y + MAP_SHAPE_SIZE_PIXELS / 4), New Point(ptLocation.X + MAP_SHAPE_SIZE_PIXELS, ptLocation.Y + MAP_SHAPE_SIZE_PIXELS / 4))

                ElseIf pIngotMapData.TPShape = TP_SHAPE.SQUARE Then
                    Dim rcShape As Rectangle = New Rectangle(ptLocation.X, ptLocation.Y - MAP_SHAPE_SIZE_PIXELS / 2, MAP_SHAPE_SIZE_PIXELS, MAP_SHAPE_SIZE_PIXELS)
                    g.DrawRectangle(Pens.Black, rcShape)

                ElseIf pIngotMapData.TPShape = TP_SHAPE.TRIAGLE Then
                    Dim ptLocation1 As Point = New Point(ptLocation.X, ptLocation.Y + MAP_SHAPE_SIZE_PIXELS / 2)
                    Dim ptLocation2 As Point = New Point(ptLocation.X + MAP_SHAPE_SIZE_PIXELS, ptLocation.Y + MAP_SHAPE_SIZE_PIXELS / 2)
                    Dim ptLocation3 As Point = New Point(ptLocation.X + MAP_SHAPE_SIZE_PIXELS / 2, ptLocation.Y - MAP_SHAPE_SIZE_PIXELS / 2)
                    Dim pathArrow As System.Drawing.Drawing2D.GraphicsPath = New System.Drawing.Drawing2D.GraphicsPath()
                    pathArrow.AddLine(ptLocation1, ptLocation2)
                    pathArrow.AddLine(ptLocation2, ptLocation3)
                    pathArrow.AddLine(ptLocation3, ptLocation1)
                    g.DrawPath(Pens.Black, pathArrow)

                ElseIf pIngotMapData.TPShape = TP_SHAPE.X Then
                    g.DrawLine(Pens.Black, New Point(ptLocation.X, ptLocation.Y - MAP_SHAPE_SIZE_PIXELS / 2), New Point(ptLocation.X + MAP_SHAPE_SIZE_PIXELS, ptLocation.Y + MAP_SHAPE_SIZE_PIXELS / 2))
                    g.DrawLine(Pens.Black, New Point(ptLocation.X, ptLocation.Y + MAP_SHAPE_SIZE_PIXELS / 2), New Point(ptLocation.X + MAP_SHAPE_SIZE_PIXELS, ptLocation.Y - MAP_SHAPE_SIZE_PIXELS / 2))

                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawShape()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawName(ByRef g As Graphics, ByRef pIngotMapData As DataSet.clsIngotMapData) As Boolean

            Dim fmtTitle As StringFormat = New StringFormat
            Dim fontText As Font

            Try
                If pIngotMapData.SegmentType = SEGMENT_TYPES.VTP Then

                    fontText = New Font(ParentControl.Font.FontFamily, 9, FontStyle.Bold)

                    fmtTitle.LineAlignment = StringAlignment.Center
                    fmtTitle.Alignment = StringAlignment.Near

                    ' Name
                    g.DrawString(pIngotMapData.DisplayName, _
                        fontText, _
                        New SolidBrush(Color.Blue), _
                        PosName, _
                        pIngotMapData.CenterPos, _
                        fmtTitle)

                    ' Relation TP Name
                    g.DrawString(pIngotMapData.RelationTPName, _
                        fontText, _
                        New SolidBrush(Color.Blue), _
                        PosRelationTPName, _
                        pIngotMapData.CenterPos, _
                        fmtTitle)

                ElseIf pIngotMapData.SegmentType = SEGMENT_TYPES.SCRAP Then

                    fontText = New Font(ParentControl.Font.FontFamily, 8, FontStyle.Regular)

                    fmtTitle.LineAlignment = StringAlignment.Center
                    fmtTitle.Alignment = StringAlignment.Far

                    ' Name
                    g.DrawString(Convert.ToDouble(pIngotMapData.DisplayName).ToString("####.0 mm"), _
                        fontText, _
                        New SolidBrush(Color.Black), _
                        PosName + 42, _
                        pIngotMapData.CenterPos, _
                        fmtTitle)
                ElseIf pIngotMapData.SegmentType = SEGMENT_TYPES.TP Then

                    fontText = New Font(ParentControl.Font.FontFamily, 9, FontStyle.Bold)

                    fmtTitle.LineAlignment = StringAlignment.Center
                    fmtTitle.Alignment = StringAlignment.Near

                    ' Name
                    g.DrawString(pIngotMapData.DisplayName, _
                        fontText, _
                        New SolidBrush(Color.Black), _
                        PosName, _
                        pIngotMapData.CenterPos, _
                        fmtTitle)

                Else
                    If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Then
                        fontText = New Font(ParentControl.Font.FontFamily, 9, FontStyle.Bold)

                        fmtTitle.LineAlignment = StringAlignment.Center
                        fmtTitle.Alignment = StringAlignment.Near

                        ' Name
                        g.DrawString(pIngotMapData.DisplayName, _
                            fontText, _
                            New SolidBrush(Color.Black), _
                            PosName, _
                            pIngotMapData.CenterPos, _
                            fmtTitle)
                    End If
                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawName()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function DrawGFOPosition(ByRef g As Graphics) As Boolean

            Dim ptLocation1 As Point = Point.Empty
            Dim ptLocation2 As Point = Point.Empty
            Dim pt1 As Point = Point.Empty
            Dim pt2 As Point = Point.Empty
            Dim pt3 As Point = Point.Empty
            Dim pathArrow As System.Drawing.Drawing2D.GraphicsPath
            Dim fontText As Font
            Dim fmtTitle As StringFormat = New StringFormat
            Dim pIngotMapData1 As DataSet.clsIngotMapData = Nothing
            Dim pIngotMapData2 As DataSet.clsIngotMapData = Nothing
            Dim sText As String = ""

            Try
                fontText = New Font(ParentControl.Font.FontFamily, 8, FontStyle.Regular)

                pIngotMapData1 = ParentControl.DataSet(0)
                pIngotMapData2 = ParentControl.DataSet(1)

                ptLocation1 = New Point(pIngotMapData1.BarRegion.X, PosArrow)
                ptLocation2 = New Point(pIngotMapData1.BarRegion.X + pIngotMapData1.BarRegion.Width, PosArrow)

                pt1 = New Point(ptLocation1.X - MAP_ARROW_SIZE_PIXELS / 2, ptLocation1.Y + MAP_ARROW_SIZE_PIXELS)
                pt2 = New Point(ptLocation1.X + MAP_ARROW_SIZE_PIXELS / 2, ptLocation1.Y + MAP_ARROW_SIZE_PIXELS)
                pt3 = New Point(ptLocation1.X, ptLocation1.Y)

                pathArrow = New System.Drawing.Drawing2D.GraphicsPath()
                pathArrow.AddLine(pt1, pt2)
                pathArrow.AddLine(pt2, pt3)
                pathArrow.AddLine(pt3, pt1)
                g.FillPath(Brushes.SteelBlue, pathArrow)

                g.DrawLine(Pens.SteelBlue, ptLocation1.X, ptLocation1.Y + MAP_ARROW_SIZE_PIXELS, ptLocation1.X, PosDistance - MAP_GAP_STEP_PIXELS)

                pt1 = New Point(ptLocation2.X - MAP_ARROW_SIZE_PIXELS / 2, ptLocation2.Y + MAP_ARROW_SIZE_PIXELS)
                pt2 = New Point(ptLocation2.X + MAP_ARROW_SIZE_PIXELS / 2, ptLocation2.Y + MAP_ARROW_SIZE_PIXELS)
                pt3 = New Point(ptLocation2.X, ptLocation1.Y)

                pathArrow = New System.Drawing.Drawing2D.GraphicsPath()
                pathArrow.AddLine(pt1, pt2)
                pathArrow.AddLine(pt2, pt3)
                pathArrow.AddLine(pt3, pt1)
                g.FillPath(Brushes.SteelBlue, pathArrow)

                g.DrawLine(Pens.SteelBlue, ptLocation2.X, ptLocation2.Y + MAP_ARROW_SIZE_PIXELS, ptLocation2.X, PosDistance - MAP_GAP_STEP_PIXELS)

                'g.DrawLine(Pens.SteelBlue, ptLocation1.X, PosDistance - CInt(MAP_H_ARROW_SIZE_PIXELS / 2), ptLocation2.X, PosDistance - CInt(MAP_H_ARROW_SIZE_PIXELS / 2))

                fmtTitle.LineAlignment = StringAlignment.Near
                fmtTitle.Alignment = StringAlignment.Center

                If pIngotMapData1.IngotShoulderDistance = 0 Then
                    sText = "0.00"
                Else
                    sText = pIngotMapData1.IngotShoulderDistance.ToString("####.00")
                End If

                g.DrawString(sText, _
                    fontText, _
                    New SolidBrush(Color.Black), _
                    pIngotMapData1.BarRegion.X, _
                    PosDistance, _
                    fmtTitle)

                If pIngotMapData1.IngotShoulderDistance + pIngotMapData1.Height = 0 Then
                    sText = "0.00"
                Else
                    sText = (pIngotMapData1.IngotShoulderDistance + pIngotMapData1.Height).ToString("####.00")
                End If

                g.DrawString(sText, _
                    fontText, _
                    New SolidBrush(Color.Black), _
                    pIngotMapData1.BarRegion.X + pIngotMapData1.BarRegion.Width, _
                    PosDistance, _
                    fmtTitle)

                ptLocation1 = New Point(pIngotMapData2.BarRegion.X, PosUpperArrow)
                ptLocation2 = New Point(pIngotMapData2.BarRegion.X + pIngotMapData2.BarRegion.Width, PosUpperArrow)

                pt1 = New Point(ptLocation1.X - MAP_ARROW_SIZE_PIXELS / 2, ptLocation1.Y - MAP_ARROW_SIZE_PIXELS)
                pt2 = New Point(ptLocation1.X + MAP_ARROW_SIZE_PIXELS / 2, ptLocation1.Y - MAP_ARROW_SIZE_PIXELS)
                pt3 = New Point(ptLocation1.X, ptLocation1.Y)

                pathArrow = New System.Drawing.Drawing2D.GraphicsPath()
                pathArrow.AddLine(pt1, pt2)
                pathArrow.AddLine(pt2, pt3)
                pathArrow.AddLine(pt3, pt1)
                g.FillPath(Brushes.SteelBlue, pathArrow)

                g.DrawLine(Pens.SteelBlue, ptLocation1.X, ptLocation1.Y - MAP_ARROW_SIZE_PIXELS, ptLocation1.X, PosHeight + MAP_GAP_STEP_PIXELS)

                pt1 = New Point(ptLocation2.X - MAP_ARROW_SIZE_PIXELS / 2, ptLocation2.Y - MAP_ARROW_SIZE_PIXELS)
                pt2 = New Point(ptLocation2.X + MAP_ARROW_SIZE_PIXELS / 2, ptLocation2.Y - MAP_ARROW_SIZE_PIXELS)
                pt3 = New Point(ptLocation2.X, ptLocation2.Y)

                pathArrow = New System.Drawing.Drawing2D.GraphicsPath()
                pathArrow.AddLine(pt1, pt2)
                pathArrow.AddLine(pt2, pt3)
                pathArrow.AddLine(pt3, pt1)
                g.FillPath(Brushes.SteelBlue, pathArrow)

                g.DrawLine(Pens.SteelBlue, ptLocation2.X, ptLocation2.Y - MAP_ARROW_SIZE_PIXELS, ptLocation2.X, PosHeight + MAP_GAP_STEP_PIXELS)

                g.DrawLine(Pens.SteelBlue, ptLocation1.X, PosHeight + CInt(MAP_H_ARROW_SIZE_PIXELS / 2), ptLocation2.X, PosHeight + CInt(MAP_H_ARROW_SIZE_PIXELS / 2))

                fmtTitle.LineAlignment = StringAlignment.Near
                fmtTitle.Alignment = StringAlignment.Center

                If pIngotMapData2.Height = 0 Then
                    sText = "0.00"
                Else
                    sText = pIngotMapData2.Height.ToString("####.00")
                End If

                g.DrawString(sText, _
                    fontText, _
                    New SolidBrush(Color.Black), _
                    pIngotMapData2.CenterPos, _
                    PosHeight, _
                    fmtTitle)

                g.FillRectangle(Brushes.Gainsboro, pIngotMapData2.BarRegion)
                g.FillRectangle(Brushes.WhiteSmoke, pIngotMapData1.BarRegion)

                If pIngotMapData2.IsSelected = True Then
                    Dim penSelected As Pen = New Pen(Color.Red)
                    penSelected.Width = 3
                    g.DrawRectangle(penSelected, pIngotMapData2.BarRegion)
                Else
                    g.DrawRectangle(Pens.Black, pIngotMapData2.BarRegion)
                End If

                If pIngotMapData1.IsSelected = True Then
                    Dim penSelected As Pen = New Pen(Color.Red)
                    penSelected.Width = 3
                    g.DrawRectangle(penSelected, pIngotMapData1.BarRegion)
                Else
                    g.DrawRectangle(Pens.Black, pIngotMapData1.BarRegion)
                End If

                ' Bar Text
                fontText = New Font(ParentControl.Font.FontFamily, 15, FontStyle.Bold)
                fmtTitle.LineAlignment = StringAlignment.Center
                fmtTitle.Alignment = StringAlignment.Center

                If pIngotMapData1.Height = 0 Then
                    sText = "GFO" + vbCrLf + "0.00"
                Else
                    sText = "GFO" + vbCrLf + pIngotMapData1.Height.ToString("####.00")
                End If

                g.DrawString(sText, _
                    fontText, _
                    New SolidBrush(Color.Black), _
                    pIngotMapData1.BarRegion, _
                    fmtTitle)

            Catch ex As Exception
                MsgBox("clsIngotMap.DrawGFOPosition()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function GetBarColor(ByVal sItem As String) As Color

            Dim crBar As Color = Color.Empty
            Dim iTotalCnt As Integer = 20
            Dim iColor As Integer = 0

            Try
                Dim nColorsDelta As Integer = 240 / iTotalCnt

                Select Case sItem
                    Case "RES", "1RE", "2RE", "NRE"
                        iColor = 1
                    Case "BOI", "GFA"
                        iColor = 2
                    Case "WOI"
                        iColor = 3
                    Case "BCA"
                        iColor = 4
                    Case "LT", "LT-", "LT1", "LT2"
                        iColor = 5
                    Case "OSF1", "OSF2", "OS7", "OSH", "OSN", "OSE"
                        iColor = 6
                    Case "BMD", "BM3", "BM5"
                        iColor = 7
                    Case "MD", "MD-", "MD1"
                        iColor = 8
                    Case "COP"
                        iColor = 9
                    Case "PO", "PO2", "PO5", "POA"
                        iColor = 10
                    Case "ROC"
                        iColor = 11
                    Case "BOC"
                        iColor = 12
                    Case "BOR"
                        iColor = 13
                    Case "BCR"
                        iColor = 14
                    Case "SPD", "SPF", "SPN", "SDF", "SDN", "SFN", "SPV"
                        iColor = 15
                    Case "DZ", "DZ-", "DZ3", "DZ5"
                        iColor = 16
                    Case "BMZ", "BD3", "BD5"
                        iColor = 17
                    Case "BOSF1", "BOSF2", "BO7", "BOH", "BON", "BOE"
                        iColor = 18
                    Case "OSS", "OB7", "OBH", "OBN", "OBE"
                        iColor = 19
                    Case "DSC"
                        iColor = 20
                    Case Else
                        Return Color.White
                End Select

                crBar = HLStoRGB(nColorsDelta * iColor, 120, 240)

            Catch ex As Exception
                MsgBox("clsIngotMap.GetBarColor()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return Color.Empty
            End Try

            Return crBar

        End Function


        Public Function HLStoRGB(ByVal wH As Integer, ByVal wL As Integer, ByVal wS As Integer) As Color

            Dim wR As Integer = 0
            Dim wG As Integer = 0
            Dim wB As Integer = 0

            Try
                If wS = 0 Then
                    wR = wG = wB = (wL * RGBMAX) / HLSMAX

                    If UNDEFINED <> wH Then
                        Return Color.Empty
                    End If
                Else
                    Dim Magic1 As Integer = 0
                    Dim Magic2 As Integer = 0

                    If wL <= HLSMAX / 2 Then
                        Magic2 = (wL * (HLSMAX + wS) + (HLSMAX / 2)) / HLSMAX
                    Else
                        Magic2 = wL + wS - ((wL * wS) + (HLSMAX / 2)) / HLSMAX
                    End If

                    Magic1 = 2 * wL - Magic2

                    wR = (HueToRGB(Magic1, Magic2, wH + (HLSMAX / 3)) * RGBMAX + (HLSMAX / 2)) / HLSMAX
                    wG = (HueToRGB(Magic1, Magic2, wH) * RGBMAX + (HLSMAX / 2)) / HLSMAX
                    wB = (HueToRGB(Magic1, Magic2, wH - (HLSMAX / 3)) * RGBMAX + (HLSMAX / 2)) / HLSMAX

                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.HLStoRGB()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return Color.Empty
            End Try

            Return Color.FromArgb(wR, wG, wB)

        End Function

        Public Function HueToRGB(ByVal w1 As Integer, ByVal w2 As Integer, ByVal wH As Integer) As Integer

            Try
                If (wH < 0) Then
                    wH += HLSMAX
                End If

                If (wH > HLSMAX) Then
                    wH -= HLSMAX
                End If

                If (wH < HLSMAX / 6) Then
                    Return w1 + (((w2 - w1) * wH + (HLSMAX / 12)) / (HLSMAX / 6))
                End If

                If (wH < HLSMAX / 2) Then
                    Return w2
                End If

                If (wH < (HLSMAX * 2) / 3) Then
                    Return w1 + (((w2 - w1) * (((HLSMAX * 2) / 3) - wH) + (HLSMAX / 12)) / (HLSMAX / 6))
                Else
                    Return w1
                End If

            Catch ex As Exception
                MsgBox("clsIngotMap.HueToRGB()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return 0
            End Try

        End Function

#End Region

    End Class

End Namespace

