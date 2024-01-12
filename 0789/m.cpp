#include <vector>
#include <iostream>
using namespace std;
int upper_bound(const vector<int>& d, int t) {
    int l = 0, r = d.size() - 1, mid;
    if (d[l] >= t) return l;
    if (d[r] < t) return -1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (d[mid] >= t) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int lower_bound(const vector<int>& d, int t) {
    int l = 0, r = d.size() - 1, mid;
    if (d[r] <= t) return r;
    if (d[l] > t) return -1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (d[mid] <= t) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> d(n);
    for (int& di : d) cin >> di;
    while (q--) {
        int t;
        cin >> t;
        int ub = upper_bound(d, t), lb = lower_bound(d, t);
        if (ub >= 0 && d[ub] != t) ub = -1;
        if (lb >= 0 && d[lb] != t) lb = -1;
        cout << ub << " " << lb << endl;
    }
    return 0;
}