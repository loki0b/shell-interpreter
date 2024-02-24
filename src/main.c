#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"

#define BUFFER_SIZE 60

int main(int argc, char *argv[]) {
    bool running = true;
    char buffer[BUFFER_SIZE]; 
    char *cmd[10];

    while (running) {
        printf("sh>");
        fgets(buffer, BUFFER_SIZE, stdin);
        // Should I encapsulate the separate_cmdline function?
        parser_cmdline(buffer, cmd);
        execute_program(cmd[0], cmd);
        exit(EXIT_SUCCESS);
    }
}
