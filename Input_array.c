#include<stdio.h>
int main(){
    int n,s=0,avg;
    printf("Enter the number of elements in an array");
    scanf("%d",&n);
    int arr[n];
    printf("The number of elements in an array");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("The sum of all the elements in the array");
    for(int i = 0; i < n; i++) {
        if(arr[i]%2==0)
        s=s+arr[i];
    }
    printf("%d ", s); 
    avg=s/n;
    printf("%d",avg);
    return 0;
}