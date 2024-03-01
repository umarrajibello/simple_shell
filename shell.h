#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
extern char environ;

void prompt(void);
char *r_input(void);
void read_command(char param);
void run_cmd(char **cmd_vec);
char **tokenize_input(char *input);


#endif /*SHELL_H*/
