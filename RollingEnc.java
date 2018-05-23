import java.util.*;
import java.io.*;
public class RollingEnc{
	public static void main(String[] args) throws IOException {
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(sc.readLine());
		String s = sc.readLine();
		String ret = "";
		int[] count = new int[26];
		for(int i = 0; i < s.length(); i++){
			char curr = s.charAt(i);
			if(i >= k){
				int max = Integer.MIN_VALUE;
				int idx = -1;
				for(int j = 0; j < 26; j++){
					if(max < count[j]){
						max = count[j];
						idx = j;
					}
				}
				System.out.print((char)('a'+(idx+(int)(s.charAt(i)-'a')+1)%26)+""); 
				count[(int)(s.charAt(i-k)-'a')]--;
				count[(int)(s.charAt(i)-'a')]++;
			}
			else{
				count[(int)(curr-'a')]++;
				System.out.print(curr+"");
			}
		}
	}
}
