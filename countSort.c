#include<stdio.h>
#include<stdlib.h>
void input(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
    printf("Enter arr[%d]:",i);
    scanf("%d",&arr[i]);
    }
}
void display(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int findMax(int n,int arr[])
{
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
void countSort(int n,int arr[])
{
    int i,j;
    int max=findMax(n,arr);
    int *C;
    C=(int*)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++)
    {
        C[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        C[arr[i]]++;
    }
    i=0,j=0;
    while(j<max+1)
    {
        if(C[j]>0)
        {
            arr[i++]=j;
            C[j]--;
        }
        else
            j++;
    }
}
int main()
{
    int n;
    printf("Enter no. of elements in the array :");
    scanf("%d",&n);
    int arr[n];
    input(n,arr);
    printf("\nOriginal array is:\n");
    display(n,arr);
    countSort(n,arr);
    printf("\nArray after sorting is:\n");
    display(n,arr);
}