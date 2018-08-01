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

/*	for(int i =0;i<row;i++){

		for(int j = 0;j<col;j++){
			scanf("%d",&number);
			invertedNumber = 255 - number;
			printf("%d ",invertedNumber);
		}
		printf("\n");

        scanf("%d",&number);
        if(number == 0){
            continue;
        }
	}
*/

	int i = 0;
	while(i<row){
        int j = 0;
        while(j<col){
            scanf("%d",&number);
			invertedNumber = 255 - number;
			printf("%d ",invertedNumber);
            j++;
        }
		printf("\n");

        scanf("%d",&number);
        if(number == 0){
            continue;
        }

	}

	return 0;
}
