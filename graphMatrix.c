#include<stdio.h>
int main()
{
	int a[10][10];
	int v,e;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
	int p,k,i,j,w,flag=0;
	for(p=0;p<v;p++)
	{
		for(k=0;k<v;k++)
		{
			a[p][k]=0;
		}
	}
	for(p=0;p<e;p++)
	{
		printf("\nEnter the two vertices of an edge along with the cost\n");
		scanf("%d%d%d", &i, &j, &w);
		if(i==j)
			flag=1;
		a[i][j]=w;
		a[j][i]=w;
	}
	printf("\nThe adjacency matrix:\n");
	for(p=0;p<v;p++)
	{
		for(k=0;k<v;k++)
		{
			printf("%d ",a[p][k]);
		}
		printf("\n");
	}
	if(flag==1)
		printf("\nSelf loop exists");
	else
		printf("\nSelf doesn't loop exist");
}
