#include<stdio.h>
int main()
{
    int n=6,a[6],i,j,item;
    printf("Enter the number of elements you want to insert in array:");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    printf("Your given array is: ");
    for(i=0;i<=n-1;i++){
        printf("%d ",a[i]);
    }
    for(i=0;i<=n-1;i++){
        item = a[i];
        for(j=i-1;j>=0;j--){
            if(a[j]>item){
                a[j+1] = a[j];
            }
            else{
                break;
            }
        }
        a[j+1] = item;
    }
    printf("\nnew sorted array is: ");
    for(i=0;i<=n-1;i++){
        printf("%d ",a[i]);
    }
}
