#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		bool visited;
		std::vector <Node*> adj;
		Node(){
			visited = false;
		}
		~Node(){
			delete this;
		}
};

long long dfs(Node *root){
	root -> visited = true;
	long long counter = 1;
		//inclusive of itself
	for(long long i = 0; i < root -> adj.size(); i++){
		if(!root -> adj.at(i) -> visited)
			counter += dfs(root -> adj.at(i));
	}
	return counter;
}

int main(){
	long long q;
	cin >> q;
	for(long long test = 0; test < q; test++){
		long long q, n_cities, n_roads, c_lib, c_road;
		cin >> n_cities >> n_roads >> c_lib >> c_road;
		vector <Node*> node;
		for(long long i = 0; i < n_cities; i++)
			node.push_back(new Node());
		for(long long i = 0; i < n_roads; i++){
			long long src,dst;
			cin >> src >> dst;
			src--;
			dst--;
			node.at(src) -> adj.push_back(node.at(dst));
			node.at(dst) -> adj.push_back(node.at(src));
		}
		if(c_lib <= c_road){
			cout << c_lib*n_cities << endl;
			continue;
		}
		long long total_cost = 0;
		for(long long i = 0; i < node.size(); i++){
			if(node.at(i) -> visited)
				continue;
			long long n_node = dfs(node.at(i));
			total_cost += (n_node-1)*c_road + c_lib;
		}
		cout << total_cost << endl;
	}
}