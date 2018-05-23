import java.util.*;
import java.io.*;
public class BeautifulNumbers{
	public static long isBeautiful(String s){
		for(int i = 1; i <= s.length()/2; i++){
			long start = Long.parseLong(s.substring(0,i));			//starting number
			long num = start;										//number we are looking for
			num++;
			int l = i;						
			int r;		
			Long next = new Long(num+"");
			r = next.toString().length() + l;			
			while(true){
				if(r > s.length() || l >= s.length()) 	   break;
				if(s.substring(l,l+1).equals("0")) 		   break;
				if(Long.parseLong(s.substring(l,r)) == num){
					if(r == s.length()) 		   return start;
					l = r;
					num++;
					next = new Long(num+"");
					r = next.toString().length() + l;
				}
				else break;
			}
		}
		return -1;													//not found
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		String[] results = new String[n];
		for(int i = 0; i < n; i++){
			String s = sc.nextLine();
			long outcome = isBeautiful(s);
			if(outcome == -1) System.out.println("NO");
			else			  System.out.println("YES "+outcome);
		}
	}
}