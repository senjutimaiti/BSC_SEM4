// A C Program to demonstrate adjacency matrix
// representation of graphs 
#include <stdio.h>
#include <stdlib.h>

void check_trivial(int v)
{
	if( v==1 )
		printf("\nA Trivial graph");
    else
        printf("\nNot a Trivial graph");
}

void check_null(int v, int a[v][v])
{
	int i,j,f=1;
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{          
            if( a[i][j]==1 )
                f=0;
		}
	}
	if( f==0 )
        printf("\nNot a NuLL graph");
    else
        printf("\nA NuLL graph");
}

int check_simple(int v, int a[v][v])
{
	int i,f=1;
	for(i=0; i<v; i++)
	{
		if( a[i][i]==1 )
			f=0;
	}
	return f;
}

void check_complete(int v, int a[v][v])
{
	int i,j,f=1;
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{          
            if( a[i][j]==0 && i!=j )
                f=0;
		}
	}
	// first need to check if the graph is simple or not
	int s=check_simple(v,a);
	if( f==1 && s==1 )
        printf("\nComplete graph");
    else
        printf("\nNot a Complete graph");
}

void check_regular(int v, int a[v][v])
{
	int i,j,sum1=0,sum2=0,f=1;
	if( a[0][0]==1 )
			sum1=sum1+1;
	for( i=0; i<v; i++ )
	{	
		sum1=sum1+a[0][i];
	}
	for( i=1; i<v; i++ )
	{
		for( j=0; j<v; j++ )
		{
			// for a self loop degree becomes 2 for an isolated vertex
			if ( i==j && a[i][j]==1 )
				sum2+=1;
            sum2=sum2+a[i][j];
		}
        if(sum1!=sum2)
        {
            f=0;
            break;
        }
        sum2=0;
	}
    if( f==0 )
        printf("\nNot a Regular Graph\n");
	else
		printf("\nRegular Graph\n");
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
	check_trivial(v);
	check_null(v,a);
	int s=check_simple(v,a);
	if( s==0 )
        printf("\nNot a Simple graph");
    else
        printf("\nA Simple graph");
	check_complete(v,a);
	check_regular(v,a);
}
