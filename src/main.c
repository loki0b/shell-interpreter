#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shell_functions.h"

#define BUFFER_SIZE 60

int main(int argc, char *argv[]) {
    bool running = true;
    char buffer[BUFFER_SIZE]; 
    
    while (running) {
        printf("sh>");
        fgets(buffer, BUFFER_SIZE, stdin);
        // execute_program("ls", cmd);
        exit(EXIT_SUCCESS);
    }
}