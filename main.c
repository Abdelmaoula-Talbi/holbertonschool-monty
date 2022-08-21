#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (On success)
 */
int main(int argc, char *argv[])
{
	instruction_t opcodes[] = {
		{"pall", op_pall},
		{"pint", op_pint},
		/*{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},*/
		{NULL, NULL}
	};
	unsigned int line_number = 1;
	int i, j;
	FILE *fd_open/*, *fd_read*/;
	char *line, *token/*, *buff_read*/;
	char **tokens;
	size_t len = 0;
	stack_t *new;
	stack_t **stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd_open = fopen(argv[1], O_RDONLY);
	if (fd_open == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	/*buff_read = malloc(1024);
	fd_read = read(fd_open, buff_read, 1024);
	if (buff_read == NULL || fd_read == -1)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}*/
	while (getline(&line, &len, fd_open) != - 1)
	{
		j = 0;
		token = strtok(line, " \n");
		while (token != NULL)
		{
			tokens[j] = token;
			token = strtok(NULL, " \n");
			j++;
		}
		tokens = malloc(sizeof(char *) * j);
		if (strcmp(tokens[0], "push") == 0)
		{
			new = malloc(sizeof(stack_t));
			if (new == NULL || tokens[1] == NULL || atoi(tokens[1]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			new->n = atoi(tokens[1]);
			new->next = (*stack);
			new->prev = NULL;
			if ((*stack) != NULL)
				(*stack)->prev = new;
			(*stack) = new;
		}
		i = 0;
		while (i < 2/*6*/)
		{
			if (strcmp(tokens[0], opcodes[i].opcode) == 0)
				opcodes[i].f(stack, line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, argv[1]);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		line_number ++;
	}
	/*free(buff_read);
	close(fd_open);*/
	free(line);
	return (0);
}
