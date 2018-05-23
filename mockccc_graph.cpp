#include <bits/stdc++.h>
using namespace std;

struct node{
	double sum;
	vector<edge*> adj;
	node(int sum)
	{
		this->sum = (double)sum;
	}
};

struct edge{
	node *dst
	double weight;
	edge(nodes *dst)
	{
		dst = dst;
		weight = -1;
	}
};

void add_edge(node *src, node *dst)
{
	src->adj.push_back(new edge(dst));
	dst->adj.push_back(new edge(src));
}

bool possible()
{

}

int main()
{
	return 0;
}