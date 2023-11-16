#include "monty.h"
/**
 * pall - prints the stack
 * @head: stack head
 * @count: no used
 * Return: no return
 */
void pall(stack_t **head, unsigned int count)
{
	stack_t *s;
	(void)count;

	s = *head;
	if (s == NULL)
		return;
	while (s)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}
