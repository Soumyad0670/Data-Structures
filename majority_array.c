#include<stdio.h>
int main()
{
    int n1,n2,i,j,count;
    printf("how many number do you want to enter?:");
    scanf("%d",&n1);
    int num[n1];
    printf("enter number:\n");
    for(i=1;i<n1;i++)
    {scanf("%d\n",&n2);
    // num[i]=n2;
    }
    for(j=1;j<=n1;j++)
    {
    count=0;
    for(i=1;i<=n1;i++)
    {
    if(num[j]==num[i])
    {count++;}
    }
    if(count>=(n1/2))
    {printf("majority elements is %d \n",num[j]);
    }
        else
    {
        printf("have no majority number which satisfy the condition\n");}
        return 0;
    }
}
