#include <bits/stdc++.h>
using namespace std;

typedef struct node node;
node *trie = NULL;

struct node{
	char letter, end;
	node **arr;
};

void insert(node *root, const char *str, int idx, int len)
{
	if(idx < len){
		if (root->arr == NULL)
			root->arr    = (node**)malloc(sizeof(node*)*128);	//alphanumeric
		if (root->arr[(int)str[idx]] == NULL) {
			root->arr[(int)str[idx]]  = (node*)malloc(sizeof(node));
			*root->arr[(int)str[idx]] = (node){
				.letter = str[idx],
				.end    = 0,		//set this later
				.arr    = NULL
			};
		}
		root->arr[(int)str[idx]]->end |= idx == len-1;
		insert(root->arr[(int)str[idx]], str, idx + 1, len);
	}
}

char query(node *root, const char *str, int idx, int len)
{
	if (root->letter == '~' && root->arr != NULL && root->arr[(int)str[idx]] != NULL)
		return query(root->arr[(int)str[idx]], str, idx, len);
	if (idx == len-1 && root->letter == str[idx] && root->end)
		return 1;
	else if (root->letter == str[idx] && root->arr[(int)str[idx]] != NULL)
		return query(root->arr[(int)str[idx]], str, idx+1, len);
	return 0;
}

void traverse(node *root);
long sb_cnt(string str)
{
	long val = 0;
	if (!query(trie, str.c_str(), 0, str.size()) && str.size() > 0) {
		insert(trie, str.c_str(), 0, str.size());
		traverse(trie);
		printf("\n");
		val = 1 + sb_cnt(str.substr(1, str.size()-1)) + sb_cnt(str.substr(0,str.size()-1));
	}
	return val;
}

void traverse(node *root)		//debug
{
	printf("%c:%d ->", root->letter, root->end);
	if (root->arr != NULL) {
		for (int i = 0; i < 128; i++) {
			if (root->arr[i] != NULL)
				traverse(root->arr[i]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int test = 0; test < n; test++) {
		trie = (node*)malloc(sizeof(node));
		string str;
		cin >> str;
		*trie = (node){
			.letter = '~',
			.end    = 0,
			.arr    = NULL
		};
		printf("%ld\n", sb_cnt(str)+1);
		//figure out a way to destruct everything
		free(trie);
	}
	return 0;
}