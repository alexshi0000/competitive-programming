import java.util.*;

public class KnapSackWeightVariant{

	public static int knapSack(int[] weights, int capacity){					
		int[] memo = new int[capacity+1];
		memo[0] = 0;
		for(int i = 1; i <= capacity; i++){
			memo[i] = memo[i-1];
			for(int j = 0; j < weights.length && weights[j] <= i; j++)
				memo[i] = Math.max(memo[i], weights[j] + memo[i-weights[j]]);
		}
		return memo[capacity];
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int[] results = new int[t];
		for(int T = 0; T < t; T++){
			int n = sc.nextInt();
			int capacity = sc.nextInt();
			int[] weights = new int[n];
			for(int i = 0; i < n; i++)
				weights[i] = sc.nextInt();
			Arrays.sort(weights);
			results[T] = knapSack(weights,capacity);
		}
		for(int i: results)
			System.out.println(i);
	}
}