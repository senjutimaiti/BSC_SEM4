// A C Program for dijkstra algorithm
// representation of graphs using adjacency matrix
#include <stdio.h>
#include <stdlib.h>

void dij(int v, int a[v][v],int s)
{
    int i,j,min,n;
    int parent[v], val[v], set[v];
    for( j=0; j<v; j++ )
    {
        val[j]=9999;
        set[j]=0;
        parent[j]=-1;
    }
    j=0;
    val[s]=0;
    while (j<v-1)
    {
        min=9998;
        for( i=0; i<v; i++ )
        {
            if( set[i]==0 )
            {
                if( min>val[i] )
                {
                    min=val[i];
                    n=i;
                }
            }
        }
        set[n]=1;
        for( i=0; i<v; i++ )
        {
            if( a[n][i] > 0 )
            {
                if( set[i]==0 )
                {
                    if( val[i]> ( val[n] + a[n][i] ))
                    {
                        val[i]=a[n][i] + val[n];
                        parent[i]=n;
                    }
                }
            }
        }
        j++;
    }
    printf("\nSPT:\n");
    for( i=0; i<v; i++ )
    {
        if( parent[i]!=-1 )
            printf("(%d, %d)\n",parent[i],i);
    }
    printf("\nDestination\tDistance from source\n");
    for( i=0; i<v; i++ )
    {
        printf("%d\t\t%d\n",i,val[i]);
    }
}

int main()
{
	int v,e,s;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
    printf("Enter the starting node: ");
	scanf("%d",&s);
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
    dij(v,a,s);
}