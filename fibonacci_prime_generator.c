#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

	int input_array[100];
	int buffer[100];
	int n;
	int pfd[2];
	pid_t process;
	int res=pipe(pfd);
	if(res == -1){
		perror("Pipe error");
	}
	process = fork();
	if(process > 0){
		printf("Parent process\n");
		printf("Parent process waiting\n");
		wait(0);
		close(pfd[1]);
		read(pfd[0],buffer,25*sizeof(int));
		for(int i=0;i<25;i++){
			printf("%d ",buffer[i]);
		}
		printf("\nPrime Generator\n");
		for(int i=0;i<25;i++){
			int num=buffer[i];
			int count=0;
			for(int j=1;j<=num;j++){
				if(num%j == 0){
					count++;
				}
			}
			if(count == 2)
				printf("%d\n",num);
		}
		close(pfd[0]);
	}	

	else{
		printf("Child process\n");
		close(pfd[0]);
		int first=0;
		int second=1;
		int j=2;
		input_array[0]=0;
		input_array[1]=1;
		int next=first+second;
		for(int i=0;i<23;i++){
			input_array[j]=next;
			first=second;
			second=next;
			next=first+second;
			j++;
		}
		close(pfd[0]);
		write(pfd[1],input_array,25*sizeof(int));
		close(pfd[1]);
	}


}