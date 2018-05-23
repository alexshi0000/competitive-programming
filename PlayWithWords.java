import java.util.*;
public class PlayWithWords{
	static int dp(String s){
		int n = s.length();
		int[][] memo = new int [n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				memo[i][j] = (int)(i == j ? 1 : 0);
		}
		int pad = 1, i, j;
		while(pad < n){
			i = 0;
			j = pad;
			while(j < n){
				if(j - i == 1){
					if(s.charAt(j) == s.charAt(i))
						memo[i][j] = 2;
					else
						memo[i][j] = 1;
				}
				else if(s.charAt(i) == s.charAt(j))
					memo[i][j] = 2 + memo[i+1][j-1];
				else
					memo[i][j] = Math.max(memo[i+1][j], memo[i][j-1]);
				j++;
				i++;
			}
			pad++;
		}
		int lps = 0;
	    for(i = 1; i < n-1; i++){
	        lps = Math.max(lps,memo[0][i-1]*memo[i][n-1]);
	    }
	    return lps;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String in = sc.next();
		System.out.println(dp(in));
	}
}