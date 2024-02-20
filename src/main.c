#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 60

int main() {
    bool running = true;
    char buffer[BUFFER_SIZE];
    
    while (running) {
        printf("sh>");
        fgets(buffer, BUFFER_SIZE, stdin);
        exit(EXIT_SUCCESS);
    }
}