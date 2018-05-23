import java.io.*;
import java.util.*;
public class StringRounding{
	public static void main(String[] args) throws IOException{
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		String s = sc.readLine();
		for(int i = s.length()-1; i >= 0; i--){
			char c = s.charAt(i);
			if(c <= 'm' && c >= 'a'){
				s = s.substring(0,i) + 'a' + s.substring(i+1);
				break;
			}
			else{
				if(i > 0){
					s = s.substring(0,i) + 'a' + s.substring(i+1);
					if(s.charAt(i-1) != 'z'){
						s = s.substring(0,i-1) + (char)((int)s.charAt(i-1)+1) + s.substring(i);
						break;
					}
				}
				else{
					s = "aa"+s.substring(1);
					break;
				}
			}
		}
		System.out.println(s);
	}	
}