import java.util.*;
public class BuyMaxStocks{
	public static class Pair implements Comparable<Pair>{
		long first, second;
		Pair(long first, long second){
			this.first = first;
			this.second = second;
		}
		public String toString(){
			return "("+first+", "+second+")";
		}
		public int compareTo(Pair arg0){
			if(arg0.first > this.first)
				return -1;	
			return 1;
		}
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		Pair[] arr = new Pair[(int)n];
		for(int i = 0; i < n; i++){
			long price = sc.nextInt();
			arr[i] = new Pair(price,i+1);
		}
		long k = sc.nextLong();
		long counter = 0;
		Arrays.sort(arr);
		System.out.println(Arrays.toString(arr));
		for(int i = 0; i < n; i++){
			if((k/arr[i].first) > arr[i].second){
				k -= (arr[i].first * arr[i].second);
				if(k < 0)
					break;
				counter += arr[i].second;
			}
			else{
				long amt = k/arr[i].first;
				k -= amt * arr[i].first;
				if(k < 0)
					break;
				counter += amt;
			}
		}
		System.out.println(counter);
	}
}