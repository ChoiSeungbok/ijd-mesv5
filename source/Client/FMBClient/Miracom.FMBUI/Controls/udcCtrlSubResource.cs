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
        
        public class udcCtrlSubResource: FMBUI.Controls.udcCtrlBase
        {
            
            
            #region " Windows Form Auto Generated Code "
            
            public udcCtrlSubResource()
            {
                
                //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
                InitializeComponent();
                
                //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
                
            }

            public udcCtrlSubResource(ImageList imlRes)
            {
                
                //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
                InitializeComponent();
                int i;
                for (i = 0; i <=  imlRes.Images.Count - 1; i++)
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

            private IContainer components;

            //Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            
            //李멸퀬: ?ㅼ쓬 ?꾨줈?쒖???Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            //Windows Form ?붿옄?대꼫瑜??ъ슜?섏뿬 ?섏젙?????덉뒿?덈떎.
            //肄붾뱶 ?몄쭛湲곕? ?ъ슜?섏뿬 ?섏젙?섏? 留덉떗?쒖삤.
            public System.Windows.Forms.ImageList imlResource;
            [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
            {
                this.components = new System.ComponentModel.Container();
                System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(udcCtrlResource));
                this.imlResource = new System.Windows.Forms.ImageList(this.components);
                ((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
                this.SuspendLayout();
                // 
                // imlResource
                // 
                this.imlResource.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imlResource.ImageStream")));
                this.imlResource.TransparentColor = System.Drawing.Color.Transparent;
                this.imlResource.Images.SetKeyName(0, "");
                this.imlResource.Images.SetKeyName(1, "");
                this.imlResource.Images.SetKeyName(2, "");
                this.imlResource.Images.SetKeyName(3, "");
                this.imlResource.Images.SetKeyName(4, "");
                this.imlResource.Images.SetKeyName(5, "");
                this.imlResource.Images.SetKeyName(6, "");
                this.imlResource.Images.SetKeyName(7, "");
                this.imlResource.Images.SetKeyName(8, "");
                this.imlResource.Images.SetKeyName(9, "");
                this.imlResource.Images.SetKeyName(10, "");
                this.imlResource.Images.SetKeyName(11, "");
                this.imlResource.Images.SetKeyName(12, "");
                this.imlResource.Images.SetKeyName(13, "");
                this.imlResource.Images.SetKeyName(14, "");
                this.imlResource.Images.SetKeyName(15, "");
                this.imlResource.Images.SetKeyName(16, "");
                this.imlResource.Images.SetKeyName(17, "");
                this.imlResource.Images.SetKeyName(18, "");
                this.imlResource.Images.SetKeyName(19, "");
                this.imlResource.Images.SetKeyName(20, "");
                // 
                // udcCtrlSubResource
                // 
                this.Name = "udcCtrlSubResource";
                ((System.ComponentModel.ISupportInitialize)(this)).EndInit();
                this.ResumeLayout(false);

            }
            
            #endregion
            
            protected override void DrawControl(Graphics g)
            {
                
                try
                {
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
                    
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "udcCtrlSubResource.DrawControl()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                
            }
            
            private void DrawCtrlResource(Graphics g)
            {

                try
                {
                    g.FillRectangle(new SolidBrush(CtrlStatus.GetBackColor(IsHot, IsPressed)), CtrlPos.X, CtrlPos.Y, CtrlPos.Width - 1, CtrlPos.Height - 1);
                    g.DrawRectangle(new Pen(CtrlStatus.GetBorderColor(IsHot), 1), CtrlPos.X, CtrlPos.Y, CtrlPos.Width - 1, CtrlPos.Height - 1);

                    int iSignalSize = 0;
                    int iXPos = 0;
                    int iYPos = 0;

                    StringFormat drawFormat = new StringFormat();
                    if (CtrlStatus.ImageIndex > ListBox.NoMatches && imlResource.Images.Count > CtrlStatus.ImageIndex)
                    {
                        iXPos = System.Convert.ToInt32(CtrlPos.X + iSignalSize + (CtrlPos.Width - iSignalSize) / 2 - (imlResource.ImageSize.Width * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)) / 2);
                        iYPos = System.Convert.ToInt32(CtrlPos.Y + (CtrlPos.Height - CtrlStatus.TextSize) / 2 - (imlResource.ImageSize.Height * modCommonFunctions.GetScale(this.CtrlStatus.ZoomScale)) / 2 - 1);
                        if (iXPos < iSignalSize + 2)
                        {
                            iXPos = iSignalSize + 2;
                        }
                        if (iYPos < 2)
                        {
                            iYPos = 2;
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
                    RectangleF rcText = new RectangleF(System.Convert.ToSingle(CtrlPos.X + iSignalSize), System.Convert.ToSingle(CtrlPos.Y), System.Convert.ToSingle(CtrlPos.Width - iSignalSize), System.Convert.ToSingle(CtrlPos.Height - 1));
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
            
        }
        
    }
            
        
}
