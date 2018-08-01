/*
 * "Rock Paper Scissors Lizard Spock" Game from B.B.T.
 *==@luke==
 */
#include <strings.h>
#include <stdio.h>


int checkInput(char player);
int  main(){
	char player1,player2;
	char[] list[10] = ['R','C','L','P','S','R','C','L','P','S'];
	int returnValue = scanf("%c %c", &player1, &player2);

	if((returnValue == 2)&&(checkInput(player1))&&(checkInput(player2))){//Check input validation
		printf("Correct input\n");
		
		return 0;
	}else{//Exit if error occured.
		printf("Wrong input\n");
		return 1;
	}
}

int checkWin(char player,char[] list){
	int i = 0;
	while(i < 5){
		if( (player == list[i+1]) || (player == list[i+2])){
			printf("Player 1 wins\n");break;
		}else if( (player == list[i+3]) || (player == list[i+4]) ){
			printf("Player 2 wins\n");break;
		}else{
			printf("Tie\n");break;
		}
		
	}

}


//Method to check inputs...
int checkInput(char player){
	int val = 0;
	switch (player){
		case 'R':
			val = 1;break;
		case 'C':
			val = 1;break;
		case 'L':
			val = 1;break;
		case 'P':
			val = 1;break;
		case 'S':
			val = 1;break;
	}
	return val;
}
