Public Class frmViewIngotMap

    Private Sub IngotMap1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles IngotMap1.Load

        Try
            Me.Location = New Point(0, 0)

        Catch ex As Exception
            MsgBox(ex.Message)
        End Try
    End Sub

    Private Sub btnView_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnView.Click

        Try
            Me.IngotMap1.SetIngotMapType(INGOT_MAP_TYPE.TYPE_2, 50)
            Me.IngotMap2.SetIngotMapType(INGOT_MAP_TYPE.TYPE_3, 70)
            Me.IngotMap3.SetIngotMapType(INGOT_MAP_TYPE.TYPE_4, 70)


            Me.IngotMap1.ResetMapData()
            Me.IngotMap1.SetMainTitle("EXE585-1")
            If Me.IngotMap1.AddMapData(1, "EXE585-1-ST11S", "ST11S", "OS7", 1, 0, SEGMENT_TYPES.TP, TP_TYPES_FLAG.D, TP_SHAPE.X, 1, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap1.AddMapData(2, "EXE585-1-ST11R", "ST11R", "RES", 1, 1.97, SEGMENT_TYPES.TP, TP_TYPES_FLAG.G, TP_SHAPE.CIRCLE, 2, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap1.AddMapData(3, "EXE585-1-ST12S", "ST12S", "OS7", 1, 3.87, SEGMENT_TYPES.TP, TP_TYPES_FLAG.L, TP_SHAPE.CIRCLE, 4, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap1.AddMapData(4, "SCRAP", "", "SCRAP", 30, 5.78, SEGMENT_TYPES.SCRAP, TP_TYPES_FLAG.B, TP_SHAPE.BLANK, 5, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap1.AddMapData(5, "EXE585-1", "EXE585-1", "G1", 120 - 5.5, 5.5, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.A, TP_SHAPE.BLANK, 5, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap1.AddMapData(6, "EXE585-2-ST11R", "ST11R", "RES", 2, 120, SEGMENT_TYPES.TP, TP_TYPES_FLAG.O, TP_SHAPE.SQUARE, 100, "", 2) = False Then
                Exit Sub
            End If
            If Me.IngotMap1.AddMapData(7, "EXE585-2", "EXE585-2", "G2", 260 - 122, 122, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.A, TP_SHAPE.BLANK, 101, "", 2) = False Then
                Exit Sub
            End If
            If Me.IngotMap1.AddMapData(8, "EXE585-2-SB11R", "SB11R", "RES", 2, 260, SEGMENT_TYPES.TP, TP_TYPES_FLAG.R, TP_SHAPE.TRIAGLE, 259, "", 2) = False Then
                Exit Sub
            End If
            If Me.IngotMap1.AddMapData(9, "EXE585-2-ZB11R", "ZB11R", "RES", 1, 264, SEGMENT_TYPES.VTP, TP_TYPES_FLAG.Y, TP_SHAPE.CIRCLE, 260, "2-ST11R", 2) = False Then
                Exit Sub
            End If
            Me.IngotMap1.Refresh()

            Me.IngotMap2.ResetMapData()
            Me.IngotMap1.SetMainTitle("EXE585")
            If Me.IngotMap2.AddMapData(1, "EXE585-1-ST11S", "ST11S", "OS7", 1, 0, SEGMENT_TYPES.TP, TP_TYPES_FLAG.D, TP_SHAPE.X, 1, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap2.AddMapData(2, "EXE585-1-ST11S", "ST11R", "RES", 1, 1.97, SEGMENT_TYPES.TP, TP_TYPES_FLAG.G, TP_SHAPE.CIRCLE, 2, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap2.AddMapData(3, "EXE585-1-ST11S", "ST12S", "BOR", 1, 3.87, SEGMENT_TYPES.TP, TP_TYPES_FLAG.L, TP_SHAPE.CIRCLE, 4, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap2.AddMapData(4, "EXE585-1-ST11S", "", "SCRAP", 30, 5.78, SEGMENT_TYPES.SCRAP, TP_TYPES_FLAG.B, TP_SHAPE.BLANK, 5, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap2.AddMapData(5, "EXE585-1-ST11S", "EXE585-1", "G1", 120 - 10.5, 10.5, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.A, TP_SHAPE.BLANK, 16, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap2.AddMapData(6, "EXE585-1-SB11R", "SB11R", "DSC", 2, 120, SEGMENT_TYPES.TP, TP_TYPES_FLAG.O, TP_SHAPE.SQUARE, 100, "", 1) = False Then
                Exit Sub
            End If
            If Me.IngotMap2.AddMapData(7, "EXE585-2", "EXE585-1", "G2", 260 - 122, 122, SEGMENT_TYPES.GFO, TP_TYPES_FLAG.A, TP_SHAPE.BLANK, 101, "", 2) = False Then
                Exit Sub
            End If
            If Me.IngotMap2.AddMapData(8, "EXE585-2-SB11R", "SB11R", "GFA", 2, 260, SEGMENT_TYPES.TP, TP_TYPES_FLAG.R, TP_SHAPE.TRIAGLE, 259, "", 2) = False Then
                Exit Sub
            End If
            If Me.IngotMap2.AddMapData(9, "EXE585-2-ZB11R", "ZB11R", "WOI", 1, 264, SEGMENT_TYPES.VTP, TP_TYPES_FLAG.Y, TP_SHAPE.CIRCLE, 260, "2-ST11R", 2) = False Then
                Exit Sub
            End If
            Me.IngotMap2.Refresh()

            Me.IngotMap3.ResetMapData()
            Me.IngotMap3.MainTitle = "KVN240"
            If Me.IngotMap3.SetGFOPosition(1250, 85.54, 981.79) = False Then
                Exit Sub
            End If

            Me.IngotMap3.Refresh()

        Catch ex As Exception
            MsgBox(ex.Message)
        End Try

    End Sub

    Private Sub btnClose_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnClose.Click

        Me.Close()

    End Sub

    Private Sub btnCopyImage1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCopyImage1.Click

        If IngotMap1.CopyImage() = False Then Exit Sub

    End Sub

    Private Sub btnSaveImage1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSaveImage1.Click

        Dim dlg As SaveFileDialog = New SaveFileDialog
        dlg.Filter = "Png Image|*.png"
        dlg.Title = "Save an Image File"
        If dlg.ShowDialog() = System.Windows.Forms.DialogResult.OK Then

            IngotMap1.SaveImage(dlg.FileName)

        End If

    End Sub

    Private Sub btnPrint1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnPrint1.Click

        If IngotMap1.Print() = False Then Exit Sub

    End Sub

    Private Sub btnCopyImage2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCopyImage2.Click

        If IngotMap2.CopyImage() = False Then Exit Sub

    End Sub

    Private Sub btnSaveImage2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSaveImage2.Click

        Dim dlg As SaveFileDialog = New SaveFileDialog
        dlg.Filter = "Png Image|*.png"
        dlg.Title = "Save an Image File"
        If dlg.ShowDialog() = System.Windows.Forms.DialogResult.OK Then

            IngotMap2.SaveImage(dlg.FileName)

        End If

    End Sub

    Private Sub btnPrint2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnPrint2.Click

        If IngotMap2.Print() = False Then Exit Sub

    End Sub

    Private Sub btnCopyImage3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCopyImage3.Click

        If IngotMap3.CopyImage() = False Then Exit Sub

    End Sub

    Private Sub btnSaveImage3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSaveImage3.Click

        Dim dlg As SaveFileDialog = New SaveFileDialog
        dlg.Filter = "Png Image|*.png"
        dlg.Title = "Save an Image File"
        If dlg.ShowDialog() = System.Windows.Forms.DialogResult.OK Then

            IngotMap3.SaveImage(dlg.FileName)

        End If

    End Sub

    Private Sub btnPrint3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnPrint3.Click

        If IngotMap3.Print() = False Then Exit Sub

    End Sub

    Private Sub IngotMap1_MouseButtonDown(ByVal sender As System.Object, ByVal e As Miracom.IngotMap.DrawIngotMap.MouseButtonDown_EventArgs) Handles IngotMap1.MouseButtonDown

        Me.txtClickInfo.Text = e.FullName + " : " + e.IngotShoulderDistance.ToString

    End Sub

    Private Sub IngotMap2_MouseButtonDown(ByVal sender As System.Object, ByVal e As Miracom.IngotMap.DrawIngotMap.MouseButtonDown_EventArgs) Handles IngotMap2.MouseButtonDown

        Me.txtClickInfo.Text = e.FullName + " : " + e.IngotShoulderDistance.ToString

    End Sub

    Private Sub IngotMap3_MouseButtonDown(ByVal sender As System.Object, ByVal e As Miracom.IngotMap.DrawIngotMap.MouseButtonDown_EventArgs) Handles IngotMap3.MouseButtonDown

        Me.txtClickInfo.Text = e.FullName + " : " + e.IngotShoulderDistance.ToString

    End Sub

End Class