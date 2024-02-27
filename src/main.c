#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"

#define BUFFER_SIZE 60


bool running = true;
bool sequential = false;
bool parallel = false;
bool batch = false;

int main(int argc, char **argv) {

    while (running) {

        switch (argc) {
            case 1:
                sequential = true;
                break;
            case 2:
                batch = true;
                break;
            default:
                break;
        }

        if (batch) {
            batch_exec(argv);
            running = false;
        }
		
		if (sequential) {
            sequential_mode();
        }
        
        if (parallel) {
            parallel_mode();
        }

        exit(EXIT_SUCCESS);
    }

}
