#include <unistd.h>
#include <sys/types.h>
#include "constants.h"

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
		//fprintf(stderr, "Fork failed");
		return -1;
	} else if (pid == 0) {
		execvp(prg[0], prg);
	} else {
		wait(NULL);
	}

	return 0;
}