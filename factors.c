#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - Returns the 2 factors of a number.
 * @argc : Number of args.
 * @argv : Pointer to array of args.
 * Return: 0 Succes, 1 else.
 */
int main(int argc, char **argv)
{
	int line_number = 0, i, j, a, b;
	FILE *file;
	char **arr_lines;

	file = fopen(argv[1], "r");
	if (file == NULL)
		return (1);
	arr_lines = malloc(sizeof(char *) * 50);
	if (arr_lines == NULL)
		return (1);
	while (!feof(file) && !ferror(file))
	{
		arr_lines[line_number] = malloc(sizeof(char) * 100);
		if (arr_lines[line_number] == NULL)
			return (1);
		if (fgets(arr_lines[line_number], 100, file) != NULL)
			line_number++;
	}
	for (j = 0; j < line_number; j++)
	{
		arr_lines[j][strlen(arr_lines[j]) - 1] = '\0';
		for (i = 2; i < atoi(arr_lines[j]); i++)
		{
			if (atoi(arr_lines[j]) % i == 0)
			{
				a = i;
				b = atoi(arr_lines[j]) / i;
				printf("%d=%d*%d\n", atoi(arr_lines[j]), a, b);
				break;
			}
		}
	}
	fclose(file);
	return (0);
}
