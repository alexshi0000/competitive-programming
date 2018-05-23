#include <bits/stdc++.h>
#define INF (2000000000)
using namespace std;
vector<vector<int>> graph;
bool *visited;
int  *bunny, *parent, n, r, x, y;
void construct(int root){
	int min_bun = bunny[root];
	for(int a: graph[root]){
		if(parent[root] != a){
			parent[a] = root;
			construct(a);
			min_bun = min(bunny[a]+1,min_bun);
		}
	}	
	bunny[root] = min_bun;
	if(root == x)
		return;
}
int get_min_bun(int src, int dst, int min_bun){
	visited[src] = true;
	int tp_min = bunny[src];
	for(int a: graph[src]){ 
		if(parent[src] != a && !visited[a] && tp_min > bunny[a]+1)
			tp_min = bunny[a]+1;
	}
	min_bun = min(min_bun,tp_min);
	if(src == dst)
		return min_bun;
	return get_min_bun( parent[src], dst, min_bun);
}
int main(){
	scanf("%d%d",&n,&r);
	graph   = vector<vector<int>> (n);		//init to n
	visited = (bool*) malloc(sizeof(bool)*n);
	parent  = (int*)  malloc(sizeof(int)*n);
	bunny   = (int*)  malloc(sizeof(int)*n);
	memset(visited, 0, sizeof(bool)*n);
	memset(parent, -1, sizeof(int)*n);
	fill(bunny+0,bunny+n,INF);
	for(int i = 0; i < n-1; i++){
		int src, dst;
		scanf("%d%d", &src, &dst);
		graph[src-1].push_back(dst-1);
		graph[dst-1].push_back(src-1);
	}
	for(int i = 0; i < r; i++){
		int bun;
		scanf("%d", &bun);
		bunny[bun-1] = 0;
	}
	scanf("%d%d", &x, &y);
	construct(y-1);
	printf("%d\n", get_min_bun(x-1, y-1, INF));
}
/*
class node{
	public:
		vector <node*> adj;
		bool visited;
		int bunny, id;
		node *parent;
		node(int id){
			this->id = id;
			bunny = INF;
			visited = false;
			parent  = NULL;
		}
};
void add_edge(node *a, node *b){
	a->adj.push_back(b);
	b->adj.push_back(a);
}
void construct_path( node *focus){			//get the parents for the path that it will take
	for(node *a: focus->adj){
		if(focus->parent != a){
			a->parent = focus;
			construct_path(a);
		}
	}
}
int min_dist_util( node *focus){
	int min_dist = focus->bunny;
	for(node *a: focus->adj){
		if(!a->visited && a != focus->parent){
			min_dist_util(a);
			if(a->bunny+1 < min_dist)
				min_dist = a->bunny+1;
		}
	}	
	focus->bunny = min_dist;
}
int min_dist( node *src, node *dst, int min_bun){
	src->visited = true;
	min_dist_util(src);
	min_bun = min(min_bun, src->bunny);
	if(src == dst)
		return min_bun;
	return min_dist(src->parent, dst, min_bun);
}
int main() {
	node **arr;
	int n, r, x, y;
	cin>>n>>r;
	arr = (node**)malloc(sizeof(node*)*n);
	for(int i = 0; i < n; i++)
		arr[i] = new node(i+1);
	for(int i = 0; i < n-1; i++){
		int src,dst;
		cin>>src>>dst;
		add_edge(arr[src-1],arr[dst-1]);
	}
	for(int i = 0; i < r; i++){
		int bun;
		cin>>bun;
		arr[bun-1]->bunny = 0;
	}
	cin>>x>>y;
	construct_path(arr[y-1]);
	cout<<min_dist( arr[x-1], arr[y-1], INF)<<endl;
}*/

//tried to optimize the above code