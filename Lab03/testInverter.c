/* Lab03
 * Image Inverting Program
 *==@luke==
 *E/15/142
 */

#include <stdio.h>

int main(){

	int col,row,number,invertedNumber;
	scanf("%d %d",&col,&row);
	printf("%d %d\n",col,row);

	//Check padddings...;
	int padding = (4 - ((col*3)%4));
    	if(padding == 4){
        	padding = 0;
    	}

	int i,j,k,l;
	for( i=0;i<row;i++){//Outer loop for rows;

        	for(j = 0;j<col;j++){//Nested loop for columns;

	            for(k = 0;k<3;k++){//Inner loop for individual numbers;

	                scanf("%d",&number);
	                invertedNumber = 255 - number;
	                printf("%d ",invertedNumber);

	            }

	            printf("\n");

	        }
		//Clear padding inputs;
	        for(l = 0;l<padding;l++){
		        printf("0\n");
			scanf("%d",&number);
			
	        }

		if(number == 0){
			continue;
		}
	}
	return 0;
}
