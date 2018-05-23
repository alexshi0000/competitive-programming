#include <bits/stdc++.h>
using namespace std;

class edge;

class node{
	public:
		int id;
		int max_weight;
		vector <edge*> adj;
		bool visited;						//this is useless variable but in the case that the problem asks to return -1 for unreachable, this is very helpful 
		node(int id){
			this -> id = id;
			max_weight = 0;
			visited = false;
		}
		~node(){}
};

class edge{
	public:
		node *src, *dst;
		int weight;
		edge(node *src, node *dst, int weight){
			this -> src = src;
			this -> dst = dst;
			this -> weight = weight;
		}
};

void bfs(node *start){						//updates the max weight your allowed to bring to the cities
	vector <node*> queue;
	start -> max_weight = 2000000000;
	queue.insert(queue.begin(),start);
	while(queue.size() > 0){
		node *focus = queue.back();
		queue.pop_back();
		focus -> visited = true;
		for(int i = 0; i < focus -> adj.size(); i++){
			edge *e = focus -> adj.at(i);
			if(e -> dst -> max_weight < min(e -> weight, focus -> max_weight)){
				e -> dst -> max_weight = min(e -> weight, focus -> max_weight);
				queue.insert(queue.begin(),e -> dst);
			}
		}
	}
}

void add_edge(node *src, node *dst, int weight){
	src -> adj.push_back(new edge(src,dst,weight));
	dst -> adj.push_back(new edge(dst,src,weight));
}

int main(){
	int c,r,d;
	cin >> c >> r >> d;
	node** nodes = (node**) malloc(c*sizeof(node*));
	for(int i = 0; i < c; i++)
		nodes[i] = new node(i);
	for(int i = 0; i < r; i++){
		int src,dst,weight;
		cin >> src >> dst >> weight;
		add_edge(nodes[src-1], nodes[dst-1], weight);
	}
	bfs(nodes[0]);
	int minimum = 2000000000;
	for(int i = 0; i < d; i++){
		int destination; 
		cin >> destination;
		destination--;
		if(nodes[destination] -> max_weight < minimum)
			minimum = nodes[destination] -> max_weight;
	}
	cout << minimum << endl;
	return 0;
}