import java.util.*;
import java.io.*;
public class RiceBalls{
	static int[] riceballs;
	static int[][] memo;
	public static void combine(int l ,int r){
		if(l == r)
			memo[l][r] = riceballs[l];											//base cases
		
		else if(r - l == 1 && riceballs[l] == riceballs[r])
			memo[l][r] = riceballs[l] + riceballs[r];
		
		else if(r - l == 2 && riceballs[l] == riceballs[r])
			memo[l][r] = riceballs[l] + riceballs[r] + riceballs[l+1];

		else{														
			for(int i = l; i < r; i++){
				if(memo[l][i] == memo[i+1][r] && memo[l][i] != 0){
					memo[l][r] = memo[l][i] + memo[i+1][r];
					return;
				} 
				for(int j = i+1; j < r; j++){
					if(memo[i+1][j] != 0 && memo[l][i] == memo[j+1][r] && memo[l][i] != 0){
						memo[l][r] = memo[l][i] + memo[j+1][r] + memo[i+1][j];
						return;
					}
				}
			}
		}
	}
	public static int dynamic(){
		int max = 0;																//max riceball size
		int l = 0, r = 0, d = 0;													//l and r pointers, d is the difference
		while(true){
			if(r >= riceballs.length){
				d++;
				if(d >= riceballs.length) break;
				r = d;
				l = 0;
			}
			combine(l,r);
			if(memo[l][r] > max) max = memo[l][r];
			l++;
			r++;
		}
		return max;
	}
	public static void main(String[] args){
		try{
			BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(sc.readLine());
			riceballs = new int[n];
				 memo = new int[n][n];
			String[] in = sc.readLine().split(" ");
			for(int i = 0; i < in.length; i++) riceballs[i] = Integer.parseInt(in[i]);
			System.out.println(dynamic());
		} catch (Exception e){	e.printStackTrace();  }
	}
}