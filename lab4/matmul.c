#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 1000

int initialize(double * matrix);
int _initialize(double * matrix);

int main()
{
	int i, j, k;
	double *A, *B, *Cs, *Cp;
	struct timeval start, end;
	double timeCost;

	A=(double *)malloc(sizeof(double)*N*N);
	B=(double *)malloc(sizeof(double)*N*N);
	Cs=(double *)malloc(sizeof(double)*N*N);
	Cp=(double *)malloc(sizeof(double)*N*N);

	initialize(A);
	initialize(B);
	_initialize(Cs);
	_initialize(Cp);

    // sequential version
	gettimeofday(&start, NULL);
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++)
		for(k=0; k<N; k++)
		  Cs[i*N+j]+=A[i*N+k]*B[k*N+j];
	gettimeofday(&end, NULL);

	timeCost=1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
	timeCost/=1000000;
    printf("The squential version of matrix multiplication costs %lf seconds\n", timeCost);

    //////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    // please change this into a parallel version
	gettimeofday(&start, NULL);
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++)
		for(k=0; k<N; k++)
		  Cp[i*N+j]+=A[i*N+k]*B[k*N+j];
	gettimeofday(&end, NULL);

	timeCost=1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
	timeCost/=1000000;
	printf("The parallel version of matrix multiplication costs %lf seconds\n", timeCost);
    //////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
	
    // verification
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++) {
            if (Cs[i*N+j] - Cp[i*N+j] < 0.000001)
                continue;
            else {
                printf("ERRORS DETECTED!!!!!!!!!!!!!\n");
                return -1;
            }
      }

    // release resources and return
    free(A);
	free(B);
	free(Cs);
	free(Cp);
	
	return 0;
}


int initialize(double * matrix)
{
	srand((unsigned)time(NULL));
	for(int i=0; i<N; i++)
	  for(int j=0; j<N; j++)
	  {
		  matrix[i*N+j]=rand()/3000.0;
	  }
	printf("Initialized successfully!\n");
	return 0;
}

int _initialize(double * matrix)
{
	for(int i=0; i<N; i++)
	  for(int j=0; j<N; j++)
	  {
		  matrix[i*N+j]=0.0;
	  }
	printf("Initialized successfully!\n");
	return 0;
}
