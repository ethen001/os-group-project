#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	system("clear");

	//creating file t1.txt.
	FILE * fp;
	fp = fopen("t1.txt", "w+");
	if(fp == NULL){
		printf("Unable to create file.\n");
	}
		
	//listing out all content of the current directory.
	system("ls -l");
	
	//renaming the t1.txt file to tree.txt.
	int rn;
	rn = rename("t1.txt", "tree.txt");
	if(rn == 0) {
		printf("\nFile renamed successfully.\n");
	}else{
		printf("Error: unable to rename the file\n");
	}

	printf("\nAfter update \n");
	system("ls -l");

	return 0;
}
