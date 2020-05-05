#include<stdio.h>
#include<stdlib.h>

int main(){

	int i;
	char cmd[4096];
	int cmdHisC =0; 
	char *cmdHistory;
	char *cmdsHistory[4];


	while(1) {
	    fgets(cmd,4096,stdin); //read input from shell
		if(strcmp(cmd,"") != 0){ 
	    	if((cmdHistory= strdup(cmd)) != NULL){
	       		if (cmdsHistory[cmdHisC]){
	       			free(cmdsHistory[cmdHisC]);
	       			cmdsHistory[cmdHisC] = cmdHistory;
	       			cmdHisC++;
	       		} 
	    	} 
	    }

	    else
	    fprintf(stderr, "Error, Cannot save this command in the history pointer: Out of memory\n");

	    if(cmdHisC>3)
	        cmdHisC=0;
	}

	//list last 4 command
	if(strcmp(argsCmd[0], "history")==0){
	    for(int n = 0; n<4; n++) {
	        if(cmdsHistory[n] != NULL)
	        printf("History command  %d: %s\n", n, cmdsHistory[n]);
	    }
	}


	// print last 4 commmands
   	printf("\n Last four commands : ");

   	system("history 4")
   		
   	printf("\n");
  
	//list all content in current directory
	printf("\n List of content in cur dir : ");

	system("ls -l");

	return 0;
}




