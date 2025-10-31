
using System.Diagnostics;
using System;
using System.Windows.Forms;
using System.Collections;
using System.Drawing;

using Miracom.MsgHandler;
using System.Data;
using Miracom.MESCore;
using Miracom.CliFrx;
using Miracom.TRSCore;
using System.Collections.Generic;

namespace Miracom.RASCore
{
    public sealed class modGlobalVariables
    {
        public static Color DEFECT1_COLOR = Color.Red;
        public static Color DEFECT2_COLOR = Color.Blue;

        internal const char FLAG_INCREASE = '+';
        internal const char FLAG_DECREASE = '-';
        internal const char FLAG_MULTIPLY = '*';
        internal const char FLAG_DIVISION = '/';
        internal const char FLAG_MOD = 'M';
        internal const char FLAG_POW = 'P';
        internal const char FLAG_TIME = 'T';
        internal const char FLAG_RESET = 'R';
        internal const char FLAG_CHANGE = 'Y';
        internal const char FLAG_NOT_CHANGE = 'N';

        public static List<CarrierEventItem> DefaultCarrierItems = new List<CarrierEventItem>()
        {
            new CarrierEventItem("CRR_STATUS", "Carrier Status", TRSDataType.String, 10),
            new CarrierEventItem("LOCATION_1", "Location 1", TRSDataType.String, 20),
            new CarrierEventItem("LOCATION_2", "Location 2", TRSDataType.String, 20),
            new CarrierEventItem("LOCATION_3", "Location 3", TRSDataType.String, 20),
            new CarrierEventItem("LOCATION_4", "Location 4", TRSDataType.String, 20),
            new CarrierEventItem("LOCATION_5", "Location 5", TRSDataType.String, 20),
            new CarrierEventItem("RES_ID", "Resource ID", TRSDataType.String, 20),
            new CarrierEventItem("SUBRES_ID", "Sub Resource ID", TRSDataType.String, 20),
            new CarrierEventItem("PORT_ID", "Port ID", TRSDataType.String, 10),
            new CarrierEventItem("LOT_ID", "Lot ID", TRSDataType.String, 25),
            new CarrierEventItem("QTY_1", "Qty 1", TRSDataType.Double, 12),
            new CarrierEventItem("QTY_2", "Qty 2", TRSDataType.Double, 12),
            new CarrierEventItem("QTY_3", "Qty 3", TRSDataType.Double, 12),
            new CarrierEventItem("USAGE_COUNT", "Usage Count", TRSDataType.Int, 6),
            new CarrierEventItem("CLEAN_COUNT", "Clean Count", TRSDataType.Int, 6),
            new CarrierEventItem("REUSE_COUNT", "Reuse Count", TRSDataType.Int, 6),
            new CarrierEventItem("NEED_CLEAN_FLAG", "Need Clean Flag", TRSDataType.Char, 1),
            new CarrierEventItem("STOCK_IN_TIME", "Stock In Time", TRSDataType.String, 14, true)
        };
    }

    public class CarrierEventItem
    {
        private string itemName;
        public string ItemName
        {
            get { return this.itemName; }
        }
        private string itemLabel;
        public string ItemLabel
        {
            get { return this.itemLabel; }
        }
        private TRSDataType itemType;
        public TRSDataType ItemType
        {
            get { return this.itemType; }
        }
        private int itemSize;
        public int ItemSize
        {
            get { return this.itemSize; }
        }
        private bool isDateTime;
        public bool IsDateTime
        {
            get { return this.isDateTime; }
        }

        public CarrierEventItem(string name, string label, TRSDataType type, int size, bool isDateTime = false)
        {
            this.itemName = name;
            this.itemLabel = label;
            this.itemType = type;
            this.itemSize = size;
            this.isDateTime = isDateTime;
        }

        public override string ToString()
        {
            return this.ItemName;
        }

        public bool Equals(string name)
        {
            return this.ItemName.Equals(name);
        }
    }
    
    
}
