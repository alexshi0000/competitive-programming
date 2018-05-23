public class Padding{
	public static String pad(String text, int desiredSize, char c){
		String out = "";
		for(int i = 0; i < desiredSize - text.length(); i++)
			out += c;
		return out + text;
	}
	public static void main(String[] args){
		System.out.println(pad("",4,'*'));
	}
}