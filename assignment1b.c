#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void merge(int a[],int low,int mid,int high)
    {
      int *x=(int *)malloc((mid-low+1)*sizeof(int));
      int *y=(int *)malloc((high-mid)*sizeof(int));
      int i,k=0;

      for(i=low;i<=mid;i++)
       x[k++]=a[i];
      k=0;
      for(i=mid+1;i<=high;i++)
        y[k++]=a[i];
       int j=0;
       i=low,k=0;
       while(k<mid-low+1&&j<high-mid)
        {
         if(x[k]>y[j])
           a[i++]=y[j++];
         else
           a[i++]=x[k++];
        }
       while(k<mid-low+1)
         a[i++]=x[k++];
       while(j<high-mid)
      a[i++]=y[j++];
    }

  void mergeSort(int a[],int low,int high)
     {
       if(low<high)
         {
           int mid=(low+high)/2;
	    mergeSort(a,low,mid);
	    mergeSort(a,mid+1,high);
            merge(a,low,mid,high);
	 }
    }





 void quicksort(int a[],int start,int end)
  {
    int pindex;
    if(start<end)
     {
        pindex=partition(a,start,end);
        quicksort(a,start,pindex-1);
        quicksort(a,pindex+1,end);
     }
  }
  
  int partition(int a[],int start,int end)   
   {
     int pindex;
     int temp;
     int i;
     int pivot=a[end];
     pindex=start;
     for(i=start;i<end;i++)
      {
        if(a[i]<=pivot)
          {
            temp=a[i];
            a[i]=a[pindex];
            a[pindex]=temp;
            pindex=pindex+1;
           }
      }
      temp=a[pindex];
      a[pindex]=a[end];
      a[end]=temp;
      return pindex;
    }

int main(){
  int n,i;
  printf("enter the no of elements  : ");
  scanf("%d",&n);
  int a[n];
  printf("enter array elements\n");
  for(i=0;i<n;i++)
  {
     scanf("%d",&a[i]);
  }
	pid_t process;
	process=fork();

	if(process>0){
		
		printf("parent process starting\n");
    mergeSort(a,0,n-1);
    printf("mergesort\n");
    for( i=0;i<n;i++)
    {
     printf("%d ",a[i]);
     
    }
    printf("parent process waiting,..\n");
    wait(0);
    printf("\nparent process ending\n");
	}
	else{
		printf("\nchild process starting\n");
     quicksort(a,0,n-1);
     printf("quicksort\n");
     for(i=0;i<n;i++)
        printf("%d " , a[i]);
        printf("\nchild process ending\n");
	}
}
