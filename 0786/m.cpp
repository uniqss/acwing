#include <vector>
#include <iostream>
using namespace std;
int mink(vector<int>& d, int l, int r, int k) {
    if (l == r) return d[l];
    int vmid = d[l + (r - l) / 2], i = l - 1, j = r + 1;
    while (i < j) {
        while (d[++i] < vmid);
        while (d[--j] > vmid);
        if (i < j) swap(d[i], d[j]);
    }
    if (k <= j) return mink(d, l, j, k);
    return mink(d, j + 1, r, k);
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    for (int& t : d) cin >> t;
    cout << mink(d, 0, d.size() - 1, k - 1);
    return 0;
}