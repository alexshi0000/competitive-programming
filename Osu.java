import java.util.*;
public class Osu{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int D = sc.nextInt();
		int max = 1;
		int counter = 1;							//combo
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		for(int i = 0; i < N-1; i++){
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			if(Math.sqrt(Math.pow(x2-x1,2) + Math.pow(y2-y1,2)) <= D){
				counter++;
				if(counter > max) max = counter;
				x1 = x2;
				y1 = y2;
			} else {
				counter = 0;
				x1 = x2;
				y1 = y2;
			}
		}
		System.out.println(max);
	}
}