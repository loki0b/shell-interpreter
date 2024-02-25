#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"
#include <string.h>

#define BUFFER_SIZE 60

int main(int argc, char *argv[]) {
    bool running = true;
    char buffer[BUFFER_SIZE]; 
    char *cmd[10];

    while (running) {
        printf("sh>");
        fgets(buffer, BUFFER_SIZE, stdin);

        // exit
        if (strcmp(buffer, "exit")) {
            ;
        }
        else {
           return 0;
           // exit(EXIT_SUCCESS);
        }

        // I'll need change this later
        parser(buffer, cmd);
        execute_program(cmd[0], cmd);
    }
}
