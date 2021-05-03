#include<stdio.h>
#include<stdlib.h>
int a[20][20], q[20], visited[20], n, i, j, f=0, r=-1;
void bfs(int v)
{
 for(i = 1;i <= n;i++)
  if(a[v][i] && !visited[i])// if i th node is adjascent to vth node and if i th node is not reached yet
   q[++r]=i; // then enqueue i
 if(f<=r) // if queue is non empty
 {
  visited[q[f]] = 1; // visit node at front of queue
  bfs(q[f++]); // BFS staring at node at front queue then dequeue
 }
}
void main()
{
 int v;

 printf("\n Enter the number of vertices:");
 scanf("%d", &n);
 for(i = 1;i <= n;i++) // initialising to zero
 {
  q[i] = 0;
  visited[i] = 0;
 }
 printf("\n Enter adjascency matrix :\n");
 for(i = 1;i <= n;i++)
  for(j = 1;j <= n;j++)
   scanf("%d", &a[i][j]);
 printf("\n Enter the starting vertex:");
 scanf("%d", &v);
 bfs(v); // start BFS at v th node
 printf("\n The node which are reachable are:\n");
 for(i = 1;i <= n;i++)
  if(visited[i]) // print i only if node i could be visited by starting at node v using BFS algorithm
   printf("%d\t", i);
 printf("\n");
}