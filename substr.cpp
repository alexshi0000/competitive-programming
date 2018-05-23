#include <bits/stdc++.h>
using namespace std;
class node;
void insertk(node *root, char *str, int idx, int len, long *distinct);
class node{
public:
	node *head, *tail, *next;
	char letter;
	node(char letter){
		this->letter = letter;
		next = NULL;
		head = NULL;
		tail = NULL;
	}
	void insert(char c, char *str, int idx, int len, long *distinct)
	{
		if (head == NULL) {
			head = new node(c);
			tail = head;
		} else {
			tail->next = new node(c);
			tail = tail->next;
		}
		insertk(tail, str, idx, len, distinct);
	}
	node* find(char c)
	{
		node *ret = head;
		while (ret != NULL && ret->letter != c)
			ret = ret->next;
		return ret;
	}
};
node *trie = NULL;
void insertk(node *root, char *str, int idx, int len, long *distinct)	//root is fucking null
{
	if (idx < len) {
		if (root->find(str[idx])) {
			insertk(root->find(str[idx]), str, idx+1, len, distinct);
		} else {
			(*distinct)++;
			root->insert(str[idx], str, idx+1, len, distinct);
		}
	}
}
long sb_cnt(char *str)
{
	long distinct = 0;
	int i = 0;
	while (i < strlen(str)) {
		insertk(trie, str, i, strlen(str), &distinct);
		i++;
	}
	return distinct;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int test = 0; test < n; test++) {
		trie = new node('~');
		char str[5001];
		scanf("%s", str);
		printf("%ld\n", sb_cnt(str) + 1);
		delete trie;
	}
	return 0;
}
