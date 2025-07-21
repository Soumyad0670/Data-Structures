#include<stdio.h>
int main() {
    int n, temp;
    printf("Enter the number of elements in an array:\n ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Array should have at least two elements\n");
        return -1;
    }
    int arr[n];
    printf("Enter the elements of the array:\n ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1 ; j < n; j++) {
            if(arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int second_largest = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < second_largest) {
            second_largest = arr[i];
            break;
        }
    }

    int third_largest = second_largest;
    for(int i = 1; i < n; i++) {
        if(arr[i] < third_largest) {
            third_largest = arr[i];
            break;
        }
    }
    // if(second_largest == arr[0]) {
    //     printf("There is no second largest element\n");
    // } else {
    //     printf("The second largest element is %d\n", second_largest);
    // }
    if(third_largest == second_largest) {
        printf("There is no third largest element\n");
    } else {
        printf("The second largest element is %d\n", third_largest);
    }
    return 0;
}

// #include<stdio.h>
// int main()
// {
// int n,n1,i,j,count;
// printf("how many number do you want to enter:");
// scanf("%d",&n);
// int num[n];
// int cnt[n];
// printf("enter number:\n");
// for(i=1;i<=n;i++)
// {
// scanf("%d",&n1);
// num[i]=n1;
// }
// for(i=1;i<=n;i++)
// {count=0;
// for(j=1;j<=n;j++)
// {
// if(num[i]<num[j])
// {count++;}
// }
// cnt[i]=count;
// }
// for(i=1;i<=n;i++)
// {
// if(cnt[i]==1)
// {printf("second largest number is %d\n",num[i]);
// break;}
// }
// return 0;
// }