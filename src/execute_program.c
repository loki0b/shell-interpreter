#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void execute_program(char *program, char *args[]) {
    pid_t pid;

    if (pid = fork() == -1) { /*  TODO: error */ ;}
    else if (pid == 0) {
        // Maybe use a different exec function. TODO: Learn more about exec family function
        execvp(program, args);
    }
}