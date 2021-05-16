#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int n;
int main()
{
	printf("\n Enter the size\n");
	scanf("%d",&n);
	
	int a[n][n],vector[n],result[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j] = i+j ;
	
	for(int i=0;i<n;i++)
		vector[i] = i;
	for(int i=0;i<n;i++)
		result[i] = 0;
	
	
	printf("\n Matrix : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf(" %d ",a[i][j]);
		} 
		printf("\n");
		}
		
	printf("\n Vector: \n");
	for(int i=0;i<n;i++)
		printf("%d \n",vector[i]);
	int j;	
	#pragma omp parallel private(j) 
	for(int i=0;i<n;i++)
		for(j=0;j<n;j++)
	result[i] += a[i][j]*vector[j];

	
	printf(" Result: \n");
	for(int i=0;i<n;i++)
		printf("%d \n",result[i]);
	
	
	}
	
		
	
	
	
	
