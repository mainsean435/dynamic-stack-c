/* 
* Example 1: Reverse the words of a string of any length entered by the user  
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stack.h"


int main2() {
  printf("Enter a string: ");
  char *word, *input;
  scanf("%m[^\n]", &input);
  
  Stack_t *stack = stack_create();
  while((word = strsep(&input, " "))) {
    stack->push(stack, word);
  }

  printf("\nReversed string: ");
  while((word = stack->pop(stack))) {
    printf("%s ", word);
  }
  printf("\n");

  free(input);
  stack->destroy(stack);

  return 0;
}