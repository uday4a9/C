#include <stdio.h> 

#define N 5

void rotate90(int (*a)[N])
{
	int i,j,tmp;

	for(i=0;i<N/2;i++)
	{
		for(j=i;j<(N-1-i);j++)
		{
			tmp = a[j][i];
			a[j][i] = a[N-1-i][j];
			a[N-1-i][j] = a[N-1-j][N-1-i];
			a[N-1-j][N-1-i] = a[i][N-1-j];
			a[i][N-1-j]=tmp;
		}
	}
}


void print_mat(int (*a)[N])
{
	int i,j;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%4d",a[i][j]);
		}
		puts("");
	}
}

int main() 
{
	int i,j,val=0,a[N][N];

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			a[i][j]=++val;

	printf("Given Matrix is \n");
	print_mat(a);
	rotate90(a);
	printf("After Rotating Matrix is \n");
	print_mat(a);
	return 0;
}
