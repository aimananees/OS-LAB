#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(){

	pid_t process;
	int myPipe[2];
	char filename[100];
	char buffer[100];
	char ch;
	int count=0;
	int res=pipe(myPipe);
	FILE *fp;
	if(res == -1){
		perror("PIPE ERROR");
		exit(0);
	}
	process =fork();
	if(process > 0){
		printf("Parent process\n");
		wait(0);

		close(myPipe[1]);
		read(myPipe[0],buffer,sizeof(buffer));

		close(myPipe[0]);
		
		fp = fopen(buffer,"r"); // read mode
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		printf("\n");
		fclose(fp);
		
	}
	else{
		printf("Child Process\n");
		printf("Enter name of the file: ");
		scanf("%s",filename);
		close(myPipe[0]);
		write(myPipe[1],filename,strlen(filename));
		close(myPipe[1]);
		exit(0);
	}
}
