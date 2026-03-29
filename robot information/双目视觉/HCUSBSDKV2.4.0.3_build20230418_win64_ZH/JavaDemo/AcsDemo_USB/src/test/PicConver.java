package test;

import java.awt.Color;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;

import javax.imageio.ImageIO;

import com.sun.image.codec.jpeg.JPEGCodec;
import com.sun.image.codec.jpeg.JPEGImageEncoder;
import com.sun.org.apache.xalan.internal.xsltc.runtime.Parameter;

public class PicConver {
	//因为jdk只识别jpg, png, gif三种格式的图片，所以在显示bmp图片时先进行转换,这里转成jpg格式
	public PicConver()
	{
		File file = new File(AcsDemo_USB.szLogPath + "\\tmpIDPhoto_$_$.bmp");
		try {
			file.canRead();
			file.canWrite();
			BufferedImage src = ImageIO.read(file);
			ImageIO.write(src, "JPG", new File(AcsDemo_USB.szLogPath + "\\tmpIDPhoto_$_$.jpg"));
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
}
