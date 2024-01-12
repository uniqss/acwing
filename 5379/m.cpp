
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
#define ALL(__x__) __x__.begin(), __x__.end()

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> d1(n, vector<bool>(n)), d2(d1);
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c, d1[i][j] = c == 'X';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c, d2[i][j] = c == 'X';
        }
    }
    // 这题没啥好说的，以后做题一定一定一定要养成先画图的习惯，无论多简单。这题一画图就超清晰了，随便把i,j赋值个有代表性的就看出来了
    vector<bool> ans(8, true);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d1[i][j] != d2[i][j]) ans[0] = false;
            if (d1[i][j] != d2[j][i]) ans[1] = false;
            if (d1[i][j] != d2[n - i - 1][j]) ans[2] = false;
            if (d1[i][j] != d2[j][n - i - 1]) ans[3] = false;
            if (d1[i][j] != d2[n - j - 1][i]) ans[4] = false;
            if (d1[i][j] != d2[i][n - j - 1]) ans[5] = false;
            if (d1[i][j] != d2[n - i - 1][n - j - 1]) ans[6] = false;
            if (d1[i][j] != d2[n - j - 1][n - i - 1]) ans[7] = false;
        }
    }
    for (auto a : ans) {
        if (a) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
