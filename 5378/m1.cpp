
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

// 这个算法应该被记住的：n / x正整数向上取整 = (n + x - 1) / x

int main() {
    int n, x;
    cin >> n >> x;
    cout << (n + x - 1) / x << endl;

    return 0;
}
