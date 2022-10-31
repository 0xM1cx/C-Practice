#include <stdio.h>

// void main(){
    // int age = 18;
    // printf("%d\n", age);
    // printf("%p\n", &age);
    // int *address = &age;
    // printf("%d", *address);


#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    *a += *b;    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    // printf("%d\n%d", a, b);

    return 0;
}

// }