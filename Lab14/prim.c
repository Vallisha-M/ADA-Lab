

#include<stdio.h>
#include<stdbool.h> 

#define INF 9999999

#define V 4

int G[V][V] = {
  {0,1,3,0},{0,0,1,0},{7,0,0,2},{2,0,0,0}};

int main() {
  int no_edge;  // number of edge


  int selected[V];

  // set selected false initially
  memset(selected, false, sizeof(selected));

  no_edge = 0;

  selected[0] = true;

  int x;  //  row 
  int y;  //  col 

  // print for edge and weight
  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }

  return 0;
}