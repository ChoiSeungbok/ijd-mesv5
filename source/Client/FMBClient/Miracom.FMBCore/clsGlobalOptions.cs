
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Miracom.CliFrx;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : clsGlobalOptions.vb
//   Description : Global Options Class
//
//   FMB Version : 1.0.0
//
//   Function List
//
//   Detail Description
//       -
//
//   History
//       - 2005-03-22 : Created by Laverwon
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public class clsGlobalOptions : ArrayList
    {
        
        
        public clsGlobalOptions()
        {
            
        }
        
        public bool AddOption(string factory, clsOptionData.Options opt, object data)
        {
            
            try
            {
                int i;
                for (i = 0; i <= this.Count - 1; i++)
                {
                    if (((clsOptionData) this[i]).GetOptionData(clsOptionData.Options.Factory, "","").ToString() == factory)
                    {
                        ((clsOptionData) this[i]).SetOptionData(data, opt);
                        return true;
                    }
                }
                clsOptionData OptionData = new clsOptionData(factory);
                OptionData.SetOptionData(data, opt);
                this.Add(OptionData);
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsGlobalOptions.AddOptions()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        public bool AddOption(string factory, string sType, string sEventID, Color clEventColor)
        {
            
            try
            {
                clsEventColor objEvent = new clsEventColor(sType, sEventID, clEventColor);
                
                int i;
                for (i = 0; i <= this.Count - 1; i++)
                {
                    if (((clsOptionData) this[i]).GetOptionData(clsOptionData.Options.Factory, "","").ToString() == factory)
                    {
                        ((clsOptionData)this[i]).SetOptionData(objEvent, clsOptionData.Options.EventColor);
                        return true;
                    }
                }
                clsOptionData OptionData = new clsOptionData(factory);
                OptionData.SetOptionData(objEvent, clsOptionData.Options.EventColor);
                this.Add(OptionData);
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsGlobalOptions.AddOptions()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        public bool AddOptions(clsOptionData options)
        {
            
            try
            {
                int i;
                for (i = 0; i <= this.Count - 1; i++)
                {
                    if (((clsOptionData)this[i]).GetOptionData(clsOptionData.Options.Factory, "", "").ToString() == options.GetOptionData(clsOptionData.Options.Factory,"", "").ToString())
                    {
                        this.RemoveAt(i);
                        break;
                    }
                }
                this.Add(options);
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsGlobalOptions.AddOptions()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        public object GetOptions(string factory, clsOptionData.Options opt)
        {
            
            try
            {
                clsOptionData OptionData = GetItem(factory);
                if (OptionData != null)
                {
                    object Options = OptionData.GetOptionData(opt,"", "");
                    if (Options != null)
                    {
                        return Options;
                    }
                }
                
                return GetItem("SYSTEM").GetOptionData(opt,"", "");
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsGlobalOptions.GetOptions()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        public Color GetOptions(string factory, string sType, string sEventID)
        {
            
            try
            {
                clsOptionData OptionData = GetItem(factory);
                if (OptionData != null)
                {
                    object OOptions = OptionData.GetOptionData(clsOptionData.Options.EventColor, sType, sEventID);
                    if (OOptions != null)
                    {
                        clsEventColor Options = (clsEventColor)OOptions;
                        return ((Color)Options.GetEventColor());
                    }
                    else
                    {
                        return Color.Empty;
                    }

                    //clsEventColor Options = (clsEventColor)OptionData.GetOptionData(clsOptionData.Options.EventColor, sEventID);
                    //if (Options != null)
                    //{
                    //    return ((Color)Options.GetEventColor());
                    //}
                }
                if ((GetItem("SYSTEM").GetOptionData(clsOptionData.Options.EventColor, sType, sEventID)) != null)
                    return (Color)(GetItem("SYSTEM").GetOptionData(clsOptionData.Options.EventColor, sType, sEventID));
                else
                    return Color.Empty;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsGlobalOptions.GetOptions()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return Color.Empty;
            }
            
        }
        
        public clsOptionData GetItem(string factory)
        {
            
            try
            {
                int i;
                for (i = 0; i <= this.Count - 1; i++)
                {
                    if (((clsOptionData)this[i]).GetOptionData(clsOptionData.Options.Factory,"", "").ToString() == factory)
                    {
                        return ((clsOptionData)this[i]);
//                        break;
                    }
                }
                
                return null;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsGlobalOptions.GetItem()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return null;
            }
            
        }
        
        public bool RemoveOptions(string factory)
        {
            
            try
            {
                int i;
                for (i = 0; i <= this.Count - 1; i++)
                {
                    if (((clsOptionData)this[i]).GetOptionData(clsOptionData.Options.Factory, "","").ToString() == factory)
                    {
                        this.RemoveAt(i);
                        return true;
                    }
                }
                
                return false;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsGlobalOptions.GetOptions()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
    }
    
    public class clsOptionData : object
    {
        
        
        public clsOptionData(string _factory)
        {
            
            Factory = _factory;
            
        }
        
        public enum Options
        {
            Factory = 0,
            DefaultLayoutSize = 1,
            DefaultUDRSize = 2,
            DefaultResourceSize = 3,
            DefaultSubResourceSize = 4,
            DefaultPortSize = 5,
            DefaultToolSize = 6,
            DefaultRectangleSize = 7,
            DefaultEllipseSize = 8,
            DefaultTriangleSize = 9,
            DefaultVerticalLineSize = 10,
            DefaultHorizontalLineSize = 11,
            DefaultPie1Size = 12,
            DefaultPie2Size = 13,
            DefaultPie3Size = 14,
            DefaultPie4Size = 15,
            DefaultFontName = 16,
            UseEventColor = 17,
            EventColor = 18,
            IsProcessMode = 19,
            DefaultTextColor = 20,
            DefaultTextSize = 21,
            DefaultBackColor = 22,
            BackColorOpt = 23
        }
        
        private string Factory = null;
        private Size DefaultLayoutSize = Size.Empty;
        private Size DefaultUDRSize = Size.Empty;
        private Size DefaultResourceSize = Size.Empty;
        private Size DefaultSubResourceSize = Size.Empty;
        private Size DefaultPortSize = Size.Empty;
        private Size DefaultToolSize = Size.Empty;
        private Size DefaultRectangleSize = Size.Empty;
        private Size DefaultEllipseSize = Size.Empty;
        private Size DefaultTriangleSize = Size.Empty;
        private Size DefaultVerticalLineSize = Size.Empty;
        private Size DefaultHorizontalLineSize = Size.Empty;
        private Size DefaultPie1Size = Size.Empty;
        private Size DefaultPie2Size = Size.Empty;
        private Size DefaultPie3Size = Size.Empty;
        private Size DefaultPie4Size = Size.Empty;
        private string DefaultFontName = null;
        private string UseEventColor = null;
        private string IsProcessMode = null;
        private Color DefaultTextColor = Color.Empty;
        private int DefaultTextSize = 0;
        private Color DefaultBackColor = Color.Empty;
        private string BackColorOpt = null;
        
        private ArrayList EventColorList = new ArrayList();
        
        public void SetOptionData(object data, Options opt)
        {
            
            try
            {
                switch (opt)
                {
                    case Options.Factory:
                        
                        Factory = System.Convert.ToString(data);
                        break;
                    case Options.DefaultLayoutSize:
                        
                        DefaultLayoutSize = (Size) data;
                        break;
                    case Options.DefaultUDRSize:
                        
                        DefaultUDRSize = (Size) data;
                        break;
                    case Options.DefaultResourceSize:
                        
                        DefaultResourceSize = (Size) data;
                        break;
                    case Options.DefaultSubResourceSize:

                        DefaultSubResourceSize = (Size)data;
                        break;
                    case Options.DefaultPortSize:

                        DefaultPortSize = (Size)data;
                        break;
                    case Options.DefaultToolSize:

                        DefaultToolSize = (Size)data;
                        break;
                    case Options.DefaultRectangleSize:
                        
                        DefaultRectangleSize = (Size) data;
                        break;
                    case Options.DefaultEllipseSize:
                        
                        DefaultEllipseSize = (Size) data;
                        break;
                    case Options.DefaultTriangleSize:
                        
                        DefaultTriangleSize = (Size) data;
                        break;
                    case Options.DefaultVerticalLineSize:
                        
                        DefaultVerticalLineSize = (Size) data;
                        break;
                    case Options.DefaultHorizontalLineSize:
                        
                        DefaultHorizontalLineSize = (Size) data;
                        break;
                    case Options.DefaultPie1Size:
                        
                        DefaultPie1Size = (Size) data;
                        break;
                    case Options.DefaultPie2Size:
                        
                        DefaultPie2Size = (Size) data;
                        break;
                    case Options.DefaultPie3Size:
                        
                        DefaultPie3Size = (Size) data;
                        break;
                    case Options.DefaultPie4Size:
                        
                        DefaultPie4Size = (Size) data;
                        break;
                    case Options.DefaultFontName:
                        
                        DefaultFontName = System.Convert.ToString(data);
                        break;
                    case Options.UseEventColor:
                        
                        UseEventColor = System.Convert.ToString(data);
                        break;
                    case Options.EventColor:
                        
                        int i;
                        for (i = 0; i <= EventColorList.Count - 1; i++)
                        {
                            if (((clsEventColor)EventColorList[i]).GetResType() == ((clsEventColor)data).GetResType() && 
                                ((clsEventColor) EventColorList[i]).GetEventID() == ((clsEventColor) data).GetEventID())
                            {
                                ((clsEventColor)EventColorList[i]).SetEventColor(((clsEventColor)data).GetResType().ToString(), ((clsEventColor)data).GetEventID().ToString(), (Color)(((clsEventColor)data).GetEventColor()));
                                goto endOfSelect;
                            }
                        }
                        EventColorList.Add(data);
                        break;
                    case Options.IsProcessMode:
                        
                        IsProcessMode = System.Convert.ToString(data);
                        break;
                    case Options.DefaultTextColor:
                        
                        DefaultTextColor = (Color) data;
                        break;
                    case Options.DefaultTextSize:

                        DefaultTextSize = MPCF.ToInt(data);
                        break;
                    case Options.DefaultBackColor:
                        
                        DefaultBackColor = (Color) data;
                        break;

                    case Options.BackColorOpt:

                        BackColorOpt = System.Convert.ToString(data);
                        break;
                }
endOfSelect:
                1.GetHashCode() ; //nop
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsOptionData.SetOptionData()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        public object GetOptionData(Options opt, string sType, string sEventID)
        {
            
            try
            {
                switch (opt)
                {
                    case Options.Factory:
                        
                        return Factory;
                    case Options.DefaultLayoutSize:

                        return DefaultLayoutSize;
                    case Options.DefaultUDRSize:

                        return DefaultUDRSize;
                    case Options.DefaultResourceSize:

                        return DefaultResourceSize;
                    case Options.DefaultSubResourceSize:

                        return DefaultSubResourceSize;
                    case Options.DefaultPortSize:

                        return DefaultPortSize;
                    case Options.DefaultToolSize:

                        return DefaultToolSize;
                    case Options.DefaultRectangleSize:

                        return DefaultRectangleSize;
                    case Options.DefaultEllipseSize:

                        return DefaultEllipseSize;
                    case Options.DefaultTriangleSize:

                        return DefaultTriangleSize;
                    case Options.DefaultVerticalLineSize:

                        return DefaultVerticalLineSize;
                    case Options.DefaultHorizontalLineSize:

                        return DefaultHorizontalLineSize;
                    case Options.DefaultPie1Size:

                        return DefaultPie1Size;
                    case Options.DefaultPie2Size:

                        return DefaultPie2Size;
                    case Options.DefaultPie3Size:

                        return DefaultPie3Size;
                    case Options.DefaultPie4Size:

                        return DefaultPie4Size;
                    case Options.DefaultFontName:

                        return DefaultFontName;
                    case Options.UseEventColor:

                        return UseEventColor;
                    case Options.EventColor:

                        int i;
                        for (i = 0; i <= EventColorList.Count - 1; i++)
                        {
                            if (System.Convert.ToString(((clsEventColor)EventColorList[i]).GetResType()) == sType &&
                                System.Convert.ToString(((clsEventColor)EventColorList[i]).GetEventID()) == sEventID)
                            {
                                return ((clsEventColor)EventColorList[i]);
                            }
                        }
                        break;
                    case Options.IsProcessMode:

                        return IsProcessMode;
                    case Options.DefaultTextColor:

                        return DefaultTextColor;
                    case Options.DefaultTextSize:

                        return DefaultTextSize;
                    case Options.DefaultBackColor:

                        return DefaultBackColor;

                    case Options.BackColorOpt:

                        return BackColorOpt;
                  }

                  return null;
                        
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("clsOptionData.GetOptionData()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return null;
            }
                
        }
            
    }
    
    public class clsEventColor : object
    {
        public clsEventColor(string sType, string sEventID, Color clEventColor)
        {

            SetEventColor(sType, sEventID, clEventColor);
        }

        private string ResType;
        private string EventID;
        private Color EventColor;

        public void SetEventColor(string sType, string sEventID, Color clEventColor)
        {
            ResType = sType;
            EventID = sEventID;
            EventColor = clEventColor;
            
        }

        public object GetResType()
        {

            return ResType;

        }

        public object GetEventID()
        {
            
            return EventID;
            
        }
        
        public object GetEventColor()
        {
            
            return EventColor;
            
        }
        
    }
    
}
