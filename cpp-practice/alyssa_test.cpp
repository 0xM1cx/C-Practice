#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int top = -1, stack[MAX];

void push() {
    if (top == MAX - 1)
        printf("\nStack is full!!");
    else {
        int val;
        printf("\nEnter element to push: ");
        scanf("%d", &val);
        stack[++top] = val;
    }
}

void pop() {
    if (top == -1)
        printf("\nStack is empty!!");
    else
        printf("\nDeleted element is %d", stack[top--]);
}

void display() {
    if (top == -1)
        printf("\nStack is empty!!");
    else {
        printf("\nStack is...\n");
        for (int i = top; i >= 0; i--)
            printf("Index %d: %d\n", i, stack[i]);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n*** Stack Menu *");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\n\nEnter your choice (1-4): ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong Choice!!");
        }
    }
    return 0;
}