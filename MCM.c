#include<stdio.h>
#include<limits.h>
//#include<conio.h>

void optimal_MCM(int s[][5], int i, int j){
  if(i==j){
    printf(" M%d ",i);
  }
  else{
    printf("(");
    optimal_MCM(s,i,s[i][j]);
    optimal_MCM(s,s[i][j]+1,j);
    printf(")");
  }
}
int MCM(int p[], int n) { 
    // mcm start
    int i,j,k,l,q;            //q is cost 
    int c[n][n], s[n][n]; // c is min multiplication and s for matrix order
    for(i=1;i<n;i++) {
        c[i][i]=0;
    }
    for(l=2;l<n;l++){
        for(i=1;i<n-l+1;i++) {
            j = l+i-1;
            c[i][j] = INT_MAX;
            for(k=i;k<=j-1;k++){
                q = c[i][k] + c[k+1][j] + p[i-1]*p[k]*p[j];
                if(c[i][j] > q){
                    c[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    optimal_MCM(s,1,n-1);
    return c[1][n-1];
}
int main(

) {
    int n;
    printf("Enterno. of dimensions ");
    scanf("%d",&n);

    int p[n]; /* p is dimension matrix and n is no. dimensions */
    // clrscr();
    
    printf("Enter dimensions\n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
    printf("Min no. of multiplications are %d ", MCM(p,n));
    //getch();
    return 0;
}