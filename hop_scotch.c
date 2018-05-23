#include <stdlib.h>
#include <stdio.h>
#include <math.h>	//link with math lib -lm
#include <string.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
#define INF (0x7FFFFFF76B48C000)	//for long64

typedef struct node node;
typedef long long int long64;
struct node{
	long long val, idx, path;
	node *prev;
};

node *head = NULL;
void enqueue(node *entry, int idx, int k)
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
	//don't forget to free from heap after this
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

long64 hopscotch(long64 *arr, int *memo, int n, int k)
{
	long64 table[n+1];
	for (long i = 0; i < k; i++) {
		table[i] = arr[i];
		memo[i]  = -1;
		enqueue(new_node(arr[i], i, 0));
	}
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
	return table[n];
}

void print_steps(int *memo, int step)
{
	if (memo[step] != -1) {
		print_steps(memo, memo[step]);
		printf("%d ",memo[step]+1);
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	long64 arr[n];
	if (k == 1) {
		long64 sum = 0;
		long64 min_pw = INF;
		int idx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			if (min_pw > arr[i]) {
				min_pw = arr[i];
				idx = i;
			}
			sum += arr[i];
		}
		printf("%lld\n", sum);
		for (int i = 0; i < n; i++)
			printf("%d ", i+1);
		printf("\n");
		return 0;
	}
	else if (k == n) {
		long64 min_pw = INF;
		int idx = -1;
		for (int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		for (int i = 0; i < k; i++) {
			if (min_pw > arr[i]) {
				min_pw = arr[i];
				idx = i;
			}
		}
		printf("%lld\n", min_pw);
		printf("%d\n", idx+1);
	}
	else if (k <= sqrt(n)) {

		/*
		long64 table[n+1];
		int memo[n+1];
		int path_size[n+1];
		for (int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		for (int i = 0; i < k; i++) {
			table[i] = arr[i];
			memo[i] = -1;
			path_size[i] = 0;
		}
		for (int i = k; i <= n; i++) {
			long64 min_pw = INF;
			int max_path_size = 0;
			int max_idx;
			int idx = -1;
			for (int j = i-1; j >= i-k; j--) {
				if (table[j] < min_pw) {
					min_pw = table[j];
					max_path_size = path_size[j];
					max_idx = j;
					idx = j;
				}
				else if (table[j] == min_pw && max_path_size < path_size[j]) {
					min_pw = table[j];
					max_path_size = path_size[j];
					max_idx = j;
					idx = j;
				}
				//j is already max val if we are looking from back to front
			}
			table[i] = table[idx];
			memo[i] = idx;
			path_size[i] = path_size[idx];
			if (i != n) {
				//not last one yet
				table[i] += arr[i];
			}
		}
		printf("%lld\n", table[n]);
		print_steps(memo, n);
		printf("\n");
		*/

	}

	return 0;

}
