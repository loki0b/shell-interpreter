#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 80 /* Command line max length */
#define MAX_TOKENS 40 /* Tokens max length */

void separate_tokens(char *ch, char *arr_ch[]);

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

		pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork failed");
			return -1;
		} 
		else if (pid == 0) {
			if (run_history) {
				separate_tokens(history, tokens);
			} else {
				separate_tokens(args, tokens);
			}
			execvp(tokens[0], tokens);
		}
		else {
			wait(NULL);
		}
	}

	return 0;
}

void separate_tokens(char *ch, char *arr_ch[]) {
	/* Function to separate args of typed command line */
	char *token;
	int t_i = 0;

	token = strtok(ch, " ");
	do {
		arr_ch[t_i] = token;
		token = strtok(NULL, " ");
		t_i++;
	} while (token != NULL);
	arr_ch[t_i] = NULL; // Indicate the final of args in array
}