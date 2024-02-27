#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

extern bool running;

int batch_exec(char *argv[]){
	char *buffer[60];
	FILE *batch;
	
	batch = fopen(argv[1], "r");
	if (batch != NULL) {
		fgets(buffer, 61, batch);
//		execvp();
	} else {
		fprintf(stderr, "File doesn't exists");
        running = false;

        return -1;
	}
}
