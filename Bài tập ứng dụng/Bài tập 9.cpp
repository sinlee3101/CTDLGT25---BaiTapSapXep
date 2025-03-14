#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct SinhVien {
    int maSo;
    string hoDem;
    string ten;
    int ngay, thang, nam;
    string phai;
    double diemTB;
};

// (a) Nhap danh sach sinh vien va luu vao file
void nhapDanhSach(vector<SinhVien>& danhSach) {
    ofstream file("SINHVIEN.DAT", ios::binary);
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    danhSach.resize(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Nhap ma so: ";
        cin >> danhSach[i].maSo;
        cout << "Nhap ho va dem: ";
        cin.ignore();
        getline(cin, danhSach[i].hoDem);
        cout << "Nhap ten: ";
        getline(cin, danhSach[i].ten);
        cout << "Nhap ngay thang nam sinh (dd mm yyyy): ";
        cin >> danhSach[i].ngay >> danhSach[i].thang >> danhSach[i].nam;
        cout << "Nhap phai (Nam/Nu): ";
        cin >> danhSach[i].phai;
        cout << "Nhap diem trung binh: ";
        cin >> danhSach[i].diemTB;
    }
    file.write((char*)&danhSach[0], danhSach.size() * sizeof(SinhVien));
    file.close();
}

// (b) Sap xep danh sach theo ma so
void sapXepTheoMaSo(vector<SinhVien>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](SinhVien a, SinhVien b) {
        return a.maSo < b.maSo;
    });
}

// (c) Tao tap tin chi muc theo tieu chi sap xep
void taoChiMuc(const vector<SinhVien>& danhSach, const string& tenFile, function<bool(SinhVien, SinhVien)> cmp) {
    vector<SinhVien> dsSorted = danhSach;
    sort(dsSorted.begin(), dsSorted.end(), cmp);
    ofstream file(tenFile, ios::binary);
    file.write((char*)&dsSorted[0], dsSorted.size() * sizeof(SinhVien));
    file.close();
}

int main() {
    vector<SinhVien> danhSach;
    nhapDanhSach(danhSach);
    sapXepTheoMaSo(danhSach);
    taoChiMuc(danhSach, "SVMASO.IDX", [](SinhVien a, SinhVien b) { return a.maSo < b.maSo; });
    taoChiMuc(danhSach, "SVTH.IDX", [](SinhVien a, SinhVien b) { return (a.ten == b.ten) ? (a.hoDem < b.hoDem) : (a.ten < b.ten); });
    taoChiMuc(danhSach, "SVDTB.IDX", [](SinhVien a, SinhVien b) { return a.diemTB > b.diemTB; });
    return 0;
}
