
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 5

#define STACK_OVERFLOW  -100
#define ERROR_STACK_OVERFLOW printf("Error. Stack overflow\n");
#define STACK_UNDERFLOW -101
#define ERROR_STACK_UNDERFLOW printf("Error. Stack underflow\n");
#define OUT_OF_MEMORY   -102
#define STACK_WAS_CLEARED printf("Stack was cleared\n");

typedef struct stack
{
	int data[STACK_MAX_SIZE];
	size_t size;
}stc;

void push(stc *stack, const int value)
{
	if (stack->size >= STACK_MAX_SIZE) {
		ERROR_STACK_OVERFLOW;
		exit(STACK_OVERFLOW);
	}
	stack->data[stack->size] = value;
	stack->size++;
}

int pop(stc *stack)
{
	if (stack->size == 0)
	{
		ERROR_STACK_UNDERFLOW;
		exit(STACK_UNDERFLOW);
	}
	stack->size--;
	return stack->data[stack->size];
}

void print_stack(stc *stack)
{
	if (stack->size > 0)
	{
		int i = 0;
		while (i < stack->size)
		{
			printf("%d->", stack->data[i]);
			i++;
		} 
		printf("\n");
	}
}

stc* create_stack()
{
	stc* my_stack = (stc*)malloc(STACK_MAX_SIZE);
	my_stack->size = 0;
	return my_stack;
}

void free_stack(stc *stack)
{
	while (stack->size != 0)
	{
		pop(stack);
	}
	free(stack->data);
	STACK_WAS_CLEARED;
}

int main(int argc, char const *argv[])
{
	stc* my_stack = create_stack();
	push(my_stack, 3);
	push(my_stack, 5);
	push(my_stack, 6);
	push(my_stack, 7);
	push(my_stack, 8);
	print_stack(my_stack);
	pop(my_stack);
	print_stack(my_stack);
	free_stack(my_stack);
	print_stack(my_stack);
	return 0;
}