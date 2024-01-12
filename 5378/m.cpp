
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
    int n, x, ans;
    cin >> n >> x;
    ans = n / x;
    if (n % x != 0) ++ans;
    cout << ans << endl;

    return 0;
}
