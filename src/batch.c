#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

int batch_exec(char *argv[]){
	char *buffer[60];
	FILE *batch;

	*buffer[1] = NULL;
	// TODO argc sendo 2 para rodar com apenas 1 argumento, futuramente outros casos serão tratados
	batch = fopen(argv[1], "r");
	if (batch != NULL) {
		fgets(buffer, 61, batch);
		printf("%s\n", buffer);
		printf("%s\n", buffer[1]);
		execvp(buffer[0], buffer);
	} else {
		fprintf(stderr, "File doesn't exists");
	}
}
