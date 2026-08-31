typedef struct Stack Stack;

Stack* stack_create(void);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
int stack_size(Stack *stack);
void stack_free(Stack *stack);
