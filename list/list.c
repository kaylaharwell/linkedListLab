// list/list.c
// 
// Implementation for linked list.
//
// Kayla Harwell @02892084

#include <stdio.h>
#include <stdlib.h> 
#include "list.h"

list_t *list_alloc() {
  list_t *newList = (list_t *)malloc(sizeof(list_t));
  newList -> head = (node_t *)malloc(sizeof(node_t));
  newList -> head = NULL;
  
  return newList;
  
}




void list_free(list_t *l) {
  node_t* temp = l ->head;
  node_t* temp2;
 
  while(temp!=NULL){
    temp2 = temp -> next;
    free(temp);
    temp = temp2;
  }
  
  free(temp2);
  free(temp);
  free(l);
 
}

void list_print(list_t *l) {
  node_t* current = l -> head;
  int a = 0;
  while(current != NULL){
    printf("Index : %d\n", a);
    printf("Value : %d\n", current -> value);
    printf("\n");
    a++;
    current = current -> next;
  }
  
}
int list_length(list_t *l) { 
  int length = 0;
  node_t* current = l -> head;
  while(current!= NULL){
    length++;
    current = current -> next;
  }
  return length; 
}

void list_add_to_back(list_t *l, elem value) {
  
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  node_t* temp = l->head;
  newNode -> value = value;
  newNode -> next = NULL;
  
  if(l -> head == NULL){
    l -> head = newNode;
    return;
  }
  
  while(temp -> next != NULL){
    temp = temp -> next;
  }
  
  temp -> next = newNode;
  
    
}
void list_add_to_front(list_t *l, elem value) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  node_t* temp = l -> head;
  new_node -> value = value;
  new_node -> next = NULL;
  
  if (l -> head == NULL){
    l -> head = new_node;
    return;
  }
  
  
  
  new_node -> next = temp;
  l -> head = new_node;
  
  return;
}
void list_add_at_index(list_t *l, elem value, int index) {
  
   node_t *new_node = (node_t*)malloc(sizeof(node_t));
  node_t *temp = l -> head;
  new_node -> value = value;
  new_node -> next = NULL;
  int lenght = list_length(l);
  
  if( l -> head == NULL){
    printf("New Node is the head now");
    l -> head = new_node;
    return;
  }
 
  if(index < 1 || index > lenght +1){
    printf("Out of bounds.\n");
    return;
  }
  
  index = index -2;
  while(index != 0){
    temp = temp -> next;
    index--;
  }
  
  new_node -> next = temp -> next;
  temp -> next = new_node;

  }
 

elem list_remove_from_back(list_t *l) { 
  node_t *temp = l -> head;
  if(temp == NULL){
    printf("Empty List.\n");
    return;
  }
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  
}
elem list_remove_from_front(list_t *l) { 
 node_t *temp = l-> head;
 if (temp == NULL){
   printf("Empty list.\n");
 }
  l->head = temp->next;
  free(temp);
}
elem list_remove_at_index(list_t *l, int index) { 
  node_t *temp = l-> head;
  node_t *temp2;
  int lenght = list_length(l);
  if( l -> head == NULL){
    printf("New Node is the head now");
    return;
  }
 
  if(index < 1 || index > lenght +1){
    printf("Out of bounds.\n");
    return;
  }
  
  index = index -1;
  while(index != 0){
    temp = temp -> next;
    index--;
  }
  if(temp->next->next != NULL){
    temp2 = temp ->next;
    temp->next = temp2->next;
    free(temp2);
  }
  else{
    free(temp->next);
    temp->next = NULL;
  }
 }

bool list_is_in(list_t *l, elem value) { 
  node_t *temp = l-> head;
  while(temp != NULL){
    if(temp -> value == value){
      printf("True.\n");
      return true;
      
    }
    else{
      temp = temp->next;
    }
  }
  printf("False.\n");
  return false; }
elem list_get_elem_at(list_t *l, int index) { 
  node_t *temp = l -> head;
  int lenght = list_length(l);
  
  if( l -> head == NULL){
    printf("New Node is the head now");
    return;
  }

  if(index < 1 || index > lenght +1){
    printf("Out of bounds.\n");
    return;
  }
  
  while(index != 0){
    temp = temp -> next;
    index--;
  }
  return temp->value; 
}
int list_get_index_of(list_t *l, elem value) { 
  node_t *temp = l->head;
  int a = 0;
  
  if(temp == NULL){
    printf("The List is empty.\n");
    return;
  }
  
  while(temp != NULL ){
    if(temp->value == value){
      return a;
    }
    else{
      a++;
      temp = temp->next;
    }
  }
  printf("Value not found.\n");
  return;
}
