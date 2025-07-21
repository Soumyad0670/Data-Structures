#include<stdio.h>
int main(){
    int n,max;
    printf("Enter the number of elements in an array");
    scanf("%d",&n);
    int arr[n];
    printf("The number of elements in an array");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Even 3 digits of a array");
    max=arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i]>max)
        max=arr[i];
    }
    if(max%2==0)
        printf("%d",max);
    return 0;
}




