#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int running_mode = 1; // Mode 1 to sequential, mode 0 to parallel

int main(int argc, char *argv[]) {
 
    while (1) {
        if (argc == 2) {
	        batch_exec(argv);
            break;
        }
        else if (argc == 1) {
	        if (running_mode) sequential_mode();
            else parallel_mode();
            break;
        }
	// change later
	else {
		fprintf(stderr, "Error number of args dont match.\n");
        exit(EXIT_FAILURE);
	}

    }

    exit(EXIT_SUCCESS);

}
