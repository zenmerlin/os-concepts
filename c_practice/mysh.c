#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARG_LEN 80 /* Maximum number of command args */
#define MAX_ARGS 1000
#define TRUE 1
#define FALSE 0

int getargs(char *args[], int lim);
int getarg(char arg[], int lim);

int main(int argc, char *argv[])
{
        char *args[MAX_ARGS];
        int arg_count;
        int i;
        printf("jsh>");
        arg_count = getargs(args, MAX_ARGS);
        for (i = 0; i < arg_count; i++)
                printf("argument %d: %s\n", i, args[i]);
                free(args[i]);
        exit(0);
}

int getargs(char *args[], int lim)
{
        char arg[MAX_ARG_LEN];
        int c;
        int i = 0;
        do {
                memset(arg, 0, MAX_ARG_LEN);
                c = getarg(arg, MAX_ARG_LEN);
                args[i] = malloc(sizeof(char) * MAX_ARG_LEN);
                strcpy(args[i], arg);
                ++i;
        } while (c != '\n' && i < lim - 1);
        return i;
}

int getarg(char arg[], int lim)
{
        int i;
        int c;

        i = 0;
        while (i < lim - 1) {
                c = getchar();
                if (c != EOF && c != '\n' && c != ' ') {
                        arg[i] = c;
                        ++i;
                } else {
                        ++i;
                        break;
                }
        }
        arg[i] = '\0';
        if (c == EOF || c == '\n')
                return '\n';
        else
                return 0;
}
