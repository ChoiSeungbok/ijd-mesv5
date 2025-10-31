using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using System.ComponentModel;
using System.Drawing.Drawing2D;


namespace Miracom.FMBUI
{
    namespace Controls
    {

        public class udcCtrlResource : FMBUI.Controls.udcCtrlBase
        {


            #region " Windows Form Auto Generated Code "

            public udcCtrlResource()
            {

                //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
                InitializeComponent();

                //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.

            }

            public udcCtrlResource(ImageList imlRes)
            {

                //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
                InitializeComponent();
                int i;
                for (i = 0; i <= imlRes.Images.Count - 1; i++)
                {
                    this.imlResource.Images.Add(imlRes.Images[i]);
                }
                //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.

            }

            //Form? Dispose瑜??ъ젙?섑븯??援ъ꽦 ?붿냼 紐⑸줉???뺣━?⑸땲??
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

            //Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            private System.ComponentModel.Container components = null;

            //李멸퀬: ?ㅼ쓬 ?꾨줈?쒖???Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            //Windows Form ?붿옄?대꼫瑜??ъ슜?섏뿬 ?섏젙?????덉뒿?덈떎.
            //肄붾뱶 ?몄쭛湲곕? ?ъ슜?섏뿬 ?섏젙?섏? 留덉떗?쒖삤.
            public System.Windows.Forms.ImageList imlResource;
            [System.Diagnostics.DebuggerStepThrough()]
            private void InitializeComponent()
            {
                this.components = new System.ComponentModel.Container();
                System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(udcCtrlResource));
                this.imlResource = new System.Windows.Forms.ImageList(this.components);
                ((System.ComponentModel.ISupportInitialize)this).BeginInit();
                //
                //imlResource
                //
                this.imlResource.ImageSize = new System.Drawing.Size(32, 32);
                this.imlResource.ImageStream = (System.Windows.Forms.ImageListStreamer)resources.GetObject("imlResource.ImageStream");
                this.imlResource.TransparentColor = System.Drawing.Color.Transparent;
                //
                //udcCtrlResource
                //
                this.Name = "udcCtrlResource";
                ((System.ComponentModel.ISupportInitialize)this).EndInit();

            }

            #endregion

            private const int RC_SIZE = 7;
            private const int OUT_LINE = 6;

            protected override void DrawControl(Graphics g)
            {

                try
                {

                    switch ((int)CtrlStatus.ResShape - '0')
                    {
                        case (int)Enums.eResourceShape.Ellipse:
                            if (IsSelected == true && IsDesignMode == true)
                            {
                                GraphicsPath path = new GraphicsPath();
                                path.AddEllipse(CtrlPos);
                                path.CloseFigure();
                                Region meRegion = new Region(path);
                                int i;
                                for (i = 1; i <= GetTrackerCount(Enums.eLineType.Null); i++)
                                {
                                    path.Reset();
                                    path.AddRectangle(GetTrackerRect(i));
                                    path.CloseFigure();
                                    meRegion.Union(path);
                                }
                                this.Region = meRegion;
                                path.Dispose();
                                meRegion.Dispose();

                                DrawCtrlEllipse(g);
                                DrawTracker(g, Enums.eLineType.Null);
                            }
                            else
                            {
                                GraphicsPath path = new GraphicsPath();
                                path.AddEllipse(CtrlPos);
                                path.CloseFigure();
                                Region meRegion = new Region(path);
                                this.Region = meRegion;
                                path.Dispose();
                                meRegion.Dispose();

                                DrawCtrlEllipse(g);
                            }
                            break;
                        case (int)Enums.eResourceShape.Stocker:
                            if (IsSelected == true && IsDesignMode == true)
                            {
                                GraphicsPath path = new GraphicsPath();
                                AddStocker(path, CtrlPos);
                                path.CloseFigure();
                                Region meRegion = new Region(path);
                                int i;
                                for (i = 1; i <= GetTrackerCount(Enums.eLineType.Null); i++)
                                {
                                    path.Reset();
                                    path.AddRectangle(GetTrackerRect(i));
                                    path.CloseFigure();
                                    meRegion.Union(path);
                                }
                                this.Region = meRegion;
                                path.Dispose();
                                meRegion.Dispose();

                                DrawCtrlStockerResource(g);
                                DrawTracker(g, Enums.eLineType.Null);
                            }
                            else
                            {
                                GraphicsPath path = new GraphicsPath();
                                AddStocker(path, CtrlPos);
                                path.CloseFigure();
                                Region meRegion = new Region(path);
                                this.Region = meRegion;
                                path.Dispose();
                                meRegion.Dispose();

                                DrawCtrlStockerResource(g);
                            }
                            break;
                        default:
                            if (IsSelected == true && IsDesignMode == true)
                            {
                                GraphicsPath path = new GraphicsPath();
                                path.AddRectangle(CtrlPos);
                                Region meRegion = new Region(path);
                                int i;
                                for (i = 1; i <= GetTrackerCount(Enums.eLineType.Null); i++)
                                {
                                    path.Reset();
                                    path.AddRectangle(GetTrackerRect(i));
                                    path.CloseFigure();
                                    meRegion.Union(path);
                                }
                                this.Region = meRegion;
                                path.Dispose();
                                meRegion.Dispose();
                                DrawCtrlResource(g);
                                DrawTracker(g, Enums.eLineType.Null);
                            }
                            else
                            {
                                GraphicsPath path = new GraphicsPath();
                                path.AddRectangle(CtrlPos);
                                path.CloseFigure();
                                Region meRegion = new Region(path);
                                this.Region = meRegion;
                                path.Dispose();
                                meRegion.Dispose();
                                DrawCtrlResource(g);
                            }
                            break;
                    }




                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "udcCtrlResource.DrawControl()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }


            private void DrawCtrlResource(Graphics g)
            {

                try
                {
                    g.FillRectangle(new SolidBrush(CtrlStatus.GetBackColor(IsHot, IsPressed)), CtrlPos.X, CtrlPos.Y, CtrlPos.Width - 1, CtrlPos.Height - 1);
                    g.DrawRectangle(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), CtrlPos.X, CtrlPos.Y, CtrlPos.Width - 1, CtrlPos.Height - 1);

                    int iXSignalSize, iYSignalSize;
                    int iXPos = 0;
                    int iYPos = 0;
                    int iSignalX, iSignalY, iSignalWidth, iSignalHeight;

                    iXSignalSize = 0;
                    iYSignalSize = 0;

                    if (CtrlStatus.IsViewSignal == true)
                    {
                        //Operation Mode
                        if (CtrlStatus.SignalPosition == '1')
                        {
                            if (CtrlStatus.CtrlMode.Trim() != "")
                            {
                                if (CtrlStatus.CtrlMode.Substring(0, 2) == "OL")
                                {
                                    g.DrawRectangle(new Pen(Color.Blue, 1), CtrlPos.X, CtrlPos.Y, CtrlPos.Width - 1, CtrlPos.Height - 1);
                                }
                                else if (CtrlStatus.CtrlMode.Substring(0, 2) == "OR")
                                {
                                    g.DrawRectangle(new Pen(Color.Magenta, 1), CtrlPos.X, CtrlPos.Y, CtrlPos.Width - 1, CtrlPos.Height - 1);
                                }
                                else if (CtrlStatus.CtrlMode.Substring(0, 2) == "OF")
                                {
                                    g.DrawRectangle(new Pen(Color.White, 1), CtrlPos.X, CtrlPos.Y, CtrlPos.Width - 1, CtrlPos.Height - 1);
                                }
                            }

                        }
                        else
                        {
                            int iRed = 0;
                            int iGreen = 0;
                            int iBlue = 0;

                            if (CtrlStatus.UpDownFlag != "")
                            {
                                if (CtrlStatus.UpDownFlag.Substring(0, 1) == "D")
                                {
                                    iRed = 1;
                                }
                            }

                            if (CtrlStatus.PrimaryStatus == "PROC")
                            {
                                iGreen = 1;
                            }

                            if (CtrlStatus.IsProcessMode == true)
                            {
                                if (CtrlStatus.ProcMode != "")
                                {
                                    if (CtrlStatus.ProcMode.Substring(0, 1) == "S")
                                    {
                                        iBlue = 1;
                                    }
                                    else if (CtrlStatus.ProcMode.Substring(0, 1) == "F")
                                    {
                                        iBlue = 2;
                                    }
                                }
                            }
                            else
                            {
                                if (CtrlStatus.CtrlMode != "")
                                {
                                    if (string.IsNullOrEmpty(CtrlStatus.CtrlMode) == false)
                                    {
                                        if (CtrlStatus.CtrlMode.Substring(0, 2) == "OL")
                                        {
                                            iBlue = 1;
                                        }
                                        else if (CtrlStatus.CtrlMode.Substring(0, 2) == "OR")
                                        {
                                            iBlue = 2;
                                        }
                                    }
                                }
                            }

                            if (CtrlStatus.SignalPosition == '2')
                            {
                                iSignalX = CtrlPos.X;
                                iSignalY = CtrlPos.Y;
                                iSignalWidth = modDefines.CTRL_LIGHT_SIZE;
                                iSignalHeight = CtrlPos.Height - 1;

                                iXSignalSize = modDefines.CTRL_LIGHT_SIZE;
                                iYSignalSize = 0;
                            }
                            else if (CtrlStatus.SignalPosition == '3')
                            {
                                iSignalX = CtrlPos.Right - modDefines.CTRL_LIGHT_SIZE - 1;
                                iSignalY = CtrlPos.Y;
                                iSignalWidth = modDefines.CTRL_LIGHT_SIZE;
                                iSignalHeight = CtrlPos.Height - 1;

                                iXSignalSize = modDefines.CTRL_LIGHT_SIZE * (-1);
                                iYSignalSize = 0;
                            }
                            else if (CtrlStatus.SignalPosition == '4')
                            {
                                iSignalX = CtrlPos.X;
                                iSignalY = CtrlPos.Y;
                                iSignalWidth = CtrlPos.Width - 1;
                                iSignalHeight = modDefines.CTRL_LIGHT_SIZE;

                                iXSignalSize = 0;
                                iYSignalSize = modDefines.CTRL_LIGHT_SIZE;
                            }
                            else if (CtrlStatus.SignalPosition == '5')
                            {
                                iSignalX = CtrlPos.X;
                                iSignalY = CtrlPos.Bottom - modDefines.CTRL_LIGHT_SIZE - 1;
                                iSignalWidth = CtrlPos.Width - 1;
                                iSignalHeight = modDefines.CTRL_LIGHT_SIZE;

                                iXSignalSize = 0;
                                iYSignalSize = modDefines.CTRL_LIGHT_SIZE * (-1);
                            }
                            else
                            {
                                iSignalX = CtrlPos.X;
                                iSignalY = CtrlPos.Y;
                                iSignalWidth = modDefines.CTRL_LIGHT_SIZE;
                                iSignalHeight = CtrlPos.Height - 1;

                                iXSignalSize = modDefines.CTRL_LIGHT_SIZE;
                                iYSignalSize = 0;
                            }

                            g.FillRectangle(Brushes.White, iSignalX, iSignalY, iSignalWidth, iSignalHeight);

                            iXPos = CtrlPos.X;
                            iYPos = CtrlPos.Y;

                            if (CtrlStatus.SignalPosition == '2' || CtrlStatus.SignalPosition == '3')
                            {
                                iSignalHeight = System.Convert.ToInt32((CtrlPos.Height - 1) / 4);
                            }
                            else if (CtrlStatus.SignalPosition == '4' || CtrlStatus.SignalPosition == '5')
                            {
                                iSignalWidth = System.Convert.ToInt32((CtrlPos.Width - 1) / 4);
                            }


                            if (iRed == 1) // Down
                            {
                                g.FillRectangle(Brushes.Red, iSignalX, iSignalY, iSignalWidth, iSignalHeight);
                            }
                            else
                            {
                                g.FillRectangle(Brushes.White, iSignalX, iSignalY, iSignalWidth, iSignalHeight);

                            }

                            iYPos += System.Convert.ToInt32((CtrlPos.Height - 1) / 4);
                            iXPos += System.Convert.ToInt32((CtrlPos.Width - 1) / 4);

                            if (CtrlStatus.SignalPosition == '2' || CtrlStatus.SignalPosition == '3')
                            {
                                iSignalY = iYPos;
                            }
                            else if (CtrlStatus.SignalPosition == '4' || CtrlStatus.SignalPosition == '5')
                            {
                                iSignalX = iXPos;
                            }

                            g.FillRectangle(new SolidBrush(CtrlStatus.SignalColor), iSignalX, iSignalY, iSignalWidth, iSignalHeight);

                            iYPos += System.Convert.ToInt32((CtrlPos.Height - 1) / 4);
                            iXPos += System.Convert.ToInt32((CtrlPos.Width - 1) / 4);

                            if (CtrlStatus.SignalPosition == '2' || CtrlStatus.SignalPosition == '3')
                            {
                                iSignalY = iYPos;
                            }
                            else if (CtrlStatus.SignalPosition == '4' || CtrlStatus.SignalPosition == '5')
                            {
                                iSignalX = iXPos;
                            }
                            else
                            {
                                iSignalY = iYPos;
                            }

                            if (iGreen == 1)
                            {
                                g.FillRectangle(Brushes.Lime, iSignalX, iSignalY, iSignalWidth, iSignalHeight);
                            }
                            else
                            {
                                g.FillRectangle(Brushes.White, iSignalX, iSignalY, iSignalWidth, iSignalHeight);
                            }
                            iYPos += System.Convert.ToInt32((CtrlPos.Height - 1) / 4);
                            iXPos += System.Convert.ToInt32((CtrlPos.Width - 1) / 4);

                            if (CtrlStatus.SignalPosition == '2' || CtrlStatus.SignalPosition == '3')
                            {
                                iSignalY = iYPos;
                                iSignalHeight = System.Convert.ToInt32(CtrlPos.Bottom - iYPos);
                            }
                            else if (CtrlStatus.SignalPosition == '4' || CtrlStatus.SignalPosition == '5')
                            {
                                iSignalX = iXPos;
                                iSignalWidth = System.Convert.ToInt32(CtrlPos.Right - iXPos);
                            }
                            else
                            {
                                iSignalY = iYPos;
                                iSignalHeight = System.Convert.ToInt32(CtrlPos.Bottom - iYPos);
                            }

                            if (iBlue == 1)
                            {
                                g.FillRectangle(Brushes.Cyan, iSignalX, iSignalY, iSignalWidth, iSignalHeight);
                            }
                            else if (iBlue == 2)
                            {
                                g.FillRectangle(Brushes.Blue, iSignalX, iSignalY, iSignalWidth, iSignalHeight);
                            }
                            else
                            {
                                g.FillRectangle(Brushes.White, iSignalX, iSignalY, iSignalWidth, iSignalHeight);
                            }
                            if (CtrlStatus.SignalPosition == '2')
                            {
                                iSignalX = CtrlPos.X;
                                iSignalY = CtrlPos.Y;
                                iSignalWidth = modDefines.CTRL_LIGHT_SIZE;
                                iSignalHeight = CtrlPos.Height - 1;
                            }
                            else if (CtrlStatus.SignalPosition == '3')
                            {
                                iSignalX = CtrlPos.Right - modDefines.CTRL_LIGHT_SIZE - 1;
                                iSignalY = CtrlPos.Y;
                                iSignalWidth = modDefines.CTRL_LIGHT_SIZE;
                                iSignalHeight = CtrlPos.Height - 1;
                            }
                            else if (CtrlStatus.SignalPosition == '4')
                            {
                                iSignalX = CtrlPos.X;
                                iSignalY = CtrlPos.Y;
                                iSignalWidth = CtrlPos.Width - 1;
                                iSignalHeight = modDefines.CTRL_LIGHT_SIZE;
                            }
                            else if (CtrlStatus.SignalPosition == '5')
                            {
                                iSignalX = CtrlPos.X;
                                iSignalY = CtrlPos.Bottom - modDefines.CTRL_LIGHT_SIZE - 1;
                                iSignalWidth = CtrlPos.Width - 1;
                                iSignalHeight = modDefines.CTRL_LIGHT_SIZE;
                            }
                            else
                            {
                                iSignalX = CtrlPos.X;
                                iSignalY = CtrlPos.Y;
                                iSignalWidth = modDefines.CTRL_LIGHT_SIZE;
                                iSignalHeight = CtrlPos.Height - 1;
                            }

                            g.DrawRectangle(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), iSignalX, iSignalY, iSignalWidth, iSignalHeight);
                        }

                    }
                    else
                    {
                        iXSignalSize = 0;
                        iYSignalSize = 0;

                    }
                    StringFormat drawFormat = new StringFormat();
                    if (CtrlStatus.ImageIndex > ListBox.NoMatches && imlResource.Images.Count > CtrlStatus.ImageIndex)
                    {
                        iXPos = System.Convert.ToInt32(CtrlPos.X + iXSignalSize + (CtrlPos.Width - iXSignalSize) / 2 - (imlResource.ImageSize.Width * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)) / 2);
                        iYPos = System.Convert.ToInt32(CtrlPos.Y + iYSignalSize + (CtrlPos.Height - iYSignalSize - CtrlStatus.TextSize) / 2 - (imlResource.ImageSize.Height * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)) / 2 - 1);
                        if (iXPos < iXSignalSize + 2)
                        {
                            iXPos = iXSignalSize + 2;
                        }
                        if (iYPos < iYSignalSize + 2)
                        {
                            iYPos = iYSignalSize + 2;
                        }
                        Rectangle rcImage = new Rectangle(iXPos, iYPos, Convert.ToInt32(imlResource.ImageSize.Width * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)), Convert.ToInt32(imlResource.ImageSize.Height * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)));
                        if (IsPressed == true)
                        {
                            rcImage.Location = new Point(rcImage.Left + 1, rcImage.Top + 1);
                        }
                        g.DrawImage(imlResource.Images[CtrlStatus.ImageIndex], rcImage);
                        drawFormat.LineAlignment = StringAlignment.Far;
                    }
                    else
                    {
                        drawFormat.LineAlignment = StringAlignment.Center;
                    }
                    drawFormat.Alignment = StringAlignment.Center;
                    RectangleF rcText = new RectangleF(System.Convert.ToSingle(CtrlPos.X + iXSignalSize), System.Convert.ToSingle(CtrlPos.Y + iYSignalSize), System.Convert.ToSingle(CtrlPos.Width - iXSignalSize), System.Convert.ToSingle(CtrlPos.Height - iYSignalSize - 1));
                    if (IsPressed == true)
                    {
                        rcText.Location = new PointF(System.Convert.ToSingle(rcText.Left + 1), System.Convert.ToSingle(rcText.Top + 1));
                    }
                    Brush drawBrush;
                    if (this.Enabled == true)
                    {
                        drawBrush = new SolidBrush(CtrlStatus.GetTextColor());
                    }
                    else
                    {
                        drawBrush = new SolidBrush(Color.FromArgb(128, 128, 128));
                    }
                    g.DrawString(CtrlStatus.Text,
                        new Font(CtrlStatus.TextFontName, System.Convert.ToInt32(CtrlStatus.TextSize * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)),
                        ((FontStyle)(Enum.Parse(typeof(FontStyle), Enum.GetValues(typeof(FontStyle)).GetValue(CtrlStatus.TextStyle).ToString())))),
                        drawBrush, rcText, drawFormat);

                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "udcCtrlResource.DrawCtrlResource()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }



            private void DrawCtrlEllipse(Graphics g)
            {

                try
                {
                    g.FillEllipse(new SolidBrush(CtrlStatus.GetBackColor(IsHot, IsPressed)), CtrlPos);
                    g.DrawEllipse(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), CtrlPos.X + 1, CtrlPos.Y + 1, CtrlPos.Width - 2, CtrlPos.Height - 2);

                    if (CtrlStatus.IsViewSignal == true)
                    {
                        //Operation Mode
                        if (CtrlStatus.SignalPosition == '1')
                        {
                            if (CtrlStatus.CtrlMode != "")
                            {
                                if (CtrlStatus.CtrlMode.Substring(0, 2) == "OL")
                                {
                                    g.DrawEllipse(new Pen(Color.Blue, 1), CtrlPos.X + 1, CtrlPos.Y + 1, CtrlPos.Width - 2, CtrlPos.Height - 2);
                                }
                                else if (CtrlStatus.CtrlMode.Substring(0, 2) == "OR")
                                {
                                    g.DrawEllipse(new Pen(Color.Magenta, 1), CtrlPos.X + 1, CtrlPos.Y + 1, CtrlPos.Width - 2, CtrlPos.Height - 2);
                                }
                                else if (CtrlStatus.CtrlMode.Substring(0, 2) == "OF")
                                {
                                    g.DrawEllipse(new Pen(Color.White, 1), CtrlPos.X + 1, CtrlPos.Y + 1, CtrlPos.Width - 2, CtrlPos.Height - 2);
                                }
                            }

                        }
                    }
                    StringFormat drawFormat = new StringFormat();
                    drawFormat.LineAlignment = StringAlignment.Center;
                    drawFormat.Alignment = StringAlignment.Center;
                    RectangleF rcText = new RectangleF(System.Convert.ToSingle(CtrlPos.X), System.Convert.ToSingle(CtrlPos.Y), System.Convert.ToSingle(CtrlPos.Width), System.Convert.ToSingle(CtrlPos.Height));
                    if (IsPressed == true)
                    {
                        rcText.Location = new PointF(System.Convert.ToSingle(rcText.Left + 1), System.Convert.ToSingle(rcText.Top + 1));
                    }

                    Brush drawBrush;
                    if (this.Enabled == true)
                    {
                        drawBrush = new SolidBrush(CtrlStatus.GetTextColor());
                    }
                    else
                    {
                        drawBrush = new SolidBrush(Color.FromArgb(128, 128, 128));
                    }
                    g.DrawString(CtrlStatus.Text, new Font(CtrlStatus.TextFontName, System.Convert.ToInt32(CtrlStatus.TextSize * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)), ((FontStyle)(Enum.Parse(typeof(FontStyle), Enum.GetValues(typeof(FontStyle)).GetValue(CtrlStatus.TextStyle).ToString())))), drawBrush, rcText, drawFormat);

                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "udcCtrlTag.DrawCtrlEllipse()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }
            private void DrawCtrlChamberResource(Graphics g)
            {

                try
                {
                    GraphicsPath path = new GraphicsPath();
                    int i_x, i_y, i_w, i_h;

                    i_x = CtrlPos.X;
                    i_y = CtrlPos.Y;
                    i_w = CtrlPos.Width - 1;
                    i_h = CtrlPos.Height - 1;

                    path.AddLine(i_x, i_y, i_x + i_w / 2, i_y);
                    path.AddLine(i_x + i_w / 2, i_y, i_x + i_w / 2, i_y + i_h / 4);
                    path.AddLine(i_x + i_w / 2, i_y + i_h / 4, i_x + i_w / 4 * 3, i_y + i_h / 4);
                    path.AddLine(i_x + i_w / 4 * 3, i_y + i_h / 4, i_x + i_w, i_y + i_h / 8 * 3);
                    path.AddLine(i_x + i_w, i_y + i_h / 8 * 3, i_x + i_w, i_y + i_h / 8 * 5);

                    path.AddLine(i_x + i_w, i_y + i_h / 8 * 5, i_x + i_w / 4 * 3, i_y + i_h / 4 * 3);
                    path.AddLine(i_x + i_w / 4 * 3, i_y + i_h / 4 * 3, i_x + i_w / 2, i_y + i_h / 4 * 3);
                    path.AddLine(i_x + i_w / 2, i_y + i_h / 4 * 3, i_x + i_w / 2, i_y + i_h);
                    path.AddLine(i_x + i_w / 2, i_y + i_h, i_x, i_y + i_h);
                    path.AddLine(i_x, i_y + i_h, i_x, i_y);

                    g.FillPath(new SolidBrush(CtrlStatus.GetBackColor(IsHot, IsPressed)), path);
                    g.DrawPath(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), path);

                    StringFormat drawFormat = new StringFormat();
                    drawFormat.LineAlignment = StringAlignment.Center;
                    drawFormat.Alignment = StringAlignment.Center;
                    RectangleF rcText = new RectangleF(System.Convert.ToSingle(CtrlPos.X), System.Convert.ToSingle(CtrlPos.Y), System.Convert.ToSingle(CtrlPos.Width), System.Convert.ToSingle(CtrlPos.Height));
                    if (IsPressed == true)
                    {
                        rcText.Location = new PointF(System.Convert.ToSingle(rcText.Left + 1), System.Convert.ToSingle(rcText.Top + 1));
                    }

                    Brush drawBrush;
                    if (this.Enabled == true)
                    {
                        drawBrush = new SolidBrush(CtrlStatus.GetTextColor());
                    }
                    else
                    {
                        drawBrush = new SolidBrush(Color.FromArgb(128, 128, 128));
                    }
                    g.DrawString(CtrlStatus.Text, new Font(CtrlStatus.TextFontName, System.Convert.ToInt32(CtrlStatus.TextSize * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)), ((FontStyle)(Enum.Parse(typeof(FontStyle), Enum.GetValues(typeof(FontStyle)).GetValue(CtrlStatus.TextStyle).ToString())))), drawBrush, rcText, drawFormat);


                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "udcCtrlResource.DrawCtrlChamberResource()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }

            private void AddStocker(GraphicsPath path, Rectangle rc)
            {

                try
                {
                    int i_x, i_y, i_w, i_h;

                    i_x = rc.X - 1;
                    i_y = rc.Y - 1;
                    i_w = rc.Width + 1;
                    i_h = rc.Height + 1;

                    path.AddLine(i_x, i_y + RC_SIZE, i_x + RC_SIZE, i_y);
                    path.AddLine(i_x + RC_SIZE, i_y, i_x + i_w, i_y);
                    path.AddLine(i_x + i_w, i_y, i_x + i_w, i_y + i_h - RC_SIZE);
                    path.AddLine(i_x + i_w, i_y + i_h - RC_SIZE, i_x + i_w - RC_SIZE, i_y + i_h);
                    path.AddLine(i_x + i_w - RC_SIZE, i_y + i_h, i_x, i_y + i_h);
                    path.AddLine(i_x, i_y + i_h, i_x, i_y + RC_SIZE);

                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "udcCtrlResource.DrawCtrlChamberResource()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }

            private void DrawCtrlStockerResource(Graphics g)
            {

                try
                {
                    GraphicsPath path = new GraphicsPath();
                    Rectangle rcpb = new Rectangle();
                    Rectangle rc_out = new Rectangle();

                    LinearGradientBrush gbr;
                    int i_x, i_y, i_w, i_h;

                    i_x = CtrlPos.X;
                    i_y = CtrlPos.Y;
                    i_w = CtrlPos.Width - 1;
                    i_h = CtrlPos.Height - 1;

                    path.AddLine(i_x, i_y + RC_SIZE, i_x + RC_SIZE, i_y);
                    path.AddLine(i_x + RC_SIZE, i_y, i_x + i_w, i_y);
                    path.AddLine(i_x + i_w, i_y, i_x + i_w - RC_SIZE, i_y + RC_SIZE);
                    path.AddLine(i_x + i_w - RC_SIZE, i_y + RC_SIZE, i_x, i_y + RC_SIZE);

                    rcpb.X = i_x;
                    rcpb.Y = i_y + RC_SIZE;
                    rcpb.Width = i_w - RC_SIZE;
                    rcpb.Height = i_h - RC_SIZE;

                    GraphicsPath rcpath = new GraphicsPath();
                    rcpath.AddRectangle(rcpb);

                    GraphicsPath rgpath = new GraphicsPath();
                    rgpath.AddLine(i_x + i_w - RC_SIZE, i_y + RC_SIZE, i_x + i_w, i_y);
                    rgpath.AddLine(i_x + i_w, i_y, i_x + i_w, i_y + i_h - RC_SIZE);
                    rgpath.AddLine(i_x + i_w, i_y + i_h - RC_SIZE, i_x + i_w - RC_SIZE, i_y + i_h);
                    rgpath.AddLine(i_x + i_w - RC_SIZE, i_y + i_h, i_x + i_w - RC_SIZE, i_y + RC_SIZE);

                    g.FillPath(new SolidBrush(CtrlStatus.GetBackColor(IsHot, IsPressed)), path);
                    g.FillPath(new SolidBrush(CtrlStatus.GetBackColor(IsHot, IsPressed)), rcpath);
                    g.FillPath(new SolidBrush(CtrlStatus.GetBackColor(IsHot, IsPressed)), rgpath);
                    g.DrawPath(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), path);
                    g.DrawPath(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), rcpath);
                    g.DrawPath(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), rgpath);

                    if (CtrlStatus.IsViewSignal == true)
                    {
                        //Operation Mode
                        if (CtrlStatus.SignalPosition == '1')
                        {
                            if (CtrlStatus.CtrlMode != "")
                            {
                                Pen p;
                                if (CtrlStatus.CtrlMode.Substring(0, 2) == "OL")
                                {
                                    p = new Pen(Color.Blue, 1);
                                }
                                else if (CtrlStatus.CtrlMode.Substring(0, 2) == "OR")
                                {
                                    p = new Pen(Color.Magenta, 1);
                                }
                                else if (CtrlStatus.CtrlMode.Substring(0, 2) == "OF")
                                {
                                    p = new Pen(Color.White, 1);
                                }
                                else
                                {
                                    p = new Pen(CtrlStatus.GetBorderColor(IsHot), 1);
                                }
                                g.DrawPath(p, path);
                                g.DrawPath(p, rcpath);
                                g.DrawPath(p, rgpath);
                            }

                        }

                    }


                    if (CtrlStatus.WIPRate > 0)
                    {
                        rc_out.X = rcpb.X + OUT_LINE;
                        rc_out.Y = rcpb.Y + OUT_LINE;
                        rc_out.Width = rcpb.Width - OUT_LINE * 2;
                        rc_out.Height = rcpb.Height - OUT_LINE * 2;

                        GraphicsPath pbpath = new GraphicsPath();
                        pbpath.AddRectangle(rc_out);

                        if (CtrlPos.Width < CtrlPos.Height)
                        {
                            gbr = new LinearGradientBrush(rc_out, Color.Red, Color.Yellow, LinearGradientMode.Vertical);
                        }
                        else
                        {
                            gbr = new LinearGradientBrush(rc_out, Color.Yellow, Color.Red, LinearGradientMode.Horizontal);
                        }

                        Blend blend1 = new Blend(9);
                        blend1.Factors = new float[] { 0.0F, 0.1F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 1.0F };

                        blend1.Positions = new float[] { 0.0F, 0.1F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 1.0F };

                        gbr.Blend = blend1;


                        g.FillPath(gbr, pbpath);
                        g.DrawPath(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), pbpath);
                        if (CtrlPos.Width < CtrlPos.Height)
                        {
                            g.FillRectangle(new SolidBrush(Color.White), rc_out.X + 1, rc_out.Y + 1, rc_out.Width - 1, (float)(rc_out.Height * (1 - CtrlStatus.WIPRate)));
                        }
                        else
                        {
                            g.FillRectangle(new SolidBrush(Color.White), (float)(rc_out.X + (rc_out.Width * CtrlStatus.WIPRate)), rc_out.Y + 1, (float)(rc_out.Width * (1 - CtrlStatus.WIPRate)), rc_out.Height - 1);
                        }
                    }

                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "udcCtrlResource.DrawCtrlChamberResource()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }

        }

    }


}
