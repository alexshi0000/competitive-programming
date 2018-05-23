#include <bits/stdc++.h>
using namespace std;				
constexpr int MOD = 1000000007;
typedef long long ll;
vector < vector <int> > graph;
int *parents;
ll ***memo;
long *neighbor;
ll find(int root, int curr_color, int parent_color){
	if(neighbor[root] == 1 && parents[root] == graph.at(root).at(0)){
		if(curr_color == parent_color)
			return 1;
		return 0;
	}	
	ll solutions = 1;
	ll invalid = 1;
	for(int i = 0; i < graph.at(root).size(); i++){
		int focus = graph.at(root).at(i);  
		if(focus != parents[root]){		 
			parents[focus] = root;
			ll same_sol, diff_sol;
			if(memo[focus][curr_color][curr_color] != -1){
				same_sol = memo[focus][curr_color][curr_color];
				diff_sol = memo[focus][curr_color^1][curr_color];
			}
			else{
				same_sol = find(focus,curr_color,curr_color);
				diff_sol = find(focus,curr_color^1,curr_color);
				memo[focus][curr_color][curr_color] = same_sol;
				memo[focus][curr_color^1][curr_color] = diff_sol;
			}
			solutions = (solutions * (same_sol + diff_sol)) % MOD;
			invalid = (diff_sol * invalid) % MOD;
		}
	}
	if(curr_color != parent_color)
		solutions = (solutions - invalid + MOD) % MOD;
	return solutions;
}
int main(){
	int n;
	cin >> n;
	graph = vector < vector<int> >(n);					//adj list representation of graph, the parent vector is static while the child vector is dynamic
	memo = (ll***) malloc(sizeof(ll**)*n);				
	for(int i = 0; i < n; i++){
		memo[i] = (ll**) malloc(sizeof(ll*)*2);
		for(int j = 0; j < 2; j++){
			memo[i][j] = (ll*) malloc(sizeof(ll)*2);
			for(int k = 0; k < 2; k++)
				memo[i][j][k] = -1;						//initializing the triple pointer for 3d array memo table
		}
	}
	neighbor = (long*) malloc(sizeof(long)*n);									
	parents = (int*) malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){							//std::fill() can also be used
		neighbor[i] = 0;								//do not use memset for non zero values, memset works with characters, use std::fill() instead
		parents[i] = -1;
	}	
	for(int i = 0; i < n-1; i++){
		int src, dst;
		cin >> src >> dst;
		src--;
		dst--;
		graph[src].push_back(dst);
		graph[dst].push_back(src);
		neighbor[src]++;
		neighbor[dst]++;
	}
	cout << ((find(0,0,1)+find(0,1,0)) % MOD) << endl;
	for(int i = 0; i < n; i++){							//free
		for(int j = 0; j < 2; j++)
			free(memo[i][j]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){	
			free(memo[i][j]);
		}
		free(memo[i]);
	}
	free(memo);
	free(neighbor);
	free(parents);
	return 0;
}