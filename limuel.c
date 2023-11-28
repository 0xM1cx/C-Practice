#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int bet, deposit, d1, d2, total1, total2, again;
	int balance = 0;
	char choice;
	printf("===========================\n");
	printf("|     D    I    C    E    |\n");
	printf("===========================\n");
	printf("     [P]Play [E]Exit     \n");
	scanf("%s", &choice);
	system("cls");
	switch (choice)
	{
		case 'P': case 'p':
			printf("===========================\n");
			printf("Balance: %d\n", balance);
			printf("How much do you want to deposit: ");
			scanf("%d",&deposit);
			balance += deposit;
			system("cls");
			bet:
			printf("===========================\n");
			printf("Balance: %d\n", balance);
			printf("===========================\n");
			printf("How much will you bet: ");
			scanf("%d", &bet);
			if(bet > balance)
				{printf("Not Enough Balance.\n");
				goto bet;}
			else
				{balance = balance - bet;}
			system("cls");
			printf("===========================\n");
			printf("Balance: %d\n", balance);
			printf("Bet: %d\n",bet);
			printf("===========================\n");
			printf("Bet Accepted\n\nPress Enter to Continue...");
			getch();
			system("cls");
			printf("Roll 1:.\n");
			printf("===========================\n");
			printf("Your balance now is: %d\n", balance);
			printf("Bet: %d\n",bet);
			printf("===========================\n");			
			printf("Press Enter to throw Dice.\n\n");
			srand(time(NULL));
			d1 = rand()%6 + 1;
			d2 = rand()%6 + 1;
			getch();
			printf("Dice 1: %d\n",d1);
			printf("Dice 2: %d\n",d2);
			total1 = d1 + d2;
			
			printf("The total of both dice is %d\n", total1);
			
			if(total1 == 7){
				printf("You Won!!!\n");
				bet = bet*2;
				balance = balance + bet;
				printf("===========================\n");
				printf("Your balance now is: %d\n", balance);
				printf("===========================\n");
			}
			else if((total1 == 11) || (total1 == 2)){
				printf("You Lose!\n");
				balance = balance - bet;
				printf("===========================\n");
				printf("Your balance now is: %d\n", balance);
				printf("===========================\n");
			}
			else{
				roll:
				
				printf("\nNo Luck\n\nRoll Again\n");
				printf("Press Enter to throw Dice.\n\n");
				getch();
				system("cls");
				srand(time(NULL));
				d1 = rand()%6 + 1;
				d2 = rand()%6 + 1;
				printf("Roll 2:.\n");
				printf("===========================\n");
				printf("Your balance now is: %d\n", balance);
				printf("Bet: %d\n",bet);
				printf("===========================\n");
				printf("Roll 1: %d\n\n", total1);
				printf("Dice 1: %d\n",d1);
				printf("Dice 2: %d\n",d2);
				total2 = d1 + d2;
				
				printf("The total of both dice is %d\n", total2);
				
				if(total2 == total1){
					printf("You Won!!!\n");
					bet = bet*2;
					balance = balance + bet;
					printf("===========================\n");
					printf("Your balance now is: %d\n", balance);
					printf("===========================\n");
				}
				else if(total2 == 7){
					printf("You Lose!\n");
					balance = balance - bet;
					printf("===========================\n");
					printf("Your balance now is: %d\n", balance);
					printf("===========================\n");
				}
				else{goto roll;}
			}
			printf("===========================\n");
			printf("       Play Again?   \n");
			printf("      [1]Yes  [2]No   \n");
			printf("===========================\n");
			scanf("%d",&again);
			system("cls");
			if(again == 1){goto bet;}
			else{printf("Thak you for Playing!");}
			break;
		default:
			printf("Thak you for Playing!");
			return 0;
	}
}
