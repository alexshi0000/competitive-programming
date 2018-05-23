#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
 * notes:
 * if it doesnt pass the test cases for the lexicographic
 * ordering of the sequence, you can always just change
 * the way the nodes are being sorted in the priority queue
 *
 * sort by val, then by long longest path, then by index 
 */

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

typedef struct node node;
struct node{
	long long val, idx, path;
	node *prev;
};

node *head = NULL;
long long *memo, *arr, n, k;

void enqueue(node *entry)
{
	node **focus = &head;
	while ((*focus) != NULL && ((*focus)->val < entry->val || 
		((*focus)->val == entry->val && entry->path < (*focus)->path)))
		focus = &(*focus)->prev;
	node *tmp = *focus; 
	*focus  = entry;
	(*focus)->prev = tmp;
}

node* dequeue()
{
	node *ret = head;
	head = head->prev;
	return ret;
}

node* peek()
{
	return head;
}

node *new_node(long long val, long long idx, long long path)
{
	node *ret = (node*)malloc(sizeof(node));
	*ret = (node){
		.val = val,
		.idx = idx,
		.prev = NULL,
		.path = path
	};
	return ret;
}

long long hopscotch(long long *arr, long long *memo, long long n, long long k)
{
	if (k == n) {
		long long min_pw = 0x7FFFFFFF;
		long long idx = -1;
		for(int i = 0; i < k; i++) {
			if (min_pw > arr[i]) {
				min_pw = arr[i];
				idx = i;
			}
			memo[i] = -1;
		}
		memo[n] = idx;
		return min_pw;
	}
	else {
		long long *table = (long long*)malloc(sizeof(long long)*(n+1));
		for (long i = 0; i < k; i++) {
			table[i] = arr[i];
			memo[i]  = -1;
			enqueue(new_node(arr[i], i, 0));
		}
		//if there are memory issues, you can free(min_pw)
		for (long i = k; i <= n; i++) {
			node *min_pw = peek();
			while (i - min_pw->idx > k) {
				dequeue();
				min_pw = peek();
			}
			table[i] = min_pw->val;
			memo[i]  = min_pw->idx;
			if (i != n) {
				table[i] += arr[i];
				enqueue(new_node(table[i], i, min_pw->path+1));
			}
		}
		/*
		for (int i = 0; i <= n; i++) {
			printf("%lld ", table[i]);
		}
		printf("\n");
		*/
		return table[n];
	}
}

void print_steps(long long *memo, int step)
{
	if (memo[step] != -1) {
		print_steps(memo, memo[step]);
		printf("%lld ",memo[step]+1);
	}
}

int main()
{
	scanf("%lld %lld", &n, &k);
	if (k == 1) {
		long long sum = 0;
		long min_pw = 0x7FFFFFFF;
		long idx = 0;
		long *arr = (long*)malloc(sizeof(long)*n);
		for (long i = 0; i < n; i++) {
			scanf("%ld", &arr[i]);
			if (min_pw > arr[i]) {
				min_pw = arr[i];
				idx = i;
			}
			sum += arr[i];
		}
		printf("%lld\n", sum);
		for (long i = 0; i < n; i++) 
			printf("%ld ", i+1);
		printf("\n");
		free(arr);
		return 0;
	}
	arr  = (long long*)malloc(sizeof(long long)*n);
	memo = (long long*)malloc(sizeof(long long)*(n+1));
	for (long long i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	long long result = hopscotch(arr, memo, n, k);
	if (result != -1)
		printf("%lld\n", result);
	print_steps(memo, n);
	printf("\n");
	return 0;
}

/*
int naive (int *memo, int *arr, int n, int k)
{
	for (int i = 0; i < k; i++)
		memo[i] = arr[i];
	for (int i = k; i <= n; i++) {
		int min_pw = 0x7FFFFFFF;
		for (int j = i-1; j >= i-k; j--)
			min_pw = min(min_pw, memo[j]);
		if (i == n)
			memo[i] = min_pw;
		else
			memo[i] = min_pw + arr[i];
	}
	return memo[n];
}

int main()
{
	int n, k, *arr, *memo;
	scanf("%d %d", &n, &k);
	arr = (int*)malloc(sizeof(int)*n);
	memo = (int*)malloc(sizeof(int)*(n+1));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("least power used: %d\n", naive(memo, arr, n, k));
	free(arr);
	free(memo);
	return 0;
}
*/