#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// (a) Dinh nghia cau truc du lieu luu tru mot so hang cua day thuc bac n
struct SoHang {
    double heSo;
    int bac;
};

// (b) Sap xep cac so hang theo thu tu tang dan cua bac
bool compareBac(const SoHang &a, const SoHang &b) {
    return a.bac < b.bac;
}

int main() {
    int n;
    cout << "Nhap so luong so hang: ";
    cin >> n;
    
    vector<SoHang> dayThuc(n);
    cout << "Nhap cac so hang (he so va bac): \n";
    for (int i = 0; i < n; i++) {
        cout << "So hang thu " << i + 1 << ": ";
        cin >> dayThuc[i].heSo >> dayThuc[i].bac;
    }
    
    // Sap xep cac so hang theo thu tu tang dan cua bac
    sort(dayThuc.begin(), dayThuc.end(), compareBac);
    
    cout << "Day thuc sau khi sap xep: \n";
    for (const auto &sh : dayThuc) {
        cout << sh.heSo << "x^" << sh.bac << " ";
    }
    cout << endl;
    
    return 0;
}
