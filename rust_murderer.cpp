#include <bits/stdc++.h>
using namespace std;
unordered_set<string> road;
queue<int> unvisited;
int *dist;
int n, m, s;
constexpr int MAX = 2000000000;
void add_edge(int src, int dst){
	road.insert(to_string(src)+"@"+to_string(dst));
	road.insert(to_string(dst)+"@"+to_string(src));
}
void bfs(int start){
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(q.size() > 0){
		int focus = q.front();
		q.pop();
		int size = unvisited.size();
		for(int i = 0; i < size; i++){
			int adj = unvisited.front();
			unvisited.pop();
			if(adj != focus && adj != start && dist[adj] > dist[focus] + 1){
				if(road.find(str(focus)+"@"+str(adj)) == road.end()){
					dist[adj] = dist[focus] + 1;
					q.push(adj);
				}
				else
					unvisited.push(adj);
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	for(int Test = 0; Test < t; Test++){
		road = unordered_set<string>();
		unvisited = queue<int>();
		cin >> n >> m; 
		dist = (int*) malloc(sizeof(int)*n);
		fill(dist, dist + n, MAX);
		for(int i = 0; i < n; i++)
			unvisited.push(i);
		for(int i = 0; i < m; i++){
			int src, dst;
			cin >> src >> dst;
			add_edge(src-1,dst-1);
		}
		cin >> s;
		bfs(s-1);
		for(int i = 0; i < n; i++){
			if(i != s)
				cout << dist[i] << " ";
		}
		cout << endl;
	}
	return 0;
}