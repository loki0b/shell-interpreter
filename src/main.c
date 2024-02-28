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

	break;
	if (running_mode) {
            sequential_mode();
        } else {
            parallel_mode();
        }
        
    }

    exit(EXIT_SUCCESS);

}
