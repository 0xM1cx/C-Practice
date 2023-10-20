#include <malloc.h>
#include <stdio.h>
#include <string.h>

struct node {
    char data[2];
    struct node *link;
};

struct node *createNode(char data[]) {
    struct node *newNode = malloc(sizeof(struct node));

    strcpy(newNode->data, data);
    newNode->link = NULL;

    return newNode;
}

struct node *insertNewNodeAtBeginning(struct node *head, char data[]) {
    struct node *newNode = createNode(data);
    newNode->link = head;
    return newNode;
}

void main() {
    struct node *head = NULL;

    head = insertNewNodeAtBeginning(head, "SH");
    head = insertNewNodeAtBeginning(head, "ZJ");
    head = insertNewNodeAtBeginning(head, "SM");
    head = insertNewNodeAtBeginning(head, "ZD");

    struct node *current = head;
    while (current != NULL) {
        printf("%s->", current->data);
        current = current->link;
    }
    printf("NULL");

    // strcpy(head->data, "SH");
    // head->link = NULL;

    // struct node *second = malloc(sizeof(struct node));
    // strcpy(second->data, "ZJ");
    // second->link = NULL;

    // struct node *third = malloc(sizeof(struct node));
    // strcpy(third->data, "SM");
    // third->link = NULL;

    // head->link = second;
    // second->link = third;

    // printf("%s\n", head->data);
    // printf("%x\n", head->link);
    // printf("%s\n", head->link->data);
    // printf("%x\n", second->link);
    // printf("%s\n", second->link->data);
    // printf("%x", second->link->link);
}