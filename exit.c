#include<stdio.h>
#include<stdlib.h>

int main(){
	// print last 4 commmands
   	printf("\n Last four commands : ");

   	system("history 4");
   		
   	printf("\n");
  
	//list all content in current directory
	printf("\n List of content in cur dir : ");

	system("ls -l");

	return 0;
}








