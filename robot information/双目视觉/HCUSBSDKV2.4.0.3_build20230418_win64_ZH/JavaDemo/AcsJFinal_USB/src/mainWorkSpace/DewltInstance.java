package mainWorkSpace;

import com.sun.jna.Native;
import UsbSDK.Dewlt;

public class DewltInstance {
	public static Dewlt dewlt = null;
	public static Dewlt getInstance()
	{
		if(dewlt == null)
		{
			synchronized(Dewlt.class)
			{
				if(Is32Bit())
				{
					dewlt = (Dewlt) Native.loadLibrary("..\\lib\\dewlt",Dewlt.class);
				}
			}
		}
		return dewlt;
	}
	
	//判断JDK位数
	public static boolean Is32Bit(){
		String strVersion = System.getProperty("sun.arch.data.model");
    	if(strVersion.contains("32"))
    	{
    		return true;
    	}
    	else
    	{
			return false;
		}
    }
}
