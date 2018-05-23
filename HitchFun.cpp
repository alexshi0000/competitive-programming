#include<bits/stdc++.h>
using namespace std;
class node;
class edge{
public:
	bool danger;
	node *src, *dst;
	edge(node *src,node *dst, bool danger){
		this->src = src;
		this->dst = dst;
		this->danger = danger;
	}
	~edge(){}
};
class node{
public:
	int dist, danger, id;
	vector<edge*> adj;
	bool visited;
	node(int id){
		this->id = id;
		visited = false;
		dist = 2000000000;
		danger = 2000000000;
	}
	~node(){}
};

int bfs(node *src, node *dst){
	queue<node*> q;
	q.push(src);
	src->dist = 0;
	src->danger = 0;
	bool found = false;
	while(q.size() > 0){
		node *focus = q.front();
		q.pop();
		if(focus == dst)
			found = true;
		for(int i = 0; i < focus->adj.size(); i++){
			node *dst = focus->adj.at(i)->dst;
			bool danger = focus->adj.at(i)->danger;
			if(danger){
				if(dst->danger > 1+focus->danger){
					dst->danger = focus->danger+1;
					dst->dist = focus->dist+1;
					q.push(dst);
				}
				else if(dst->danger == 1+focus->danger && dst->dist > 1+focus->dist){
					dst->dist = 1+focus->dist;
					q.push(dst);
				}
			}
			else{
				if(dst->danger > focus->danger){
					dst->danger = focus->danger;
					dst->dist = focus->dist+1;
					q.push(dst);
				}
				else if(dst->danger == focus->danger && dst->dist > 1+focus->dist){
					dst->dist = 1+focus->dist;
					q.push(dst);
				}
			}
		}
	}
	if(found)
		return 0;
	return -1;
}
int main(){
	int n,m;
	cin >> n >> m;
	node **nodes = (node**) malloc(sizeof(node*)*n);
	for(int i = 0; i < n; i++)
		nodes[i] = new node(i+1);
	for(int i = 0; i < m; i++){
		int src,dst,danger;
		scanf("%d",&src);
		scanf("%d",&dst);
		scanf("%d",&danger);
		nodes[src-1]->adj.push_back(new edge(nodes[src-1],nodes[dst-1],danger==1));
		nodes[dst-1]->adj.push_back(new edge(nodes[dst-1],nodes[src-1],danger==1));
	}
	if(bfs(nodes[0],nodes[n-1]) != -1)
		cout<<nodes[n-1]->danger<<" "<<nodes[n-1]->dist<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}