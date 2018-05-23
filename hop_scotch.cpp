#include <bits/stdc++.h>
using namespace std;
#define INF (0x7FFFFFF76B48C000)	//for long64

void print_steps(int *memo, int step)
{
	int mp = memo[step];
	if (mp != -1) {
		print_steps(memo, mp);
		printf("%d ", mp+1);
	}
}

struct comparator{
	bool operator()(node *a, node *b)
	{
		if (b->val < a->val)
			return 1;
		else if (b->val == a->val && b->path > a->path)
			return 1; 
		return 0;
	}
};

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
	else {
		long64 table[n+1];
		int memo[n+1];
		priority_queue<node*, vector<node*>,comparator> pq;
		for (int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		for (int i = 0; i < k; i++) {
			table[i] = arr[i];
			memo[i]  = -1;
			pq.push(new_node(arr[i], i, 0));
		}
		for (int i = k; i <= n; i++) {
			node *min_pw = pq.top();
			while (min_pw->idx < i-k) {
				pq.pop();
				min_pw = pq.top();
			}
			table[i] = min_pw->val;
			memo[i]  = min_pw->idx;
			if (i != n) {
				table[i] += arr[i];
				pq.push(new_node(table[i], i, min_pw->path+1));
			}
		}
		printf("%lld\n", table[n]);
		print_steps(memo, n);
		printf("\n");
	}
	return 0;

}
