#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/syscall.h>
#include<unistd.h>

int main()
{
int fd;
char buffer[1024];
ssize_t n;

fd=syscall(335,"test2.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
if(fd<0)
{
perror("myopen");
exit(1);
}

if(write(fd,"Hello, world!\n", 14) !=14)
{
perror("write");
exit(1);
}

syscall(336,fd);

fd = syscall(335,"test2.txt",O_RDONLY);
if(fd <0)
{
perror("myopen");
exit(1);
}

n = read(fd, buffer,sizeof(buffer));
if(n<0)
{
perror("read");
exit(1);
}

write(STDOUT_FILENO , buffer,n);

syscall(336,fd);
return 0;
}
