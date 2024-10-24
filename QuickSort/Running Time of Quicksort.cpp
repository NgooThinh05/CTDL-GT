#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count shifts in Insertion Sort
int insertionSortCountShifts(vector<int>& arr) {
    int shifts = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shifts++; 
        }
        arr[j + 1] = key;  
    }
    return shifts;
}

// Function to count swaps in Quicksort using Lomuto partition
int quicksortCountSwaps(vector<int>& arr, int l, int r, int& quicksortSwaps) {
    if (r - l <= 1) return quicksortSwaps; 


    int pivot = arr[r - 1];
    int first_higher = l;

    for (int i = l; i < r - 1; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[first_higher]);
            quicksortSwaps++;  
            first_higher++;
        }
    }


    swap(arr[r - 1], arr[first_higher]);
    quicksortSwaps++;


    quicksortCountSwaps(arr, l, first_higher, quicksortSwaps);        
    quicksortCountSwaps(arr, first_higher + 1, r, quicksortSwaps);    

    return quicksortSwaps;
}

int main() {
    int n;
    cin >> n;  

    vector<int> arr(n), arrCopy(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  
        arrCopy[i] = arr[i];  
    }

    int insertionShifts = insertionSortCountShifts(arr);

    int quicksortSwaps = 0;
    quicksortCountSwaps(arrCopy, 0, n, quicksortSwaps);

    cout << insertionShifts - quicksortSwaps << endl;

    return 0;
}
