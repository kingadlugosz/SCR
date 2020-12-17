#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>


int main()

{
int file;
char img[100];
struct stat filestat;
char *file_in_memory;
int file_size;

     while(1) 
     {


        if(fork() == 0) 
      {
            sleep(2);
            execlp("display", " ", "-update", "1", "plik", NULL);
      }

	printf("name of file:\n");
        scanf("%s", img);


     if(( file = open(img, O_RDWR, S_IRWXO | S_IWUSR)) < 0 ) printf("cant open");
       file_size= open("file", O_RDWR | O_CREAT);  
    
    if(fstat(file, &filestat) < 0) 
	{
	    printf("error");
	    return(1);
	}


    truncate("plik", filestat.st_size);
    file_in_memory = mmap(NULL, filestat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file_size, 0 );

    read(file, file_in_memory,filestat.st_size);

    msync(file_in_memory, filestat.st_size, MS_SYNC);
    
    munmap(file_in_memory, filestat.st_size);
    
    close(file);

    }


}