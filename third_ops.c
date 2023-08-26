#include "monty.h"

/**
  *mod - find the mode of the top and second number
  *@stack: the tail of the stack
  *@line_number: the number of the line
  *
  *Return: void
  */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *prev;
	int modd = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
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
	modd = prev->n % (*stack)->n;
	prev->n = modd;
	temp = *stack;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}

/**
  *pchar - print the ascii character of the number
  *@stack: the tail of the stack
  *@line_number: the number of the line
  *
  *Return: void
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
				line_number);
		exit_m(NULL);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
		exit_m(NULL);
	}
	print_char((*stack)->n);
}
/**
  *print_char - helper function to print ascii characters
  *@c: the interger to be printed
  *
  *Return: void
  */
int print_char(int c)
{
	char a = (char)c;

	return (write(1, &a, 1));
}
/**
  *pstr - print a string from the stack
  *@stack: the tail of the stack
  *@line_number: the number of the line
  *
  *Return: void
  */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;
	while (!(temp == NULL) || !(temp->n == 0))
	{
		if (temp->n < 0 || temp->n > 127)
			break;
		print_char(temp->n);
	}
	printf("\n");
}
