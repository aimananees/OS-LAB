#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>



int main(){

	int myPipe[2];
	pid_t process;
	char output[]="AIMAN";
	char buffer[100];

	int res=pipe(myPipe);
	if(res == -1){
		perror("PIPE");
		exit(0);
	}

	process=fork();

	if(process>0){
		printf("Parent process:\n");
		wait(0);
		read(myPipe[0],buffer,1000);
		printf("%s\n",buffer);
	}
	else{
		printf("Child Process:\n");
		write(myPipe[1],output,sizeof(output));
	}

}