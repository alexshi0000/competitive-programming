#include <stdlib.h>
#include <stdio.h>

/*
	in this original piece of code focus prev was set to the head, therefore causing the issue
*/

typedef struct node node;
struct node
{
	int val;
	node *prev;
};

node *head = NULL;

void enqueue(int val)
{
	node **focus = &head;
	while((*focus) != NULL && (*focus)->val <= val)
	{
		//(*focus) = (*focus)->prev; 
		focus = & (*focus)->prev;
		//we dont want focus assignment to effect the original head
	}
	node *tmp = *focus; 
	*focus  = (node*)malloc(sizeof(node));
	**focus = (node)
	{
		.val = val,
		.prev = tmp
	};
}

int dequeue()
{
	if(head == NULL)
	{
		return 0x7FFFFFFF;
	}
	int ret = head->val;
	node *tmp = head;
	head = head->prev;
	free(tmp);
	return ret;
}

int main()
{
	enqueue(20);
	enqueue(11);
	enqueue(4);
	enqueue(6);
	enqueue(9);
	enqueue(8);
	enqueue(27);
	enqueue(44);
	printf("dequeue: %d\n",dequeue());
	printf("dequeue: %d\n",dequeue());
	printf("dequeue: %d\n",dequeue());
	printf("dequeue: %d\n",dequeue());
	printf("dequeue: %d\n",dequeue());
	printf("dequeue: %d\n",dequeue());
	printf("dequeue: %d\n",dequeue());
	printf("dequeue: %d\n",dequeue());
}