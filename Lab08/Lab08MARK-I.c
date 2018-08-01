#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	FILE *inputFilePointer;

	if(argc != 3){
	//INPUT ARGUMENTS SUCCESS!!!
		printf("Usage: ./prog <width> <input-file>");
		//printf("Wrong input\n");
		return 0; 
	}else{
		if( atoi(argv[1]) <= 10){
			printf("Word length must be less than screen width\n");
			return 0;
		}
//		int count = str2int(argv[1]);
		int count = atoi(argv[1]);
		inputFilePointer = fopen(argv[2],"r");
		if(inputFilePointer != NULL){
		//READ SUCESS!!!
			char read[100];
			fscanf(inputFilePointer,"%s",read);
			printf("%s\n",read);
			while(){
			
			}
		}else{
			printf("Segmentation fault (core dumped)\n");
		}
	}

	return 0;
}
