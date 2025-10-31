
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;

using Miracom.CliFrx;

namespace Miracom.FMBCore
{
    public interface intFMBMdiFormFunction : intMdiFormFunction
    {
        
        bool RefreshUdrGroupList();
        bool RefreshFileList();
        bool RefreshDesignList(string sStep, string sFactory, string sLayout, string sResource, string sMoveLayout);
        bool RefreshDesignList(string sStep, string sFactory, string sLayout, string sResource, string sParent, string sMoveLayout);
        void CreateResourceEvent(string sFactory, string sResource, string sUpDownflag);
        void DeleteResourceEvent(string sFactory, string sResource);
        void ArrageLayouts(ArrayList sLayouts, int iLayoutCount);
        void CreateToolEvent(string sFactory, string sTool);
        void DeleteToolEvent(string sFactory, string sTool);
        void CreatePortEvent(string sFactory, string sPort);
        void DeletePortEvent(string sFactory, string sPort);
        void CreateSubResourceEvent(string sFactory, string sResource, string sSubResource, string sUpDownflag);
        void DeleteSubResourceEvent(string sFactory, string sResource, string sSubResource);

        ToolStrip GetToolBar();
        
    }
    
    public sealed class FMBFI
    {
        
        public static intFMBMdiFormFunction gIMdiForm;
        
    }
}
