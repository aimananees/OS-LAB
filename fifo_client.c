#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
main()
{
 int wrfd,rdfd,n;
 char buf[50],line[50];
 /*open the first named pipe for writing*/
 wrfd=open("np1",O_WRONLY);
 /*create the second named pipe for reading */
 rdfd=open("np2",O_RDONLY);
 /*write to the pipe*/
 printf("enter line of text");
 gets(line);
 write(wrfd,line,strlen(line));
 /*read from the pipe*/
 n=read(rdfd,buf,50);
 buf[n]='\0';//end of line
 printf("full duplex client:read from the pipe:%s\n",buf);
}