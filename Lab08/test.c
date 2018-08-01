#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *inputFilePointer;

	if(argc != 3){
	//INPUT ARGUMENTS SUCCESS!!!
		printf("Usage: ./prog <width> <input-file>\n");
		return 0;
	}
	if( atoi(argv[1]) <= 10){
			printf("Word length must be less than screen width\n");
		return 0;
	}
	int space = atoi(argv[1]);
	int spaceLeft = space,spaceUsed = 0;
	
	inputFilePointer = fopen(argv[2],"r");
	
	if(inputFilePointer != NULL){
	//READ SUCESS!!!
		char read[100];
		int c,count = 0;
		while(1){
			c = fscanf(inputFilePointer,"%s",read);
			if (strchr(read,'\n')){
				printf("\n");
				continue;
			}
			if(strlen(read) <= spaceLeft){
				printf("%s ", read);
				spaceLeft = spaceLeft - strlen(read) - 1;
				if (spaceLeft <= 0){
					printf("\n");
					spaceLeft = space ;
				}
				
			}else{
				printf("\n%s ", read); 
				spaceLeft = space - strlen(read) - 1;
			
			}

			if(c!=1){
				//printf("\nEND!!\n");
				//printf("%d\n",count);
				break;
			}
			count++;
		}
	}else{
			printf("Segmentation fault (core dumped)\n");
		}
		
	return 0;
}