#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

int batch_exec(char *argv[]){
	char *buffer[60];
	FILE *batch;
	
	// TODO argc sendo 2 para rodar com apenas 1 argumento, futuramente outros casos serão tratados
	batch = fopen(argv[1], "r");
	if (batch != NULL) {
		fgets(buffer, 61, batch);
		char *command[] = {"/bin/sh", "-c", (char *) buffer, NULL};
		printf("%s", buffer);
		printf("%s", buffer[2]);
		execvp(command[0], command);
	} else {
		fprintf(stderr, "File doesn't exists");
	}
}
