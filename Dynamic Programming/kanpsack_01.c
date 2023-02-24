#include <stdio.h>

int main(void) {
  int n, W[50], p[50], i, j, mw, c[50][50], w,profit = 0;
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  printf("\nEnter the max weight of knap sack:");
  scanf("%d",&mw);
  printf("\nEnter the weight of elemnts:\n");
  for(i=0;i<n;i++){
    scanf("%d",&W[i]);
  }
  printf("\nEnter the profit corresponding to each element:\n");
  for(i=0;i<n;i++){
    scanf("%d",&p[i]);
  }
  for(i=0;i<=n;i++){
    c[i][0] = 0;
  }
  for(w=0;w<=mw;w++){
    c[0][w] = 0;
  }
  for(i=1;i<=n;i++){
    for(w=1;w<=mw;w++){
      if(W[i-1]<=w){
        if(p[i-1]+c[i-1][w-W[i-1]]>=c[i-1][w]){
          c[i][w] = p[i-1]+c[i-1][w-W[i-1]];
        }
        else{
          c[i][w] = c[i-1][w];
        }
      }
      else{
        c[i][w] = c[i-1][w];
      }
    }
  }
  printf("\n");
  for(i=0;i<=n;i++){
    for(j=0;j<=mw;j++){
      printf("%d\t",c[i][j]);
    }
    printf("\n");
  }

  printf("\n"); 
  i = n;
  j = mw;
  while(i>0&&j>0){
    if(c[i][j] != c[i-1][j]){
      printf("%d ",W[i-1]);
      profit = profit+p[i-1];
      printf("\nThe profit is: %d",profit);
      i = i-1;
      j = j-W[i];  /* i alredy changed */
    }
    else{
      i = i-1;
    }
  } 
 

  return 0;
}