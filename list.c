#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int status;
	pid_t pid_1, pid_2;
	pid_1 = fork();

	if (pid_1 == 0)
	{ //children process
		system("clear");
	}
	else if (pid_1 > 0)
	{ //parent process

		//listing out all content of the current directory.
		waitpid(pid_1, &status, 0);
		pid_2 = fork();
		if (pid_2 == 0)
		{ //child2
			FILE *fp;
			fp = fopen("t1.txt", "w+");
			if (fp == NULL)
			{
				printf("Unable to create file.\n");
			}
			execlp("ls", "ls", "-l", NULL);
		}
		else if (pid_2 > 0)
		{ //parent process
			waitpid(pid_2, &status, 0);
			system("ls -l >> t1.txt");
			int rn;
			rn = rename("t1.txt", "tree.txt");
			if (rn == 0)
			{
				printf("\nFile renamed successfully.\n");
			}
			else
			{
				printf("Error: unable to rename the file.\n");
			}
			printf("\nAfter update \n");

			execlp("ls", "ls", "-l", NULL);
		}

		else
		{
			printf("Failed to fork.");
			return 1;
		}
	}
	return 0;
}
