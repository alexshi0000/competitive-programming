import java.util.*;
public class KnapSack{
	public static int dynamic(int capacity, int[] values, int[] weights){							//max weight, values, weights
		int[][] memo = new int[values.length+1][capacity+1];
		int n = values.length;
		for(int i = 0; i <= n; i++){																//across items, i represents the iten index
			for(int j = 0; j <= capacity; j++){														//across weights
				if(i == 0 || j == 0) memo[i][j] = 0;
				else if(weights[i-1] <= j){															//must be smaller than current testing capacity
					memo[i][j] = Math.max(values[i-1] + memo[i-1][j-weights[i-1]],memo[i-1][j]);
				}																					//the reason we use i-1 ^^ is that the items are index differently than the memo
 				else{
					memo[i][j] = memo[i-1][j];
				}
			}
		}
		return memo[n][capacity];																	//retuns bottom rightest value
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int capacity = sc.nextInt();
		int numberOfItems = sc.nextInt();
		int[] values = new int[numberOfItems];
		int[] weights = new int[numberOfItems];
		for(int i = 0; i < numberOfItems; i++){
			values[i] = sc.nextInt();
			weights[i] = sc.nextInt();
		}
		int maxValue = dynamic(capacity,values,weights);
		System.out.println(maxValue);
	}
}