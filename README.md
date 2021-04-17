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

__2B__

__2C__

__2D__

__2E__
