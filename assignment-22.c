#include <stdio.h> 

struct stats {
    int points;
    int games;
};


int main(){
    
    // Create a program that takes input for five player's point totals and
    // games played totals and then calculates the scoring averages for each
    // player. 
    //
    // Create a struct with members for total points and games played. Create
    // an array of structures that is five elements deep and loop through the
    // array filling it with the point totals and games played totals for each
    // player

    struct stats players[5];    

    
    for(int i = 1; i <= 5; i++){
        printf("Enter Player %d's point total: ", i);
        scanf("%d", &players[i-1].points);
        printf("Enter Player %d's game total: ", i);
        scanf("%d", &players[i-1].games);
    }
    
    
    
    for(int i = 0; i < 5; i++){
        printf("Player %d's scoring average was %.2f ppg\n", i+1, (float)(players[i].points/players[i].games));
    }

    return 0;
}
