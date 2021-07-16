#include<stdio.h>
#include<string.h>

void bfs(int v,int vt[v],int a[v][v],int s)
{
    int q[v], p[v], r=-1, f=-1, i, d=0;
    q[++r]=s; //EnQueue
    vt[s]=1;
    while(r!=f)
    {
		printf("\nQueue: ");
		for( i=++f; i<=r; i++ )
			printf("%d ",q[i]);
        s=q[f]; //DeQueue
		p[d++]=s;
		printf("\nPrint: ");
        for( i=0; i<d; i++ )
			printf("%d ",p[i]);
        for( i=0; i<v; i++ )
        {
            if( a[s][i]==1 && vt[i]==0 ) //isEmpty and isVisited
            {
                q[++r]=i; //EnQueue
                vt[i]=1;
            }
        }
    }
}

int main()
{
	int v,e;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
	int a[v][v], vt[v];
	int i,j,p,start;
	for( i=0; i<v; i++ )
	{
		vt[i]=0;
		for( j=0; j<v; j++ )
		{
			a[i][j]=0;
		}
	}
	for( p=0; p<e; p++ )
	{
		printf("\nEnter the two vertices of an edge\n");
		scanf("%d%d", &i, &j);
		a[i][j]=1;
		a[j][i]=1;
	}
	printf("\nThe adjacency matrix:\n");
	for( i=0; i<v; i++)
	{
		for( j=0; j<v; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the starting point\n");
	scanf("%d", &start);
	printf("\nBFS:\n");
    bfs(v,vt,a,start);
}