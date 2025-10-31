
using System;
using System.Data;
using System.Drawing;
using System.Collections;
using System.Diagnostics;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;

namespace MESClient
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

#if _H101
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
#endif
    }
}
