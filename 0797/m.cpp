#include <vector>
#include <iostream>
using namespace std;
void sinsert(vector<int>& s, int l, int r, int c) {
    s[l] += c;
    s[r + 1] -= c;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 2);
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        sinsert(s, i, i, c);
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        sinsert(s, l, r, c);
    }
    for (int i = 1; i <= n; ++i) s[i] += s[i - 1], cout << s[i] << " ";
    return 0;
}