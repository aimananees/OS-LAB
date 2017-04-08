#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main(){

	int myPipe[2];
	pid_t process;
	int write_n;

	int res=pipe(myPipe);
	if(res == -1){
		perror("pipe");
	}
	process=fork();
	if(process>0){
		printf("Parent process:\n");
		printf("Enter the limit: ");
		scanf("%d",&write_n);
		close(myPipe[0]);
		write(myPipe[1],&write_n,sizeof(write_n));
		close(myPipe[1]);
		printf("Parent process waiting\n");
		wait(0);
		printf("Parent process exiting\n");
	}
	else{
		printf("Child-Process");
		close(myPipe[1]);
		read(myPipe[0],&write_n,sizeof(write_n));
		close(myPipe[0]);
		printf("0\n");
		printf("1\n");
		int first=0;
		int second=1;
		int next=first+second;
		for(int i=1;i<=(write_n-2);i++){
			printf("%d\n",next);
			first=second;
			second=next;
			next=first+second;
		}
		exit(0);
	}
	return 0;
}
