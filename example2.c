/*
* Example 2: Reverse a linked using a stack
*/

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct Node {
  int data;
  struct Node *next;
} Node_t;


int main(int argc, char **argv) {
  
  int num_nodes = 10;
  if (argc == 2) {
    num_nodes = atoi(argv[1]);
  }

  Node_t *head = malloc(sizeof(Node_t));
  head->data = 0;
  head->next = NULL;
  Node_t *tmp = head;
  for (int i = 1; i < num_nodes; i++) {
    Node_t *node = malloc(sizeof(Node_t));
    node->data = i*10;
    node->next = NULL;
    tmp->next = node;
    tmp = node;
  }

  printf("\nLinked list: ");
  tmp = head;
  while (tmp) {
    printf("%d", tmp->data);
    tmp = tmp->next;
    if (tmp) printf("->");
  }
  printf("\n");
  

  Stack_t *stack = stack_create();
  Node_t *curr = head;
  while (curr) {
    stack->push(stack, curr);
    curr = curr->next;
  }

  // Reverse the linked list by popping from the stack
  head = curr = stack->pop(stack);
  while (curr) {
    curr->next = stack->pop(stack);
    curr = curr->next;
  }

  printf("\nReversed linked list: ");
  curr = head;
  while (curr) {
    printf("%d", curr->data);
    curr = curr->next;
    if (curr) printf("->");
  }
  printf("\n");


  curr = head;
  while (curr) {
    Node_t *tmp = curr;
    curr = curr->next;
    free(tmp);
  }
  stack->destroy(stack);
  
  return 0;

}
