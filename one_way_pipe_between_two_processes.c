#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	pid_t process;
	int pipefd[2];
	pipe(pipefd);
	char a[100];
	char buffer[100];

	process=fork();
	if(process == 0){
		printf("Child Process\n");
		printf("Enter name: ");
		scanf("%s",a);
		close(pipefd[0]);
		write(pipefd[1],a,sizeof(a));
		close(pipefd[1]);
		exit(0);
	}
	else{
		wait(0);
		printf("Parent Process\n");
		close(pipefd[1]);
		read(pipefd[0],buffer,sizeof(buffer));
		printf("%s\n",buffer);
		close(pipefd[0]);
		exit(0);
	}
	return 0;
}