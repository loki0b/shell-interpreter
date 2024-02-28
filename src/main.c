#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main(int argc, char **argv) {

    while (running) {
        if (argc == 2) {
            batch_exec(argv);
            break;
        }
        else if (argc == 1) {
            sequential_mode();
            break;
        }
        else {
            fprintf(stderr, "Error number of args dont match.\n");
            exit(EXIT_FAILURE);
        }
    }

    exit(EXIT_SUCCESS);

}
