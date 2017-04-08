#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

	pid_t process;
	process=fork();
	if(process>0){
		printf("Parent process\n");
		wait();
		printf("Exiting parent process\n");
		exit(0);
	}
	else{
		printf("Child process\n");
		printf("Enter the number of numbers: ");
		int n;
		scanf("%d",&n);
		int first=0;
		int second=1;
		int next=first+second;
		printf("0\n");
		printf("1\n");

		for(int i=1;i<=(n-2);i++){
			printf("%d\n",next);
			first=second;
			second=next;
			next=first+second;
		}
	}
	


}