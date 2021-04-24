#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>
#include <signal.h>

void sig() {
    int run = 0 ;
}

void pkiller(char a[]) {
    FILE* src = fopen("killer.sh", "w") ;
    fputs(a, src) ;
    fclose(src) ;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        char a[85] ;
        if (!strcmp(argv[1], "-z")) {
            strcpy(a, "#!/bin/bash\nkillall -9 ./soal3\nrm $0\n") ;
            pkiller(a) ;
        }
        else if (!strcmp(argv[1], "-x")) {
            strcpy(a, "#!/bin/bash\nkillall -15 ./soal3\nrm $0\n") ;
            pkiller(a) ;
            signal(SIGTERM, sig) ;
        }
        else {
            return 0 ;
        }
    }
    else {
        return 0 ;
    }
    
    int a=1;
    while(a) {
        
        pid_t child_id =fork(); // mem fork
 
        char hit[105] ;
        char ans[105] ;

        time_t timesekarang = time(0) ;  
        struct tm t = *localtime(&timesekarang) ;
        strftime(ans, sizeof(ans), "%Y-%m-%d_%X", &t) ; // mendeklarasikan time, kemudian di masukkan ke variable hit dan ans
        

        if (child_id < 0) {
            exit(EXIT_FAILURE) ;
        }

        if (child_id == 0) {
            if (fork() == 0) {
                char* arg[] = {"mkdir", "-p", ans, NULL} ;
                execv("/bin/mkdir", arg) ; // untuk menjalankan execv untuk membuat direktori/folder
            }
        }
        else {
            sleep(1) ; // menahan proses selama satu detik
            for (int i = 0 ; i < 10 ; i++, sleep(5)) {

                if (fork() == 0) {
                    continue ;
                }

                time_t waktubaru = time(0) ;
                struct tm new_tstruct = *localtime(&waktubaru) ;
                char new_ans[85] ;
                strftime(new_ans, sizeof(new_buff), "%Y-%m-%d_%X", &new_tstruct) ; // membuat struct untuk tahun date
                
                strcpy(hit, ans) ;
                strcat(hit, "/") ;
                strcat(hit, new_ans) ;
                
                char link[55] = "https://picsum.photos/" ; 
                int sizefoto = (((long)mktime(&t)) % 1000) + 50 ; // ukuran foto
                char size[15] ;
                sprintf(size, "%d",sizefoto) ;
                strcat(link, size) ; // menyimpan size foto di link

                char* arg[] = {"wget", "-q", "-O", hit, link, NULL} ;
                execv("/bin/wget", arg) ; // menjalankan proses execv 
            }
            
            char depth[50], hint[55] = "Download Success" ; // hint sendiri merupakan status
            strcpy(depth, ans) ;
            strcat(depth, "/") ;
            strcat(depth, "status.txt") ;
            FILE* txt = fopen(depth, "w") ;
            
            if(txt == NULL){
                exit(EXIT_FAILURE);
            }
            
            for (int i = 0 ; i < strlen(hint) ; i++) {
                if ((hint[i] >= 'a' && hint[i] <= 'z') ||
                    (hint[i] >= 'A' && hint[i] <= 'Z'))
                {
                    hint[i] += 5;

                    if ((hint[i] > 'z') || (hint[i] > 'Z' && hint[i] < 'a'))
                    {
                        hint[i] -= 26;
                    }
                }
            }
            fputs(hint,txt);
            fclose(txt) ;
       
            strcpy(depth, ans) ;
            strcat(depth, ".zip") ;
            char* argz[] = {"zip", depth, "-q", "-m", "-r", ans, NULL} ;
            execv("/bin/zip", argz) ;
        }
        time_t awal = time(0), second ;
        while (difftime(second, awal) != 40) // untuk memunculkan tiap 40s
		{
            second = time(0) ;
        }
    }
}
