#include "monty.h"

/**
  *rotl - rotate the stack
  *@stack: the tail of the stack
  *@line_number: the line number
  *
  *Return: void
  */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp, *last;

	if (*stack == NULL || (*stack)->prev == NULL)
		return;
	temp = *stack;
	last = temp->prev;
	while (!(last->prev == NULL))
		last = last->prev;
	temp->next = last;
	last->prev = temp;
	last = temp;
	temp = last->prev;
	last->prev = NULL;
	temp->next = NULL;
	*stack = temp;
}
/**
  *rotr - rotate the stack
  *@stack: the tail of the stack
  *@line_number: the line number
  *
  *Return: void
  */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp, *last;

	if (*stack == NULL || (*stack)->prev == NULL)
		return;
	temp = *stack;
	last = temp->prev;
	while (!(last->prev == NULL))
		last = last->prev;
	temp->next = last;
	last->prev = temp;
	temp = last;
	last = temp->next;
	last->prev = NULL;
	temp->next = NULL;
	*stack = temp;
}
