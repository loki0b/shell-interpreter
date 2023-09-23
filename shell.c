#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 80 /* command line max length */
#define MAX_TOKENS 40 /* tokens max length */

void separate_tokens(char *ch, char *arr_ch[]);

int main(void) {
	char args[MAX_LENGTH+1], *tokens[MAX_TOKENS];
	int running; /* flag to determine when to exit program */
	pid_t pid;

	running = 1;
	while (running)	{
		printf("hgl>");
		fflush(stdout);

		fgets(args, MAX_LENGTH, stdin);
		args[strcspn(args, "\n")] = 0;

		pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork failed");
			return -1;
		} 
		else if (pid == 0) {
			printf("Child process init\n");
			separate_tokens(&*args, tokens);
			execvp(tokens[0], tokens);
		}
		else {
			wait(NULL);
			printf("\nChild process finished\n");
		}

		running = 0;
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