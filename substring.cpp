#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct node node;
node *trie = NULL;
struct node{
	node **arr;
};
void destruct(node *root)
{
	if (root == NULL)
		return;
	if (root->arr != NULL) {
		for (int i = 0; i < 26; i ++) {
			if (root->arr[i] != NULL) {
				destruct(root->arr[i]);
			}
		}
	}
	free(root);
}
void insert(node *root, const char *str, int idx, int len, long *distinct)
{
	if (idx < len) {
		int mod_idx = 0;
		if (str[idx] < 97)
			mod_idx = str[idx]-'A';
		else
			mod_idx = str[idx]-'a';
		if (root->arr == 0) {
			root->arr = (node**)malloc(sizeof(node*)*26);
			memset(root->arr, 0, sizeof(node*)*26);
		}
		if (root->arr[mod_idx] == 0) {
			root->arr[mod_idx]  = (node*)malloc(sizeof(node));
			*root->arr[mod_idx] = (node){ .arr = 0};
			(*distinct)++;
		}
		insert(root->arr[mod_idx], str, idx+1, len, distinct);
	}
}
long sb_cnt(const char *str)
{
	long distinct = 0;
	for (int i = 0; i < strlen(str); i++)
		insert(trie, str, i, strlen(str), &distinct);
	return distinct;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int test = 0; test < n; test++) {
		trie = (node*)malloc(sizeof(node));
		*trie = (node){ .arr = 0};
		char str[5001];
		scanf("%s", str);
		printf("%ld\n", sb_cnt(str)+1);
		destruct(trie);
	}
	return 0;
}