#include <stdio.h>
#include <stdlib.h>
// SHAWN MICHAEL SUDARIA
// SHEESH
void main(){
    int PassFlag = 0, tries = 4, input; // Initialize han mga gagamiton na bariables
    do
    {
        printf("Input: "); // Input it user, bali an iya input
        scanf("%d", &input); // gin store an input han user didto han address han input variable in memory
        if(tries != 0){ // check anay kun mayda pa tries it user, if wry na edi out na hiya.
            if(input == 2004){ // check kun it tama ba it guess han user. if pass 2004 pa pero plano ko mag check if dire ak gin hubya
                system("cls"); // para mag clear anay it screen before mag print "CORRECT!!".
                printf("Correct!!");
                PassFlag = 1; // ig set an PassFlag to 1 kay para mag end na it game.
            }else{
                printf("Incorrect Password!\n"); // kun mali edi mali tapos amo ine an magawas.
                tries--; // since mali man ig miminus an tries kay sure ak it user mag try again. stubborn man it sure dire maaram mag let go.
            }
        }else{
            PassFlag = 1; // kun an condition above dire ma satisfy then ig exit na. kay dapat mayda pa tries it user.
        }
        
    } while (PassFlag != 1); // nag aabang kun an passflag kay 1 para ig stop na an loop.
     
}