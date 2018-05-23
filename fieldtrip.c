#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct node node;
node **arr;

int N, M, K, total = 0, sever = 0;

struct node
{
	node *parent;
	char visited;
	char cycle;
	int children;
};

node* find(node *a)
{
	if(a->parent == NULL)
	{
		return a;
	}
	return find(a->parent);
}

void union_(node *a, node *b)
{
	node *par_a = find(a);
	node *par_b = find(b);
	if(par_a == par_b)
	{
		par_a->cycle = 1;
	}
	else{
		if(a->parent == NULL && b->parent == NULL)
		{
			b->parent = a;
			a->children += b->children;
		}
		else if(a->parent == NULL && b->parent != NULL)
		{
			a->parent = par_b;
			par_b->children += a->children;
		}
		else if(a->parent != NULL && b->parent == NULL)
		{
			b->parent = par_a;
			par_a->children += b->children;
		}
		else
		{
			par_b->parent = par_a;
			par_a->children += par_b->children;
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	arr = (node**)malloc(sizeof(node*)*N);
	for(int i = 0; i < N; i++)
	{
		arr[i] = (node*)malloc(sizeof(node));
		*arr[i] = (node)
		{
			.parent   = NULL,
			.visited  = 0,
			.cycle    = 0,
			.children = 1			//one including itself
		};
	}
	for(int i = 0; i < M; i++)
	{
		int src, dst;
		scanf("%d %d", &src, &dst);
		union_(arr[src-1], arr[dst-1]);
	}
	for(int i = 0; i < N; i++)
	{
		if(arr[i]->parent == NULL)
		{
			total += (arr[i]->children/K)*K;
			if(arr[i]->children > K)
			{
				sever += arr[i]->cycle + (arr[i]->children/K) - 1;
				if(arr[i]->children % K != 0)
				{
					sever++;
				}
			}
		}
	}
	printf("%d %d\n", total, sever);
	return 0;
}