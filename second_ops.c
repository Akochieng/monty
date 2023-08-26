#include "monty.h"
/**
  *add - function that adds the two top number in the stack
  *and stores result in the second node and pops up the top node
  *@stack: the tail of the stack
  *@line_number: the number of the line
  *
  *Return: void
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *prev;
	int sum = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		exit_m(NULL);
	}
	prev = (*stack)->prev;
	sum = (*stack)->n + prev->n;
	prev->n = sum;
	temp = *stack;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}
/**
  *nop - does nothing to the stack
  *@stack: the tail of the stack
  *@line_number: the number of the line
  *
  *Return: void
  */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number
		__attribute__((unused)))
{
}

/**
  *sub - subtract the top element of the stack from the second one
  *@stack: the tail of the stack
  *@line_number: the number of the line
  *
  *Return: void
  */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *prev;
	int dif = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit_m(NULL);
	}
	prev = (*stack)->prev;
	dif = prev->n - (*stack)->n;
	prev->n = dif;
	temp = *stack;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}

/**
  *thediv - divide the top element in the stack be the second one
  *@stack: the tail of the stack
  *@line_number: the number of the line
  *
  *Return: void
  */
void thediv(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *prev;
	int dif = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		exit_m(NULL);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
				line_number);
		exit_m(NULL);
	}
	prev = (*stack)->prev;
	dif = prev->n / (*stack)->n;
	prev->n = dif;
	temp = *stack;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}

/**
  *mul - multiply the top element in the stack by the second one
  *@stack: the tail of the stack
  *@line_number: the number of the line
  *
  *Return: void
  */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *prev;
	int prod = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				line_number);
		exit_m(NULL);
	}
	prev = (*stack)->prev;
	prod = (*stack)->n * prev->n;
	prev->n = prod;
	temp = *stack;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}
