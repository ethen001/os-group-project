#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
void printLastFourCommands(int argc, char *argv[])
{
	int count = 0;
	for (int i = argc - 2; i >= 0; i--) {
		if (count < 4) {
			printf("%s\n", argv[i]);
			++count;
		}
		else {
			break;
		}
	}
}
void quitOnReturn() {
	char prev = 0;
	while (1) {
		char c = getchar();
		if (c == '\n' && prev == c)
		{
			// double return pressed!
			break;
		}
		prev = c;
	}
}
int main(int argc, char *argv[])
{
	printf("\n Last four commands: \n");
	printLastFourCommands(argc, argv);
	printf("\n List of content in curr dir");
	system("ls -l");
	printf("\n");
	quitOnReturn();
	return 0;
}
