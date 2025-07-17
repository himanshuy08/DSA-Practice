#include<iostream>
#include<vector>
using namespace std;
// Function to sort an array using recursion
void sortArray(vector<int>& arr, int n) {
    // Base case: if the array has one or no elements, it's already sorted
    if (n <= 1) {
        return;
    }
    
    // Recursive case: sort the first n-1 elements
    sortArray(arr, n - 1);
    
    // Insert the nth element into its correct position in the sorted part of the array
    int last = arr[n - 1];
    int j = n - 2;
    
    // Move elements of arr[0..n-2], that are greater than last, to one position ahead
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    
    // Place last at its correct position
    arr[j + 1] = last;
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    int n = arr.size();
    
    sortArray(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
