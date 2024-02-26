#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 60

int main(int argc, char *argv[]) {
    bool running = true;
    char buffer[BUFFER_SIZE];
	FILE *batch;	
 
    while (running) {
	// TODO argc sendo 2 para rodar com apenas 1 argumento, futuramente outros casos serão tratados
	if (argc == 2) {
		batch = fopen(argv[1], "r");
		if (batch != NULL) {
			fgets(buffer, BUFFER_SIZE, batch);
			//execute_function();
		} else {
			fprintf(stderr, "File doesn't exists");
		}
			running = false;
	} else {
		printf("sh>");
       	//TODO: Criar função para input com fgets()
        fgets(buffer, BUFFER_SIZE, stdin);
        exit(EXIT_SUCCESS);
 
		}
	}

}
