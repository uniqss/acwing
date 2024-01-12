
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
    int a, b;
    cin >> a >> b;
    int apow = a * a, bpow = b * b;
    for (int ax = 1; ax < a; ++ax) {
        int remaina = apow - ax * ax, ay = sqrt(remaina);
        if (ay * ay != remaina) continue;
        // bx / b = ay / a   bx = ay * b / a
        // by / b = ax / a   by = ax * b / a
        int bx = ay * b, by = ax * b;
        if (bx % a != 0 || by % a != 0) continue;
        bx /= a, by /= a;
        if (ay == by) continue;
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << -ax << " " << ay << endl;
        cout << bx << " " << by << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
