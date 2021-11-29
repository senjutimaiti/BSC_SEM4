// A C Program for prim algorithm
// representation of graphs using adjacency matrix
#include <stdio.h>
#include <stdlib.h>

void prim(int v, int a[v][v])
{
    int i,j,min,n,sw=0;
    int parent[v], key[v], mstset[v];
    for( j=0; j<v; j++ )
    {
        key[j]=9999;
        mstset[j]=0;
        parent[j]=-1;
    }
    j=0;
    key[j]=0;
    while (j<v)
    {
        min=9998;
        for( i=0; i<v; i++ )
        {
            if( mstset[i]==0 )
            {
                if( min>key[i] )
                {
                    min=key[i];
                    n=i;
                }
            }
        }
        mstset[n]=1;
        for( i=0; i<v; i++ )
        {
            if( a[n][i] > 0 )
            {
                if( mstset[i]==0 )
                {
                    if( key[i]>a[n][i] )
                    {
                        key[i]=a[n][i];
                        parent[i]=n;
                    }
                }
            }
        }
        j++;
    }
    printf("\nMST:\n");
    for( i=1; i<v; i++ )
    {
        sw += a[i][parent[i]];
        printf("(%d, %d)\n",parent[i],i);
    }
    printf("\nThe minimum cost: %d\n",sw);
}

int main()
{
	int v,e;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
	int a[v][v];
	int i,j,p,w;
	for( i=0; i<v; i++ )
	{
		for( j=0; j<v; j++ )
		{
			a[i][j]=0;
		}
	}
    printf("\nEnter the edge - m n w\n");
	for( p=0; p<e; p++ )
	{
		scanf("%d%d%d", &i, &j, &w);
        if(( a[i][j] > 0 && a[i][j] < w) || ( i==j ))
            continue;
        else{
		    a[i][j]=w;
		    a[j][i]=w;
        }	
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
    prim(v,a);
}