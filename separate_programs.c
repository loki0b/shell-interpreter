#include <stdlib.h>

void separate_programs(char *command_line, char *tokens[]) {
	/* Function to separate programs of command line.
  The first command line that user types */
	char *aux_token;
	int i;
	
	aux_token = strtok(command_line, ";\n");
	for (i = 0; aux_token != NULL; i++) {
		tokens[i] = aux_token;
		aux_token = strtok(NULL, ";");
	}
	tokens[i] = NULL; // Indicate the final of args in array
}