#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

void main(int argc,char* argv[]){
	long niter=1000000;
	double x,y,z;
	int count=0;
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int recv[size];
	MPI_Status status;
	if(rank!=0){
		for(int i=0;i<niter;i++){
			 x=((double)rand())/RAND_MAX;
			 y=((double)rand())/RAND_MAX;
			z=x*x+y*y;
			if(z<=1)
				count++;
		}
		for(int j=0;j<size;j++){
			MPI_Send(&count,1,MPI_INT,0,1,MPI_COMM_WORLD);
		}
	}
	else if(rank==0){
		for(int i=0;i<size;i++)
			MPI_Recv(&recv[i],size,MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,&status);
	}
	if(rank==0){
		int finalcount=0;
		for(int i=0;i<size;i++)
			finalcount+=recv[i];
		double pi=(((double)finalcount)/(niter));
		printf("Pi value=%f",pi);
			

	}
	MPI_Finalize();
}
