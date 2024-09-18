#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void input(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
    printf("Enter arr[%d]:",i);
    scanf("%d",&arr[i]);
    }
}
typedef struct node{
    int data;
    struct node *next;
} node;
 
int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}
void initializeBins(node** p, int n){
    for (int i=0; i<n; i++){
        p[i] = NULL;
    }
}
void Insert(node** ptrBins, int value, int idx){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
 
    if (ptrBins[idx] == NULL){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        node* p = ptrBins[idx];
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}
 
int Delete(node** ptrBins, int idx){
    node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->data;
    free(p);
    return x;
}
int findMax(int n, int arr[])
{
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}
 
void RadixSort(int A[], int n){
    int max = findMax(n,A);
    int nPass = countDigits(max);
 
    // Create bins array
    node** bins = (node**)malloc(sizeof(node*)*10);
 
    // Initialize bins array with nullptr
    initializeBins(bins, 10);
 
    // Update bins and A for nPass times
    for (int pass=0; pass<nPass; pass++){
 
        // Update bins based on A values
        for (int i=0; i<n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
 
        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10){
            while (bins[i] != NULL){
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }
 
    // Delete heap memory
    free(bins);
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
    input(n,arr);
    printf("\nOriginal array is:\n");
    display(n,arr);
    RadixSort(arr,n);
    printf("\nArray after sorting is:\n");
    display(n,arr);
}