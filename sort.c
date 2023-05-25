#include <stdio.h>
#include <stdlib.h>

void heapify(int* arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
    }
}

void heap_sort(int* arr, int n)
{
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr, i, 0);
    }
}

void insertion_sort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    printf("Введите длину массива:\n");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка: введите целое число\n");
        exit(-1);
    }

    int arr[n];
    printf("Введите массив:\n");
    for (int i = 0; i < n; i++){
        if (scanf("%d", &arr[i]) != 1) {
            printf("Ошибка: введите целое число\n");
            exit(-1);
        }
    }
    
    
    printf("Начальный массив: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int insertion[n];
    int heap[n];
    for (int i = 0; i < n; i++) {
        insertion[i] = arr[i];
        heap[i] = arr[i];
    }
    
    printf("Сортировка вставками\n");
    insertion_sort(insertion, n);
    printf("Отсортированный массив: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", insertion[i]);
    }
    printf("\n\n");

    printf("Пирамидальная сортировка\n");
    heap_sort(heap, n);
    printf("Отсортированный массив: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}