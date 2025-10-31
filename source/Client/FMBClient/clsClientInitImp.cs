
using System.Diagnostics;
using System;
using System.Collections;
using System.Drawing;

using System.Data;
using Miracom.FMBCore;
using Miracom.MsgHandler;
using Miracom.CliFrx;
using Miracom.TRSCore;

namespace FMBClient
{
    public class clsInitialFunctionImp : clsMESPlusInitialFunction
    {

        //Add by CM Koo. 2005.08.25
        //Site Caster Prologue/Epilogue를 처리하기 위한 Abstract Function
        public override void CustCasterPrologue(TRSNode in_node)
        {

        }


        public override void CustCasterEpilogue(TRSNode in_node, TRSNode out_node)
        {

        }

        //Add by CM Koo. 2005.08.25
        //Site Tuner Prologue/Epilogue를 처리하기 위한 Abstract Function
        public override void CustTunerPrologue(TRSNode in_node)
        {

        }

        public override void CustTunerEpilogue(TRSNode in_node, TRSNode out_node)
        {

        }

        //Add by IC.Bae 2017.03.15 Only H101
        //Site H101 OnConnect, OnDisconnect를 처리하기 위한 Abstract Function
        public override void CustOnConnect()
        {
            //Console.WriteLine("Connected!!!!!!");
        }

        public override void CustOnDisconnect()
        {
            //Console.WriteLine("Disconnected!!!!!!");
        }

        public override bool LoadResource()
        {
            if (MPCF.LoadMessageResource("FMBMessage.xml") == false)
            {
                return false;
            }
            if (MPCF.LoadCaptionResource("FMBCaption.xml") == false)
            {
                return false;
            }
            if (GetClientOptions() == false)
            {
                return false;
            }

            return true;
        }
        
    }
    
}
