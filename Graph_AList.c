// A C Program to demonstrate adjacency list
// representation of graphs using Linked list
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent an adjacency list node
struct Node
{
    int dest;
    struct Node* next;
};
 
// A structure to represent an adjacency list
struct AList
{
    struct Node *head;
};
 
struct Node* new_AList_Node(int dest)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node) * 1);
    newNode->dest = dest;
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
 
void Edge(struct AList* src, struct AList* dest, int s, int d)
{
    struct Node* newNode = new_AList_Node(d);
    newNode->next = src->head;
    src->head = newNode;
    if ( s!=d )
    {
        newNode = new_AList_Node(s);
        newNode->next = dest->head;
        dest->head = newNode;
    }
}
 
void print(struct AList* graph, int src)
{
    struct Node* temp = graph->head;
    while (temp!=NULL)
    {
        printf("(%d -> %d)", src, temp->dest);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int v,e,i,a,b;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
    struct AList* graph[v];
    for( i=0; i<v; i++ )
    {
        graph[i]=new_Graph();
    }
    for( i=0; i<e; i++ )
	{
		printf("\nEnter the two vertices of an edge\n");
		scanf("%d%d", &a, &b);
		Edge(graph[a], graph[b], a, b);
	}
    for( i=0; i<v; i++ )
    {
        printf("\nAdjacency list of vertex %d\n", i);
        print(graph[i], i);
    }
}