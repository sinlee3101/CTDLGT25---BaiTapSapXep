#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    num = abs(num);
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, k;
    cout << "Nhap so phan tu cua day: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Nhap cac phan tu cua day: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Nhap so phan tu lon nhat can tim: ";
    cin >> k;

    // (a) Tim vi tri cua k phan tu lon nhat
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) { return arr[i] > arr[j]; });
    cout << "Vi tri cua " << k << " phan tu lon nhat: ";
    for (int i = 0; i < k; i++) {
        cout << indices[i] << " ";
    }
    cout << endl;

    // (b) Sap xep tang dan theo tong chu so
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return sumOfDigits(a) < sumOfDigits(b);
        });
    cout << "Day sau khi sap xep theo tong chu so: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // (c) Xoa tat ca cac so nguyen to
    arr.erase(remove_if(arr.begin(), arr.end(), isPrime), arr.end());
    cout << "Day sau khi xoa so nguyen to: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}