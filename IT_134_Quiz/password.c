#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Lucky 9
Ung array is range from{ 'A', 2-10)
Tapos {Hearts, Spades, Clover, Diamond}


1. Mag aask si program ng name ng dalawag player, tpaos un yung magiging name ni Player 1 and Player 2. (Ex. Player Josh and Player Earl)

2. Next, may lalabas na "Card is shuffling........." (delay for 10s

3. "Card is giving to both players" 

4. Player 1 card "9 of hearts and 7 of spades" tapos kay player 2 din ganon

5. (5s bago lumabas to) Player Josh, you want another card? If yes, magbibigay ng card pero naka "* of ****" muna, if No proceed na kay player 2.  Pagdating kay player 2,ganon din mag aask din mun,a if Yes print "Your card is ****" ganyan. 

7. Lalabas ung total cards, kasama ung isang extra na card na inask ni program 

8. After non, lalabas na ung result ganto
"Player 1 total card: 1 of hearts, 4 of spades and 3 of  diamonds with a total acore of 8" same kay player 2 ganyan din.

9. If more than 9 ung score, minus 10 dapat, so kapag 10 ung total, magiging 0 ung score, kapag 11 naman, magiging 1 ung score 

10. (3s bago lumabas to) Player 1 is the winner.*/

void main(){

    char letters[4] = {'A', 'J', 'K', 'Q'};
    int numbers[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

    char pass[100];
    printf("Password: ");
    scanf("%s", pass);

    int len = strlen(pass);
    printf("\n Your Hidden Password: ");
    for(int i = 1; i <= len; i++){
        printf("*");
    }
}