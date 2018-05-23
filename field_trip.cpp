#include <bits/stdc++.h>
using namespace std;

class node;
int N, M, K;

class node
{
	public:
		node *parent;
		vector<node*> adj;
		int size;
		node()
		{
			size = 1;											//size of this party
			parent = nullptr;
		}
		~node()
		{
			adj.clear();
			if(parent != nullptr)
			{
				delete parent;
			}
		}
};	

node* find(node *child)
{
	if(child->parent == nullptr)
	{
		return child;
	}
	return find(child->parent);
}

void _union(node *a, node *b)									//function name union is already taken by stl
{
	if(a->parent == nullptr && b->parent == nullptr)
	{
		b->parent = a;
		a->size += b->size;
	}
	else if(a->parent == nullptr && b->parent != nullptr)
	{
		node *b_parent = find(b);
		a->parent = b_parent;
		b_parent->size += a->size;
	}
	else if(a->parent != nullptr && b->parent == nullptr)
	{
		node *a_parent = find(a);
		b->parent = a_parent;
		a_parent->size += b->size;
	}
	else//(a->parent != nullptr && b->parent != nullptr)
	{
		node *a_parent = find(a);
		node *b_parent = find(b);	
		b_parent->parent = a_parent;
		a_parent->size += b_parent->size;
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	arr = (node**) malloc (sizeof(node*)*N);
	for(int i = 0; i < N; i++)
	{
		arr[i] = new node();
	}
	for(int i = 0; i < M; i++)
	{
		int a, b;
		_union(arr[a-1], arr[b-1]);
	}
}