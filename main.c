#include "monty.h"
instruction_t opcodes[] = {{"push", push}, {"pall", pall},
	{"pint", pint}, {NULL, NULL}
};

/**
 * main - to read the monty code
 * @argc: number of arguments
 * @argv: array of string of arguments passed
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *mfile;
	unsigned int i, is_instruction, line_no = 0;
	stack_t *stack = NULL;
	char *opcode, *line_buffer = NULL;
	size_t line_b_size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mfile = fopen(argv[1], "r");
	if (mfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line_buffer, line_b_size, mfile) != NULL)
	{
		line_no++;
		opcode = strtok(line_buffer, "\n");
		is_instruction = 0;

		if (opcode == NULL)
			continue;

		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_no);
				is_instruction = 1;
				break;
			}
		}
		if (!is_instruction)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_no, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(line_buffer);
	fclose(mfile);
	return (0);
}
