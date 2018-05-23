import java.util.*;
import java.io.*;

public class KnightlyPursuit{

	public static class Node{
		int r, c, steps;					//steps is the amount of steps to reach this location
		Node(int r, int c){
			this.r = r;
			this.c = c;
			steps = -1;
		}
	}

	public static boolean safe(Node[][] knight, int r, int c){
		try{
			Node pass = knight[r][c];
		}catch(Exception e){
			return false;
		}
		if(knight[r][c].steps != -1)
			return false;
		return true;
	}

	public static void print(int[][] arr){
		for(int i = 0; i < arr.length; i++){
			for(int j = 0; j < arr[0].length; j++){
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
	}

	public static void getKnightMoves(int[][] arr, Node[][] knight, Node start){
		Queue<Node> queue = new LinkedList<Node>();
		queue.add(start);
		start.steps = 0;
		while(!queue.isEmpty()){
			Node focus = queue.poll();
			int r = focus.r;
			int c = focus.c;
			arr[focus.r][focus.c] = focus.steps;
			if(safe(knight,r+2,c+1)){
				knight[r+2][c+1].steps = focus.steps + 1;
				queue.add(knight[r+2][c+1]);
			}
			if(safe(knight,r+1,c+2)){
				knight[r+1][c+2].steps = focus.steps + 1;
				queue.add(knight[r+1][c+2]);
			}
			if(safe(knight,r-2,c+1)){
				knight[r-2][c+1].steps = focus.steps + 1;
				queue.add(knight[r-2][c+1]);
			}
			if(safe(knight,r-1,c+2)){
				knight[r-1][c+2].steps = focus.steps + 1;
				queue.add(knight[r-1][c+2]);
			}
			if(safe(knight,r+2,c-1)){
				knight[r+2][c-1].steps = focus.steps + 1;
				queue.add(knight[r+2][c-1]);
			}
			if(safe(knight,r+1,c-2)){
				knight[r+1][c-2].steps = focus.steps + 1;
				queue.add(knight[r+1][c-2]);
			}
			if(safe(knight,r-2,c-1)){
				knight[r-2][c-1].steps = focus.steps + 1;
				queue.add(knight[r-2][c-1]);
			}
			if(safe(knight,r-1,c-2)){
				knight[r-1][c-2].steps = focus.steps + 1;
				queue.add(knight[r-1][c-2]);
			}
		}
	}

	public static void main(String[] args) throws Exception{
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(sc.readLine());
		for(int T = 0; T < t; T++){
			int r = Integer.parseInt(sc.readLine());
			int c = Integer.parseInt(sc.readLine());
			int pr = Integer.parseInt(sc.readLine()) - 1;
			int pc = Integer.parseInt(sc.readLine()) - 1;
			int kr = Integer.parseInt(sc.readLine()) - 1;
			int kc = Integer.parseInt(sc.readLine()) - 1;
			int[][] arr = new int[r][c];
			Node[][] knight = new Node[r][c];
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					knight[i][j] = new Node(i,j);
					arr[i][j] = -1;
				}
			}
			getKnightMoves(arr,knight,knight[kr][kc]);
			boolean foundSolution = false;
			for(int i = pr; i < r-1; i++){
				int moves = i - pr;
				if(arr[i][pc] == -1) continue;
				if(arr[i][pc] == moves || (moves > arr[i][pc] && (moves - arr[i][pc]) % 2 == 0)){
					System.out.println("Win in "+moves+" knight move(s).");
					foundSolution = true;
					break;
				}	
			}
			if(!foundSolution){
				//the knight was unable to get to the pawn
				for(int i = pr; i < r-1; i++){
					int moves = i - pr;		//the amount of moves it takes for the pawn to reach here
					if(arr[i+1][pc] == -1) continue;
					if(arr[i+1][pc] == moves || (moves > arr[i+1][pc] && (moves - arr[i+1][pc]) % 2 == 0)){
						System.out.println("Stalemate in "+ moves +" knight move(s).");
						foundSolution = true;
						break;
					}
				}
				if(!foundSolution)
					System.out.println("Loss in "+ (r - 2 - pr) +" knight move(s).");
			}
		}
	}
}