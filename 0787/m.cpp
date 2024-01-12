#include <vector>
#include <iostream>
using namespace std;
void msort(vector<int>& d, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    msort(d, l, mid), msort(d, mid + 1, r);
    static vector<int> tmp(d);
    int i = l, j = mid + 1, t = 0;
    while (i <= mid && j <= r) {
        if (d[i] <= d[j]) tmp[t++] = d[i++];
        else tmp[t++] = d[j++];
    }
    while (i <= mid) tmp[t++] = d[i++];
    while (j <= r) tmp[t++] = d[j++];
    for (i = l, j = 0; i <= r; ++i, ++j) d[i] = tmp[j];
}
int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int& di : d) cin >> di;
    msort(d, 0, d.size() - 1);
    for (int di : d) cout << di << " ";
    return 0;
}