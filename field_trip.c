#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int N, M, K;
typedef struct node node;
//forward declare struct node

node **arr;

struct node
{
	node **adj;
	node *parent;
	int idx, id;
	char visited;
};

void add_edge(node* a, node* b)
{
	a->adj[a->idx] = b;
	b->adj[b->idx] = a;
	a->idx++;
	b->idx++;
}

void traverse(node *focus, int *students, char *cycle_detected)
{
	//printf("id: %d\n", focus->id);
	(*students)++;
	focus->visited = 1;
	for(int i = 0; i < focus->idx; i++)
	{
		if(!focus->adj[i]->visited)
		{
			focus->adj[i]->parent = focus;
			traverse(focus->adj[i], students, cycle_detected);
		}
		else if(focus->adj[i]->visited && focus->adj[i] != focus->parent)
		{
			*cycle_detected = 1;
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
		//create memory on heap and assign address to arr
		*arr[i] = (node)
		{
			.adj 	 = (node**)malloc(sizeof(node*)*2),
			//at max each person has 2 friends
			.id      = i+1,
			.parent  = NULL,
			.idx 	 = 0,
			.visited = 0
		};
		//deref to use C99 style of initialization
	}
	for(int i = 0; i < M; i++)
	{
		int src, dst;
		scanf("%d %d", &src, &dst);
		add_edge(arr[src-1], arr[dst-1]);
	}
	int total_students = 0;
	int friendship_severed = 0;
	for(int i = 0; i < N; i++)
	{
		if(arr[i]->visited)		//we already considered this friend group
		{
			continue;
		}
		int students = 0;
		char cycle_detected = 0;
		traverse(arr[i], &students, &cycle_detected);
		//printf("cycle: %d students: %d\n", cycle_detected, students);
		total_students += (students/K) * K;
		if(students > K)
		{
			friendship_severed += cycle_detected + (students/K) -1;
			if(students % K != 0)
			{
				friendship_severed++;
			}
		}
	}
	printf("%d %d\n", total_students, friendship_severed);
	return 0;
}
