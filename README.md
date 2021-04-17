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

__3A__<br>
pada soal ini kita di minta untuk membuat direktori seperti berikut
```
 int timelimit;
 int awalan = 1;
 int hint = 1;

    time_currenttime = time(NULL);
    time_previoustime = time(NULL);
    while (hint == 1) {
        currenttime = time(NULL);

        timelimit = (int)diff_time(currenttime, previoustime);
        if (awalan|| timelimit >= 40) {
            previoustime = currrenttime;

            pid_t child;

            child = fork();
            if (child == 0)
 { 
                char nama_dir[200];
                time_t now_dir = time(NULL);
                struct tm *t_dir = localtime(&now_dir);
                strftime(nama_dir, sizeof(nama_dir)-1, "%d-%m-%Y_%H:%M:%S", t_dir);

                pid_t child_dir;

                child_dir = fork();
            if (child_dir == 0)
 {
                    char *arg1[3]={"/bin/mkdir", nama_dir, NULL};
                    execv("/bin/mkdir", arg1);
                }
```
__3B__<br>
pada soal kali ini kita di minta untuk mendownload gambar ke direktori 
```
 char link[205];
                int detik = ((int)time(NULL) % 1000) + 50;
                sprintf(link, "https://picsum.photos/%d", detik);
                
                int timelimit ;
                int ans = 1;
                int awalan = 1;
                int hint = 1;

                time_t currentttime = time(NULL);
                time_t previoustime = time(NULL);
       
                  while (hint ==1) {
                    currenttime = time(NULL);

                    timelimit = (int)difftime(currenttime, previoustime);
                    if (awalan_ph || timelimit_ph >= 5) {
                        previoustime = currenttime;

                        if (ans > 10) {
                            hint = 0;
                            break;
                        }

                        pid_t child;

                         child= fork();
            if (child== 0)
 {
                            char namafile[205];
                            time_t now = time(NULL);
                            struct tm *t = localtime(&now);
                            strftime(namafile, sizeof(namafile)-1, "%d-%m-%Y_%H:%M:%S", t);
			    
}
```
__3C__
<br>belum<br>
__3D__
<br>belum<br>
__3E__
<br>belum<br>
			    
