#include "monty.h"
/**
  *push - pushes the parameter in the cmd to the stack
  *@stack: the tail of the stack
  *@line_number: the line number
  *
  *Return: void
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (cmd[1] == NULL || isint(cmd[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit_m(NULL);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit_m("Error: malloc failed");
	new->n = atoi(cmd[1]);
	new->next = NULL;
	if (*stack == NULL)
		new->prev = NULL;
	else
		new->prev = *stack;
	*stack = new;
}
/**
  *pall - prints all the numbers in the stack
  *@stack: the tail of the stack
  *@line_number: the line number of the stack
  *
  *Return: void
  */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *prev;

	if (*stack == NULL)
		return;
	prev = *stack;
	while (!(prev == NULL))
	{
		printf("%d\n", prev->n);
		prev = prev->prev;
	}
}
/**
  *pint - prints the interger at the top of the stack
  *@line_number: the line number
  *@stack: the tail of the stack
  *
  *Return: void
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_m(NULL);
	}
	printf("%d\n", (*stack)->n);
}
/**
  *pop - remove the interger at the top ot the stack
  *@line_number: the line number
  *@stack: the stack
  *
  *Return: void
  */
void  pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				line_number);
		exit_m(NULL);
	}
	temp = *stack;
	*stack = temp->prev;
	free(temp);
}
/**
  *swap - swap the top intergers in the stack
  *@stack: the tail of the stack
  *@line_number: the line number
  *
  *Return: void
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *cur;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_m(NULL);
	}
	cur = *stack;
	temp = cur->prev;
	if (temp->prev != NULL)
	{
		(temp->prev)->next = cur;
		cur->prev = temp->prev;
	}
	else
		cur->prev = NULL;
	cur->next = temp;
	temp->prev = cur;
	temp->next = NULL;
	*stack = temp;
}
