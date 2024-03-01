#ifndef _SHELL_H_
#define _SHELL_H_

int sequential_mode();
int parallel_mode();
int batch_exec(char *argv[]); 
int execute_command(char **command);
char** parser(char *input);

#endif
