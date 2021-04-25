# soal-shift-sisop-modul-2-C07-2021


# soal nomor 1 

__1A__

di soal ini kami diminta untuk membuat tiga folder yang akan diberi nama dengan "Musyik","Pyoto", dan "Fylm"
```
char *nmfolder[]={"Musyik","Pyoto","Fylm"};
```
bagian diatas untuk mendeclare array "nmfolder" yang berisikan nama-nama folder yang akan dibuat
```
firstchild = fork();
    
    if (firstchild < 0){
        exit(EXIT_FAILURE);
    }

    if (firstchild == 0)
    { 
	   char *arg[] = {"mkdir",nmfolder[0],nmfolder[1],nmfolder[2],NULL};
	   execv("/bin/mkdir",arg);
    }
```
bagian diatas adalah Melakukan fork pada parent process, kemudian dalam child process, membuat array "folder" yang berisi  argumen - argumen untuk digunakan dalam membuat folder yaitu mkdir untuk membuat folder, dan nama - nama folder yang sudah di masukkan kedalam array "nmfolder" yang sudah dideclare di atas.

__1B__

dalam soal ini kami diminta untuk men-download file berupa music,foto, dan film dari link yang sudah diberikan

```
char *linkdonlot[] = {"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download"};
    int foto = 0;
    int musik = 1;
    int film = 2;
```
bagian diatas adalah men-declare array"linkdonlot" dan memasukkan argumen-argumen berupa link dari file-file yang diminta untuk didownload dan juga mendeclare index-index sesuai urutan link dalam array dan namanya untuk array "linkdonlot" yang akan dimasukkan kedalam array argv yang nanti dibuat saat dalam proses 

___untuk file foto___

```
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
	   while((wait(&status)) > 0);}
 ```
 ___untuk file musik___
 ```
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
		   while((wait(&status)) == 0);}
 ```
 ___untuk file film___
 ```
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
	 while((wait(&status)) > 0);}
 ```
 pada setiap file yang didownloan, melakukan fork pada parent process, membuat array argv yang didalamya berisikan ``"wget","--no-check-certificate",linkdonlot[film],"-O","Film_for_Stevany.zip",NULL`` index dalam array "linkdonlot" disesuaikan dengan file yang di-download, kemudian memanggil fungsi evecv dengan argumen ``"/usr/bin/wget",argv`` lalu melakukan wait pada proses tersebut.
 
 ___hasil dari nomor 1a dan 1b___
 ![output 1a1b](https://user-images.githubusercontent.com/81466736/115110407-7b2e8a80-9fa5-11eb-86a3-f8f8ebd0f6c8.JPG)


__1C__

__1D__

__1E__

__1F__

# Soal 2

__2A__

Pada soal ini kita diminta pertama-tama untuk mengextract file `pets.zip` yang kita masukkan kedalam folder `modul 2` dan `petshop`. Permasalah tersebut kita gunakan fungsi `execv` dimana akan melakukan eksekusi suatu program. Fungsi tersebut kita buatkan seperti berikut
```
if (fork()==0){	
		char *argv[] = {"mkdir", "-p", "modul2/petshop", NULL};
		execv("/bin/mkdir", argv);	
	}
	while ((wait(&status)) > 0){
	char *argv[] = {"unzip", "pets.zip", "*.jpg", "-d", "modul2/petshop", NULL}; 
	execv("/bin/unzip", argv);
}
```
Kita menggunakan `fork` dan `wait` untuk melakukan pengerjaan `exec` agar bisa berjalan dan tereksekusi semua secara tidak berbentrokan. Untuk menggunakan fungsi wait kita gunakan `while ((wait(&status)) > 0)` dimana jika nilai dari **int** `status` bernilai benar maka akan jalan. 

__2B__

Pada soal ini kami dimintakan untuk membuat folder untuk tiap jenis hewan yang terdapat di dalam foto-foto yang di extract. Pada soal ini kami menyelesaikan dengan menggunakan directory dimana fungsi `DIR` akan mengakses dan melakukan pemeriksaan ada apa saja di dalam directory yang diakses. Setelah itu, kami masukkan kedalam looping dimana kita menggunakan pointer `directoryType` untuk melakukan pemeriksaan tersebut dan diarahkan ke folder yang ingin dituju. 
```
if (fork()==0){
			DIR *directoryType;
          		struct dirent *fileDir;
          		directoryType = opendir("modul2/petshop");
			while((fileDir = readdir(directoryType)) != NULL){
```
Lalu, untuk mengambil nama dari tiap foto untuk kita buatkan folder kita menggunakan fungsi `string` dengan `strcpy` dan `strcat` dimana akan mengabil dari folder `modul2/petshop` dan string hingga symbol `;` dengan menggunakan `strtok`
```
printf("Folder Terbuat\n");    
				    strcpy(animalName_folder, "modul2/petshop/");
				    strcat(animalName_folder, strtok(fileDir -> d_name, ";"));
```
Setelah itu, untuk membuat foldernya kita menggunakan `childid2` yang kita gunakan sebagai `fork` dari pengeksekusian program dan menggunakan `execv` dengan argumen ` char *argv[] = {"mkdir", "-p", animalName_folder, NULL};` agar terbuat folder beserta nama yang dingingkan.
```
childid2 = fork();
				    if(childid2 == 0)
				    {
				      char *argv[] = {"mkdir", "-p", animalName_folder, NULL};
				      execv("/bin/mkdir", argv);
				    }
```

__2C__

Masih bermasalah dalam memindahkan file dan rename secara bersamaan

__2D__

Masih bermasalah dalam melakukan pemisahan nama

__2E__

Masih bermasalah karena prgram tidak bisa membuat file textnya sesuai output yang diinginkan

# Soal 3

```
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
                strftime(new_ans, sizeof(new_ans), "%Y-%m-%d_%X", &new_tstruct) ; // membuat struct untuk tahun date
                
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

```
Penjelasan Source Code :
<br>
__3A__
```
pid_t child_id =fork(); // mem fork
 
        char hit[105] ;
        char ans[105] ;

        time_t timesekarang = time(0) ;  
        struct tm t = *localtime(&timesekarang) ;
        strftime(ans, sizeof(ans), "%Y-%m-%d_%X", &t) ; // mendeklarasikan time, kemudian di masukkan ke variable hit dan ans 
```

Pada poin mini merupakan perintah untuk melakukan fork dan mendeklarasikan time,kemudian di masukkan ke variable hit dan ans.
<br>
Selanjutnya
```
if (child_id < 0) {
            exit(EXIT_FAILURE) ;
        }

        if (child_id == 0) {
            if (fork() == 0) {
                char* arg[] = {"mkdir", "-p", ans, NULL} ;
                execv("/bin/mkdir", arg) ; // untuk menjalankan execv untuk membuat direktori/folder
            }
        }
```
Fungsi di atas di gunakan untuk menjalankan execv membuat direktori folder.<br><br>
__3B__
<br>
Untuk 3B sendiri kita di minta untuk melakukan download dari `piscum.photos` kemudian kita di suruh memasukan ke direkrori yang telah kita buat.
```
char link[55] = "https://picsum.photos/" ; 
                int sizefoto = (((long)mktime(&t)) % 1000) + 50 ; // ukuran foto
                char size[15] ;
                sprintf(size, "%d",sizefoto) ;
                strcat(link, size) ; // menyimpan size foto di link
		 
		char* arg[] = {"wget", "-q", "-O", hit, link, NULL} ;
                execv("/bin/wget", arg) ; // menjalankan proses execv
```
fungsi ini memerintahkan kita untuk menyimpan size foto(ukuran foto). kemudian di `execv` .
<br><br>
__3C__
<br>
Pada soal ini kita di minta melakukan status dowload ketika dowonload selesai dan terdapat enskripsi string yang telah di tentukan.
```
 char depth[50], hint[55] = "Download Success" ; // hint sendiri merupakan status
            strcpy(depth, ans) ;
            strcat(depth, "/") ;
            strcat(depth, "status.txt") ;
            FILE* txt = fopen(depth, "w") ;
            
            if(txt == NULL){
                exit(EXIT_FAILURE);
            }
```
Pada fungsi ini merupakan untuk menunjukkan status download berhasil yang nantinya akan berbentuk `.txt`.
<br> Selanjutnya <br>
```
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
```
fungsi di atas merupakan bagian enkripsi yang sudah di tentukan yang nanti kan berbentuk `.zip`
<br><br>
__3D__
<br>
Pada soal ini kita di minta utuk melakukan fungsi killer.sh yang dimana akan men terminasi atau menghentikan semua program yang jalan.
```
void pkiller(char a[]) {
    FILE* src = fopen("killer.sh", "w") ;
    fputs(a, src) ;
    fclose(src) ;
}
```
<br><br>
__3E__
Pada soal ini kita diminta membuat program dengan dua kondisi ketika `-x` dan juga ketika `-z` .
```
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
        if (!strcmp(argv[1], "-z")) // kondisi -z
	{
            strcpy(a, "#!/bin/bash\nkillall -9 ./soal3\nrm $0\n") ;
            pkiller(a) ;
        }
        else if (!strcmp(argv[1], "-x")) kondisi -x 
	{
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
```
berikut merupakan program dengan 2 kondisi yang berbeda

			    
