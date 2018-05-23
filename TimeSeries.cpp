#include <bits/stdc++.h>
using namespace std;

class node;
node *price_root = nullptr;				//out roots
node *time_root = nullptr;

class node{
	public:
		static int id_count;
		node *left, *right, *parent;
		int price, time, id;
		node(int time, int price){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			this->time = time;
			this->price = price;
			id = id_count;
			id_count++;
		}
		~node(){
			delete left;
			delete right;
		}
};

int node::id_count = 0;

int find_min_util(node *root, int value, int tmp_min, bool time_tree, int last){
	if(time_tree){
		if(root == nullptr)
			return tmp_min;
		if(root->time <= last)
			return tmp_min;
		if(root->time >= value && root->price > tmp_min)			//for the time tmp_min is actually a max{
			tmp_min = root->price;
		return max(find_min_util(root->left, value, tmp_min, time_tree, last), find_min_util(root->right, value, tmp_min, time_tree, last)); 
	}
	else{
		if(root == nullptr)
			return tmp_min;
		if(root->price <= last)
			return tmp_min;
		if(root->price >= value && root->time < tmp_min)
			tmp_min = root->time;
		return min(find_min_util(root->left, value, tmp_min, time_tree, last), find_min_util(root->right, value, tmp_min, time_tree, last)); 
	}
}

int find_min(node *root, int value, bool time_tree){
	if(root == nullptr)
		return -1;
	if(time_tree){
		if(root->time < value)
			return find_min(root->right, value, time_tree);
		else{
			if(root->parent != nullptr)
				return find_min_util(root, value, -2000000000, time_tree, root->parent->time);
			else
				return find_min_util(root, value, -2000000000, time_tree, -2000000000);
		}
	}
	else{
		if(root->price < value)
			return find_min(root->right, value, time_tree);
		else{
			if(root->parent != nullptr)
				return find_min_util(root, value, 2000000000, time_tree, root->parent->price);
			else
				return find_min_util(root, value, 2000000000, time_tree, -2000000000);
		}
	}
}

int query(int type, int value){			//value could possibly be price or time
	int minimum;
	if(type == 1)
		minimum = find_min(price_root, value, false);
	else
		minimum = find_min(time_root, value, true);
	if(minimum == 200000000 || minimum == -2000000000)
		return -1;						//not possible
	return minimum;
}

void insert(node **root, node *entry, bool time_tree, node *parent){
	if((*root) == nullptr){
		(*root) = entry;
		(*root)->parent = parent;
	}
	else{
		if(time_tree){
			if(entry->time < (*root)->time)
				insert(&(*root)->left, entry, time_tree, (*root));
			else
				insert(&(*root)->right, entry, time_tree, (*root));
		}
		else{
			if(entry->price < (*root)->price)
				insert(&(*root)->left, entry, time_tree, (*root));
			else
				insert(&(*root)->right, entry, time_tree, (*root));
		}
	}
}

void traverse(node *root){
	if(root != nullptr){
		cout << "time: " << root->time << " price: " << root->price << endl;
		traverse(root->left);
		traverse(root->right);
	}
}

int main(){
	int max_time = -2000000000;
	int max_price = -2000000000;
	int n, q;
	cin >> n >> q;
	int *time_stamp = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){
		cin >> time_stamp[i];
		if(time_stamp[i] > max_time)
			max_time = time_stamp[i]; 
	}
	for(int i = 0; i < n; i++){
		int p;														//price of the stock
		cin >> p;
		if(p > max_price)
			max_price = p;
		insert(&price_root, new node(time_stamp[i], p), false, nullptr);
		insert(&time_root, new node(time_stamp[i], p), true, nullptr);		//true for time tree, false for price tree
	}
	free(time_stamp);												//no more need for time_stamp	
	//queries
	for(int i = 0; i < q; i++){
		int type, value;
		cin >> type >> value;
		if((type == 1 && value > max_price) || (type == 2 && value > max_time))
			cout << "-1" << endl;
		else
			cout << query(type, value) << endl;
	}
	//garbage collection
	delete time_root;
	delete price_root;
	return 0;
}