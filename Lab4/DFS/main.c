#include <stdio.h>
#include <stdlib.h>
int a[20][20],reach[20],n;
void dfs(int v)
{
 int i;
 reach[v]=1; // we have reached v th node, so marking it as reached
 for(i=1;i<=n;i++)
  if(a[v][i] && !reach[i]) // if i th node is adjascent to vth node and if i th node is not reached yet
   dfs(i); // then recursively call DFS starting at i th node
}
void main()
{
 int i,j,count=0;

 printf("\n Enter number of vertices:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  reach[i]=0; // initialisation to zero
  for(j=1;j<=n;j++)
   a[i][j]=0; // initialisation to zero
 }
 printf("\n Enter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 dfs(1); // start DFS at node 1
 printf("\n");
 for(i=1;i<=n;i++)
 {
   if(reach[i]) // if i th node can be reached from node 1
    count++; // then increment number of nodes that can be reached by starting at node 1 through DFS
 }
 if(count==n) // if number of nodes that can be reached is equal to the total number of nodes in the graph
  printf("\n Graph is connected\n");
 else
  printf("\n Graph is not connected\n");
}