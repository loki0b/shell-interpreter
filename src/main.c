#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

#define BUFFER_SIZE 60

int running_mode = 0; // Mode 0 to sequential, mode 1 to parallel

int main(int argc, char *argv[]) {

	if (argc == 2) {
		batch_exec(argv);
	}
 
    while (1) {
    	break; // Break here to temp avoid error with seq. and parallel.
      
		if (running_mode) {
            sequential_mode();
        } else{
            parallel_mode();
        }
        
    }

    exit(EXIT_SUCCESS);

}
