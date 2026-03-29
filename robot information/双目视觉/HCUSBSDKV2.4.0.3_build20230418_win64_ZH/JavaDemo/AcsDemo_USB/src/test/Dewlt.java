package test;

import com.sun.jna.Native;
import com.sun.jna.win32.StdCallLibrary;

public interface Dewlt extends StdCallLibrary{
	int dewlt(String strPictureBin);	 
}
