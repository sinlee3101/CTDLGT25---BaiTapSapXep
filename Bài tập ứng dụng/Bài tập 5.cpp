#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ham tinh tong cac phan tu trong mot dong
int sumRow(const vector<int> &row) {
    int sum = 0;
    for (int num : row) {
        sum += num;
    }
    return sum;
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
    
    // (a) Tim dong co tong lon nhat
    int maxSum = -1, maxRowIndex = -1;
    for (int i = 0; i < m; i++) {
        int rowSum = sumRow(matrix[i]);
        if (rowSum > maxSum) {
            maxSum = rowSum;
            maxRowIndex = i;
        }
    }
    cout << "\nDong co tong lon nhat: " << maxRowIndex + 1 << " voi tong = " << maxSum << "\n";
    
    // (b) Sap xep cac dong theo tong giam dan
    sort(matrix.begin(), matrix.end(), [](const vector<int> &a, const vector<int> &b) {
        return sumRow(a) > sumRow(b);
    });
    
    cout << "\nMa tran sau khi sap xep cac dong theo tong giam dan:\n";
    for (const auto &row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
