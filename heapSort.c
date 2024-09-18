//heap sort
// bfs dfs
// topological sort
// strongly connected components

//priority queues,tree,hashing

#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int i, int n, int *arr) {
    int left, right, maxindex;
    left = 2*i;
    right = 2*i + 1;
    maxindex = i;

    if ((left <= n) && (arr[left] > arr[maxindex])) {
        maxindex = left; 
    }
    if ((right <= n) && (arr[right] > arr[maxindex])) {
        maxindex = right;
    }
    if (maxindex != i) {
        swap(&arr[maxindex], &arr[i]);
        max_heapify(maxindex, n, arr);
    }
}

void heapsort(int *arr, int n) {
    // Build Max Heap
    for (int i = n / 2; i >= 1; i--) {
        max_heapify(i, n, arr);
    }
    
    // Heap Sort
    for (int i = n; i >= 2; i--) {
        swap(&arr[1], &arr[i]);
        max_heapify(1, i - 1, arr);
    }
}

void display_array(int* arr, int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void input(int* arr, int n) {
    printf("Taking Inputs ------------\n");
    for (int i = 1; i <= n; i++) {
        printf("Element %d : ", i);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int arr[51];    // max size assumed to be 50
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    input(arr, size);
    printf("Array before Sorting: ");
    display_array(arr, size);
    heapsort(arr, size);
    printf("Sorting done\n");
    printf("Array after Sorting: ");
    display_array(arr, size);
    return 0;
}