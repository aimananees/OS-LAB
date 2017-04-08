#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
pid_t process;
int myPipe[2];
pipe(myPipe);
process=fork();
if (process == 0)
{
close(1);
dup(myPipe[1]);
close(myPipe[0]);
execlp("who", "who", NULL);

}

else
{
close(0);
dup(myPipe[0]);
close(myPipe[1]);
execlp("wc", "wc","-l", NULL);

}
}


