#ifndef _EXEC_PGR_
#define _EXEC_PGR_

void execute_program(char *program, char *args[]);
char **separate_cmdline(char *cmd_input, char **cmd_return);

#endif