import java.util.*;
public class TimeSeries{
	static int binarySearch(int[] arr, int value){
		if(arr[0] >= value)
			return 0;
		int lo = 0;
		int hi = arr.length - 2;
		while(lo <= hi){
			int mid = lo + (hi-lo)/2;
			if(arr[mid] < value && arr[mid+1] >= value)
				return mid+1;
			else if(arr[mid] < value)
				lo = mid+1;
			else 
				hi = mid-1;
		}
		return -1;		// not found
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		int[] prefixMax = new int[n];
		int[] sufixMax = new int[n];
		int[] time = new int[n];				
		int[] price = new int[n];
		for(int i = 0; i < n; i++)
			time[i] = sc.nextInt();
		for(int i = 0; i < n; i++){
			price[i] = sc.nextInt();
			if(i == 0)
				prefixMax[i] = price[i];
			else if(prefixMax[i-1] < price[i])
				prefixMax[i] = price[i];
			else
				prefixMax[i] = prefixMax[i-1];
		}	
		for(int i = n-1; i >= 0; i--){
			if(i == n-1)
				sufixMax[i] = price[i];
			else if(sufixMax[i+1] < price[i])
				sufixMax[i] = price[i];
			else
				sufixMax[i] = sufixMax[i+1];
		}
		Arrays.sort(time);
		for(int i = 0; i < q; i++){
			int type = sc.nextInt();
			int value = sc.nextInt();
			if(type == 1){
				int idx = binarySearch(prefixMax, value);
				if(idx == -1)
					System.out.println("-1");
				else	
					System.out.println(time[idx]);
			}
			else{
				int idx = binarySearch(time, value);
				if(idx == -1)
					System.out.println("-1");
				else
					System.out.println(sufixMax[idx]);
			}
		}	
	}
}