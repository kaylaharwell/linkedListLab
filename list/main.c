#include <stdio.h>

#include "list.h"


int main() {
  printf("Tests for linked list implementation\n");
  
  list_t *testList = list_alloc();
  
  list_add_to_back(testList ,1);
  list_add_to_back(testList, 2);
  list_add_to_back(testList, 3);
  list_add_to_back(testList, 4);
  
  
  printf("Order of the list should be 1 2 3 4: \n");
  list_print(testList);
  
  
  list_add_to_front(testList, 5);
  list_add_to_front(testList, 6);
  
  printf("Order of the list should be 6 5 1 2 3 4 : \n");
  list_print(testList);
  
  
  printf("Order should be 6 5 1 44 2 3 4 - Testing the add at index function: \n");
  list_add_at_index(testList, 44, 4);
  list_print(testList);
 
  printf("Order should be 6 5 1 44 2 3 - Testing remove from back: \n");
  list_remove_from_back(testList);
  list_print(testList);
  
  printf("Order should be 6 1 44 2 3 - Testing remove from index 1: \n");
  list_remove_at_index(testList, 1);
  list_print(testList);
  
  printf("Testing list is in function - checking if 44 is still in - should say true: \n");
  list_is_in(testList, 44);
  printf("\n");
  
 
  printf("testing list_get_elem_at function - requesting number at el 2 - should be 44: %d\n",list_get_elem_at(testList,2));
  printf("\n");
 
  printf("testing list_get_index_of function - requesting the index of 6 - should be 0: %d\n",list_get_index_of(testList,6));
  printf("\n");
  
  list_free(testList);
  
  return 0;
}