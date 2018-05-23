#include <bits/stdc++.h>
using namespace std;

long **func_memo;			//let -1 represent null
long ***junc_memo;
int *parent;
long func(int root, int k);
long junc(int parent, int curr, int ignore, int k);
vector <vector<int>> graph;

void dfs(int root){			//figures out the parent situation
	int idx = -1;
	if(parent[root] != -1){
		for(int i = 0; i < graph[root].size() && idx == -1; i++)
			if(graph[root].at(i) == parent[root])
				idx = i;
	}
	if(idx != -1)
		graph[root].erase(graph[root].begin()+idx);
	for(int i = 0; i < graph[root].size(); i++){
		parent[graph[root].at(i)] = root;
		dfs(graph[root].at(i));
	}
}

long func(int root, int k){
	if(func_memo[root][k] != -1)
		return func_memo[root][k];
	long solutions = 0;
	for(int i = 0; i <= min((int)graph[root].size(), k); i++)
		solutions += junc(root,0,i,k-i);
	func_memo[root][k] = solutions;
	return solutions;
}

long junc(int parent, int curr, int ignore, int k){
	if(curr == graph[parent].size()){
		if(ignore == 0 && k == 0)
			return 1;
		return 0;
	}
	if(junc_memo[graph[parent].at(curr)][ignore][k] != -1)
		return junc_memo[graph[parent].at(curr)][ignore][k];
	long combinations = 0;
	if(ignore >= 1)
		combinations += junc(parent, curr+1, ignore-1, k);// choose to ignore
	for(int i = 0; i <= k; i++)
		combinations += func(graph[parent].at(curr), i) * junc(parent, curr + 1, ignore, k-i);
	junc_memo[graph[parent].at(curr)][ignore][k] = combinations;
	return combinations;
}

int main(){
	int n,k,src,dst;
	cin >> n >> k;
	graph = vector <vector<int>>(n,vector<int>());
	func_memo = (long**) malloc(sizeof(long*) * 51);
	junc_memo = (long***) malloc(sizeof(long**) * 51);
	parent = (int*) malloc(sizeof(int)*n);
	fill(parent, parent + n, -1);						
	for(int i = 0; i < 51; i++){
		func_memo[i] = (long*) malloc(sizeof(long) * 51);
		junc_memo[i] = (long**) malloc(sizeof(long*) * 51);
		fill(func_memo[i], func_memo[i] + 51, -1);
		for(int j = 0; j < 51; j++){
			junc_memo[i][j] = (long*) malloc (sizeof(long) * 51);
			fill(junc_memo[i][j], junc_memo[i][j] + 51, -1);
		}
	}
	for(int i = 0; i < n-1; i++){
		cin >> src >> dst;
		src--;
		dst--;
		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}
	dfs(0);
	long total_solutions = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			if(i == 0 || j < k)
				total_solutions += func(i,j);
		}
	}
	cout << (total_solutions + 1) << endl;
	for(int i = 0; i < 50; i++){
		free(func_memo[i]);
		for(int j = 0; j < 50; j++)
			free(junc_memo[i][j]);
		free(junc_memo[i]);
	}
	free(func_memo);
	free(junc_memo);
}