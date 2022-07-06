#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stack.h"


Stack_t *stack_push(Stack_t *stack, void *element) {
  assert(stack);
  assert(stack->data);

  if (stack->top == stack->capacity) {
    stack->capacity += DEFAULT_STACK_SIZE;
    stack->data = realloc(stack->data, (stack->capacity * sizeof(void *)));
    assert(stack->data);
  }

  stack->data[++stack->top] = element;

  return stack;
}


void *stack_pop(Stack_t *stack) {
  assert(stack);
  assert(stack->data);
  
  if (stack->top >= 0)
    return stack->data[stack->top--];

  return NULL;
}


void *stack_destroy(Stack_t *stack) {
  assert(stack);
  assert(stack->data);

  free(stack->data);
  free(stack);

  return NULL;
}


Stack_t *stack_create(void) {
  Stack_t *stack = malloc(sizeof(Stack_t));
  assert(stack);
  
  stack->data = malloc(sizeof(void *) * DEFAULT_STACK_SIZE);
  assert(stack->data);

  stack->top = -1;
  stack->capacity = DEFAULT_STACK_SIZE;
  stack->push = &stack_push;
  stack->pop = &stack_pop;
  stack->destroy = &stack_destroy;

  return stack;
}
