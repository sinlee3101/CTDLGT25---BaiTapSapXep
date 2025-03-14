#include <iostream>
#include <vector>
using namespace std;

void rearrangeArray(vector<int> &arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        while (left < right && arr[left] % 2 == 0) left++;
        while (left < right && arr[right] % 2 != 0) right--;
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sap xep chan o dau, le o cuoi voi O(n)
    rearrangeArray(arr);
    
    cout << "\nMang sau khi sap xep:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}
