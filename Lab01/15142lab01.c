/*
* A Simple Electricity Bill Calculator
*==@luke== 
* E/15/142
*/

#include <stdio.h>

int main() {
	int units;
	float bill;
	printf("Enter the units : ");
	
	for(int i = 0; i < 3;){
		if(i ==0){// check for correct inputs
			if(scanf("%d",&units)==0){
				printf("Please enter a valid number for the units.\n");
				i = 3;
			
			}else if(units<0){
				printf("Please enter a posible number for the units : \n");
				units = 0;
				i = 0;
				break;
			}
			i++;	
		}else if(i == 1){//do the calculations
			if(units > 60){
				if(units <= 90){
					bill = (units-60)*10 + 60*7.85 + 90;			
				}else if(units <= 120){
					bill = (units-90)*27.75 + 30*10 + 60*7.85 + 480;	
				}else if(units <= 180){
					bill = (units-120)*32 + 30*27.75 + 30*10 +60*7.85 + 480;
				}else{
					bill = (units-180)*45 + 60*32 + 30*27.75 + 30*10 + 60*7.85 + 540;
				}
			}else{
				if(units > 30){
					bill = (units-30)*4.85+30*2.50+60;
				}else{
					bill = units*2.5 +30;
				}
			}
			i++;
		}else{//display the output
			printf("The total Bill = %.2f\n",bill);	
			i++;		
		}
	}
}
