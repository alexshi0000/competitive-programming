import java.util.*;
import java.io.*;

public class Intersections{

	static int[][] map;
	static int[][] visited;

	public static class Node{
		int dist = Integer.MAX_VALUE;
		int x,y;
		Node(int y, int x){
			this.x = x;
			this.y = y;
		}
	}

	public static boolean valid(int y, int x){
		if(y < 0 || y >= map.length || x < 0 || x >= map[0].length) return false;
		if(map[y][x] == 1 || visited[y][x] == 1) return false;
		return true;
	}

	public static int solve(Node start){
		start.dist = 1;
		Queue<Node> q = new LinkedList<Node>();  
		q.add(start);
		visited[start.y][start.x] = 1;
		while(!q.isEmpty()){
			Node focus = q.poll();
			if(focus.y == map.length-1 && focus.x == map[0].length-1) return focus.dist;
			if(map[focus.y][focus.x] == 3){
				if(valid(focus.y+1,focus.x)){
					Node n = new Node(focus.y+1,focus.x);
					n.dist = focus.dist + 1;
					visited[n.y][n.x] = 1;
					q.add(n);
				}
				if(valid(focus.y-1,focus.x)){
					Node n = new Node(focus.y-1,focus.x);
					n.dist = focus.dist + 1;
					visited[n.y][n.x] = 1;
					q.add(n);
				}
			} 
			else if(map[focus.y][focus.x] == 4){
				if(valid(focus.y,focus.x+1)){
					Node n = new Node(focus.y,focus.x+1);
					n.dist = focus.dist + 1;
					visited[n.y][n.x] = 1;
					q.add(n);
				}
				if(valid(focus.y,focus.x-1)){
					Node n = new Node(focus.y,focus.x-1);
					n.dist = focus.dist + 1;
					visited[n.y][n.x] = 1;
					q.add(n);
				}
			}
			else{
				if(valid(focus.y,focus.x+1)){
					Node n = new Node(focus.y,focus.x+1);
					n.dist = focus.dist + 1;
					visited[n.y][n.x] = 1;
					q.add(n);
				}
				if(valid(focus.y,focus.x-1)){
					Node n = new Node(focus.y,focus.x-1);
					n.dist = focus.dist + 1;
					visited[n.y][n.x] = 1;
					q.add(n);
				}
				if(valid(focus.y+1,focus.x)){
					Node n = new Node(focus.y+1,focus.x);
					n.dist = focus.dist + 1;
					visited[n.y][n.x] = 1;
					q.add(n);
				}
				if(valid(focus.y-1,focus.x)){
					Node n = new Node(focus.y-1,focus.x);
					n.dist = focus.dist + 1;
					visited[n.y][n.x] = 1;
					q.add(n);
				}
			}
		}
		return -1;
	}
	
	public static void main(String[] args){
		try{
			BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(sc.readLine());
			for(int T = 0; T < t; T++){
				int r = Integer.parseInt(sc.readLine());
				int c = Integer.parseInt(sc.readLine());
				map = new int[r][c];
				visited = new int[r][c];
				for(int i = 0; i < r; i++){
					String in = sc.readLine();
					for(int j = 0; j < c; j++){
						if(in.substring(j,j+1).equals("+")) map[i][j] = 5;
						else if(in.substring(j,j+1).equals("|")) map[i][j] = 3;
						else if(in.substring(j,j+1).equals("-")) map[i][j] = 4;
						else 									 map[i][j] = 1;
					}
				}
				System.out.println(solve(new Node(0,0)));
			}
		} catch (Exception e){

		}
	}

}