#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

#define BUFFER_SIZE 60

int main(int argc, char *argv[]) {
    bool running = true;
    char buffer[BUFFER_SIZE];
    bool sequential_flg = true;
    bool parallel_flg = false;
	char command[60];

    while (running) {
        if (argc == 2) {
			batch_exec(argv);
			return 0;
		}
		if (sequential_flg) {
            sequential_mode();
        }
        
        if (parallel_flg) {
            parallel_mode();
        }

        exit(EXIT_SUCCESS);
    }

}
