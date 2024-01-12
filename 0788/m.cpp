#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;
LL rcount(vector<int>& d, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    LL ret = rcount(d, l, mid) + rcount(d, mid + 1, r);
    static vector<int> tmp(d);
    int i = l, j = mid + 1, t = 0;
    while (i <= mid && j <= r) {
        if (d[i] <= d[j]) tmp[t++] = d[i++];
        else {
            tmp[t++] = d[j++];
            ret += mid - i + 1;
        }
    }
    while (i <= mid) tmp[t++] = d[i++];
    while (j <= r) tmp[t++] = d[j++];
    for (i = l, j = 0; i <= r; ++i, ++j) d[i] = tmp[j];
    
    return ret;
}
int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for (int& di : d) cin >> di;
    cout << rcount(d, 0, d.size() - 1);
    return 0;
}