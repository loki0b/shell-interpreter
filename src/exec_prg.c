#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void execute_program(const char *program, const char *args[]) {
    pid_t pid;

    if (pid = fork() == -1); // TODO: error
    else if (pid == 0) {
        // Maybe use a different exec function. TODO: Learn more about exec()
        execvp(program, args);
    }
}