#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @stack_head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _rotl(stack_t **stack_head, unsigned int line_num)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)line_num;

	if (*stack_head == NULL)
		return;

	if ((*stack_head)->next == NULL)
		return;

	aux1 = (*stack_head)->next;
	aux2 = *stack_head;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *stack_head;
	(*stack_head)->next = NULL;
	(*stack_head)->prev = aux2;
	*stack_head = aux1;
}

/**
 * _rotr - reverse the stack
 *
 * @stack_head: head of the linked list
 * @line_num: line number
 * Return: no return
 */

void _rotr(stack_t **stack_head, unsigned int line_num)
{
	stack_t *aux = NULL;
	(void)line_num;

	if (*stack_head == NULL)
		return;

	if ((*stack_head)->next == NULL)
		return;

	aux = *stack_head;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *stack_head;
	aux->prev = NULL;
	(*stack_head)->prev = aux;
	*stack_head = aux;
}
