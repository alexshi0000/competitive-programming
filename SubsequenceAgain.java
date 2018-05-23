import java.util.*;
import java.io.*;
public class SubsequenceAgain{
	public static void main(String[] args) throws IOException{
		BufferedReader sc = new BufferedReader(new InputSteamReader(System.in));
		String s = sc.readLine();
		int k = Integer.parseInt(sc.readLine());
		int[] map = new int[Character.MAX_VALUE+1];
		for(int i = 0; i < s.length(); i++)
			map[(int)s.charAt(i)]++;	
		for(int i = 0; i < s.length(); i++)
			if(map[(int)s.charAt(i)] >= k)	
				System.out.print(s.charAt(i)+"");
	}
}