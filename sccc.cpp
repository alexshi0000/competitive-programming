#include <bits/stdc++.h>
using namespace std;

typedef struct node node;
node *trie = NULL;
struct node{
	char letter, end;
	node **arr;
};

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

void destruct(node *root)
{
	if (root == NULL)
		return;
	if (root->arr != NULL) {
		for (int i = 0; i < 128; i ++) {
			if (root->arr[i] != NULL) {
				destruct(root->arr[i]);
			}
		}
	}
	free(root);
}

void insert(node *root, const char *str, int idx, int len, int *query)
{
	if (idx < len) {
		if (root->arr == NULL) {
			root->arr = (node**)malloc(sizeof(node*)*128);
			memset(root->arr, NULL, sizeof(node*)*128);
		}
		if (root->arr[(int)str[idx]] == NULL) {
			root->arr[(int)str[idx]]  = (node*)malloc(sizeof(node));
			*root->arr[(int)str[idx]] = (node){
				.letter = str[idx],
				.end    = 0,		//set this later
				.arr    = NULL
			};
			*query = 1;
		}
		if (idx == len-1 && !root->arr[(int)str[idx]]->end)
			*query = 1;
		root->arr[(int)str[idx]]->end |= idx == len-1;
		insert(root->arr[(int)str[idx]], str, idx + 1, len, query);
	}
}

/*
 * use insert to return the number of distinct substrings that can be created with the current string
 */

long sb_cnt(string str)
{
	long cnt = 0;
	int len = 1;
	int l = 0;
	while (len <= str.size()) {
		if (l + len > str.size()) {
			len++;
			l = 0;
			continue;
		}
		int distinct = 0;
		insert(trie, str.substr(l, len).c_str(), 0, str.substr(l, len).size(), &distinct);
		cnt += distinct;
		l++;
	}/*
	if (str.size() > 0) {
		int distinct = 0;
		insert(trie, str.c_str(), 0, str.size(), &distinct);
		if (distinct) {
			//traverse(trie);
			//printf("\n");
			return 1 + sb_cnt(str.substr(0, str.size()-1)) + sb_cnt(str.substr(1, str.size()-1));
		}
	}*/
	return cnt;
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
	}
	return 0;
}