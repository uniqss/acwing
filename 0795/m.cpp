#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        s[i] = s[i - 1] + t;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
