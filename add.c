#include "monty.h"

/**
 * m_add - add 2 elements in the stack
 * @stack: dble ptr at front of stack
 * @line_number: script line number
 */

void m_add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO'
				"L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	m_pop(stack, line_number);
	(*stack)-> += n;
}
