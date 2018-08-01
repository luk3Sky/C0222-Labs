// Fix the bugs

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int value;
	struct node * next;
};

typedef struct node Node;

int main()
{
	Node head;
	Node* iterator = &head;
	// Create a linked list with 10 elements
	int i = 0;
	for(i = 0; i<10 ; i ++){
		Node* newNodep;
		newNodep = (Node *) malloc(sizeof(Node));
		iterator->next = newNodep;
		newNodep->value = i;
		iterator = newNodep;
	}
	
	// Printing the values 
	iterator = &head;
	while(iterator->next != NULL)
	{
		iterator = iterator->next;
		printf("Value %d\n", iterator->value);
	}
}
