#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int v,e;
typedef struct node{
    int name,deg,col;
}node;

void sort(node nodes[])//not working
{
    int i,j;
    node key;
    for( i=1; i<e; i++ )
    {
        key=nodes[i];
        j=i-1;
        while( j>=0 && nodes[i].deg < key.deg ) 
        {
            nodes[j+1]=nodes[j];
            j--;
        }
        nodes[j+1]=key;
    }
}

bool assign(int g[v][v], node nodes[], int u, int c)
{
    int i;
    for( i=0;i<v;i++)
    {
        if(u != i && g[u][i] == 1 && nodes[i].col == c)
            return false;
    }
    return true;
}

void color(int g[v][v],node nodes[v], node usrt[v])
{
    int i;
    for(i=0;i<v;i++)
    {
        int u = nodes[i].name;
        int c = 1;
        while(!assign(g, usrt, u, c))
        {
            c++;
        }
    usrt[u].col = c;
    }
}

int main()
{
	node nodes[v];
    node usrt[v];
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
	int a[v][v];
	int i,j,p,w;
	for( i=0; i<v; i++ )
	{
        nodes[i].name=i;
        nodes[i].col=0;
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
        int s=0;
		for( j=0; j<v; j++)
		{
            s+=a[i][j];
			printf("%d ",a[i][j]);
		}
        printf("    %d",s);
        nodes[i].deg=s;
		printf("\n");
	}

    sort(nodes);
    for( i=0; i<v; i++ )
    {
        usrt[nodes[i].name] = nodes[i];
    }
    color(a, nodes, usrt);
    for( i=0; i<v; i++ )
    {
        printf("\n%d is coloured %d", i,usrt[i].col);
    }
}

