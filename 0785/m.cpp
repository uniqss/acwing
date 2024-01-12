#include <vector>
#include <iostream>
using namespace std;
void qsort(vector<int>& d, int l, int r) {
    if (l >= r) return;
    int vmid = d[l + (r - l) / 2], i = l - 1, j = r + 1;
    while (i < j) {
        while (d[++i] < vmid);
        while (d[--j] > vmid);
        if (i < j) swap(d[i], d[j]);
    }
    qsort(d, l, j), qsort(d, j + 1, r);
}
int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for (int& t : d) cin >> t;
    qsort(d, 0, d.size() - 1);
    for (int t : d) cout << t << " ";
    return 0;
}