#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct node node;		//call struct node as just node
struct node
{
	int val;
	node *tail;
};

node *head = NULL;
int queue_size = 0;

void enqueue(int val)
{
	node **focus = &head;
	while(*focus != NULL && (*focus)->val <= val)
	{
		focus = & (*focus)->tail;
	}
	if(*focus == NULL){
		*focus  = (node*)malloc(sizeof(node));
		**focus = (node)
		{
			.val = val,
			.tail  = NULL
		};
	}
	else
	{
		node *tail = (*focus);
		(*focus)   = (node*)malloc(sizeof(node));
		(**focus)  = (node)
		{
			.val = val,
			.tail = tail
		};
	}
	queue_size++;
}

int dequeue()
{
	int ret = head->val;
	node *ptr = head;
	head = head->tail;
	free(ptr);
	return ret;
}

int peek()
{
	return head->val;
}

int main()
{
	enqueue(5);
	enqueue(6);
	enqueue(9);
	enqueue(15);
	enqueue(2);
	enqueue(25);
	enqueue(99);
	enqueue(66);
	enqueue(19);
	enqueue(100);
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	return 0;
}
