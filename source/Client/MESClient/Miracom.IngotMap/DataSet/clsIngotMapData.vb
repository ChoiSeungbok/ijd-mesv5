Namespace DataSet

    Public Class clsIngotMapData
        Inherits Object

#Region " Properties Implementation"

        Private m_iSeqNum As Integer = INTEGER_NULL_DATA
        Private m_dIngotShoulderDistance As Double = DOUBLE_NULL_DATA
        Private m_iPCS As Integer = INTEGER_NULL_DATA
        Private m_dHeight As Double = DOUBLE_NULL_DATA
        Private m_eSegmentType As SEGMENT_TYPES
        Private m_eTPType As TP_TYPES
        Private m_eTPTypeFlag As TP_TYPES_FLAG
        Private m_eTPShape As TP_SHAPE
        Private m_sText As String = STRING_NULL_DATA
        Private m_sFullName As String = STRING_NULL_DATA
        Private m_sDisplayName As String = STRING_NULL_DATA
        Private m_sRelationTPName As String = STRING_NULL_DATA
        Private m_rcBarRegion As Rectangle = Rectangle.Empty
        Private m_iCenterPos As Integer = INTEGER_NULL_DATA
        Private m_iStartPos As Integer = INTEGER_NULL_DATA

        Private m_iDivisionNum As Integer = INTEGER_NULL_DATA

        Private m_ParentDataSet As clsIngotMapDataSet = Nothing

        Private m_bIsSelected As Boolean = False
        Private m_bModifiedFlag As Boolean = True

        Public Property SeqNum() As Integer
            Get
                Return m_iSeqNum
            End Get
            Set(ByVal value As Integer)
                If m_iSeqNum.Equals(value) = False Then
                    m_iSeqNum = value
                End If
            End Set
        End Property

        Public Property IngotShoulderDistance() As Double
            Get
                Return m_dIngotShoulderDistance
            End Get
            Set(ByVal value As Double)
                If m_dIngotShoulderDistance.Equals(value) = False Then
                    m_dIngotShoulderDistance = value
                End If
            End Set
        End Property

        Public Property PCS() As Integer
            Get
                Return m_iPCS
            End Get
            Set(ByVal value As Integer)
                If m_iPCS.Equals(value) = False Then
                    m_iPCS = value
                End If
            End Set
        End Property

        Public Property Height() As Double
            Get
                Return m_dHeight
            End Get
            Set(ByVal value As Double)
                If m_dHeight.Equals(value) = False Then
                    m_dHeight = value
                End If
            End Set
        End Property

        Public Property SegmentType() As SEGMENT_TYPES
            Get
                Return m_eSegmentType
            End Get
            Set(ByVal value As SEGMENT_TYPES)
                If m_eSegmentType.Equals(value) = False Then
                    m_eSegmentType = value
                End If
            End Set
        End Property

        Public Property TPType() As TP_TYPES
            Get
                Return m_eTPType
            End Get
            Set(ByVal value As TP_TYPES)
                If m_eTPType.Equals(value) = False Then
                    m_eTPType = value
                End If
            End Set
        End Property

        Public Property TPTypeFlag() As TP_TYPES_FLAG
            Get
                Return m_eTPTypeFlag
            End Get
            Set(ByVal value As TP_TYPES_FLAG)
                If m_eTPTypeFlag.Equals(value) = False Then
                    m_eTPTypeFlag = value
                End If
            End Set
        End Property

        Public Property TPShape() As TP_SHAPE
            Get
                Return m_eTPShape
            End Get
            Set(ByVal value As TP_SHAPE)
                If m_eTPShape.Equals(value) = False Then
                    m_eTPShape = value
                End If
            End Set
        End Property

        Public Property Text() As String
            Get
                Return m_sText
            End Get
            Set(ByVal value As String)
                If m_sText.Equals(value) = False Then
                    m_sText = value
                End If
            End Set
        End Property

        Public Property FullName() As String
            Get
                Return m_sFullName
            End Get
            Set(ByVal value As String)
                If m_sFullName.Equals(value) = False Then
                    m_sFullName = value
                End If
            End Set
        End Property

        Public Property DisplayName() As String
            Get
                Return m_sDisplayName
            End Get
            Set(ByVal value As String)
                If m_sDisplayName.Equals(value) = False Then
                    m_sDisplayName = value
                End If
            End Set
        End Property

        Public Property RelationTPName() As String
            Get
                Return m_sRelationTPName
            End Get
            Set(ByVal value As String)
                If m_sRelationTPName.Equals(value) = False Then
                    m_sRelationTPName = value
                End If
            End Set
        End Property

        Public Property BarRegion() As Rectangle
            Get
                Return m_rcBarRegion
            End Get
            Set(ByVal value As Rectangle)
                If m_rcBarRegion.Equals(value) = False Then
                    m_rcBarRegion = value
                End If
            End Set
        End Property

        Public Property CenterPos() As Integer
            Get
                Return m_iCenterPos
            End Get
            Set(ByVal value As Integer)
                If m_iCenterPos.Equals(value) = False Then
                    m_iCenterPos = value
                End If
            End Set
        End Property

        Public Property StartPos() As Integer
            Get
                Return m_iStartPos
            End Get
            Set(ByVal value As Integer)
                If m_iStartPos.Equals(value) = False Then
                    m_iStartPos = value
                End If
            End Set
        End Property

        Public ReadOnly Property ParentDataSet() As clsIngotMapDataSet
            Get
                Return m_ParentDataSet
            End Get
        End Property

        Public Property IsSelected() As Boolean
            Get
                Return m_bIsSelected
            End Get
            Set(ByVal value As Boolean)
                If m_bIsSelected.Equals(value) = False Then
                    m_bIsSelected = value
                End If
            End Set
        End Property

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

        Public Property DivisionNum() As Integer
            Get
                Return m_iDivisionNum
            End Get
            Set(ByVal value As Integer)
                If m_iDivisionNum.Equals(value) = False Then
                    m_iDivisionNum = value
                End If
            End Set
        End Property

#End Region

#Region " Functions Implementation"

        Public Sub New(ByVal sName As String, ByRef parentDatset As clsIngotMapDataSet)
            MyBase.New()

            Try
                SetParentDataSet(parentDatset)

                FullName = sName
                IngotShoulderDistance = DOUBLE_NULL_DATA

            Catch ex As Exception
                MsgBox("clsIngotMapData.New()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Sub SetParentDataSet(ByRef parentDatset As clsIngotMapDataSet)

            Try
                m_ParentDataSet = parentDatset

            Catch ex As Exception
                MsgBox("clsIngotMapData.SetParentDataSet()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Sub SetMapData(ByVal iSeqNum As Integer, ByVal sFullName As String, ByVal sDisplayName As String, ByVal sText As String, ByVal dHeight As Double, _
            ByVal dDistance As Double, ByVal iPCS As Integer, ByVal eSegmentType As SEGMENT_TYPES, _
            ByVal eTPTypeFlag As TP_TYPES_FLAG, ByVal eTPShape As TP_SHAPE, ByVal sRelationTPName As String, ByVal bAddFlag As Boolean, ByVal iDivisionNum As Integer)

            Dim i As Integer = 0

            Try
                SeqNum = iSeqNum

                If ParentDataSet.ParentControl.IsAddDataFlag = True Then
                    Me.IsModifiedFlag = True
                End If

                If bAddFlag = True Then
                    For i = 0 To ParentDataSet.Count - 1
                        If CType(ParentDataSet(i), clsIngotMapData).SeqNum >= SeqNum Then
                            CType(ParentDataSet(i), clsIngotMapData).SeqNum += 1
                            CType(ParentDataSet(i), clsIngotMapData).IsModifiedFlag = True
                        End If
                    Next
                End If

                FullName = sFullName
                DisplayName = sDisplayName
                Text = sText
                Height = dHeight
                IngotShoulderDistance = dDistance
                PCS = iPCS
                SegmentType = eSegmentType
                TPTypeFlag = eTPTypeFlag
                TPShape = eTPShape
                RelationTPName = sRelationTPName
                DivisionNum = iDivisionNum

                If eTPTypeFlag = TP_TYPES_FLAG.A Then
                    TPType = TP_TYPES.GRAY
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.B Then
                    TPType = TP_TYPES.BLACK
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.D Then
                    TPType = TP_TYPES.DARK_GRAY
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.G Then
                    TPType = TP_TYPES.GREEN
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.L Then
                    TPType = TP_TYPES.LIGHT_GREEN
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.O Then
                    TPType = TP_TYPES.ORANGE
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.R Then
                    TPType = TP_TYPES.RED
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.W Then
                    TPType = TP_TYPES.WHITE
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.Y Then
                    TPType = TP_TYPES.YELLOW
                End If

            Catch ex As Exception
                MsgBox("clsIngotMapData.SetMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

        Public Sub SetMapData(ByVal sFullName As String, ByVal sDisplayName As String, ByVal sText As String, ByVal dHeight As Double, _
            ByVal dDistance As Double, ByVal iPCS As Integer, ByVal eSegmentType As SEGMENT_TYPES, _
            ByVal eTPTypeFlag As TP_TYPES_FLAG, ByVal eTPShape As TP_SHAPE, ByVal sRelationTPName As String, ByVal iDivisionNum As Integer)

            Try
                FullName = sFullName
                DisplayName = sDisplayName
                Text = sText
                Height = dHeight
                IngotShoulderDistance = dDistance
                PCS = iPCS
                SegmentType = eSegmentType
                TPTypeFlag = eTPTypeFlag
                TPShape = eTPShape
                RelationTPName = sRelationTPName
                DivisionNum = iDivisionNum

                If eTPTypeFlag = TP_TYPES_FLAG.A Then
                    TPType = TP_TYPES.GRAY
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.B Then
                    TPType = TP_TYPES.BLACK
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.D Then
                    TPType = TP_TYPES.DARK_GRAY
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.G Then
                    TPType = TP_TYPES.GREEN
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.L Then
                    TPType = TP_TYPES.LIGHT_GREEN
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.O Then
                    TPType = TP_TYPES.ORANGE
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.R Then
                    TPType = TP_TYPES.RED
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.W Then
                    TPType = TP_TYPES.WHITE
                ElseIf eTPTypeFlag = TP_TYPES_FLAG.Y Then
                    TPType = TP_TYPES.YELLOW
                End If

            Catch ex As Exception
                MsgBox("clsIngotMapData.SetMapData()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

#End Region

    End Class

End Namespace