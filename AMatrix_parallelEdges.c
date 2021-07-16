#include <stdio.h>
#include <stdlib.h>
#define MAX 20
 
// A structure to represent an adjacency list node
struct Node
{
    int w;
    struct Node* next;
};
 
// A structure to represent an adjacency list
struct AList
{
    struct Node *head;
};

struct Node* new_AList_Node(int w)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node) * 1);
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

struct AList* new_Graph()
{
    struct AList* graph;
    graph = (struct AList*) malloc(sizeof(struct AList) * 1);
    graph->head = NULL;
    return graph;
}

void Edge(struct AList *src, struct AList *dest, int w)
{
    struct Node* newNode = new_AList_Node(w);
    newNode->next = src->head;
    src->head = newNode;
    if( src!= dest )
    {
        newNode = new_AList_Node(w);
        newNode->next = dest->head;
        dest->head = newNode;
    }
}

void print(struct AList* graph)
{
    struct Node* temp = graph->head;
    while (temp!=NULL)
    {
        printf("%d ",temp->w);
        temp = temp->next;
    }
    printf("\n");
}

int sort(struct AList* graph)
{
	struct Node* temp = graph->head;
	int min = temp->w;
	temp = temp->next;
    while (temp!=NULL)
    {
        if(temp->w < min)
		min = temp->w;
		temp = temp->next;
    }
	if(graph == NULL)
		return 0;
	else
    	return min;
}

int main()
{
	int v,e;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
	struct AList *a[v][v];
	int g[v][v],i,j,p,w;
	for( i=0; i<v; i++ )
	{
		for( j=0; j<v; j++ )
		{
			a[i][j]=new_Graph();
		}

	}
	for( p=0; p<e; p++ )
	{
		printf("\nEnter the two vertices of an edge along with weight\n");
		scanf("%d%d%d", &i, &j, &w);
		Edge(a[i][j], a[j][i], w);
	}
	printf("\nThe adjacency matrix:\n");
	for( i=0; i<v; i++)
	{
		for( j=0; j<v; j++)
		{
			printf("\nEdges for %d %d\n", i,j);
			print(a[i][j]);
		}
		printf("\n");
	}
	for( i=0; i<v; i++ )
	{
		for( j=0; j<v; j++ )
		{
			if (i==j)
				g[i][j]=0;
			else
				g[i][j]=sort(a[i][j]);
		}

	}
	printf("\nThe adjacency matrix after simplifying:\n");
	for( i=0; i<v; i++)
	{
		for( j=0; j<v; j++)
		{
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
}