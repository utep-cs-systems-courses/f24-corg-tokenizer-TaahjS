#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List *history = malloc(sizeof(List));
  Item *first;
  history->root = first;
  return history;
}

void add_history(List *list, char *str){
  int currID = 1;
  Item *ptr = list->root;
  while(ptr->next){
    ptr = ptr->next;
    currID++;
  }
  Item *newNode = malloc(sizeof(Item));
  newNode->id = currID;
  newNode->str = str;
  newNode->next = 0;
  if(ptr->id){
    ptr->next = newNode;
  }else{
    list->root = newNode;
  }
}

char *get_history(List *list, int id){
  int i = 1;
  if(list->root->id == id){
    char *str = (list->root->str);
    return str;
  }
  Item *ptr = list->root;
  while(ptr->next){
    ptr = ptr->next;
    int currID = ptr->id;
    if(currID == id){
      return ptr->str;
    }
  }
  return 0;
}

void print_history(List *list){

  if(list == NULL){

    printf("List is empty");

    return;

  }

  Item *curr = list->root;

  while(curr != NULL){

    printf("%d. %s\n", curr->id, curr->str);

    curr = curr->next;

  }
}
 void free_history(List *list){
   Item *curr = list->root;

   while (curr != NULL){

     Item *currPtr = curr;

     curr = curr->next;

     free(currPtr->str);

     free(currPtr);

   }

   free(list);

 }
