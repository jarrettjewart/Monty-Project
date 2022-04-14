#include "monty.h"

/**
 * add-node - add a new node to linked list
 * @stack: dble ptr front of list
 * @n: value to add to node
 * Return: ptr to new node, or NULL if fail
 */

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.pureue == STACK || var.stack_len == 0)
		*stack = new;
	return (new);
}
