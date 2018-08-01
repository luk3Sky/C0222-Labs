/*
* A simple ASCII Draw program
*==@luke==
* E/15/142
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);
int checkInput(char input[]);
int checkType(char input[]);
void checker(char c1[],char c2[]);
void donut(char c1[],char c2[],float input);

//Method checkType() returns 1 if the input type is correct o.w 0
int checkType(char input[]){
	if(strcmp(input,"checker") == 0){
		return 1;
	}else if(strcmp(input,"donut") == 0){
		return 2;
	}else{
		//printf("Requested figure is not available\n");
		return 100;
	}
}

//Method checkInput() returns 1 if the input is correct o.w 0
int checkInput(char input[]){
	int i;
	for(i = 0;i <= 8;i++){
		if(strcmp(input,"black") == 0){
			return 0;
		}else if(strcmp(input,"red") == 0){
			return 1;
		}else if(strcmp(input,"green") == 0){
			return 2;
		}else if(strcmp(input,"yellow") == 0){
			return 3;
		}else if(strcmp(input,"blue") == 0){
			return 4;
		}else if(strcmp(input,"magenta") == 0){
			return 5;
		}else if(strcmp(input,"cyan") == 0){
			return 6;
		}else if(strcmp(input,"white") == 0){
			return 7;
		}else{
			return 100;
		}
	}

}

void textcolor(int attr, int fg, int bg){
	char command[13];


	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}

//////// CHECKER PATTERN ///////////
//method checker() prints checker board pattern in the terminal
void checker(char c1[],char c2[]){
	int i,j,k;
	for(i = 0;i < 8;i++){
		if(i%2 == 0){
			for(j = 0;j < 8 ; j++){
				for(k = 0;k < 8; k++){
					if(k%2 != 1){
						textcolor(RESET,checkInput(c1),checkInput(c2));
						printf("        ");
					}else{
						textcolor(RESET,checkInput(c2),checkInput(c1));
						printf("        ");
					}
					textcolor(RESET,checkInput(c1),checkInput(c2));
				}
				printf("\n");

			}

		}else{
			for(j = 0;j < 8 ; j++){
				for(k = 0;k < 8; k++){
					if(k%2 != 1){
						textcolor(RESET,checkInput(c2),checkInput(c1));
						printf("        ");
					}else{
						textcolor(RESET,checkInput(c1),checkInput(c2));
						printf("        ");
					}
					textcolor(RESET,checkInput(c1),checkInput(c2));
				}
				printf("\n");

			}

		}
	}
}

//////// DONUT PATTERN ///////////
//method donut() calculates values to draw the figure
void donut(char c1[],char c2[],float input){
	int i,j,k;
	float x = input/4;
	float n = round(x);
	
	for(i = 0;i<2*n;i++){
		if(i!=0){
			for(j = 0; j<2*n ; j++){
				if(j!=0){
					int y = ( (2*n-j)*(2*n-j) ) + ((2*n-i)*(2*n-i));
				
					if(y <= (n)*(n)){
						textcolor(BRIGHT,checkInput(c2),checkInput(c1));
						printf(" ");
					}else if(n*n < y && y > (2*n)*(2*n)){
						textcolor(BRIGHT,checkInput(c2),checkInput(c1));
						printf(" ");
					}else{
						textcolor(BRIGHT,checkInput(c1),checkInput(c2));
						printf(" ");
					}
				}
			}
			for(j = 2*n; j>0 ; j--){
				if(j!=2*n){
					int y = ( (2*n-j)*(2*n-j) ) + ((2*n-i)*(2*n-i));
				
					if(y <= (n)*(n)){
						textcolor(BRIGHT,checkInput(c2),checkInput(c1));
						printf(" ");
					}else if(n*n < y && y > (2*n)*(2*n)){
						textcolor(BRIGHT,checkInput(c2),checkInput(c1));
						printf(" ");
					}else{
						textcolor(BRIGHT,checkInput(c1),checkInput(c2));
						printf(" ");
					}
				}
				
			}
			printf("\n");
			
		}
	}
	for(i = 2*n;i>0;i--){
		for(j = 0; j<2*n ; j++){
			if(j!=0){
				int y = ( (2*n-j)*(2*n-j) ) + ((2*n-i)*(2*n-i));
				
				if(y <= (n)*(n)){
					textcolor(BRIGHT,checkInput(c2),checkInput(c1));
					printf(" ");
				}else if(n*n < y && y > (2*n)*(2*n)){
					textcolor(BRIGHT,checkInput(c2),checkInput(c1));
					printf(" ");
				}else{
					textcolor(BRIGHT,checkInput(c1),checkInput(c2));
					printf(" ");
				}			
			}
		}
		for(j = 2*n; j>0 ; j--){
			if(j!=2*n){
				int y = ( (2*n-j)*(2*n-j) ) + ((2*n-i)*(2*n-i));
				
				if(y <= (n)*(n)){
					textcolor(BRIGHT,checkInput(c2),checkInput(c1));
					printf(" ");
				}else if(n*n < y && y > (2*n)*(2*n)){
					textcolor(BRIGHT,checkInput(c2),checkInput(c1));
					printf(" ");
				}else{
					textcolor(BRIGHT,checkInput(c1),checkInput(c2));
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

int main(int argc, char **argv){

	if(argc == 4){
		if(checkType(argv[1])<100){
			if(checkInput(argv[2])<100){
				if(checkInput(argv[3]) < 100){
					if(checkType(argv[1]) == 1){
						checker(argv[2],argv[3]);
					}else if(checkType(argv[1]) == 2){
						float input;
						scanf("%f",&input);
						donut(argv[2],argv[3],input);
					}
				}else{
					printf("Foreground color is not available\n");
				}
				
			}else{
				printf("Background color is not available\n");
			}
		}
	}else if(argc < 4){
		printf("Not enough arguments\n");	
	}else{
		printf("Too many arguments\n");
	}


	textcolor(RESET, BLACK, WHITE);
	return 0;
}
