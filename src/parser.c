#include <stdio.h>
#include <string.h>

#define DELIMETERS " \n"

char **separate_cmdline(char *cmd_input, char **cmd_return) {
    // TOREAD: strtok_r function
    char *token = strtok(cmd_input, DELIMETERS);
    int i = 0;
    for (; token != NULL; i++) {
       cmd_return[i] = token;
       token = strtok(NULL, DELIMETERS);
    }
    cmd_return[i] = NULL;

    return cmd_return;
}