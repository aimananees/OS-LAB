#include<stdio.h>
#include<stdlib.h>


int main(){

	pid_t process;
	int pipefd1[2];
	int pipefd2[2];
	pipe(pipefd1);
	pipe(pipefd2);
	char buffer1[100];
	char buffer2[100];

	pipe(pipefd1);
	pipe(pipefd2);

	process=fork();
	if(process ==0){
		printf("Child Process..\n");
		printf("Sending data to parent...\n");
		close(pipefd1[0]);
		write(pipefd1[1],"Aiman Abdullah",25);
		close(pipefd1[1]);
		sleep(2);
		close(pipefd2[1]);
		read(pipefd2[0],buffer2,sizeof(buffer2));
		printf("Reading Data from Parent: %s\n",buffer2);
		exit(0);
	}
	else{

		printf("Parent Process....\n");
		close(pipefd1[1]);
		read(pipefd1[0],buffer1,sizeof(buffer1));
		printf("Reading Data from Child: %s\n",buffer1);
		printf("Sending Data to Child...\n");
		close(pipefd2[0]);
		write(pipefd2[1],"Anees",25);
		close(pipefd2[1]);
		sleep(2);
		printf("Parent Exiting...\n");
	}
	return 0;
}
