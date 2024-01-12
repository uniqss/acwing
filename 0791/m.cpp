#include <vector>
#include <iostream>
using namespace std;
vector<int> add(const vector<int>& A, const vector<int>& B) {
    vector<int> ret;
    for (int i = 0, t = 0; i < max(A.size(), B.size())||t>0; ++i) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        ret.push_back(t % 10);
        t /= 10;
    }
    return ret;
}
int main(){
    string a, b;
    cin >> a >> b;
    vector<int> A(a.size()), B(b.size());
    for (int i = 0; i < a.size(); ++i) A[i] = a[a.size() - i - 1] - '0';
    for (int i = 0; i < b.size(); ++i) B[i] = b[b.size() - i - 1] - '0';
    auto ret = add(A, B);
    for (int i = ret.size() - 1; i >= 0; --i) cout << ret[i];
    return 0;
}