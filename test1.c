#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/syscall.h>

int main(){
int fd,bread;
char buffer[256];

fd=syscall(335,"test1.txt",O_RDONLY);
if(fd==-1)
{
perror("myopen");
exit(EXIT_FAILURE);
}

bread=read(fd,buffer,256);
if(read==-1)
{
perror("read");
exit(EXIT_FAILURE);
}

printf("%.*s",read,buffer);
printf("\n");
syscall(336,fd);
return 0;
}
