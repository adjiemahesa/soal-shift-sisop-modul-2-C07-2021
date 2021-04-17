#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>


int main()
{
    pid_t firstchild, secondchild, thirdchild, fourthchild, fifthchild, sixthchild;
    

    int status;
    char *nmfolder[]={"Musyik","Pyoto","Fylm"};
    char *linkdonlot[] = {"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download"};
    int foto = 0;
    int musik = 1;
    int film = 2;

    firstchild = fork();
    
    if (firstchild < 0){
        exit(EXIT_FAILURE);
    }

    if (firstchild == 0)
    {
	   //Buat Folder
	   char *arg[] = {"mkdir",nmfolder[0],nmfolder[1],nmfolder[2],NULL};
	   execv("/bin/mkdir",arg);
    }
    else{
    secondchild = fork();
	    if(secondchild < 0){
	    exit(EXIT_FAILURE);
	    }

     if(secondchild == 0) {
        thirdchild = fork();
	    if(thirdchild <= -1) {
	        exit(EXIT_FAILURE);
	   }
    if (thirdchild == 0){
		//1B(foto)
    char *argv[] = {"wget","--no-check-certificate",linkdonlot[foto],"-O","Foto_for_Stevany.zip",NULL};
    execv("/usr/bin/wget",argv);
		}

     else{
	   while((wait(&status)) > 0);
            fourthchild = fork();
	   if(fourthchild <= -1){
	        exit(EXIT_FAILURE);
	    }
      
     if(fourthchild == 0){
        fifthchild = fork();
		 
       if(fifthchild <= -1){
		    exit(EXIT_FAILURE);
		    }
        if(fifthchild == 0){
		    //1B(musik)
         char *argv[] = {"wget","--no-check-certificate",linkdonlot[musik],"-O","Musik_for_Stevany.zip",NULL};
         execv("/usr/bin/wget",argv);
         }
                
        }

       else{
		   while((wait(&status)) == 0);
              sixthchild = fork();
		
        if(sixthchild <= -1){
		    exit(EXIT_FAILURE);
		    }
        if(sixthchild == 0){
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
