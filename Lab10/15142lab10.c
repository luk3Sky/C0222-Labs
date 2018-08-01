/*
* A simple Word sorting program using Linked Lists
*==@luke==
* E/15/142
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  node{
	char *word;
	int length;
	struct node *next;
} Node;

static int ite = 0;
void bubbleSort(Node *head);
void addWord(Node *head, int to, char *text);
void swap(Node *current);

void bubbleSort(Node *head){	
	int swapNo=1,j;
	while (swapNo > 0){
		Node* current = head;
		swapNo = 0;
			while(current->next  != NULL){
			if ((current->length) < (current->next->length)){
				swap(current);
				swapNo++;
			}
			current = current->next;
		    }
	}
}

//Swap adjacent nodes by changing variable values
void swap(Node *current){
	Node *tempNode = malloc(sizeof(Node));
	Node *nextNode=current->next;// = malloc(sizeof(Node));
	tempNode->length=current->length;
	tempNode->word=current->word;
	current->length=nextNode->length;
	current->word=nextNode->word;
	nextNode->length=tempNode->length;
	nextNode->word=tempNode->word;
	tempNode->word=NULL;
	free(tempNode);
}

//add a word to a given list
void addWord(Node *head, int to, char *text){
	Node *current;
	current = head;
	while(current != NULL){
		if (ite == to){
			current->word = strdup(text);
			current->length = strlen(text);
			current->next = malloc(sizeof(Node));
			ite = 0;
			return;
		}
		ite++;
		current = current->next;
	}
	current->next = NULL;
	return;
}

//print the whole list
void printList(Node *head){
	
	Node *current;
	current = head;

	while(current->next != NULL){
		printf("%d %s\n",current->length, current->word);
		current = current->next;
	}
	if (current == NULL){
		return;
	}
	return;
}

int main(int argc, char const *argv[]){
	
	//create head of the list
	Node *head = (Node *)malloc(sizeof(Node));
	FILE *inputFilePointer;
	
	if(argc != 2){
	//INPUT ARGUMENTS SUCCESS!!!
		printf("Usage: ./program <input-file>\n");
		return 1;
	}	
	inputFilePointer = fopen(argv[1],"r");
	if(inputFilePointer != NULL){
	//READ SUCESS!!!
		char read[100];
		int c,count = 0;
		while(1){
			c = fscanf(inputFilePointer,"%s",read);
			if(c!=1){
				break;
			}
			addWord(head,count,read);
			count++;
		}
	}
	bubbleSort(head);
	printList(head);
	return 0;
}