#include <bits/stdc++.h>
using namespace std;

struct node;
node *node_start = NULL, *node_end = NULL;
int active = 0;
vector <node*> all;
stack <node*> recursion;

struct node{
	vector <node*> adj;
	char visited, pho, leaf;
	int dist, id;
	node(int i)
	{
		id = i;
		pho = 0;
		visited = 0;
		dist = INT_MAX;
		leaf = 0;
		all.push_back(this);
	}
};

void reset()
{
	for (int i = 0; i < all.size(); i++) {
		all.at(i)->visited = 0;
		all.at(i)->dist = INT_MAX;
	}
}

char dfs(node *start)
{
	if (start->visited)
		return 0;
	start->visited = 1;
	char found = start->pho;
	for (int i = 0; i < start->adj.size(); i++) {
		if (dfs(start->adj.at(i)))
			found = 1;
	}
	if (!found) {
		start->leaf = 1;
		active--;
	}
	return found;
}

void get_end(node *start)
{
	queue <node*> q;
	start->dist = 0;
	q.push(start);
	while (q.size() > 0) {
		node *focus = q.front();
		q.pop();
		recursion.push(focus);
		focus->visited = 1;
		for (int i = 0; i < focus->adj.size(); i++) {
			node *n = focus->adj.at(i);
			if (!n->visited && !n->leaf)
				q.push(n);
		}
	}
}

int bfs(node *start, node *end)
{
	queue <node*> q;
	start->dist = 0;
	q.push(start);
	while (q.size() > 0) {
		node *focus = q.front();
		q.pop();
		focus->visited = 1;
		if (focus == end)
			return focus->dist;
		for (int i = 0; i < focus->adj.size(); i++) {
			node *n = focus->adj.at(i);
			if (!n->leaf && !n->visited) {
				n->dist = focus->dist + 1;
				q.push(n);
			}
		}
	}
	return -1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int start = 0;
	active = n;
	node* arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = new node(i);
	for (int i = 0; i < m; i++) {
		int restaurant;
		scanf("%d", &restaurant);
		arr[restaurant]->pho = 1;
		if (start == 0)
			start = restaurant;
	}
	for (int i = 0; i  < n-1; i++) {
		int src, dst;
		scanf("%d %d", &src, &dst);
		arr[src]->adj.push_back(arr[dst]);
		arr[dst]->adj.push_back(arr[src]);
	}
	dfs(arr[start]);
	reset();
	get_end(arr[start]);
	node_start = recursion.top();
	recursion.pop();
	reset();

	recursion = std::stack <node*> ();
	get_end(node_start);
	node_end = recursion.top();
	recursion.pop();
	reset();

	int diameter = bfs(node_start, node_end);
	printf("%d", (active-1) * 2 - diameter);
	return 0;
}