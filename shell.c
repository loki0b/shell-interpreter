#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 80 /* Command line max length */
#define MAX_TOKENS 40 /* Tokens max length */

void separate_programs(char *ch, char *arr_ch[]);
int exec_programs(char *arr_prg);

int main(int argc, char *argv[]) {
	char args[MAX_LENGTH+1], history[MAX_LENGTH+1], *tokens[MAX_TOKENS+1];
	int running; /* Flag to determine when to exit program */
	int run_history; /* Flag to determine when execute last command typed */
	pid_t pid;

	run_history = 0;
	running = 1;
	while (running)	{
		printf("hgl>");
		fflush(stdout);

		if (argc < 2) { // Interactive mode
			fgets(args, MAX_LENGTH, stdin);
		} else if (argc == 2) { // Batch mode
			FILE *fptr;
			fptr = fopen(argv[1], "r");
			fgets(args, MAX_LENGTH, fptr);
			fclose(fptr);

			running = 0;
		} else {
			fprintf(stderr, "Invalid arguments");
			return -1;
		}

		args[strcspn(args, "\n")] = 0; // Remove the "\n" char to use exec functions

		if (!(strcmp(args, "exit")))
			exit(EXIT_SUCCESS);

		if (!(strcmp(args, "!!"))) 
			run_history = 1;
		else 
			strcpy(history, args);

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
	}
}

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

int exec_programs(char *arr_prg) {
	/* Function to execute the programns in array of args */
	char *prg[MAX_LENGTH+1];
	pid_t pid;
	int i;

	char *token = strtok(arr_prg, " ");
	for (i = 0; token != NULL; i++) {
		prg[i] = token;
		token = strtok(NULL, " ");
	}
	prg[i] = NULL;

	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return -1;
	} else if (pid == 0) {
		execvp(prg[0], prg);
	} else {
		wait(NULL);
	}

	return 0;
}