#include<stdio.h>
#include <stdlib.h>

int main() {

    int i,j,k,n,a[10][10],ind[10],flag[10],c=0; 
    printf("Enter the no of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix;\n");

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);

    for(i=0;i<n;i++) {
            ind[i]=0;
            flag[i]=0;
    } 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ind[i]=ind[i]+a[j][i]; 

    printf("\nThe topological order is : "); 

    while(c<n){
        for(k=0;k<n;k++){
            if((ind[k]==0) && (flag[k]==0)) {
                printf("%d ",(k+1));
                flag [k]=1;
            }

            for(i=0;i<n;i++){
                if(a[i][k]==1)
                    ind[k]--;
                }    
        }
        c++;
    }  
    printf("\n\n");
    return 0;
}