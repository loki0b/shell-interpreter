#include <stdlib.h>

void separate_programs(char *command_line, char *arr_prg[]) {
	/* Function to separate programs of command line */
	char *token;
	int i;
	
	token = strtok(command_line, ";\n");
	for (i = 0; token != NULL; i++) {
		arr_prg[i] = token;
		token = strtok(NULL, ";");
	}
	arr_prg[i] = NULL; // Indicate the final of args in array
}