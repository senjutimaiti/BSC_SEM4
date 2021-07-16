// A C Program for Floyd Warshall algorithm
// representation of graphs using adjacency matrix
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(int v, int a[v][v])
{
    int i,j;
    for( i=0; i<v; i++)
	{
		for( j=0; j<v; j++)
		{
            if(a[i][j]==9999)
                printf("INF\t");
            else
			    printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void fw(int v, int a[v][v])
{
    int i,j,k=0;
    while( k<v )
    {
        for( i=0; i<v; i++ )
        {
            for( j=0; j<v; j++ )
            {
                if( i==j )
                    continue;
                else
                    a[i][j]=fmin(a[i][j],(a[i][k]+a[k][j]));
            }
        }
        printf("\nD%d:\n",(k+1));
        print(v,a);
        k++;
    }
    printf("\nThe shortest path matrix:\n");
    print(v,a);
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
            if( i!=j )
			    a[i][j]=9999;
            else
                a[i][j]=0;
		}
	}
    printf("\nEnter the edge - m n w\n");
	for( p=0; p<e; p++ )
	{
		scanf("%d%d%d", &i, &j, &w);
        if( a[i][j] > 0 && a[i][j] < w)
            continue;
        else{
		    a[i][j]=w;
        }	
    }
	printf("\nThe distance matrix:\n");
	print(v, a);
    fw(v, a);
}