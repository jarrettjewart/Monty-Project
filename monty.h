#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/** Structs **/

/**
 * struct var_s - struct to contain varis of the interp
 * @queue: flag used to choose in stack or queue mode
 * @stack_len: length of the stack
 */

typedef struct var_s
{
	int queue;
	size_t stack_len;
} var_t;

#define STACK 0
#define QUEUE 1

/**
 *  * struct stack_s - doubly linked list representation of a stack (or queue)
 *   * @n: integer
 *    * @prev: points to the previous element of the stack (or queue)
 *     * @next: points to the next element of the stack (or queue)
 *      *
 *       * Description: doubly linked list node structure
 *        * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 *  * struct instruction_s - opcode and its function
 *   * @opcode: the opcode
 *    * @f: function to handle the opcode
 *     *
 *      * Description: opcode and its function
 *       * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** global struct */
extern var_t  var;

/** Prototypes **/
void m_push(stack_t **stack, unsigned int line_number);
void get_op(char *op, stack_t **stack, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **stack, const int n);
void free_stack(int status, void *arg);
void m_pint(stack_t **stack, unsigned int line_number);
#endif
