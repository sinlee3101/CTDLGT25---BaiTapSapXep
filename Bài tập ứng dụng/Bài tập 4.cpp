#include <iostream>
#include <vector>
using namespace std;

// Ham kiem tra so nguyen to
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int m, n;
    cout << "Nhap so dong va so cot cua ma tran: ";
    cin >> m >> n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // (a) Tim so nguyen to lon nhat trong ma tran
    int maxPrime = -1;
    for (const auto &row : matrix) {
        for (int num : row) {
            if (isPrime(num) && num > maxPrime) {
                maxPrime = num;
            }
        }
    }
    cout << "\nSo nguyen to lon nhat trong ma tran: " << (maxPrime == -1 ? "Khong co" : to_string(maxPrime)) << "\n";
    
    // (b) Tim nhung dong co chua so nguyen to
    cout << "\nCac dong co chua so nguyen to: ";
    for (int i = 0; i < m; i++) {
        bool hasPrime = false;
        for (int j = 0; j < n; j++) {
            if (isPrime(matrix[i][j])) {
                hasPrime = true;
                break;
            }
        }
        if (hasPrime) cout << i + 1 << " ";
    }
    cout << "\n";
    
    // (c) Tim nhung dong chi chua so nguyen to
    cout << "\nCac dong chi chua so nguyen to: ";
    for (int i = 0; i < m; i++) {
        bool allPrime = true;
        for (int j = 0; j < n; j++) {
            if (!isPrime(matrix[i][j])) {
                allPrime = false;
                break;
            }
        }
        if (allPrime) cout << i + 1 << " ";
    }
    cout << "\n";
    
    return 0;
}
