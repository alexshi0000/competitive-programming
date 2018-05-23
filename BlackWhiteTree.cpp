#include <bits/stdc++.h>
using namespace std;
class node{
	public:
		bool is_black, visited;		//true for black, and false for white
		vector<node*> adj;
		int white, black, id, size;			//remember black and white always mean max
		node *parent;
		node(bool is_black, int id){
			this->is_black = is_black;
			this->id = id;
			white = 0;
			black = 0;
			visited = false;
			parent = nullptr;
			size = 1;						//self included
		}
		~node(){}//nothing
};
void max_strange(node *root, bool is_black_str){
	if(!root->visited){
		root->visited = true;
		int black = 0, white = 0;
		for(int i = 0; i < root->adj.size(); i++){
			max_strange(root->adj.at(i),is_black_str);
			if(is_black_str){
				if(root->adj.at(i)->black - root->adj.at(i)->white > 0){
					root->adj.at(i)->parent = root;
					black+=root->adj.at(i)->black;
					white+=root->adj.at(i)->white;
				}
			}
			else{
				if(root->adj.at(i)->white - root->adj.at(i)->black > 0){
					root->adj.at(i)->parent = root;
					black+=root->adj.at(i)->black;
					white+=root->adj.at(i)->white;
				}
			}
		}
		if(root->is_black)
			black++;
		else
			white++;
		root->black = black;
		root->white = white;
	}
}
int get_max_strange(node ***arr, int n){
	int max_str = -1;
	int idx = -1;
	for(int i = 0; i < n; i++){
		if(max_str < abs((*arr)[i]->white - (*arr)[i]->black)){
			max_str = abs((*arr)[i]->white - (*arr)[i]->black);
			idx = i;
		}
	}
	return idx;
}
int st_size(node *root, string *s){
	//sub tree counting
	(*s) += to_string(root->id)+" ";
	int st_counter = 1;
	for(int i = 0; i < root->adj.size(); i++){
		node *focus = root->adj.at(i);
		if(focus->parent == root){
			st_size(focus, s);
			st_counter += focus->size;
		}
	}
	root->size = st_counter;
	return root->size;
}
void traverse(node *root){
	cout<<"id: "<<root->id<<" strangeness: "<<abs(root->white-root->black)<<endl;
	for(int i = 0; i < root->adj.size(); i++){
		node *focus = root->adj.at(i);
		if(focus->parent == root)
			traverse(focus);
	}
}
int main(){
	int n;
	cin >> n;
	node **nodes = (node**) malloc(sizeof(node*)*n);
	for(int i = 0; i < n; i++){
		int type;
		cin >> type;
		if(type == 1)
			nodes[i] = new node(true,i+1);
		else
			nodes[i] = new node(false,i+1);
	}
	for(int i = 0; i < n-1; i++){
		int src,dst;
		cin >> src >> dst;
		nodes[src-1]->adj.push_back(nodes[dst-1]);
		nodes[dst-1]->adj.push_back(nodes[src-1]);
	}
	max_strange(nodes[0], true);			//builds the segment tree with strange amounts
	string max_st_b_str = "";
	string max_st_w_str = "";
	int max_st_b_idx = get_max_strange(&nodes,n);
	int max_st_b_amt = abs(nodes[max_st_b_idx]->white - nodes[max_st_b_idx]->black);
	int max_st_b_size = st_size(nodes[max_st_b_idx], &max_st_b_str);
	for(int i = 0; i < n; i++){
		nodes[i]->black = 0;
		nodes[i]->white = 0;
		nodes[i]->visited = false;
		nodes[i]->parent = nullptr;
		nodes[i]->size = 1;
	}
	//======= repreat of previous routine with white strange version
	max_strange(nodes[0], false);
	int max_st_w_idx = get_max_strange(&nodes,n);
	int max_st_w_amt = abs(nodes[max_st_w_idx]->black - nodes[max_st_w_idx]->white);
	int max_st_w_size = st_size(nodes[max_st_w_idx], &max_st_w_str);
	//======= choose one with the more strange tree 
	if(max_st_b_amt > max_st_w_amt){
		cout << max_st_b_amt << endl;
		cout << max_st_b_size << endl;
		cout << max_st_b_str << endl;
	}
	else{
		cout << max_st_w_amt << endl;
		cout << max_st_w_size << endl;
		cout << max_st_w_str << endl;
	}
	return 0;
}