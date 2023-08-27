#define _GNU_SOURCE
#include "monty.h"
/**
  *main - the main function for the mony program
  *@argc: the number of arguments passed
  *@argv: the arguments themselves
  *
  *Return: exit success or failure
  */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	size_t n, w;
	unsigned int line_num = 1;
	int count;

	tail = head = NULL;
	cmd = malloc(sizeof(char *) * 2);
	if (cmd == NULL)
		exit_m("Error: malloc failed");
	readbuf = NULL;
	atexit(cleanup);
	n = w = 0;
	if (argc < 2)
		exit_m("USAGE: monty file");
	for (count = 1; count < argc; count++)
	{
		file = fopen(argv[count], "r");
		if (file == NULL)
		{
			dprintf(2, "Error: Can't open file %s\n", argv[count]);
			exit(EXIT_FAILURE);
		}
		while (!(w = getline(&readbuf, &n, file) == -1))
		{
			cmdgen(readbuf);
			if (cmd[0] != NULL)
				opcodemgr(cmd, &tail, &line_num);
			reset2xarr(&cmd);
		}
		fclose(file);
	}
	exit(EXIT_SUCCESS);
}
/**
  *cleanup - function to clean up the memory resources alloced
  *
  *Return: void
  */
void cleanup(void)
{
	free(readbuf);
	free(cmd);
	freestack();
}
/**
  *cmdgen - generates the command from the read buffer
  *@readbuf: the memory location used as a read buffer
  *
  *Return: the command and its parameters
  */
char **cmdgen(char *readbuf)
{
	char *del = "\n ";
	char *temp;

	temp = strtok(readbuf, del);
	if (temp != NULL)
		cmd[0] = strdup(temp);
	temp = strtok(NULL, del);
	if (temp != NULL)
		cmd[1] = strdup(temp);
	return (cmd);
}
/**
  *exit_m - exits the program with error message
  *@msg: the exit message
  *
  *Return: void
  */
void exit_m(char *msg)
{
	if (msg != NULL)
		fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
