#include<stdio.h>
void input(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
    printf("Enter arr[%d]:",i);
    scanf("%d",&arr[i]);
    }
}
void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int arr[],int l,int h)
{
    int i=l,j=h;
    int pivot=arr[l];
    do
    {
    do
    {
        i++;
    }while(arr[i]<=pivot);
    do
    {
        j--;;
    }while(arr[j]>pivot);
    if(i<j)
    swap(&arr[i],&arr[j]);
    }while(i<j);
    swap(&arr[l],&arr[j]);
    return j;
}

void quickSort(int arr[],int l,int h)
{
if(l<h)
{
    int j=partition(arr,l,h);
    quickSort(arr,l,j);
    quickSort(arr,j+1,h);
}
}

void display(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n;
    printf("Enter no. of elements in the array :");
    scanf("%d",&n);
    int arr[n];
    arr[n]=__INT_MAX__;
    input(n,arr);
    printf("\nOriginal array is:\n");
    display(n,arr);
    quickSort(arr,0,n);
    printf("\nArray after sorting is:\n");
    display(n,arr);
}