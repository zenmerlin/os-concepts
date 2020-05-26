#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE_LEN 1000 /* Max line length */
#define MAX_ARGS 80 /* Max number of args */
#define TRUE 1
#define FALSE 0

void input_line(char *str, int size);
int parse_args(char *line, char *args[]);
void get_token(char *line, int start, int end, char *token);

int main(int argc, char *argv[])
{
        char line[MAX_LINE_LEN];
        char *args[MAX_ARGS];
        int argn;
        int i;
        
        printf("jsh>");
        input_line(line, MAX_LINE_LEN);
        printf("\nYou entered: %s\n", line);
        argn = parse_args(line, args);
        for (i = 0; i <= argn; i++) {
                printf("args[%d]: %s\n", i, args[i]);
                free(args[i]);
        }
        exit(0);
}

void input_line(char *str, int size)
{
        int i;
        fgets(str, size, stdin);

        /* Strip out newline character if there is one */
        for (i=0; i<size; i++) {
                if (str[i] == '\n') {
                        str[i] = '\0';
                        return;
                }
        }
}

int parse_args(char *line, char *args[])
{
        int i;
        int start = -1;
        int end = -1;
        int in = FALSE;
        int argn = 0;

        for (i = 0; i < MAX_LINE_LEN && argn < (MAX_ARGS - 1); i++) {
                if (line[i] != ' ' && !in) {
                        in = TRUE;
                        start = i;
                        continue;
                }
                if (line[i] == ' ' && in || line[i] == '\0' && in) {
                        in = FALSE;
                        end = i - 1;
                        args[argn] = malloc(sizeof(char) * (end - start + 2));
                        get_token(line, start, end, args[argn]);
                        argn++;
                }
                if (line[i] == '\0')
                        break;
        }
        return --argn;
}

void get_token(char *line, int start, int end, char *token)
{
        int i;
        int j = 0;
        char t[end-start+2];
        for (i = start; i <= end; i++) {
                t[j++] = line[i];
        }
        t[j] = '\0';
        strcpy(token, t);
}
