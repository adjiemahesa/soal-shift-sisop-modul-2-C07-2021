#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <wait.h>
 
int main() {
  pid_t pid, sid;      
 
  pid = fork();   
 
  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }
 
  
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }
 
  umask(0);
 
  
 
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
 
  while (1) {
    time_t jadwal = time(NULL);
    struct tm *waktu = localtime(&jadwal);
    int status;
    char *nmfolder[]={"Musyik","Pyoto","Fylm"};
    char *linkdonlot[] = {"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download"};
    int foto = 0;
    int musik = 1;
    int film = 2;
    int test = 1;
   // if(waktu->tm_mon == 3 && waktu->tm_mday == 9 && waktu->tm_hour == 16 && waktu->tm_min == 22 && waktu->tm_sec == 0 )
if (test == 1)
    {
        pid_t first,second,third,fourth,fifth,sixth,seventh,eighth,ninth,th10,th11,th12;
        
    
        first = fork();
    
        if(first < 0)
        {
            exit(EXIT_FAILURE);
        }
    
        if(first == 0)
        {
            //Buat Folder
            char *arg[] = {"mkdir",nmfolder[0],nmfolder[1],nmfolder[2],NULL};
            execv("/bin/mkdir",arg);
        }
        else
        {
            second = fork();
            if(second < 0)
            {
                exit(EXIT_FAILURE);
            }
            if(second == 0)
            {
                third = fork();
                if(third < 0)
                {
                    exit(EXIT_FAILURE);
                }
                if (third == 0)
                {
                    //Download Foto
                     char *argv[] = {"wget","--no-check-certificate",linkdonlot[foto],"-O","Foto_for_Stevany.zip",NULL};
                    execv("/usr/bin/wget",argv);
                }
                else
                {
                    //unzip Foto
                    while((wait(&status)) > 0);
                    char *argv[] = {"unzip","-j","Foto_for_Stevany.zip","-d","./Pyoto",NULL};
                    execv("/usr/bin/unzip",argv);
                      
                }
            }
            else
            {
                while((wait(&status)) > 0);
                fourth = fork();
                if(fourth < 0)
                {
                    exit(EXIT_FAILURE);
                }
                if(fourth == 0)
                {
                    fifth = fork();
                    if(fifth < 0)
                    {
                        exit(EXIT_FAILURE);
                    }
                    if(fifth == 0)
                    {
                        //Download Musik
                        char *argv[] = {"wget","-q","--no-check-certificate",linkdonlot[musik],"-O","Musik_for_Stevany.zip",NULL};
                        execv("/usr/bin/wget",argv);
                    }
                    else
                    {
                        //Unzip Musik
                        while((wait(&status)) > 0);
                        char *argv[] = {"unzip","-j","Musik_for_Stevany.zip","-d","./Musyik",NULL};
                        execv("/usr/bin/unzip",argv);
                    }
                }
                else
                {
                    while((wait(&status)) > 0);
                    sixth = fork();
                    if(sixth < 0)
                    {
                        exit(EXIT_FAILURE);
                    }
                    if(sixth == 0)
                    {
                        seventh = fork();
                        if(seventh < 0)
                        {
                            exit(EXIT_FAILURE);
                        }
                        if(seventh == 0)
                        {
                            //Download Film
                            char *argv[] = {"wget","-q","--no-check-certificate",linkdonlot[film],"-O","Film_for_Stevany.zip",NULL};
                            execv("/usr/bin/wget",argv);
                        }
                        else
                        {
                            //Unzip Film
                            while((wait(&status)) > 0);
                            char *argv[] = {"unzip","-j","Film_for_Stevany.zip","-d","./Fylm",NULL};
                            execv("/usr/bin/unzip",argv);   
                        }
			_exit(1);
                    }
                    
                }
            }
        } test ++;  
    }
   // else if (waktu->tm_mon == 3 && waktu->tm_mday == 9 && waktu->tm_hour == 16 && waktu->tm_min == 22 && waktu->tm_sec == 0)
if (test > 1)
    {
    pid_t th13;
        th13 = fork();
        if(th13 < 0)
        {
            exit(EXIT_FAILURE);
        }
        if(th13 == 0)
        {
            char *argv[] = {"zip", "-qrm", "Lopyu_Stevany.zip", "Pyoto", "Musyik", "Fylm", NULL};
            execv("/usr/bin/zip", argv);
        }
        else
        {
            while((wait(&status)) > 0);
            char *argv[] = {"rm", "-r", "FOTO", "MUSIK", "FILM", NULL};
            execv("/bin/rm",argv);
        }
    }
    sleep(1);
  }
}


