#include<stdio.h>
int main(){
    int n,i,s=0;
    printf("Enter the number of elements in an array");
    scanf("%d",&n);
    int arr[n];
    printf("The elements in an array");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("The number of elements in reversed order of array");
    for(int j=n;j>=0;j--){
        printf("%d\n",arr[j]);
    }
}