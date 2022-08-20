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
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_code},
		{NULL, NULL}
	};
	unsigned int line_number = 1;
	int i, j, fd_open, fd_read;
	char *buff_read, *line, *token;
	char **tokens;
	size_t len = 0;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd_open = open(argv[1], O_RDONLY);
	if (fd_open == -1)
	{
		dprintf(2, "Error: Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	buff_read = malloc(1024);
	fd_read = read(fd_open, buff_read, 1024);
	if (buff_read == NULL || fd_read == -1)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fd_read) != - 1)
	{
		j = 0;
		token = strtok(line, " ");
		while (token != NULL)
		{
			token = strtok(NULL, " ");
			j++;
		}
		tokens = malloc(sizeof(char *) * j);
		tokens[j] = token;
		i = 0;
		while (i < 7)
		{
			if (strcmp(tokens[i], opcodes[i].opcode) == 0)
					opcodes[i].f;
			else
			{
				dprintf(2, "L%d: unknown instruction %s\n", line_number, argv[1]);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		line_number ++;
	}
	free(buff_read);
	close(fd_open);
	free(line);
	return (0);
}
