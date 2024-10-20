//Created by Alexandros Panagiotakopoulos - alexandrospanag.github.io

#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 10, 7, 8, 9, 1, 5 };
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}