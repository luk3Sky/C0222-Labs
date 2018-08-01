#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  node{
	char *word;
	int length;
	struct node *next;
} Node;

static int ite = 0;

int getListLength(Node *head);
void bubbleSort(Node *head);
void addWord(Node *head, int to, char *text);
void swap(Node *current);
char *getItem(Node *head,int n);

void bubbleSort(Node *head){
	
	int swapNo=1,j;
	while (swapNo>0){
		Node* current = head;
		swapNo=0;
			while(current->next  != NULL){
			if ((current->length) < (current->next->length)){
				swap(current);
				swapNo++;
			}
			current = current->next;
		    }
	}
}

//Node *swap(Node *current){
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

int getListLength(Node *head){
	Node* current = head;
	ite = 0;
	while(current != NULL){
		current = current->next;
		ite++;
	}
	return ite;
}

//get the last item of the list
char * getItem(Node *head,int n){
	Node *current = malloc(sizeof(Node));
	current = head;
	ite = 0;
	while(current != NULL){ 
		if (ite == n){
			return current->word;
		}
		current = current->next;
		ite ++;

	}

	return current->word;
}




//get the last item of the list
Node *getLastItem(Node *head){

	Node *current = malloc(sizeof(Node));
	current = head;
	while(current != NULL){ 
		printf("Not NULL\n");
		current = current->next;
		ite += 1;
	}
	return current;
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
		printf("Usage: ./prog <input-file>\n");
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