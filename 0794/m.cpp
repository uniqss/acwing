#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> div(const vector<int>& A, int B, int& r) {
    vector<int> ret;
    int t = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
        t *= 10;
        t += A[i];
        ret.push_back(t / B);
        t %= B;
    }
    r = t;
    reverse(ret.begin(), ret.end());
    while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
    return ret;
}
int main(){
    string a;
    int B;
    int r = 0;
    cin >> a >> B;
    vector<int> A(a.size());
    for (int i = 0;i < a.size(); ++i) A[i] = a[a.size() - i - 1] - '0';
    auto ret = div(A, B, r);
    for (int i = ret.size() - 1; i >= 0; --i) cout << ret[i];
    cout << endl;
    cout << r;
    return 0;
}