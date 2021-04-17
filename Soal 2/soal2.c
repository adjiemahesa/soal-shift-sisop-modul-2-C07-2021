#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(){

	pid_t childid, childid2;
	char foldername[100], temp[100], filename[100];
	int status;
	
	childid = fork();
	childid2 = fork();
	
	if (childid < 0 ){
    		exit(EXIT_FAILURE);
  	}

	if (childid == 0){
		if (fork()==0){	
			char *argvmk[] = {"mkdir", "-p", "modul2/petshop", NULL};
			execv("/bin/mkdir", argvmk);	
		}
		
		sleep (1);
		
		if (fork()==0){
			printf("test\n");
			DIR *dirType;
          		struct dirent *dirFile;
          		dirType = opendir("~/modul2/petshop");
		}
		
	}
	else if (childid > 0){
		char *argv[] = {"unzip", "pets.zip", "*.jpg", "-d", "modul2/petshop", NULL};
        		execv("/bin/unzip", argv);
			 
	}
	return 0;
}
	
