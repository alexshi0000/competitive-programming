import java.util.*;
import java.io.*;
public class NinePacks{
	public static int dynamic(int[] dogs, int[] buns, int capacity){			//capacity is the limit
		int[] table_dog = new int[capacity+1];
		int[] table_bun = new int[capacity+1];
		boolean[][] visited_dog = new boolean[capacity+1][dogs.length];
		boolean[][] visited_bun = new boolean[capacity+1][buns.length];
		int min = Integer.MAX_VALUE;
		for(int i = 1; i <= capacity; i++){
			table_dog[i] = Integer.MAX_VALUE;	
			table_bun[i] = Integer.MAX_VALUE;									
			int index = -1;
			for(int j = 0; j < dogs.length; j++){
				if(dogs[j] <= i && !visited_dog[i-dogs[j]][j]){						
					if(table_dog[i-dogs[j]] + 1 < table_dog[i] && table_dog[i-dogs[j]] != Integer.MAX_VALUE){
						table_dog[i] = 1 + table_dog[i-dogs[j]];
						index = j;
					}
				}
			}
			if(index != -1){
				for(int k = 0; k < dogs.length; k++){
					visited_dog[i][k] = visited_dog[i - dogs[index]][k];
					if(k == index) visited_dog[i][k] = true;
				}
			}
			index = -1;
			for(int j = 0; j < buns.length; j++){
				if(buns[j] <= i && !visited_bun[i-buns[j]][j]){						
					if(table_bun[i-buns[j]] + 1 < table_bun[i] && table_bun[i-buns[j]] != Integer.MAX_VALUE){
						table_bun[i] = 1 + table_bun[i-buns[j]];
						index = j;
					}
				}
			}
			if(index != -1){
				for(int k = 0; k < buns.length; k++){
					visited_bun[i][k] = visited_bun[i - buns[index]][k];
					if(k == index) visited_bun[i][k] = true;
				}
			}
			if(table_dog[i] != Integer.MAX_VALUE && table_bun[i] != Integer.MAX_VALUE && table_dog[i] + table_bun[i] < min) min = table_dog[i] + table_bun[i];
		}
		return min;
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] dogs = new int[n];
		int total_dogs = 0;
		for(int i = 0; i < n; i++){
			dogs[i] = sc.nextInt();
			total_dogs += dogs[i];
		}
		n = sc.nextInt();
		int[] buns = new int[n];
		int total_buns = 0;
		for(int i = 0; i < n; i++){
			buns[i] = sc.nextInt();
			total_buns += buns[i];
		}
		int min = dynamic(dogs,buns,Math.min(total_buns,total_dogs));
		if(min != Integer.MAX_VALUE){
			System.out.println(min);	return;
		}
		System.out.println("impossible");
	}
}