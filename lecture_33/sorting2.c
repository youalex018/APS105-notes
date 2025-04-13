/*
-Sorting Part II-

Quicksort - Select a pivot, partition the array into two halves and rearrange, and recursively sort each half
- Best/average case: O(n log n)
- Worst case: O(n^2) (poorly chosen pivot)

qsort() function:
- Provided in the C standard library stdlib and is a more efficient quicksort algorithm
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
- base: Pointer to the array to be sorted
- nitems: Number of elements in the array
- size: Size (in bytes) of each element in the array
- compar: pointer to a comparision function that returns <0, =0, or >0 depending on the order of the two elements

Mergesort - Divide the array into two halves, recursively sort each half, and merge them back together
- Best/average/worst case: O(n log n)

*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // Choose the last element as pivot
        int i = low - 1; // Index of smaller element

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]); // Place the pivot in the correct position
        int pi = i + 1; // Partition index

        quicksort(arr, low, pi - 1); // Recursively sort elements before partition
        quicksort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // Comparison function for qsort
}

int main(void) {

    // qsort example
    int arr[] = {2, 33, 7, 1, 4, 5, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare); // Using qsort to sort the array
    printf("Sorted array using qsort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}