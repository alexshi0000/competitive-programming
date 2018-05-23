#include <bits/stdc++.h>
using namespace std;

constexpr long MOD = 1000000007;								//global
map <string, long long> memo;

class node{
public:
	vector <node*> adj;
	string id;
	node *parent;
	node(string id){
		this->parent = NULL;
		this->id = id;
	}
};

void add_edge(node *src, node *dst){
	src->adj.push_back(dst);
	dst->adj.push_back(src);
}

long long find(node *root, int curr, int parent){
	if(root->adj.size() == 1 && root->adj.at(0) == root->parent){
		if(parent == curr)
			return 1;
		return 0;
	}
	long long solutions = 1;
	long long diff_solutions = 1;
	int n = root->adj.size();
	for(int i = 0; i < n; i++){
		node *focus = root->adj.at(i);
		if(focus != root->parent){
			focus->parent = root;
			long long same_color, diff_color;
			if(memo.find(focus->id+"@"+to_string(curr)+to_string(curr)) != memo.end()){
				same_color = memo[focus->id+"@"+to_string(curr)+to_string(curr)];
				diff_color = memo[focus->id+"@"+to_string(curr^1)+to_string(curr)];
			}
			else{
				same_color = find(focus,curr,curr);
				diff_color = find(focus,curr^1,curr);
				memo.insert(make_pair(focus->id+"@"+to_string(curr)+to_string(curr), same_color));
				memo.insert(make_pair(focus->id+"@"+to_string(curr^1)+to_string(curr), diff_color));
			}
			solutions = (solutions * (same_color + diff_color)) % MOD;
			diff_solutions = (diff_solutions * diff_color) % MOD;
		}
	}
	if(curr != parent)
		solutions = (solutions - diff_solutions + MOD) % MOD;
	return solutions;
}

int main(){
	int n;
	cin >> n;
	node **arr = (node**) malloc(sizeof(node*)*n);
	for(int i = 0; i < n; i++)
		arr[i] = new node(to_string(i+1));
	for(int i = 0; i < n-1; i++){
		int src, dst;
		cin >> src >> dst;
		add_edge(arr[src-1],arr[dst-1]);
	}
	cout << to_string((find(arr[0],0,1) + find(arr[0],1,0)) % MOD) << endl;
	return 0;
}