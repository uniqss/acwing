#include <iostream>
#include <vector>
using namespace std;
bool vcmp(const vector<int>& A, const vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; --i) 
        if (A[i] != B[i]) return A[i] > B[i];
    return true;
}
vector<int> sub(const vector<int>& A, const vector<int>& B) {
    vector<int> ret;
    for (int i = 0, t = 0; i < A.size() || t != 0; ++i) {
        t += A[i];
        if (i < B.size()) t -= B[i];
        ret.push_back((t + 10) % 10);
        if (t < 0) t = -1;
        else t = 0;
    }
    while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
    return ret;
}
int main(){
    string a, b;
    cin >> a >> b;
    vector<int> A(a.size()), B(b.size());
    for (int i = 0; i < a.size(); ++i) A[i] = a[a.size() - i - 1] - '0';
    for (int i = 0; i < b.size(); ++i) B[i] = b[b.size() - i - 1] - '0';
    if (vcmp(A, B)) {
        auto ret = sub(A, B);
        for (int i = ret.size() - 1; i >= 0; --i) cout << ret[i];
    } else {
        cout << "-";
        auto ret = sub(B, A);
        for (int i = ret.size() - 1; i >= 0; --i) cout << ret[i];
    }
    return 0;
}