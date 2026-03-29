using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using APS168_W64;
using APS_Define_W32;
namespace basic_sample
{
    public partial class SDO : Form
    {
        public Int32 v_board_id = -1;
        Int32 Bus_No = 0;
        public SDO()
        {
            InitializeComponent();          
        }

        private void SDO_Load(object sender, EventArgs e)
        {
            tBBoardID_W.Text = v_board_id.ToString();
            tBBoardID_R.Text = v_board_id.ToString();
            tBBusNo_W.Text = "0";
            tBBusNo_R.Text = "0";
            tBSlaveID_R.Text = "0";
            tBSlaveID_W.Text = "0";
            tBTimeOut_R.Text = "8000";
            tBTimeOut_W.Text = "8000";
            tBFlags_R.Text = "0";
            tBFlags_W.Text = "0";
            tBODIndex_W.Text = "60fe";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Int32 ret = 0 ,i = 0;
            UInt32 OutDataLength = 0;          
            Byte[] Data = new Byte[32];            
            String str = null,tempstr = null;
            Int32 dou = 0;
            Int32 Mod_ID = Int32.Parse(tBSlaveID_R.Text);            
            UInt16 OD_index = Convert.ToUInt16(tBODIndex_R.Text,16);
            UInt16 OD_Subindex = UInt16.Parse(tBSubIndex_R.Text);        
            UInt32 DataLength = UInt32.Parse(tBDataLength_R.Text);
            UInt32 TimeOut = UInt32.Parse(tBTimeOut_R.Text);
            UInt32 Flags = UInt32.Parse(tBFlags_R.Text);
            Boolean stringflag = false;

            ret = APS168.APS_get_field_bus_sdo(v_board_id, Bus_No, Mod_ID, OD_index, OD_Subindex, Data, DataLength, ref OutDataLength, TimeOut, Flags);
            
            if(ret !=0)
            {
                MessageBox.Show("Error code:  " + ret.ToString());
            }
            else
            {                
                tBOutDataLen_R.Text = Convert.ToString(OutDataLength, 10);
                
                for (i = 1; i <= 32;i++ )
                {
                    tempstr = Convert.ToString(Data[32 - i], 16);                 
                    tempstr = tempstr.PadLeft(2, '0');
                    str += tempstr;
                    if (((i-1) >= 8) && (Data[i-1] != 0))
                        stringflag = true;
                }
                str = "0x" + str;
                if (stringflag)
                {
                    tBData_R.Text = str;
                }
                else
                {
                    dou = Convert.ToInt32(str, 16);
                    tBData_R.Text = Convert.ToString(dou);
                }
                

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Int32 ret = 0, i =0 ;
            Byte[] Data = new Byte[32];
            Byte[] GetData = new Byte[32];
            UInt32 OutDataLength = 0;
            Int32 Mod_ID = Int32.Parse(tBSlaveID_W.Text);            
            UInt16 OD_index = Convert.ToUInt16(tBODIndex_W.Text,16);
            UInt16 OD_Subindex = UInt16.Parse(tBSubIndex_W.Text);        
            UInt32 DataLength = UInt32.Parse(tBDataLength_W.Text);
            UInt32 TimeOut = UInt32.Parse(tBTimeOut_W.Text);
            UInt32 Flags = UInt32.Parse(tBFlags_W.Text);
            Int32 Datatemp = Int32.Parse(tBData_W.Text);            
            for (i = 0; i < 8; i++)
            {
                Data[i] = (Byte)((Datatemp >> (i * 8)) & 0xFF);
            }          
            
            ret = APS168.APS_set_field_bus_sdo(v_board_id, Bus_No, Mod_ID, OD_index, OD_Subindex, Data, DataLength, TimeOut, Flags);
            if (ret != 0)
            {
                MessageBox.Show("Error code:  " + ret.ToString());
            }
            
            ret = APS168.APS_get_field_bus_sdo(v_board_id, Bus_No, Mod_ID, OD_index, OD_Subindex, GetData, DataLength, ref OutDataLength, TimeOut, Flags);

        }
    }
}