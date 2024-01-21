#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number
 * Return: no return
 */

void _push(stack_t **stack_head, unsigned int line_num)
{
	int n, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_num);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(stack_head, n);
	else
		add_dnodeint_end(stack_head, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line numbers
 * Return: no return
 */
void _pall(stack_t **stack_head, unsigned int line_num)
{
	stack_t *aux;
	(void)line_num;

	aux = *stack_head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _pint(stack_t **stack_head, unsigned int line_num)
{
	(void)line_num;

	if (*stack_head == NULL)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack_head)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _pop(stack_t **stack_head, unsigned int line_num)
{
	stack_t *aux;

	if (stack_head == NULL || *stack_head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *stack_head;
	*stack_head = (*stack_head)->next;
	free(aux);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _swap(stack_t **stack_head, unsigned int line_num)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack_head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *stack_head;
	*stack_head = (*stack_head)->next;
	aux->next = (*stack_head)->next;
	aux->prev = *stack_head;
	(*stack_head)->next = aux;
	(*stack_head)->prev = NULL;
}
