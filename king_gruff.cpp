
#include <bits/stdc++.h>
using namespace std;

struct node;
struct edge;
vector <edge*> all_edges;

struct edge{
	node *src, *dst;
	long len, cost;
	edge(node *s, node *d, long l, long c)
	{
		src = s;
		dst = d;
		len = l;
		cost = c;
	}
};

struct node{
	vector <edge*> fwd;
	vector <edge*> bck;
	long id, fwd_len, bck_len;
	node(int i)
	{
		id = i;
		fwd_len = LONG_MAX / 2; //not to be confused with llong_max
		bck_len = LONG_MAX / 2; //prevent overflow
	}
};

void add_edge(node *src, node *dst, long len, long cost)
{
	edge *fwd = new edge(src, dst, len, cost);
	src->fwd.push_back(fwd);
	all_edges.push_back(fwd);
	dst->bck.push_back(new edge(dst, src, len, cost));
}

struct functor{
	bool operator()(edge *a, edge *b)
	{
		return a->src->fwd_len + a->len + a->dst->bck_len <
			b->src->fwd_len + b->len + b->dst->bck_len;
	}
} cmpr;

void dijkstra(node *src, node *dst, char fwd)
{
	queue <node*> q;
	q.push(src);
	if (fwd)
		src->fwd_len = 0;
	else
		src->bck_len = 0;
	while (q.size() > 0) {
		node *focus = q.front();
		q.pop();
		if (fwd) {
			for (int i = 0; i < focus->fwd.size(); i++) {
				edge *e = focus->fwd.at(i);
				if (e->len + focus->fwd_len >= e->dst->fwd_len)
					continue;
				e->dst->fwd_len = e->len + focus->fwd_len;
				q.push(e->dst);
			}
		}
		else {
			for (int i = 0; i < focus->bck.size(); i++) {
				edge *e = focus->bck.at(i);
				if (e->len + focus->bck_len >= e->dst->bck_len)
					continue;
				e->dst->bck_len = e->len + focus->bck_len;
				q.push(e->dst);
			}
		}
	}
}

int main()
{
	int n, m, a, b, q;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	node* arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = new node(i+1);
	for (int i = 0; i < m; i++) {
		int src, dst;
		long len, cost;
		scanf("%d %d %ld %ld", &src, &dst, &len, &cost);
		add_edge(arr[src-1], arr[dst-1], len, cost);
	}

	dijkstra(arr[a-1], arr[b-1], 1);
	dijkstra(arr[b-1], arr[a-1], 0);
	sort(all_edges.begin(), all_edges.end(), cmpr);
	/*
	printf("forward\n");
	for (int i = 0; i < n; i++)
		printf("%d: %ld, ", i+1, arr[i]->fwd_len);
	printf("\n");
	printf("backward\n");
	for (int i = 0; i < n; i++)
		printf("%d: %ld, ", i+1, arr[i]->bck_len);
	printf("\n");
	*/
	long dist[all_edges.size()];//first = len, second = cost
	long cost[all_edges.size()];
	for (int i = 0; i < all_edges.size(); i++) {
		edge *e = all_edges.at(i);
		long len = e->src->fwd_len + 
			e->len + e->dst->bck_len;
		dist[i] = len;
		cost[i] = (i > 0 ? cost[i-1] : 0) + 
			all_edges.at(i)->cost; 
		cout << cost[i] << " ";
	}
	cout << endl;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		long d, *t_cost = 0;
		scanf("%ld", &d);
		t_cost = upper_bound(dist, dist + all_edges.size(), d);
		if (t_cost-dist-1 < 0)
			printf("0\n");
		else
			printf("%ld\n", cost[t_cost-dist-1]);
	}
	return 0;
}