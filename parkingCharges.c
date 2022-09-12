#include <stdio.h>
int main(){
    int numHrs;
    printf("How many hours have you stayed in parking \n");
    scanf("%d", &numHrs);
    int chargePerHour;
    if(numHrs == 3){
        chargePerHour = 50;
    }else if(numHrs > 3 && numHrs <= 6){
        chargePerHour = 35;
    }else if(numHrs > 6 && numHrs <= 12){
        chargePerHour = 20;
    }else if(chargePerHour > 12){
        chargePerHour = 10;
    }
    printf("Based on the time you parked you vehicle, you have been charged %d \n", chargePerHour);
}
