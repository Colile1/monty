#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _queue(stack_t **stack_head, unsigned int line_num)
{
	(void)stack_head;
	(void)line_num;

	vglo.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _stack(stack_t **stack_head, unsigned int line_num)
{
	(void)stack_head;
	(void)line_num;

	vglo.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _add(stack_t **stack_head, unsigned int line_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack_head)->next;
	aux->n += (*stack_head)->n;
	_pop(stack_head, line_num);
}

/**
 * _nop - doesn't do anythinhg
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _nop(stack_t **stack_head, unsigned int line_num)
{
	(void)stack_head;
	(void)line_num;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _sub(stack_t **stack_head, unsigned int line_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack_head)->next;
	aux->n -= (*stack_head)->n;
	_pop(stack_head, line_num);
}
