#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int running_mode = 1; // Mode 1 to sequential, mode 0 to parallel

int main(int argc, char *argv[]) {
	
	if (argc == 2) {
		batch_exec(argv);
	}
 
    while (1) {
    	break; // Break here to temp avoid error with seq. and parallel.
      
	if (running_mode) {
            sequential_mode();
        } else {
            parallel_mode();
        }
        
    }

    // why not just a return 0 ?
    exit(EXIT_SUCCESS);

}
