#include<stdio.h>
void main(){
int n, a[20], i, j, loc, min, temp;
printf("Enter the number of elements you want to insert in array:");
scanf("%d",&n);
printf("enter the array elements\n");
for(i=0;i<=n-1;i++){
    scanf("%d",&a[i]);
}
printf("array given by you is\n");
for(i=0;i<=n-1;i++){
    printf("%d ",a[i]);
}
for(i=0;i<=n-1;i++){
        min = a[i];
        loc = i;
    for(j=i+1;j<=n-1;j++){
        if(min>a[j]){
            min = a[j];
            loc = j;
        }
    }
    temp = a[i];
    a[i] = a[loc];
    a[loc] = temp;
}
printf("\nNew sorted array is\n");
for(i=0;i<=n-1;i++){
    printf("%d ",a[i]);
}
}
