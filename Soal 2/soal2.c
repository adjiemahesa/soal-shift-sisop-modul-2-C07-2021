#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(){

	pid_t childid, childid2, childid3, childid4;
	char animalName_folder[100];
	int status;
	
	childid = fork();
	childid2 = fork();
	
	if (childid < 0 ){
    		exit(EXIT_FAILURE);
  	}

	if (childid == 0){
		if (fork()==0){	
			char *argv[] = {"mkdir", "-p", "modul2/petshop", NULL};
			execv("/bin/mkdir", argv);	
		}
		while ((wait(&status)) > 0){
		char *argv[] = {"unzip", "pets.zip", "*.jpg", "-d", "modul2/petshop", NULL};
        		execv("/bin/unzip", argv);
		}
	}
	else if (childid > 0){
		sleep (1);
		
		if (fork()==0){
			DIR *dirType;
          		struct dirent *fileDir;
          		dirType = opendir("modul2/petshop");
          		
          		while((fileDir = readdir(dirType)) != NULL)
          		{
            			printf("Folder Terbuat\n");    
				    strcpy(animalName_folder, "modul2/petshop/");
				    strcat(animalName_folder, strtok(fileDir -> d_name, ";"));
				    
				    childid2 = fork();
				    if(childid2 == 0)
				    {
				      char *argv[] = {"mkdir", "-p", animalName_folder, NULL};
				      execv("/bin/mkdir", argv);
				    }
          		}		
		}	 
	}
	return 0;
}
