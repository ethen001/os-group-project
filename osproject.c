#include<stdio.h>
#include<stdlib.h>

void exit(){

	

	//get last 4 commands ands store in to array
	int last4CmdArray[4] = {}

	// print last 4 commmands
   	printf("\n Last four commands : ");

   	system("history 4")
   		
   	for (int i = 0 ; i < 4 ; i++ ){
       	printf(" %d " , last4CmdArray[i] , "\n");
      
   	}

   	printf("\n");
  

	//list all content in current directory
	printf("\n List of content in cur dir : ");

	system("ls -l");

	return;
}



