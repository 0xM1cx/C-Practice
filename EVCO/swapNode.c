#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *nextPtr;
    struct node *prevPtr;
};

struct node *createNode(int i) {
    struct node *newNode = malloc(sizeof(struct node));
    printf("Enter element %d: ", i);
    scanf("%d", newNode->data);
    newNode->nextPtr = NULL;
    newNode->prevPtr = NULL;

    return newNode;
}
void main() {
    int size;
    printf("Enter size of linked list: ");
    scanf("%d", &size);

    struct node *head = NULL;
    for (int i = 1; i <= size; i++) {
        struct node *newNode = createNode(i);
        newNode->nextPtr =
    }

    printf("%d", head->data);
}