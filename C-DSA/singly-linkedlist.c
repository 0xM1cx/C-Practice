#include <malloc.h>
#include <stdio.h>
#include <string.h>

struct node {
    char data[2];
    struct node *link;
};

void main() {
    struct node *head = malloc(sizeof(struct node));

    strcpy(head->data, "SH");
    head->link = NULL;

    printf("%s\n", head->data);
    printf("%x", head->link);
}