#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct node node;
node *trie = NULL;

struct node{
	char letter, end;
	node *arr;
};

void insert(node *root, char *str)
{

}

char query(node *root, char *str, int idx)
{

}

long sb_cnt(string str)
{
	long val = 0;
	if (!query(trie, str, 0)) {
		insert(trie, str);
		char *l = (char*)malloc(sizeof(char)*5001);
		char *r = (char*)malloc(sizeof(char)*5001);
		strcpy(l, str);
		val = 1 + sb_cnt(l), sb_cnt(r);
		free(l, r);
	}
	return val;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int test = 0; test < n; test++) {
		string str;
		scanf("%s", str);
		printf("%ld", sb_cnt(str));
	}
	return 0;
}