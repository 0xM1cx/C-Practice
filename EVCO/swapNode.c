#include <stdio.h>

struct node {
    int data;
    struct node *nextPtr;
};

void main() {
    int size;
    printf("Enter size of linked list: ");
    scanf("%d", &size);

    struct node *head = NULL;
    for (int i = 1; i <= size; i++) {
        struct node *newNode = malloc(sizeof(struct node));
        printf("Enter element %d: ");
        scanf("%d", newNode->data);
        newNode->nextPtr = head;
    }
}