package mainWorkSpace;

import java.util.HashMap;

public class Nationality 
{
	HashMap<String, String> map = new HashMap<String, String>();
	public Nationality()
	{
		map.put("01", "汉");
		map.put("02","蒙古");
		map.put("03","回");
		map.put("04","藏");
		map.put("05","维吾尔");
		map.put("06","苗");
		map.put("07","彝");
		map.put("08","壮");
		map.put("09","布依");
		map.put("10","朝鲜");
		map.put("11","满");
		map.put("12","侗");
		map.put("13","瑶");
		map.put("14","白");
		map.put("15","土家");
		map.put("16","哈尼");
		map.put("17","哈萨克");
		map.put("18","傣");
		map.put("19","黎");
		map.put("20","傈僳");
		map.put("21","佤");
		map.put("22","畲");
		map.put("23","高山");
		map.put("24","拉祜");
		map.put("25","水");
		map.put("26","东乡");
		map.put("27","纳西");
		map.put("28","景颇");
		map.put("29","柯尔克孜");
		map.put("30","土");
		map.put("31","达斡尔");
		map.put("32","仫佬");
		map.put("33","羌");
		map.put("34","布朗");
		map.put("35","撒拉");
		map.put("36","毛南");
		map.put("37","仡佬");
		map.put("38","锡伯");
		map.put("39","阿昌");
		map.put("40","普米");
		map.put("41","塔吉克");
		map.put("42","怒");
		map.put("43","乌孜别克");
		map.put("44","俄罗斯");
		map.put("45","鄂温克");
		map.put("46","德昂");
		map.put("47","保安");
		map.put("48","裕固");
		map.put("49","京");
		map.put("50","塔塔尔");
		map.put("51","独龙");
		map.put("52","鄂伦春");
		map.put("53","赫哲");
		map.put("54","门巴");
		map.put("55","珞巴");
		map.put("56","基诺");
	}
	public String GetNationality(String str)
	{
		return map.get(str);
	}
}
