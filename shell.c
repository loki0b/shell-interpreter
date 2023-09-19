#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 40
#define BIN_PATH "/bin/"

int main(void) {
	char args[MAX_LENGTH+1], *tokens, *arg_bin;
	int run = 1; /* flag to determine to exit program */
	pid_t pid;

	while (run)	{
		printf("shell>");
		fflush(stdout);
		fgets(args, MAX_LENGTH+1, stdin);
		tokens = strtok(args, " ");

		pid = fork();
		
		if (pid < 0);
		else if (pid == 0) {
			arg_bin = BIN_PATH;
			strcat(arg_bin, tokens);
			execlp(arg_bin, "ls", NULL);
			printf("Fork completed");
		}
		else {
			printf("test");
			wait(NULL);
		}

		run = 0;
	}

	return 0;
}
