import java.util.*;
import java.io.*;
public class Cubes{
	public static long value(int i, int j, long[] arr){
		if(i == 0) return arr[j];
		return arr[j] - arr[i-1];
	}
	public static void main(String[] args){
		try{
			BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			String[] in = sc.readLine().split(" ");
			int N = Integer.parseInt(in[0]);
			int M = Integer.parseInt(in[1]);
			int Q = Integer.parseInt(in[2]);
			long[] arr = new long[N];														//this isnt array of values, ts the sum array
			in = sc.readLine().split(" ");
			HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
			for(int i = 0; i < N; i++){
				map.put(Integer.parseInt(in[i]),i);
				if(i == 0) arr[i] = 		   Integer.parseInt(in[i]);
				else 	   arr[i] = arr[i-1] + Integer.parseInt(in[i]);
			}
			for(int i = 0; i < Q; i++){
				in = sc.readLine().split(" ");
				int a = map.get(Integer.parseInt(in[0]));
				int b = map.get(Integer.parseInt(in[1]));
				//System.out.println(a+" "+b+" "+value(a,b,arr));
				if(value( Math.min(a,b) , Math.max(a,b) , arr) * 0.50000001 >= M) System.out.println("Enough");
				else													          System.out.println("Not enough"); 
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}