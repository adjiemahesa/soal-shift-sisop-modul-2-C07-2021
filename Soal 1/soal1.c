#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>


int main()
{
    pid_t first second, third, fourth, fifth, sixth;
    

    int status;
    char *nmfolder[]={"Musyik","Pyoto","Fylm"};
    char *linkdonlot[] = {"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download"};
    int foto = 0;
    int musik = 1;
    int film = 2;

    first = fork();
    
    if (first < 0){
        exit(EXIT_FAILURE);
    }

    if (first == 0)
    {
	   //Buat Folder
	   char *arg[] = {"mkdir",nmfolder[0],nmfolder[1],nmfolder[2],NULL};
	   execv("/bin/mkdir",arg);
    }
    else{
    second = fork();
	    if(second < 0){
	    exit(EXIT_FAILURE);
	    }

     if(second == 0) {
        third = fork();
	    if(third <= -1) {
	        exit(EXIT_FAILURE);
	   }
    if (third== 0){
		//1B(foto)
    char *argv[] = {"wget","--no-check-certificate",linkdonlot[foto],"-O","Foto_for_Stevany.zip",NULL};
    execv("/usr/bin/wget",argv);
		}

     else{
	   while((wait(&status)) > 0);
            fourth = fork();
	   if(fourt <= -1){
	        exit(EXIT_FAILURE);
	    }
      
     if(fourth == 0){
        fifth = fork();
		 
       if(fifth<= -1){
		    exit(EXIT_FAILURE);
		    }
        if(fifth == 0){
		    //1B(musik)
         char *argv[] = {"wget","--no-check-certificate",linkdonlot[musik],"-O","Musik_for_Stevany.zip",NULL};
         execv("/usr/bin/wget",argv);
         }
                
        }

       else{
		   while((wait(&status)) == 0);
              sixthchild = fork();
		
        if(sixth <= -1){
		    exit(EXIT_FAILURE);
		    }
        if(sixth == 0){
		    //1B(film)
         char *argv[] = {"wget","--no-check-certificate",linkdonlot[film],"-O","Film_for_Stevany.zip",NULL};
         execv("/usr/bin/wget",argv);
         }
	 else {
	 while((wait(&status)) > 0);
	 }
                
            }
        }
    }
}
}
