#include <stdio.h>
#include <string.h>

#define DELIMETERS " \n"

char **parser_cmdline(char *input, char **args) {
    // TOREAD: strtok_r function
    char *token = strtok(input, DELIMETERS);
    int i = 0;
    for (; token != NULL; i++) {
       args[i] = token;
       token = strtok(NULL, DELIMETERS);
    }
    args[i] = NULL;

    return args;
}
