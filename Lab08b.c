#include<stdio.h>
#define max 20
void warshal(int n,int r[max][max]){
int i,j,k;
for(k=1;k<=n;k++){
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
r[i][j]=r[i][j]||(r[i][k]&&r[k][j]);
}
}
}
printf("Transitive closure matrix is:\n");
for(i=1;i<=n;i++){
printf("\t%d",i);
}
printf("\n\t---------------------\n");
for(i=1;i<=n;i++){
printf("%d|\t",i);
for(j=1;j<=n;j++){
printf("%d\t",r[i][j]);
}
printf("\n");
}
}


int main(){
int r[max][max];
int i,j,n;
printf("Enter the number of nodes/ vertices:");
scanf("%d",&n);
printf("Enter the adjacency(1 for edge, 0 for no edge);\n"); 
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d",&r[i][j]);
}
}
warshal(n,r);
return 0;
}