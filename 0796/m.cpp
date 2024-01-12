#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> s(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int t;
            cin >> t;
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + t;
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1;
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }
    return 0;
}