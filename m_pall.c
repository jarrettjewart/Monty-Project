#include "monty.h"

/**
 * m_pall - print all values on the stack from the top
 * @stack: dble ptr at head of the stack
 * @line_number: line number being exe.
 */

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
