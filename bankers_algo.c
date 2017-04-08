#include<stdio.h>

int main(){

	int allocation[100][100],max[100][100],available[3],num,request[3],n,need[100][100],finish[100];

	printf("Filling the available array:\n");
	for(int i=0;i<3;i++){
		printf("%c: ",(i+97));
		scanf("%d",&available[i]);
	}
	printf("Enter the number of processes; ");
	scanf("%d",&num);

	//Initialize all finish to 0
	for(int i=0;i<num;i++){
		finish[i]=0;
	}
	
	
	printf("Filling the allocation matrix: \n");	
	for(int i=0;i<num;i++){
		printf("Process%d\n",i);
		for(int j=0;j<3;j++){
			scanf("%d",&allocation[i][j]);
		}
	}

	printf("Filling the max matrix: \n");	
	for(int i=0;i<num;i++){
		printf("Process%d\n",i);
		for(int j=0;j<3;j++){
			scanf("%d",&max[i][j]);
		}
	}

	//Need Matrix Calculation
	for(int i=0;i<num;i++){
		for(int j=0;j<3;j++){
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}

	for(int i =0;i<num;i++){
		for(int j=0;j<3;j++){
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	printf("Enter the process number: ");
	scanf("%d",&n);
	printf("Enter the request: ");

	for(int i=0;i<3;i++){
		scanf("%d",&request[i]);
	}
	int count=0;
	for(int i=0;i<3;i++){
		if(need[n][i]>=request[i]){
			count++;
		}
	}
	if(count < 3){
		printf("Error\n");
		return 0;
	}
	else{
		int count=0;
		for(int i=0;i<3;i++){
		if(available[i]>=request[i]){
			count++;
			}
		}
		if(count < 3){
			printf("Error\n");
			return 0;
		}
		else{
			for(int i=0;i<3;i++){
				available[i]=available[i]-request[i];
			}

			for(int i=0;i<3;i++){
				allocation[n][i]=allocation[n][i]+request[i];
			}

			for(int i=0;i<3;i++){
				need[n][i]=need[n][i]-request[i];
			}

		}
		printf("Yes Possible!");
	}

}