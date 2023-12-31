#include "monty.h"

/**
 * open_file - opens a file
 * @fufu: the file namepath
 * Return: void
 */

void open_file(char *fufu)
{
	FILE *one = fopen(fufu, "r");

	if (fufu == NULL || one == NULL)
		just_go(2, fufu);

	read_file(one);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @one: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *one)
{
	int line_number, formy = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, one) != -1; line_number++)
	{
		formy = sonder_son(buffer, line_number, formy);
	}
	free(buffer);
}


/**
 * sonder_son - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @formy:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int sonder_son(char *buffer, int line_number, int formy)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		just_go(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (formy);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	HER(opcode, value, line_number, formy);
	return (formy);
}

/**
 * HER - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @formy:  storage format. If 0 Nodes will be entered as a stack.
 * @one: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void HER(char *opcode, char *value, int one, int formy)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call(func_list[i].f, opcode, value, HER, formy);
			flag = 0;
		}
	}
	if (flag == 1)
		just_go(3, one, opcode);
}


/**
 * call - Calls the required function.
 * @funky: Pointer to the function that is about to be called.
 * @one: string representing the opcode.
 * @value: string representing a numeric value.
 * @bruh: line numeber for the instruction.
 * @formy: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call(op_func funky, char *one, char *value, int bruh, int formy)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(one, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			just_go(5, bruh);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				just_go(5, bruh);
		}
		node = create_node(atoi(value) * flag);
		if (formy == 0)
			funky(&node, bruh);
		if (formy == 1)
			add_to_queue(&node, bruh);
	}
	else
		funky(&head, bruh);
}
