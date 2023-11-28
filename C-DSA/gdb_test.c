#include <stdio.h>

void main(){
    long double start;
    long double step;
    long double end;

    printf("Start, Step, End: ");
    scanf("%Lf %LF %Lf", &start, &step, &end);

    while(start != end){
        printf("%Lf\n", start);
        start += step;

    }


}
