#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _div(stack_t **stack_head, unsigned int line_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*stack_head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack_head)->next;
	aux->n /= (*stack_head)->n;
	_pop(stack_head, line_num);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _mul(stack_t **stack_head, unsigned int line_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack_head)->next;
	aux->n *= (*stack_head)->n;
	_pop(stack_head, line_num);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _mod(stack_t **stack_head, unsigned int line_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*stack_head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack_head)->next;
	aux->n %= (*stack_head)->n;
	_pop(stack_head, line_num);
}
/**
 * _pchar - print the char value of the first element
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _pchar(stack_t **stack_head, unsigned int line_num)
{
	if (stack_head == NULL || *stack_head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*stack_head)->n < 0 || (*stack_head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack_head)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _pstr(stack_t **stack_head, unsigned int line_num)
{
	stack_t *aux;
	(void)line_num;

	aux = *stack_head;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
