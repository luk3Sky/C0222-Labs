/*
* A simple ASCII Draw program
*==@luke==
* E/15/142
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char **argv){
    int input;
    printf("Enter N: \n");
    //scanf("%d",&input);
    input = 4;
    if(input%2 != 0){
        int i; //height of the pyramid
        int j; //width of a line
        for(i = 1; i <= input ; i++){
            for(j = input-1; j >= i ; j--){
                printf("   ");
            }
            if(i<=input){
                for(j = i; j <= 2*i-1 ; j++){
                    if(j<10){
                        printf(" ");
                    }
                    printf("%d ",j);
                }
            }else{
                for(j = i-1; j > 0  ; j--){
                    if(j<10){
                        printf(" ");
                    }
                    printf("%d ",j);
                }

            }
            for(j = 2*i-2; j >= i  ; j--){
                if(j<10){
                    printf(" ");
                }
                printf("%d ",j);
            }
            printf("\n");
        }
    }
	return 0;
}
