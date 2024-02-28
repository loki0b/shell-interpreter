#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int running_mode = 0; // Mode 0 to sequential, mode 1 to parallel

// changed **argv to a better comprehension 
int main(int argc, char *argv[]) {

    // batch_exec outside while, this doesn't have to be on a loop, it will run only 1 time
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

    // why not just a return 0 ?
    exit(EXIT_SUCCESS);

}
