#include <bits/stdc++.h>
using namespace std;

class edge;

class node{
public:
	static vector <node*> created;
	vector <edge*> adj;
	bool letter;
	bool visited;
	int distance;
	int id;
	node(int id){
		this -> id = id;
		letter = false;
		visited = false;
		distance = 2000000000;
		created.push_back(this);
	}
	static void reset(){
		for(int i = 0; i < created.size(); i++){
			created.at(i) -> visited = false;
			created.at(i) -> distance = 2000000000;
		}
	}
};

struct compare_nodes{
	bool operator()(node const *a, node const *b){
		return a -> distance > b -> distance;
	}
};

vector <node*> node::created;

class edge{
public:
	node *src, *dest;
	int weight;
	edge(node *src, node *dest, int weight){
		this -> src = src;
		this -> dest = dest;
		this -> weight = weight;
	}
};

void add_edge(node *src, node *dest, int weight){
	src -> adj.push_back(new edge(src,dest,weight));
	dest -> adj.push_back(new edge(dest,src,weight));
}

void bfs(node *start, stack <node*> *node_stack){
	queue <node*> q;
	q.push(start);
	while(q.size() > 0){
		node *focus = q.front();
		q.pop();
		node_stack -> push(focus);
		focus -> visited = true;
		for(int i = 0; i < focus -> adj.size(); i++){
			edge *e = focus -> adj.at(i);
			if(!e -> dest -> visited)
				q.push(e -> dest);
		}
	}
}

void dfs(node *start, stack <node*> *node_stack){
	if(!start -> visited){
		node_stack -> push(start);
		start -> visited = true;
		for(int i = 0; i < start -> adj.size(); i++)
			dfs(start -> adj.at(i) -> dest, node_stack);
	}
}

node* get_end(node *start){
	stack <node*> node_stack;
	bfs(start,&node_stack);
	while(!node_stack.top() -> letter)
		node_stack.pop();
	if(node_stack.size() > 0)
		return node_stack.top();
	return NULL;
}

node* get_root(node *start){
	stack <node*> node_stack;
	dfs(start, &node_stack);
	while(!node_stack.top() -> letter)
		node_stack.pop();
	if(node_stack.size() > 0){
		return node_stack.top();
	}
	return NULL;
}

bool trim(node *focus){
	if(focus -> visited)
		return false;
	focus -> visited = true;
	bool found_letter = focus -> letter;
	for(int i = 0; i < focus -> adj.size(); i++){
		edge *e = focus -> adj.at(i);
		if(trim(e -> dest))
			found_letter = true;
	}
	if(!found_letter)
		focus -> distance = -2;
	return found_letter;
}

int get_weight(node *root){
	int total_weight = 0;
	root -> visited = true;
	for(int i = 0; i < root -> adj.size(); i++){
		edge *e = root -> adj.at(i);
		if(!e -> dest -> visited)
			total_weight += get_weight(e -> dest) + e -> weight;
	}
	return total_weight;
}

int dijkstra(node *start, node *end){
	priority_queue < node*, vector <node*>, compare_nodes > pq;
	pq.push(start);
	start -> distance = 0;
	while(pq.size() > 0){
		node *focus = pq.top();
		pq.pop();
		focus -> visited = true;
		if(focus == end)
			return end -> distance;
		for(int i = 0; i < focus -> adj.size(); i++){
			edge *e = focus -> adj.at(i);
			if(focus -> distance + e -> weight < e -> dest -> distance)
				e -> dest -> distance = focus -> distance + e -> weight;
			if(!e -> dest -> visited)
				pq.push(e -> dest);
		}
	}
	return -1;
}

int main(){
	int N, L;
	cin >> N >> L;
	node* cities[N];
	for(int i = 0; i < N; i++)
		cities[i] = new node(i+1);
	for(int i = 0; i < L; i++){
		int index; cin >> index;
		cities[index-1] -> letter = true;
	}
	for(int i = 0; i < N-1; i++){
		int src,dest,weight;
		cin >> src >> dest >> weight;
		add_edge(cities[src-1],cities[dest-1],weight);
	}
	node *root = get_root(cities[0]);
	node::reset();
	trim(root);
	for(int i = 0; i < N; i++){
		if(cities[i] -> distance == -2)
			continue;
		for(int j = 0; j < cities[i] -> adj.size(); j++){
			node *neighbor = cities[i] -> adj.at(j) -> dest;
			if(neighbor -> distance == -2){
				//cout << "cut at: " << neighbor -> id << endl;
				cities[i] -> adj.erase(cities[i] -> adj.begin()+j);
				j--;
			}
		}
	}
	node::reset();
	node *start = get_end(root);
	node::reset();
	node *end = get_end(start);
	node::reset();
	int weight = get_weight(root);
	node::reset();
	int distance = dijkstra(start,end);
	//cout << "root: " << root -> id << endl;
	//cout << "start: " << start -> id << " end: " << end -> id << endl;
	//cout << "distance: " << distance << " weight: " << weight << endl;
	cout << weight*2 - distance << endl;
	return 0;
}