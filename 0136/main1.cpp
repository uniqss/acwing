
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <climits>
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
    vector<PII> an(n);
    for (int i = 0; i < n; ++i) cin >> an[i].first, an[i].second = i + 1;
    sort(ALL(an));
    vector<PII> ans(n);
    for (int i = 1; i < n; ++i) {
        ans[i].first = an[i].first - an[i - 1].first;
        ans[i].second = an[i - 1].second;
        if (i < n - 1) {
            if (an[i + 1].first - an[i].first < ans[i].first) {
                ans[i].first = an[i + 1].first - an[i].first;
                ans[i].second = an[i + 1].second;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        auto [diff, idx] = ans[i];
        cout << diff << " " << idx << endl;
    }

    return 0;
}
