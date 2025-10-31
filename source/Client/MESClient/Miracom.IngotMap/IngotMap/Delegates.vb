
Namespace DrawIngotMap

    Public Delegate Sub MouseButtonDownEventHandler(ByVal sender As Object, ByVal e As MouseButtonDown_EventArgs)

    Public Class MouseButtonDown_EventArgs
        Inherits System.Windows.Forms.MouseEventArgs


#Region "Properties Implementation"

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

#End Region

#Region "Functions Implementation"

        Public Sub New(ByVal button As MouseButtons, ByVal clicks As Integer, ByVal x As Integer, ByVal y As Integer, ByVal delta As Integer)
            MyBase.New(button, clicks, x, y, delta)

            Try
                'Nothing

            Catch ex As Exception
                MsgBox("MouseButtonDown_EventArgs.New()" & vbCrLf & ex.Message, MsgBoxStyle.Critical)
            End Try

        End Sub

#End Region

    End Class

End Namespace

