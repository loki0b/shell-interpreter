#ifndef _EXEC_PGR_
#define _EXEC_PGR_

void execute_program(char *program, char *args[]);
char **parse_cmdline(char *input, char **args);

#endif
