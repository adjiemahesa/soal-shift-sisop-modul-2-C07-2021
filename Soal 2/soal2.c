#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(){

	pid_t childid, childid2, childid3;
	char animalName_folder[100];
	char temp[100];
	char fileDirect[256];
	char fileDir2[256];
	char fileDirKet[256];
	char twoAnimal[100];
	char idAnimal[3][256];
	char nameFile[100];
	char tempnameFile[100];
	int status;
	
	childid = fork();
	
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
			DIR *directoryType;
          	struct dirent *dirFile;
          	directoryType = opendir("modul2/petshop");
          		
          		while((dirFile = readdir(directoryType)) != NULL)
          		{
            	
                strcpy(animalName_folder,"modul2/petshop/");
                strcpy(temp, dirFile->d_name);
		        strcat(animalName_folder, strtok(temp, ";"));

                //2B
                childid3 = fork();
                if (childid3 == 0)
                {
                    char *Args[] = {"mkdir", "-p", animalName_folder, NULL};
                    execv("/bin/mkdir", Args);
                }
                

				if ( !strcmp( dirFile->d_name, "."  )) continue;
                if ( !strcmp( dirFile->d_name, ".." )) continue;

                strcpy(fileDirect, "modul2/petshop/");
                strcat(fileDirect, dirFile->d_name);

                sleep(1);
                
                //2D
                if (strchr(dirFile->d_name, '_'))
                {
                    strcat(dirFile->d_name, "_");
                    char *temp2 = strtok(dirFile->d_name, "_");
                    while(temp2 != NULL)
                    {
                        sleep(1);

                        strcpy(twoAnimal, temp2);
                        int idx = 0;
                        int x;

                        sleep(1);

                        x = 0;
                        while(twoAnimal[idx]!=';') {
                            idAnimal[0][x] = twoAnimal[idx];
                            idx++;
                            x++;
                        }
                        idAnimal[0][x] = '\0';

                        sleep(1);

                        idx++;
                        x = 0;
                        while(twoAnimal[idx]!=';') {
                            idAnimal[1][x] = twoAnimal[idx];
                            idx++;
                            x++;
                        }
                        idAnimal[1][x] = '\0';

                        sleep(1);

                        idx++;
                        x = 0;
                        while(twoAnimal[idx]!='\0' && twoAnimal[idx]!='j'){
                            idAnimal[2][x] = twoAnimal[idx];
                            idx++;
                            x++;
                        }
                        idAnimal[2][x] = '\0';

                        if (idAnimal[2][x-1] == '.')
                        {
                            idAnimal[2][x-1] = '\0';
                        }

                        sleep(1);

                        // 2E
                        strcpy(fileDirKet, "modul2/petshop/");
                        strcat(fileDirKet, idAnimal[0]);
                        strcat(fileDirKet, "/keterangan.txt");

                        FILE *fKet;
                        fKet = fopen(fileDirKet, "a");
                        fprintf(fKet, "nama : %s\n", idAnimal[1]);
                        fprintf(fKet, "umur : %s tahun\n\n", idAnimal[2]);
                        fclose(fKet);
                        
                        strcpy(fileDir2, "modul2/petshop/");
                        strcat(fileDir2, temp2);

                        if(!strstr(temp2, ".jpg"))
                        {
                            strcat(fileDir2, ".jpg"); 
                        }

                        sleep(1);

                        if (childid3 = fork() == 0)
                        {
                            char *Args[] = {"cp", fileDirect, fileDir2, NULL};
                            execv("/bin/cp", Args);
                        }

                        sleep(1);

                        strcpy(nameFile, "modul2/petshop/");
                        strcat(nameFile, idAnimal[0]);
                        strcat(nameFile, "/");
                        strcat(nameFile, idAnimal[1]);
                        strcat(nameFile, ".jpg");

                        // 2C
                        if (childid3 = fork() == 0)
                        {
                            strcpy(animalName_folder,"modul2/petshop/");
                            strcpy(temp, temp2);
                            strcat(animalName_folder, strtok(temp, ";"));

                            char *Args[] = {"mv", fileDir2, nameFile, NULL};
                            execv("/bin/mv", Args);
                        }
                        
                        sleep(1);

                        temp2 = strtok(NULL, "_");
                    }

                    sleep(1);

                    if (childid3 = fork() == 0)
                    {
                        char *Args[] = {"rm", fileDirect, NULL};
                        execv("/bin/rm", Args);
                    }
                }
                
                else
                {
                    // 2E
                    strcpy(fileDirKet, animalName_folder);
                    strcat(fileDirKet, "/keterangan.txt");

                    int i = 0;
                    strcpy(tempnameFile, dirFile->d_name);
                    char *temp2 = strtok(tempnameFile, ";");

                    while(temp2 != NULL)
                    {
                        strcpy(idAnimal[i], temp2);
                        temp2 = strtok(NULL, ";");
                        i++;
                    }
                
                    strtok(idAnimal[2], "j");
                    idAnimal[2][strlen(idAnimal[2])-1] = '\0';

                    FILE *fKet;
                    fKet = fopen(fileDirKet, "a");
                    fprintf(fKet, "nama : %s\n", idAnimal[1]);
                    fprintf(fKet, "umur : %s tahun\n\n", idAnimal[2]);
                    fclose(fKet);
                    
                    // 2C
                    if (childid3 = fork() == 0)
                    {
                        char *Args[] = {"mv", fileDirect, animalName_folder, NULL};
                        execv("/bin/mv", Args);
                    }

                    sleep(1);
                    
                    strcpy(nameFile, animalName_folder);
                    strcat(nameFile, "/");
                    strcat(nameFile, idAnimal[1]);
                    strcat(nameFile, ".jpg");

                    strcat(animalName_folder, "/");
                    strcat(animalName_folder, dirFile->d_name);
                    
                    //2C Rename
                    if (childid3 = fork() == 0)
                    {
                        char *Args[] = {"mv", animalName_folder, nameFile, NULL};
                        execv("/bin/mv", Args);
                    }
                }
            }
            closedir(directoryType);
        }
    }
    return 0;
}

