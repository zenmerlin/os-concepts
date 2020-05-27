#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <linux/limits.h>

#define MAX_LINE_LEN 1000   /* Max line length */
#define MAX_ARGS 80         /* Max number of args */
#define MAX_USERNAME_LEN 32 /* Max length of user name */
#define MAX_HOSTNAME_LEN 63 /* Max length of hostname */
#define TRUE 1
#define FALSE 0

void display_prompt();
void input_line(char *str, int size);
int parse_args(char *line, char *args[]);
void get_token(char *line, int start, int end, char *token);
void run_cmd(char *args[]);

int main(int argc, char *argv[])
{
        char line[MAX_LINE_LEN];
        char *args[MAX_ARGS];
        int argn, i;
        int running = TRUE;
        
        while (running) {
                memset(line, '\0', MAX_LINE_LEN);
                memset(args, '\0', MAX_ARGS);
                display_prompt();
                input_line(line, MAX_LINE_LEN);
                argn = parse_args(line, args);
                if (strcmp(args[0], "exit") == 0)
                        running = FALSE;
                run_cmd(args);
                for (i = 0; i <= argn; i++)
                        free(args[i]);
        }
        exit(0);
}

void display_prompt()
{
        char cwd[PATH_MAX];
        char user[MAX_USERNAME_LEN];
        char host[MAX_HOSTNAME_LEN];

        if (getlogin_r(user, sizeof(user)) != 0) {
                perror("Error: ");
                exit(1);
        }
        if (gethostname(host, sizeof(host)) < 0) {
                perror("Error: ");
                exit(1);
        }
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
                perror("Error: ");
                exit(1);
        }
        printf("%s@%s: %s\n$ ", user, host, cwd);
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
                if ((line[i] == ' ' && in) || (line[i] == '\0' && in)) {
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

void run_cmd(char *args[])
{
        int rc;
        rc = fork();
        if (rc < 0) {
                fprintf(stderr, "Fork failed\n");
                exit(1);
        } else if (rc == 0) {
                execvp(args[0], args);
        } else {
                wait(NULL);
        }
}
