#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
  
};

void main(){
  struct node *head = NULL;
  head = malloc(sizeof(struct node));
  head->data = 15;
  head->next = NULL;

  printf("%d", head->data);
}
