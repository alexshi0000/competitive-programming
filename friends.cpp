#include <bits/stdc++.h>
#define INF (0x7FFFFFFF)
#define n   (9999)
using namespace std;
vector<vector<int>> graph;
bool *visited;
int *dist, *parent, N;
int bfs(int src, int dst){		//return distance
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	bool found = 0;
	while(q.size() > 0){
		int focus = q.front();
		visited[focus] = true;
		q.pop();
		if(focus == dst){
			found = 1;
			break;
		}
		for(int a: graph[focus]){
			if(!visited[a]){
				dist[a] = dist[focus]+1;
				q.push(a);
			}
		}
	}
	if(found)
		return dist[dst]-1;
	return -1;
}
int find(int src);
void _union(int src, int dst){
	if(parent[src] == -1 && parent[dst] == -1)
		parent[dst] = src;
	else if(parent[src] != -1 && parent[dst] == -1)
		parent[dst] = find(src);
	else if(parent[src] == -1 && parent[dst] != -1)
		parent[src] = find(dst);
	else
		parent[find(dst)] = find(src);
}
int find(int src){
	if(parent[src] == -1)
		return src;
	return find(parent[src]); 
}
int main(){
	scanf("%d",&N);
	graph   = vector<vector<int>>(n);
	visited = (bool*)malloc(sizeof(bool)*n);
	dist    = (int*)malloc(sizeof(int)*n);
	parent  = (int*)malloc(sizeof(int)*n);
	memset(parent,-1,sizeof(int)*n); 
		//memset later in code
	for(int i = 0; i < N; i++){
		int src, dst;
		scanf("%d%d",&src,&dst);
		graph[src-1].push_back(dst-1);
		if(find(src-1) != find(dst-1))
			_union(src-1,dst-1);
	}
	while(true){
		int src, dst;
		scanf("%d%d",&src,&dst);
		if(src == 0 && dst == 0)
			break;
		src--;
		dst--;
		memset(visited,0,sizeof(bool)*n);
		memset(dist,INF,sizeof(int)*n);
		int src_to_dst = bfs(src,dst);
		if(src_to_dst == -1)
			printf("%s\n","NO");
		else{
			//reset visited and distances
			if(find(src) != find(dst))			//do not belong to the same set
				printf("%s\n","No");
			else
				printf("%s%d\n", "Yes ", src_to_dst);
		}
	}
	return 0;
}/*
int main(){
	scanf("%d",&N);
	graph   = vector<vector<int>>(n);
	visited = (bool*)malloc(sizeof(bool)*n);
	dist    = (int*)malloc(sizeof(int)*n);
	parent  = (int*)malloc(sizeof(int)*n);
	memset(parent,-1,sizeof(bool)*n); 
	memset(visited,0,sizeof(bool)*n);
	memset(dist,INF,sizeof(int)*n);
	for(int i = 0; i < N; i++){
		int src, dst;
		scanf("%d%d",&src,&dst);
		graph[src-1].push_back(dst-1);
	}
	while(true){
		int src, dst;
		scanf("%d%d",&src,&dst);
		if(src == 0 && dst == 0)
			break;
		src--;
		dst--;
		memset(visited,0,sizeof(bool)*n);
		memset(dist,INF,sizeof(int)*n);
		int src_to_dst = bfs(src,dst);
		if(src_to_dst == -1)
			printf("%s\n","NO");
		else{
			//reset visited and distances
			memset(visited,0,sizeof(bool)*n);
			memset(dist,INF,sizeof(int)*n);
			int dst_to_src = bfs(dst,src);
			if(dst_to_src == -1)
				printf("%s\n","NO");
			else
				printf("%s%d\n", "YES ", src_to_dst);
		}
	}
	return 0;
}*/