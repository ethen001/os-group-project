#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(void)
{
  pid_t pid_1, pid_2;
  int status;
  pid_1 = fork();
  if (pid_1 == 0)
  { //child1 process
    // printf("child process1: %d\n", getpid());
    char *argv_dir[] = {"mkdir", "Dir0", NULL};
    execvp("mkdir", argv_dir);
    printf("EXECP Failed\n");
  }
  else if (pid_1 > 0)
  { //parent process
    waitpid(pid_1, &status, 0);
    pid_2 = fork();
    if (pid_2 == 0)
    { // child2 process
      // printf("child process2: %d\n", getpid());
      chdir("Dir0");
      system("touch t1.txt"); // this here doesn't use execvp because i only want to use single process for creating 3 files
      system("touch t2.txt");
      system("touch t3.txt");
      system("mkdir Dir1");
    }
    else if (pid_2 > 0)
    { //parent process
      waitpid(pid_2, &status, 0);
      // printf("parent process2: %d\n", getpid());
      printf("folder&files created");

    }
    else
    {
      printf("Fork Failed\n");
      return 1;
    }
  }
  else
  {
    printf("Fork Failed\n");
    return 1;
  }
  return 0;
}
