#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(vector<int>& arr, int l, int r) {
    if (r - l <= 1) return;
    
    int pivot = arr[r - 1];
    int first_higher = l;

    for (int i = l; i < r - 1; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[first_higher]);
            first_higher++;
        }
    }
    
    swap(arr[r - 1], arr[first_higher]);

    for (int i : arr) cout << i << " ";  
    cout << endl;

    quicksort(arr, l, first_higher);        
    quicksort(arr, first_higher + 1, r);    
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, arr.size());

    return 0;
}