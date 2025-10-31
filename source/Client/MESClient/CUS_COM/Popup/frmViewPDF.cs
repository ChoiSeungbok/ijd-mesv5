using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Miracom.TRSCore;
using Miracom.MESCore;
using CUS_COM;
using System.IO;
using DevExpress.Utils.CommonDialogs;
using AxAcroPDFLib;

namespace CUS_COM
{
    public partial class frmViewPDF : BaseForm01
    {
        public frmViewPDF()
        {
            InitializeComponent();

        }

        private void frmViewPDF_Load(object sender, EventArgs e)
        {


            try
            {

                axAcroPDF1.src = "C:\\Users\\IJMAIL\\Desktop\\AAA.PDF";
               // axAcroPDF1.setView
                    /*
                string fullPath = "";
                FileInfo finfo;
                long lengthKByte;

                openFileDialog1.Reset();
                openFileDialog1.Filter = "Images Files(*.jpg; *.jpeg; *.bmp; *.png)|*.jpg;*.jpeg;*.bmp;*.png";
                openFileDialog1.DefaultExt = "jpg";

                if (openFileDialog1.ShowDialog() == DialogResult.OK)
                {

                    fullPath = openFileDialog1.FileName;
                    //pictureBox1.Image = Image.FromFile(openFileDialog1.FileName);

                    finfo = new FileInfo(fullPath);

                    lengthKByte = finfo.Length / 1024;
                    if (lengthKByte >= 2048)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(504));
                        return;
                    }

                    axAcroPDF1.src = openFileDialog1.

                    //파일 리스트 조회
                    //  ViewInspectionFile(txtInspID.Text);

                    //  spdFileRegistration.ActiveSheet.ActiveRowIndex = iActiveRow;
                    //  fnFileSelectionChagned();
        

                }
                        */



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        private void frmViewPDF_Shown(object sender, EventArgs e)
        {
          
        }
    }   
}
