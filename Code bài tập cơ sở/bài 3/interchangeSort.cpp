void interchangeSort(int arr[], int n, long long &compareCount, long long &swapCount) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            compareCount++;
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                swapCount++;
            }
        }
    }
}
