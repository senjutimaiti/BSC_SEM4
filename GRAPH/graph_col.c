#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int v,e;

bool assign(int g[v][v], int col[v], int u, int c)
{
    int i;
    for( i=0;i<v;i++ )
    {
        if(u != i && g[u][i] == 1 && col[i] == c)
            return false;
    }
    return true;
}

void color(int g[v][v],int col[v])
{
    int i;
    for(i=0;i<v;i++)
    {
        int c = 1;
        while(!assign(g, col, i, c))
        {
            c++;
        }
        col[i] = c;
    }
}

int main()
{
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
	int a[v][v],col[v];
	int i,j,p,w;
	for( i=0; i<v; i++ )
	{
        col[i]=0;
		for( j=0; j<v; j++ )
		{
			a[i][j]=0;
		}
	}
    printf("\nEnter the edge - m n\n");
	for( p=0; p<e; p++ )
	{
		scanf("%d%d", &i, &j);
        a[i][j] = a[j][i] = 1;
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
    color(a, col);
    p=col[0];
    for( i=0; i<v; i++ )
    {
        if(p<col[i])
            p=col[i];
        printf("\n%d is coloured C%d", i,col[i]);
    }
    printf("\n\nChromatic Number of the graph = %d", p);
}

