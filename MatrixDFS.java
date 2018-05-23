import java.util.*;
public class MatrixDFS{
	static int[][][] graph;
	static boolean[] visited;
	public static void dfs(int focus){
		if(!visited[focus]){
			visited[focus] = true;
			System.out.print(focus+"->");
			for(int i = 0; i < graph.length; i++)
				if(graph[focus][i][0] == 1)
					dfs(i);
		}
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int e = sc.nextInt();
		graph = new int[n][n][2];
		visited = new boolean[n];
		Arrays.fill(visited, false);
		for(int i = 0; i < n; i++){
			graph[i][i][0] = 1;				//relationship
			graph[i][i][1] = i;				//id, or data
		}
		for(int i = 0; i < e; i++){
			int src = sc.nextInt();
			int dst = sc.nextInt();
			graph[src][dst][0] = 1;
			graph[dst][src][0] = 1;
		}
		dfs(0);
		System.out.println();
	}
}