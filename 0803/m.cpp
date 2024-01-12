#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
void qsort(vector<PII>& d, int l, int r) {
    if (l >= r) return;
    int vmid = d[l + (r - l) / 2].first, i = l - 1, j = r + 1;
    while (i < j) {
        while (d[++i].first < vmid);
        while (d[--j].first > vmid);
        if (i < j) swap(d[i], d[j]);
    }
    qsort(d, l, j), qsort(d, j + 1, r);
}
int main(){
    int n;
    cin >> n;
    vector<PII> d(n);
    for (auto& [l, r] : d) cin >> l >> r;
    qsort(d, 0, d.size() - 1);
    int ret = 1, rmax = d[0].second;
    for (int i = 1; i < d.size(); ++i) {
        if (d[i].first > rmax) ++ret;
        rmax = max(rmax, d[i].second);
    }
    cout << ret;
    return 0;
}