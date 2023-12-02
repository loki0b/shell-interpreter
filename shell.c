#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "constants.h"

void separate_programs(char *ch, char *arr_ch[]);
int exec_programs(char *arr_prg);

int main(int argc, char *argv[]) {
	char args[MAX_LENGTH+1], history[MAX_LENGTH+1], *tokens[MAX_TOKENS+1];
	pid_t pid;

	// Flags
	int running = TRUE; /* Determine when to exit program */
	int run_history = FALSE; /* Determine when execute last command typed */
	int interactive_mode = FALSE;
	int batch_mode = FALSE;
	
	while (running)	{
		printf("hgl>");
		fflush(stdout);

		if (argc < 2) {
			interactive_mode = TRUE;
		} else if (argc == 2) {
			batch_mode = TRUE;
		} else {
			return -1;
		}

		if (interactive_mode) {
			fgets(args, MAX_LENGTH, stdin);
		} else if (batch_mode) {
			FILE *fptr;
			fptr = fopen(argv[1], "r");
			fgets(args, MAX_LENGTH, fptr);
			fclose(fptr);

			running = FALSE;
		}

		args[strcspn(args, "\n")] = 0; // Remove the "\n" char to use exec functions

		if (!(strcmp(args, "exit"))) // If user type "exit"
			running = FALSE;

		if (!(strcmp(args, "!!"))) 
			run_history = TRUE;
		else 
			strcpy(history, args); // Store last command typed

		if (run_history) {
			separate_programs(history, tokens);
			for (int i = 0; tokens[i] != NULL; i++) {
				exec_programs(tokens[i]);
			}
		} else {
			separate_programs(args, tokens);
			for (int i = 0; tokens[i] != NULL; i++) {
				exec_programs(tokens[i]);
			}
		}

		if (!running) {
			exit(EXIT_SUCCESS);
		}
	}
}