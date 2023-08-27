#include "monty.h"
/**
  *checkopcode - checks for the function matching the command
  *@cmd: an array with the command and its parameters
  *
  *Return: the function pointer or NULL if none
  */
operand checkopcode(char **cmd)
{
	instruction_t codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", thediv},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	for (i = 0; codes[i].f != NULL; i++)
		if (strcmp(cmd[0], codes[i].opcode) == 0)
			return (codes[i].f);
	return (NULL);
}
/**
  *opcodemgr - function that runs the command
  *@cmd: the command and its parameters
  *@tail: the head of the stack
  *@line_number: the line number of the script
  *
  *Return: void
  */
void opcodemgr(char **cmd, stack_t **tail, unsigned int *line_number)
{
	operand func = NULL;

	if (cmd[0][0] == '#')
		return;
	func = checkopcode(cmd);
	if (func == NULL && cmd[0][0] == '\n')
		return;
	++line_number;
	if (func == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", *line_number,
				cmd[0]);
		exit_m(NULL);
	}
	func(tail, *line_number);
}
/**
  *isint - checks whether the first two characters are intergers'
  *@s: the string
  *
  *Return: 1 if int, otherwise, 0
  */
int isint(char *s)
{
	if (s[0] >= '0' && s[0] <= '9')
		return (1);
	else if (s[0] == '-')
		if (s[1] && s[1] >= '0' && s[1] <= '9')
			return (1);
	return (0);
}
