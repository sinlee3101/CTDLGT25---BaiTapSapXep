int main() {
    srand(time(0));
    int sizes[] = {10, 100, 200, 500, 1000, 2000, 5000, 10000};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);
    for (int i = 0; i < numTests; i++) {
        int n = sizes[i];
        int arr[n];
        generateRandomArray(arr, n);
        cout << "\nTesting for n = " << n << ":\n";
        measureTime(interchangeSort, arr, n, "Interchange Sort");
        measureTime(selectionSort, arr, n, "Selection Sort");
        measureTime(insertionSort, arr, n, "Insertion Sort");
    }
    return 0;
}
