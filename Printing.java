import java.util.*;
import java.io.*;
public class Printing{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int paper = sc.nextInt();
		int M = sc.nextInt();
		int A = sc.nextInt();
		int time = 0;
		while(true){
			int x = sc.nextInt();
			int y = sc.nextInt();
			time = x;
			paper += y;
			if(paper <= 0){
				System.out.println("The printer melts at "+time+" second(s).");
				break;
			}
			else if(paper > M){
				System.out.println("The printer jams at "+time+" second(s).");
				break;
			}
			A--;
			if(A == 0) break;
		}
	}
}