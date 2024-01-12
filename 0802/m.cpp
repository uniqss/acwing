#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;
int upper_bound(const vector<PII>& d, int t) {
    int l = 0, r = d.size() - 1, mid;
    if (d[l].first >= t) return l;
    if (d[r].first < t) return -1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (d[mid].first >= t) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int lower_bound(const vector<PII>& d, int t) {
    int l = 0, r = d.size() - 1, mid;
    if (d[r].first <= t) return r;
    if (d[l].first > t) return -1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (d[mid].first <= t) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
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
void merge(vector<PII>& d) {
    int valid = 0;
    for (int i = 1; i < d.size(); ++i) {
        if (d[i].first == d[valid].first) d[valid].second += d[i].second;
        else d[++valid] = d[i];
    }
    d.resize(valid + 1);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<PII> d;
    d.push_back({-1e9-1, 0});
    while (n--) {
        int x, c;
        cin >> x >> c;
        d.push_back({x, c});
    }
    qsort(d, 0, d.size() - 1);
    merge(d);
    for (int i = 1; i < d.size(); ++i) d[i].second += d[i - 1].second;
    while (m--) {
        int l, r;
        cin >> l >> r;
        int ub = upper_bound(d, l), lb = lower_bound(d, r);
        if (ub > 0) --ub;
        if (ub >= 0) cout << d[lb].second - d[ub].second << endl;
        else cout << 0 << endl;
    }
    return 0;
}