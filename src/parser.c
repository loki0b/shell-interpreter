#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMETERS " \n"
#define MAX_SIZE 10

char** parser(char *input) {
    char *token;
    char **parsed_input;
    int i;

    parsed_input = (char**) malloc(sizeof(char*) * MAX_SIZE);
    if (!parsed_input) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    token = strtok(input, DELIMETERS);
    while (token != NULL && i < MAX_SIZE) {
        parsed_input[i] = strdup(token); // read more about  strdup and remember to dealocate each string inside parse_input
        if (!parsed_input[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, DELIMETERS);
        i++;
    }
    parsed_input[i] = NULL;

    return parsed_input;
}
