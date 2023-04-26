#include<sys/syscall.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
int fd = syscall(335,"test.txt",O_RDWR);
if(fd<0)
{
perror("myopen");
return 1;
}
printf("File opened successfully.\n");
syscall(336,fd);
return 0;
}
