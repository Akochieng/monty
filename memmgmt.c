#include "monty.h"
/**
  *free2xarray - frees a two dimensional array
  *
  *Return: void
  */
void free2xarray(char **arr)
{
	if (arr == NULL)
		return;
	if (arr[0] != NULL)
		free(arr[0]);
	if (arr[1] != NULL)
		free(arr[1]);
	free(arr);
}
/**
  *reset2xarr - resets the contents of a two dimensional array
  *
  *Return: void
  */
void reset2xarr(char ***arr)
{
	char **temp = *arr;
	int i = 0;

	while (i < 2 && temp[i])
	{
		free(temp[i]);
		temp[i++] = NULL;
	}
}
/**
  *freestack - frees up the contents of a stack
  *
  *Return: void
  */
void freestack(void)
{
	stack_t *temp, *prev;

	if (tail == NULL)
		return;
	temp = tail;
	while (!(temp == NULL))
	{
		prev = temp->prev;
		free(temp);
		temp = prev;
	}
	tail = NULL;
	head = NULL;
}
