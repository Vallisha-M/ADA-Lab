#include <stdio.h>

int minDistance(int dist[], int sptSet[], int V)
{
    int min = 999, min_index;
    int v;
    for (v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
int printSolution(int dist[], int V, int number[])
{
    int i;
    printf("Vertex \t\t Distance from Source \t\t Number\n");
    for (i = 0; i < V; i++)
        printf("%d \t\t %d \t\t\t\t %d\n", i, dist[i],number[i]);
}
void dijkstra(int graph[4][4], int src, int V)
{
    int dist[V];
    int i, count, u, v;
    int sptSet[V];
    for (i = 0; i < V; i++)
        dist[i] = 999, sptSet[i] = 0;

    dist[src] = 0;
    int number[V];
    for (count = 0; count < V - 1; count++)
    {
        
        u = minDistance(dist, sptSet, V);
        number[u]=count;
      
        sptSet[u] = 1;

        for (v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != 999 && dist[u] + graph[u][v] < dist[v]){
              
                dist[v] = dist[u] + graph[u][v];
            }
    }
    
    for(i=0;i<V;i++){
    if(sptSet[i]==0){
        int max = 0;
        for(int j = 0;j<V;j++){
            if(number[j]>max && sptSet[j]!=0)
                max = number[j];
        }
        number[i] = max;
    }

    }
    printSolution(dist, V, number);
}

int main()
{
    int graph[4][4]={
        {0, 0, 3, 0}, 
        {0, 0, 0, 0},
        {0, 7, 0, 1},
        {6, 0, 0, 0}
        };

    dijkstra(graph, 0, 4);

    return 0;
}