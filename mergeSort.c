#include<stdio.h>
void input(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
    printf("Enter arr[%d]:",i);
    scanf("%d",&arr[i]);
    }
}
void merge(int n,int arr[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int brr[n];
    while( i<=mid && j<=h )
    {
        if(arr[i]<=arr[j])
        brr[k++]=arr[i++];

        if(arr[i]>arr[j])
        brr[k++]=arr[j++];
    }
    while(i<=mid)
        brr[k++]=arr[i++];

    while(j<=h)
        brr[k++]=arr[j++];

    for(int i=l;i<=h;i++)
        {
            arr[i]=brr[i];
        }
}
void mergeSort(int n,int arr[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(n,arr,0,mid);
        mergeSort(n,arr,mid+1,h);
        merge(n,arr,l,mid,h);
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
    //arr[n]=__INT_MAX__;
    input(n,arr);
    printf("\nOriginal array is:\n");
    display(n,arr);
    mergeSort(n,arr,0,n-1);
    printf("\nArray after sorting is:\n");
    display(n,arr);
}