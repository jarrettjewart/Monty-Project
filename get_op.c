#include "monty.h"

/**
 * get_op - checks opcodes
 * @op: op being checked
 * @stack: dble ptr at front of stack
 * @line_number: script line number
 */

void get_op(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t vaild_ops[] = {
		{"push", m_push},
		{"pall", m_pall}
	};

	for (i = 0; valid_ops[i].opcode != NULL; i++)
	{
		if (strcmp(valid_ops[i].opcode, op) == 0)
		{
			valid_ops[i].f(stack, line_number);
			return;
		}
	}

	dprintf(STDOUT_FILENO'
			"L%u: unknown instruction %s\n",
			line_number, op);
	exit(EXIT_FAILURE);
}
