#include <iostream>
#include <vector>
using namespace std;

// (a) Ham tim mang nghich the tu hoan vi
vector<int> findInversionArray(const vector<int>& A) {
    int N = A.size();
    vector<int> B(N, 0);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i]) {
                B[i]++;
            }
        }
    }
    return B;
}

// (b) Ham tim hoan vi tu mang nghich the (neu co)
vector<int> findPermutationFromInversion(const vector<int>& B) {
    int N = B.size();
    vector<int> A(N, 0);
    vector<bool> used(N + 1, false);
    
    for (int i = N - 1; i >= 0; i--) {
        int count = B[i];
        for (int j = 1; j <= N; j++) {
            if (!used[j]) {
                if (count == 0) {
                    A[i] = j;
                    used[j] = true;
                    break;
                }
                count--;
            }
        }
    }
    return A;
}

int main() {
    int N;
    cout << "Nhap N: ";
    cin >> N;
    
    vector<int> A(N);
    cout << "Nhap hoan vi A:\n";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Tinh mang nghich the
    vector<int> B = findInversionArray(A);
    cout << "Mang nghich the: ";
    for (int x : B) {
        cout << x << " ";
    }
    cout << "\n";
    
    // Tim hoan vi tu mang nghich the
    vector<int> recoveredA = findPermutationFromInversion(B);
    cout << "Hoan vi tim duoc tu mang nghich the: ";
    for (int x : recoveredA) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}
