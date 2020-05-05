#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0

void strsplit(char str[], char *argv[], char delim[])
{
  char *ptr = strtok(str, delim);
  int i = 0;
  while (ptr != NULL)
  {
    argv[i] = ptr;
    ptr = strtok(NULL, delim);
    ++i;
  }
  argv[i] = NULL;
}

void to_commands(char str[], char *argv[])
{
  char delim[] = " ";
  strsplit(str, argv, delim);
}

void change_dir(const char *command)
{
  int code = chdir(command);
  if (code == -1)
  {
    perror("cd: ");
    exit(1);
  }
}

int main()
{
  printf("Type \"quit\" to close & exit the shell\n");
  while (TRUE)
  {
    char input[100]; // input string from the console
    char *argv[100]; // array of command and arguments
    char path[1000];
    char *newenviron[] = {NULL};
    pid_t pid; // pid of child process
    int err_code;

    if (getcwd(path, sizeof(path)) == NULL)
    {
      perror("path: ");
      exit(1);
    }
    // get the input
    printf("\n%s=> ", path);
    fgets(input, 100, stdin);
    // remove newline character
    input[strcspn(input, "\n")] = 0;
    // get command and arguments
    to_commands(input, argv);
    // check if needs to quit
    if (strstr(argv[0], "quit"))
    {
      exit(1);
    }

    // check if command is change directory
    if (strstr(argv[0], "cd"))
    {
      change_dir(argv[1]);
    }
    else
    {
      // fork child process
      pid = fork();

      if (pid == 0)
      {
        // execute the process
        if (execve(argv[0], argv, newenviron) == -1)
        {
          err_code = execvp(argv[0], argv);
        }
        if (err_code == -1)
        {
          printf("%s: ", argv[0]);
          perror("");
        }
      }
      else
      {
        waitpid(pid, NULL, 0);
      }
    }
  }
  return 0;
}