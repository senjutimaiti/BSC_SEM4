#include<stdio.h>
#include<string.h>

int v, e, parent[20];

typedef struct edge{
    int u, v, w;
}edge;

void sort(edge edges[e])
{
    int i, j;
    edge key;
    for (i = 1; i < e; i++) {
        key = edges[i];
        j = i - 1;
        while (j >= 0 && edges[j].w > key.w){
            edges[j + 1] = edges[j];
            j = j - 1;
        }
        edges[j + 1] = key;
    }
}

int find(int n)
{
    while( parent[n]!=-1 )
    {
        n = parent[n];
    }
    return n;
}

void union_(int m, int n)
{
    int mp,np;
    mp=find(m);
    np=find(n);
    parent[np]=mp;
}

void kruskal(edge edges[e])
{
    edge mst[v-1];
    int mstl=-1, i, mstw=0;
    sort(edges);
    for( i=0; i<e; i++ )
    {
        if(find(edges[i].u) != find(edges[i].v))
        {
            mst[++mstl] = edges[i];
            union_(find(edges[i].u), find(edges[i].v)); 
        }
    }
    printf("\nMST:\n");
    for( i=0; i<=mstl; i++ )
    {
        printf("(%d, %d)\n", mst[i].u, mst[i].v);
        mstw += mst[i].w;
    }
    printf("\nThe weight of the MST is: %d\n ", mstw);
}

int main()
{
    int i, m, n, w;
    printf("Enter the no of vertices and edges\n");
    scanf("%d%d", &v, &e);
    edge edges[e];
    for( i=0; i<v; i++ )
    {
        parent[i]=-1;
    }
    printf("\nEnter the edges as vertices - m n w\n");
    for( i=0; i<e; i++ )
    {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }  
    kruskal(edges);
}