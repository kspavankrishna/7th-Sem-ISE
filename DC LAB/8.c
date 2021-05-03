#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argv, char* argc[])
{
	int rank,tag=10,temp=0,size,sum=0;
	MPI_Init(&argv,&argc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	int localsum = 0,a[size],b[size];
	for(int i=0;i<size;i++)
		a[i] = b[i] = i*i;
	if(rank==0)	{
	printf("\n Matrices are: \n");
	for(int i=0;i<size;i++)
		printf("\n %d \%d\n",a[i],b[i]);
		}
	
	for(int i=0;i<size;i++)	
		localsum+= a[i]*b[i];
	
	MPI_Reduce(&localsum,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	
	if(rank==0)
	printf("\n Final sum is: %d\n",sum);
	MPI_Finalize();
}
