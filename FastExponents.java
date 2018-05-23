import java.util.*;
import java.io.*;
public class FastExponents{
	public static void main(String[] args){
		try{
			BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(sc.readLine());
			for(int i = 0; i < n; i++){
				long number = Long.parseLong(sc.readLine());
				if((number & (number - 1)) == 0) System.out.println("T");
				else 							 System.out.println("F");
			}
		} catch (Exception e){}
	}
}