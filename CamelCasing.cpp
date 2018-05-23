#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		bool end;
		char letter;
		vector <Node*> adj;
		Node(char letter){
			this -> letter = letter;
			end = false;
		}
};

bool contains(vector <Node*> *dictionary, char c){
	for(int i = 0; i < dictionary -> size(); i++){
		if(c == dictionary -> at(i) -> letter) 
			return true;
	}
	return false;
}

Node *root = new Node('~');
	//the root has several characters but it is not a character

void insert_string(Node *focus, string s, int index){
		//insert a string to trie
	if(index >= s.length())
		return;
	for(int i = 0; i < focus -> adj.size(); i++){
		if(index == s.length()-1 && focus -> adj.at(i) -> letter == s[index]){
			focus -> adj.at(i) -> end = true;
			return;
		}
		else if(focus -> adj.at(i) -> letter == s[index]){
			insert_string(focus -> adj.at(i), s, index+1);
			return;
		}
	}
	if(index == s.length()-1){
		focus -> adj.push_back(new Node(s[index]));
		focus -> adj.at(focus -> adj.size() - 1) -> end = true;
		return;
	}
	focus -> adj.push_back(new Node(s[index]));
	insert_string(focus -> adj.at(focus -> adj.size()-1), s, index+1);
}

void traverse_trie(Node *root, string word){
		//debug tool
	if(root -> end){
		cout << word << endl;
	}
	if(root -> adj.size() == 0)
		return;
	for(int i = 0; i < root -> adj.size(); i++){
		traverse_trie(root -> adj.at(i), word + root -> adj.at(i) -> letter);
	}
}

bool has_string(Node *focus, string s, int index){
	for(int i = 0; i < focus -> adj.size(); i++){
		char c = focus -> adj.at(i) -> letter;
		if(c == s[index] && index == s.length()-1 && focus -> adj.at(i) -> end){
			return true;
		}
		else if(c == s[index])
			return has_string(focus -> adj.at(i), s, index+1);
	}
	return false;
}

string substring(string s, int l, int r){
	return s.substr(l,r-l);
}

int main(){
	freopen("/home/lx_user/Documents/programming/in.txt","r",stdin);
	int n; cin >> n;
	int longest = 0;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		insert_string(root,s,0); 
		if(s.length() > longest)
			longest = s.length();
	}
	for(int i = 0; i < 4; i++){
		string camel; cin >> camel;
		n = camel.length();
			//change the value of n to length of string
		int memo[n];
		for(int r = 0; r < n; r++){
			if(has_string(root,substring(camel,0,r+1),0))
				memo[r] = 1;
			else if(r > 0){
				int mini = 2000000;
				for(int p = r; p >= 1; p--){
					if(memo[p-1] != -1 && has_string(root, substring(camel, p, r+1),0))
						mini = min(memo[p-1] + 1, mini); 
					if(r+1 - p > longest)
						break;
				}
				memo[r] = mini;
			}
		}
		cout << memo[n-1] -1 << endl;
	}
	return 0;
}