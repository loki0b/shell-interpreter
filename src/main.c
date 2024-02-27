#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"

#define BUFFER_SIZE 60

// extern keyword is the best way?
bool running = false;
bool sequential = false;
bool parallel = false;
bool batch = false;

int main(int argc, char **argv) {

    switch (argc) {
        case 1:
            sequential = true;
            running = true;
            break;

        case 2:
            batch = true;
            running = true;
            break;
        
        // Add new cases (?)
        default:
            fprintf(stderr, "Error initializing shell.\n");
    }


    while (running) {

        if (batch) {
            batch_exec(argv);
        }
		
		if (sequential) {
            sequential_mode();
        }
        
        if (parallel) {
            parallel_mode();
        }

    }

    exit(EXIT_SUCCESS);

}
