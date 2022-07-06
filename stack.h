#ifndef  STACK_H
#define  STACK_H

#define DEFAULT_STACK_SIZE 512

struct Stack {
  void **data;
  long int top;
  unsigned int capacity;
  struct Stack *(*push)(struct Stack *, void *);
  void *(*pop)(struct Stack *);
  void *(*peek)(struct Stack *);
  void *(*destroy)(struct Stack *);
};

typedef struct Stack Stack_t;

Stack_t *stack_create(void);

#endif // ! STACK_H