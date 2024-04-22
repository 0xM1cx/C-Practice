#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
}

struct node *head = NULL;
struct node *current = NULL;

void insertAtBegining(int data){
  struct node *lk = malloc(sizeof(struct node)); 
  lk->data = data;
  lk->next = head;  
  head = lk;
  head = lk;
}

void main(){
  struct node *p = head;
  printf("\n[");
}
