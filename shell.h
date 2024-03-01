#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
extern char environ;

void prompt(void);
void read_command(char param);
void run_cmd(char *cmd);
char tokenize_input(char *input);
char *rec_cmd(void);

#endif /*SHELL_H*/
