void selectionSort(int arr[], int n, long long &compareCount, long long &swapCount) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            compareCount++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
        swapCount++;
    }
}
