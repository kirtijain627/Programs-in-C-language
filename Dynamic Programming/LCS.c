#include<stdio.h>
#include<string.h>
char X[100], Y[100];
void LCS_optimal(char X[], int b[][4], int i, int j){
  while(i>0&&j>0)
  {
    if(b[i-1][j-1] == 1){
      printf("%c",X[i-1]);
      i = i-1;
      j = j-1;
    }
    else if(b[i-1][j-1] == 2){
      i = i-1;
    }
    else{
      j = j-1;
    }
    //printf("HII");
  }
  //printf("HII");
}

void LCS(char X[], char Y[], int m, int n){
  int c[m+1][n+1], b[m][n];
  int i,j;
  for(i=0;i<=m;i++){
    c[i][0] = 0;
  }
  for(j=0;j<=n;j++){
    c[0][j] = 0;
  }
  for(i=1;i<=m;i++){
    for(j=1;j<=n;j++){
      if(X[i-1] == Y[j-1]){
        c[i][j] = c[i-1][j-1]+1;
        b[i-1][j-1] = 1;           //1 represents diagonal
      }
      else if(c[i-1][j]>=c[i][j-1]){
        c[i][j] = c[i-1][j];
        b[i-1][j-1] = 2;             // 2 means upper
      }
      else{
        c[i][j] = c[i][j-1];
        b[i-1][j-1] = 3;              //3 means left
      }
    }
  }

  for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
      printf("%d\t",c[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%d\t",b[i][j]);
    }
    printf("\n");
  }

  LCS_optimal(X,b,m,n);     
}

int main(){
int m, n;
printf("Enter length of string X and Y:\n");
scanf("%d%d",&m,&n);
printf("Enter 1st sequence: ");
scanf("%s",X);
printf("Enter 2nd sequence: ");
scanf("%s",Y);
LCS(X, Y, m, n);
}