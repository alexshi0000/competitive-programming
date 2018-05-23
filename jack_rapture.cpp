#include <bits/stdc++.h>
using namespace std;

int constexpr MAX = 2000000000;
class edge;

class node{
	public:
		int cost, id;
		bool visited;
		vector<edge*> adj;
		node *parent;
		node(int id){
			this->id = id;
			cost = MAX;
			visited = false;
			parent = NULL;
		}
		~node(){}
};

class edge{
	public:
		int cost;
		node *src, *dst;
		edge(node *src, node *dst, int cost){
			this->src = src;
			this->dst = dst;
			this->cost = cost;
		}	
		~edge(){}
};

void add_edge(node *src, node *dst, int cost){
	src->adj.push_back(new edge(src,dst,cost));
	dst->adj.push_back(new edge(dst,src,cost));
}

class comparator{
	public: 
		bool operator()(const node *a, const node *b){
			return a->cost < b->cost;
		}
};

int find_route(node *start, node *end){
	bool reached = false;
	queue<node*> q; 
	q.push(start);
	start->cost = 0;
	while(q.size() > 0){
		node *focus = q.front();
		q.pop();
		if(focus == end){
			reached = true;
			continue;
		}
		for(int i = 0; i < focus->adj.size(); i++){
			edge *neighbor = focus->adj.at(i);
			if(neighbor->cost - focus->cost < 0){
				if(neighbor->dst->cost > focus->cost){
					neighbor->dst->cost = focus->cost;
					q.push(neighbor->dst);
				}
			} 
			else if(neighbor->dst->cost > neighbor->cost){
				neighbor->dst->cost = neighbor->cost;
				q.push(neighbor->dst);
			}
		}
	}
	if(reached)
		return end->cost;
	return -1;
}

int main(){
	int n,e;
	cin >> n >> e;
	node **node_arr = (node**) malloc(sizeof(node*)*n);
	for(int i = 0; i < n; i++)
		node_arr[i] = new node(i+1);
	for(int i = 0; i < e; i++){
		int src,dst,cost;
		cin >> src >> dst >> cost;
		add_edge(node_arr[src-1], node_arr[dst-1], cost);
	}
	int min_cost = find_route(node_arr[0], node_arr[n-1]);
	if(min_cost < 0)
		cout << "NO PATH EXISTS" << endl;
	else
		cout << min_cost << endl;
	return 0;
}