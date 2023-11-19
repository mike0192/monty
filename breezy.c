#include "monty.h"


/**
 * addy - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @one: Interger representing the line number of of the opcode.
 */
void addy(stack_t **new_node, __attribute__((unused))unsigned int one)
{
	stack_t *negative;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	negative = head;
	head = *new_node;
	head->next = negative;
	negative->prev = head;
}


/**
 * stacky - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void stacky(stack_t **stack, unsigned int line_number)
{
	stack_t *negative;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	negative = *stack;
	while (negative != NULL)
	{
		printf("%d\n", negative->n);
		negative = negative->next;
	}
}

/**
 * poppy - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void poppy(stack_t **stack, unsigned int line_number)
{
	stack_t *negative;

	if (stack == NULL || *stack == NULL)
		home(7, line_number);

	negative = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * printy - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void printy(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		home(6, line_number);
	printf("%d\n", (*stack)->n);
}
