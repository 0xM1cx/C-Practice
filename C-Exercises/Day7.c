#include <stdio.h>

void main() {
    int a, b;
    char op;

    printf("Input equation(e.g. 1 + 1)  ");
    scanf("%d %c %d", &a, &op, &b);
    
    switch (op){
    case '+':
        printf("%d %c %d = %d", a, op, b, a+b);
        break;
    case '-':
        printf("%d %c %d = %d", a, op, b, a-b);
        break;
    case '*':
        printf("%d %c %d = %d", a, op, b, a*b);
        break;
    case '/':
        printf("%d %c %d = %d", a, op, b, a/b);
        break;
    default:
        printf("Mali!!");
        break;
    }
}
