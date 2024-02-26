#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 60

int main(int argc, char *argv[]) {
    bool running = true;
    char *buffer[BUFFER_SIZE];
 
    while (running) {
        printf("sh>");
        //TODO: Criar função para input com fgets()
        fgets(buffer, BUFFER_SIZE, stdin);
        exit(EXIT_SUCCESS);
    }

}
