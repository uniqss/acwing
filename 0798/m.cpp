#include <vector>
#include <iostream>
using namespace std;
void sinsert(vector<vector<int>>& s, int x1, int y1, int x2, int y2, int c) {
    ++x2, ++y2;
    s[x1][y1] += c;
    s[x1][y2] -= c;
    s[x2][y1] -= c;
    s[x2][y2] += c;
}
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> s(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c;
            cin >> c;
            sinsert(s, i, j, i, j, c);
        }
    }
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        sinsert(s, x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}