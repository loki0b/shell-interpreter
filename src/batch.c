#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"
#include <string.h>

int batch_exec(char *argv[]){
    char buffer[60]; 
    char *command;
	char *token;
    FILE *batch;

    batch = fopen(argv[1], "r");

    if (batch != NULL) {
        fgets(buffer, sizeof(buffer), batch); 
        command = strtok(buffer, " \n"); 
        
        while (token != NULL) {
            token = strtok(NULL, " \n");
        }

        execvp(command, token);
        
    } else {
        fprintf(stderr, "File doesn't exist");
        return 1;
    }
    return 0;
}
