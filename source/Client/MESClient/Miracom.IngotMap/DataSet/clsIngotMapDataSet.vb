Namespace DataSet

    Public Class DataSetSortClass
        Implements IComparer

        ' Calls CaseInsensitiveComparer.Compare with the parameters reversed.
        Public Function Compare(ByVal x As Object, ByVal y As Object) As Integer _
           Implements IComparer.Compare

            Return New CaseInsensitiveComparer().Compare(CType(x, clsIngotMapData).SeqNum, _
                                                         CType(y, clsIngotMapData).SeqNum)
        End Function 'IComparer.Compare

    End Class

    Public Class clsIngotMapDataSet
        Inherits ArrayList

#Region "Properties Implementation"

        Private m_pParentControl As IngotMap = Nothing
        Private m_dIngotLength As Double = DOUBLE_NULL_DATA
        Private m_dStartPosition As Double = DOUBLE_NULL_DATA
        Private m_dGFOLength As Double = DOUBLE_NULL_DATA

        Public ReadOnly Property ParentControl() As IngotMap
            Get
                Return m_pParentControl
            End Get
        End Property

        Public Property StartPosition() As Double
            Get
                Return m_dStartPosition
            End Get
            Set(ByVal Value As Double)
                If m_dStartPosition.Equals(Value) = False Then
                    m_dStartPosition = Value
                End If
            End Set
        End Property

        Public Property GFOLength() As Double
            Get
                Return m_dGFOLength
            End Get
            Set(ByVal Value As Double)
                If m_dGFOLength.Equals(Value) = False Then
                    m_dGFOLength = Value
                End If
            End Set
        End Property

        Public Property IngotLength() As Double
            Get
                Return m_dIngotLength
            End Get
            Set(ByVal Value As Double)
                If m_dIngotLength.Equals(Value) = False Then
                    m_dIngotLength = Value
                End If
            End Set
        End Property

#End Region

#Region "Functions Implementation"

        Public Sub New(ByRef pParentControl As IngotMap)
            MyBase.New()

            Try
                ResetContents()
                SetParentControl(pParentControl)

            Catch ex As Exception
                MsgBox("clsIngotMapDataSet.New()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Sub SetParentControl(ByRef pParentControl As IngotMap)

            Try
                m_pParentControl = pParentControl

            Catch ex As Exception
                MsgBox("clsIngotMapDataSet.SetParentControl()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Sub ResetContents()

            Try
                InitMap()

            Catch ex As Exception
                MsgBox("clsIngotMapDataSet.ResetContents()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Sub InitMap()

            Try
                Me.Clear()
                IngotLength = DOUBLE_NULL_DATA
                StartPosition = DOUBLE_NULL_DATA
                GFOLength = DOUBLE_NULL_DATA

            Catch ex As Exception
                MsgBox("clsIngotMapDataSet.InitMap()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Sub SortMapData()

            Try
                Dim sortClass As DataSetSortClass = New DataSetSortClass()
                Me.Sort(sortClass)

            Catch ex As Exception
                MsgBox("clsIngotMapDataSet.SortMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Function AddMapData(ByVal iSeqNum As Integer, ByVal sFullName As String, ByVal sDisplayName As String, ByVal sText As String, ByVal dHeight As Double, _
            ByVal dDistance As Double, ByVal iPCS As Integer, ByVal eSegmentType As SEGMENT_TYPES, _
            ByVal eTPTypeFlag As TP_TYPES_FLAG, ByVal eTPShape As TP_SHAPE, ByVal sRelationTPName As String, ByVal iDivisionNum As Integer) As Boolean

            Dim i As Integer = 0

            Try
                For i = 0 To Me.Count - 1
                    If CType(Me(i), clsIngotMapData).FullName = sFullName Then
                        CType(Me(i), clsIngotMapData).SetMapData(iSeqNum, sFullName, sDisplayName, sText, dHeight, dDistance, iPCS, eSegmentType, eTPTypeFlag, eTPShape, sRelationTPName, False, iDivisionNum)
                        SortMapData()
                        Return True
                    End If
                Next

                Dim pNewIngotMapData As clsIngotMapData = New clsIngotMapData(sFullName, Me)
                pNewIngotMapData.SetMapData(iSeqNum, sFullName, sDisplayName, sText, dHeight, dDistance, iPCS, eSegmentType, eTPTypeFlag, eTPShape, sRelationTPName, True, iDivisionNum)
                Me.Add(pNewIngotMapData)

                SortMapData()

            Catch ex As Exception
                MsgBox("clsIngotMapDataSet.AddMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function SetGFOPosition(ByVal dIngotLength As Double, ByVal dStartPos As Double, ByVal dGFOLength As Double) As Boolean

            Dim pIngotMapData As clsIngotMapData = Nothing
            Dim sName As String = ""

            Try
                InitMap()

                IngotLength = dIngotLength
                StartPosition = dStartPos
                GFOLength = dGFOLength

                sName = "GFO"
                Dim pNewIngotMapData As clsIngotMapData = New clsIngotMapData(sName, Me)
                pNewIngotMapData.SetMapData(sName, sName, "", dGFOLength, dStartPos, 0, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.G, TP_SHAPE.BLANK, "", 0)
                Me.Add(pNewIngotMapData)

                sName = "INGOT"
                pNewIngotMapData = New clsIngotMapData(sName, Me)
                pNewIngotMapData.SetMapData(sName, sName, "", dIngotLength, 0, 0, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.G, TP_SHAPE.BLANK, "", 0)
                Me.Add(pNewIngotMapData)

            Catch ex As Exception
                MsgBox("clsIngotMapDataSet.SetGFOPosition()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

        Public Function CalculationSize(ByVal parent As System.Windows.Forms.Control) As Boolean

            Dim i As Integer
            Dim pIngotMapData As DataSet.clsIngotMapData
            Dim iSumSize As Integer

            Try
                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then

                    Dim sGFOName As String = "GFO"
                    Dim dHeight As Double = 0.0

                    Dim iTest As Integer = 2

                    For i = Me.Count - 1 To 0 Step -1

                        If i = 0 Then
                            If CType(Me(i), clsIngotMapData).SegmentType = SEGMENT_TYPES.TP Then
                                If CType(Me(i), clsIngotMapData).PCS > 1 Then
                                    Dim pNewIngotMapData As clsIngotMapData = New clsIngotMapData(sGFOName, Me)
                                    dHeight = CType(Me(i), clsIngotMapData).PCS - 1
                                    pNewIngotMapData.SetMapData(i + 1, sGFOName, sGFOName, sGFOName, dHeight, dHeight, 1, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.A, TP_SHAPE.BLANK, "", True, 0)
                                    Me.Insert(i, pNewIngotMapData)
                                    i += 1
                                End If
                            End If
                            If CType(Me(i), clsIngotMapData).SegmentType = SEGMENT_TYPES.TP Then
                                If CType(Me(i + 1), clsIngotMapData).PCS - CType(Me(i), clsIngotMapData).PCS > 1 Then
                                    dHeight = CType(Me(i + 1), clsIngotMapData).PCS - CType(Me(i), clsIngotMapData).PCS - 1
                                    Dim pNewIngotMapData As clsIngotMapData = New clsIngotMapData(sGFOName, Me)
                                    pNewIngotMapData.SetMapData(i + 1, sGFOName, sGFOName, sGFOName, dHeight, dHeight, CType(Me(i), clsIngotMapData).PCS + 1, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.A, TP_SHAPE.BLANK, "", True, 0)
                                    Me.Insert(i + 1, pNewIngotMapData)
                                End If
                            End If
                        ElseIf i = Me.Count - 1 Then
                            If CType(Me(i), clsIngotMapData).SegmentType = SEGMENT_TYPES.TP Then
                                If CType(Me(i), clsIngotMapData).PCS < ParentControl.PPNQty Then
                                    Dim pNewIngotMapData As clsIngotMapData = New clsIngotMapData(sGFOName, Me)
                                    dHeight = ParentControl.PPNQty - CType(Me(i), clsIngotMapData).PCS
                                    pNewIngotMapData.SetMapData(i + 1, sGFOName, sGFOName, sGFOName, dHeight, dHeight, CType(Me(i), clsIngotMapData).PCS + 1, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.A, TP_SHAPE.BLANK, "", True, 0)
                                    Me.Insert(i + 1, pNewIngotMapData)
                                End If
                            End If
                        Else
                            If CType(Me(i), clsIngotMapData).SegmentType = SEGMENT_TYPES.TP Then
                                If CType(Me(i + 1), clsIngotMapData).PCS - CType(Me(i), clsIngotMapData).PCS > 1 Then
                                    dHeight = CType(Me(i + 1), clsIngotMapData).PCS - CType(Me(i), clsIngotMapData).PCS - 1
                                    Dim pNewIngotMapData As clsIngotMapData = New clsIngotMapData(sGFOName, Me)
                                    pNewIngotMapData.SetMapData(i + 1, sGFOName, sGFOName, sGFOName, dHeight, dHeight, CType(Me(i), clsIngotMapData).PCS + 1, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.A, TP_SHAPE.BLANK, "", True, 0)
                                    Me.Insert(i + 1, pNewIngotMapData)
                                End If
                            End If
                        End If
                    Next
                End If

                If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Or ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_2 Then

                    iSumSize = MAP_BORDER_PIXELS

                    If ParentControl.MainTitle <> STRING_NULL_DATA Then
                        iSumSize += (MAP_TOP_GAP_PIXELS * 2)
                    Else
                        iSumSize += MAP_TOP_GAP_PIXELS
                    End If


                    For i = 0 To ParentControl.DataSet.Count - 1
                        pIngotMapData = CType(ParentControl.DataSet(i), DataSet.clsIngotMapData)

                        If ParentControl.IngotMapType = INGOT_MAP_TYPE.TYPE_1 Then
                            If i > 0 Then
                                If CType(ParentControl.DataSet(i - 1), DataSet.clsIngotMapData).DivisionNum <> pIngotMapData.DivisionNum Then
                                    iSumSize += MAP_BAR_HEIGHT_PIXELS
                                End If
                            End If
                        End If

                        If pIngotMapData.SegmentType = SEGMENT_TYPES.TP Or pIngotMapData.SegmentType = SEGMENT_TYPES.VTP Then
                            iSumSize += (MAP_BAR_HEIGHT_PIXELS + MAP_GAP_BAR_PIXELS)
                        ElseIf pIngotMapData.SegmentType = SEGMENT_TYPES.GFO Then
                            iSumSize += (MAP_GFO_HEIGHT_PIXELS + MAP_GAP_BAR_PIXELS)
                        Else
                            iSumSize += (MAP_SCRAP_HEIGHT_PIXELS + MAP_GAP_BAR_PIXELS)
                        End If
                    Next

                    iSumSize += MAP_BOTTOM_GAP_PIXELS

                    ParentControl.IngotMapHeight = iSumSize

                    ParentControl.Size = New Size(ParentControl.Width, iSumSize)

                End If

            Catch ex As Exception
                MsgBox("clsIngotMapDataSet.CalculationSize()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
                Return False
            End Try

            Return True

        End Function

#End Region

    End Class

End Namespace
