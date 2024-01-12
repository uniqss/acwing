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

struct td {
    int a;
    int b;
    int x;
};

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void proc(td& d) {
    LL g = gcd(d.a, d.b);
    d.x = ((LL)d.a) * d.b / g;

    if (d.x == d.b) {
        int a = d.a, b = d.b, m = 2;
        for (; m <= b; ++m) {
            // if (m <= a && a % m != 0) continue;
            if (m <= b && b % m != 0) continue;
            break;
        }
        d.x *= m;
    }
}

int main() {
    int n;
    cin >> n;
    vector<td> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i].a >> d[i].b;
    }
    for (int i = 0; i < n; ++i) {
        proc(d[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << d[i].x << endl;
    }
    return 0;
}
