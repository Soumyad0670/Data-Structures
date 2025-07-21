#include<stdio.h>
int main(){
    int n,max;
    printf("Enter the number of elements in an array");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("The number of elements in an array\n");
    for(int i = 0; i < n; i++) {
        if(arr[i]%2==0)
        printf("%d\n",arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if(arr[i]%2!=0)
        printf("%d\n",arr[i]);
    }
}
