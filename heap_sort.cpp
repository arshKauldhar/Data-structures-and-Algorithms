#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); // Call max heapify on the reduced heap
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    heapSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}