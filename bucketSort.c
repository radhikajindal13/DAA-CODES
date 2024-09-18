#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void insert(node **Bins, int index)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = index;
    temp->next = NULL;
    if (Bins[index] == NULL) {
        Bins[index] = temp;
    } else {
        node *p = Bins[index];
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

int delete(node **Bins, int index)
{
    node *p = Bins[index];
    Bins[index] = Bins[index]->next;
    int x = p->data;
    free(p);
    return x;
}

void input(int n, int arr[])
{
    for (int i = 0; i < n; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
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

void bucketSort(int n, int arr[])
{
    int max = findMax(n, arr);
    int i, j;
    
    // Allocate memory for the array of pointers (Bins)
    node **Bins = (node**)malloc(sizeof(node*) * (max + 1));
    
    // Initialize the Bins array
    for (i = 0; i < max + 1; i++)
        Bins[i] = NULL;
    
    // Insert elements into the appropriate bins
    for (i = 0; i < n; i++)
        insert(Bins, arr[i]);
    
    // Reconstruct the sorted array from the bins
    i = 0; 
    j = 0;
    while (i < max + 1) {
        while (Bins[i] != NULL) {
            arr[j++] = delete(Bins, i);
        }
        i++;
    }

    // Free the memory allocated for Bins
    free(Bins);
}

void display(int n, int arr[])
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");  // Newline for proper formatting
}

int main()
{
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    input(n, arr);
    
    printf("\nOriginal array is:\n");
    display(n, arr);
    
    bucketSort(n, arr);
    
    printf("\nArray after sorting is:\n");
    display(n, arr);
    
    return 0;
}