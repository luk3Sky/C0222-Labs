/* 
 * "Rock Paper Scissors Lizard Spock" Game from B.B.T.
 *==@luke==
 *E/15/142
 */

#include <strings.h>
#include <stdio.h>

int checkInput(char player);
void checkWin(char player1,char player2,char list[]);
int  main(){
	char player1,player2;
	char list[10] = {'R','C','L','P','S','R','C','L','P','S'};
	int returnValue = scanf("%c %c", &player1, &player2);

	if((returnValue == 2)&&(checkInput(player1))&&(checkInput(player2))){//Check input validation
            	checkWin(player1,player2,list);
		return 0;
	}else{//Exit if error occured.
		printf("Wrong input\n");
		return 1;
	}
}

void checkWin(char player1,char player2,char list[]){
	int i = 0,j = 0;
	int plyr1Pos,plyr2Pos;
	while(i<10){

		if(player1 == list[i]){
			plyr1Pos = i;
		}
		if(player2 == list[i]){
			plyr2Pos = i;
		}
		i++;		
	}
	if(((plyr1Pos+1) == plyr2Pos) || ( (plyr1Pos+2) == plyr2Pos) || ((plyr1Pos-4) == plyr2Pos) || ( (plyr1Pos-3) == plyr2Pos)){
		printf("Player 1 wins\n");return;
	}else if(((plyr1Pos+3) == plyr2Pos) || ( (plyr1Pos+4) == plyr2Pos) || ((plyr1Pos-1) == plyr2Pos) || ( (plyr1Pos-2) == plyr2Pos)){
		printf("Player 2 wins\n");return;
	}else{
		printf("Tie\n");return;
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
