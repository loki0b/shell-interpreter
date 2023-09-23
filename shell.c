#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 80 /* command line max length */
#define MAX_TOKENS 40 /* tokens max length */
#define EXIT "exit"

void separate_tokens(char *ch, char *arr_ch[]);

int main(int argc, char *argv[]) {
	char args[MAX_LENGTH+1], *tokens[MAX_TOKENS+1];
	int running; /* flag to determine when to exit program */
	pid_t pid;

	running = 1;
	while (running)	{
		printf("hgl>");
		fflush(stdout);

		if (argc < 2) { // interactive mode
			fgets(args, MAX_LENGTH, stdin);	
		} else if (argc == 2) { // batch mode
			FILE *fptr;
			fptr = fopen(argv[1], "r");
			fgets(args, MAX_LENGTH, fptr);
			running = 0;
			
		} else {
			fprintf(stderr, "Invalid arguments");
			return -1;
		}

		args[strcspn(args, "\n")] = 0;

		if (!(strcmp(args, EXIT)))
			exit(EXIT_SUCCESS);

		pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork failed");
			return -1;
		} 
		else if (pid == 0) {
			separate_tokens(args, tokens);
			execvp(tokens[0], tokens);
			exit(EXIT_SUCCESS);
		}
		else {
			wait(NULL);
		}
	}

	return 0;
}

void separate_tokens(char *ch, char *arr_ch[]) {
	char *token;
	int t_i = 0;

	token = strtok(ch, " ");
	do {
		arr_ch[t_i] = token;
		token = strtok(NULL, " ");
		t_i++;
	} while (token != NULL);
	arr_ch[t_i] = NULL;
}