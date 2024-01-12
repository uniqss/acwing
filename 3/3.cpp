
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

struct param {
  long long xi,ki,mi;
  vector<int> m;
};
int main(){
    int n, m, b, xi, ki, mi, ei;
    cin >> n >> m >> b;
    vector<param> p(n);
    vector<vector<int>> tos(m);
    for (int i = 0; i < n; ++i) {
        cin >> xi >> ki >> mi;
        p[i].xi = xi, p[i].ki = ki, p[i].mi = mi;
        for (int j = 0; j < p[i].mi; ++j) {
            cin >> ei;
            p[i].m.emplace_back(ei - 1);
            tos[ei - 1].emplace_back(i);
        }
    }
    long long ans = INT64_MAX, vip = 0, cost = 0;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int midx){
        if (midx == m) {
            ans = min(ans, vip * b + cost);
            return;
        }
        for (int nidx : tos[midx]) {
            if (vis[nidx]) {
                dfs(midx + 1);
                continue;
            } else {
                long long vippre = vip, costpre = cost;
                vis[nidx] = true;
                cost += p[nidx].xi;
                vip = max(vip, p[nidx].ki);
                dfs(midx + 1);
                vis[nidx] = false;
                vip = vippre;
                cost = costpre;
            }
            
        }
    };
    dfs(0);
    if (ans == INT64_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}
