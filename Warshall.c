// A C Program for Warshall algorithm
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
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void war(int v, int a[v][v])
{
    int i,j,k=0;
    while( k<v )
    {
        for( i=0; i<v; i++ )
        {
            for( j=0; j<v; j++ )
            {
                if( a[i][k]==1 && a[k][j]==1 )
                    a[i][j]=1;
            }
        }
        printf("\nR%d:\n",(k+1));
        print(v,a);
        k++;
    }
    printf("\nThe transitive closure matrix:\n");
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
	int i,j,p;
	for( i=0; i<v; i++ )
	{
		for( j=0; j<v; j++ )
		{
            a[i][j]=0;
		}
	}
    printf("\nEnter the edge - m n\n");
	for( p=0; p<e; p++ )
	{
		scanf("%d%d", &i, &j);
        a[i][j]=1;
    }
	printf("\nThe adjacency matrix:\n");
	print(v, a);
    war(v, a);
}