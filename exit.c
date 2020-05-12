#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	// print last 4 commmands
		printf("\nargument: %s, %s, %s", argv[0], argv[1], argv[2]);
   	printf("\n Last four commands : ");

   	system("history 4");
   		
   	printf("\n");
  
	//list all content in current directory
	printf("\n List of content in cur dir : ");

	system("ls -l");

	return 0;
}








