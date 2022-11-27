#include <stdio.h> // para hit printf() ngan scanf()
#include <stdlib.h> // optional la ine, para la ha system("cls") na gumana.


void main() // gin void ko hiya para dire naak mag sure return 0. kay main function man. di ka na need mag return any value.
{
    // initializing the variables to be used
    int Bool = 1; // flag para ha while loop
    int size; // input han user
    
    while(Bool) // an initial value niya kay 1, so mag run hiya kay in binary 1 = to True man.
    {
        printf("Size of the table:  "); // pag determine han size han table
        scanf("%d", &size); 

        if (size >= 1 && size <= 15) // ig check kay kun an input ha user within ha specified range an assignment.
        {
            // printf("%4c", 32);
            printf("    ");
            for (int f = 1; f <= size; f++)
            {   
                printf("%4d", f);
            }
            printf("\n");
            for (int i = 1; i <= size; i++) // parent loop. an mga rows
            {   
            
                printf("%4d", i);
                for (int b = 1; b <= size; b++) // child loop para han pag print han columns.
                {   

                    printf("%4d", i * b); // multiply ko an curent value han i to the current value of b. 
                    /*So diba na first value han parent loop, i, above kay 1, because int i = 1. Since 1 < han size then mag proceed
                    hiya ha child loop. Then an first value han child loop kay 1 liwat so 1 * 1 = 1 amot una na print. Now 
                    an an child loop na liwat mag proceed han second value which is 2 na, pero an parent loop dire pa hiya mag proceed
                    han second value kay dire paman tapos an child loop. Mahulat anay hiya matapos it second loop fully before 
                    ma proceed han second value. But I digress, an second value han child loop kay 2 naman, so since 2 is still
                     less than size then ig print out na an product 1 * 2 = 2. So on and so forth na ito. IDK no kun magets niya tak yakan
                    dire ak teacher bobo ak mag tutdo.*/
                }
                
                printf("\n");
                
            }
            Bool = 0; // ig set ko to 0 kay kun an iya range kay within 1 - 15, mag run an nested for loop above
            // tapos ma stop na an program via setting the Bool to 0. I.e. Setting the Bool to false.

        }else{
            /*Kun an input han user kay dire within range, then makadi hiya ha else then ma loop.
            kay dd ha else wry man Bool = 0. so always true hiya until mabasa an if above.
            gin invoke ko ha ubos an system("cls") kay para mag clear anay an screen before ma balik kuha input*/
            system("cls"); 
        }
    }
    
    
}