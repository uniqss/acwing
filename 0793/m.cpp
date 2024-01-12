#include <iostream>
#include <vector>
using namespace std;
vector<int> mul(const vector<int>& A, int B) {
    if (B == 0) return {0};
    vector<int> ret;
    for (int i = 0, t = 0; i < A.size() || t > 0; ++i) {
        if (i < A.size()) t += A[i] * B;
        ret.push_back(t % 10);
        t /= 10;
    }
    return ret;
}
int main() {
    string a;
    int B;
    cin >> a >> B;
    vector<int> A(a.size());
    for (int i = 0; i < a.size(); ++i) A[i] = a[a.size() - i - 1] - '0';
    auto ret = mul(A, B);
    for (int i = ret.size() - 1; i >= 0; --i) cout << ret[i];
    return 0;
}