#include <bits/stdc++.h>
using namespace std;
vector < vector<int> > adj;
int n, m, *visited;

bool possible(int src, int dst)
{
	if (src == dst)
		return true;
	if (visited[src])
		return false;
	visited[src] = 1;
	for (int i = 0; i < adj[src].size(); i++) {
		if (possible(adj[src].at(i), dst))
			return true;
	}
	return false;
}
int main()
{
	cin >> n >> m;
	adj = vector < vector<int> > (n);
	visited = (int*) malloc(sizeof(int)*n);
	pair <int, int> edges[m];
	for (int i = 0; i < m; i++) {
		int src, dst;
		cin >> src >> dst;
		src--; 
		dst--;
		adj[src].push_back(dst);
		edges[i].first = src;
		edges[i].second = dst;
	}
	for (int i = 0; i < m; i++) {
		memset(visited, 0, sizeof(int)*n);
		//remove
		for (int j = 0; j < adj[edges[i].first].size(); j++) {
			if (adj[edges[i].first].at(j) == edges[i].second) {
				adj[edges[i].first].erase(adj[edges[i].first].begin() + j);
				break;
			}
		}
		if (possible(0, n-1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		adj[edges[i].first].push_back(edges[i].second); //add back
	}
	return 0;
}