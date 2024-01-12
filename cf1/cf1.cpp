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
    int n;
    int rmed;
    vector<int> remain;
    bool ok = false;
    vector<int> ans;
};

void proc(td& d) {
    int mul = 1;
    for (int r : d.remain) {
        mul *= r;
        if (mul > 2023 || 2023 % mul != 0) {
            d.ok = false;
            return;
        }
    }
    if (mul < 2023 && d.rmed < 1) {
        d.ok = false;
        return;
    }
    d.ok = true;
    d.ans.resize(d.rmed, 1);
    d.ans[0] = 2023 / mul;
}

int main() {
    int n;
    cin >> n;
    vector<td> d(n);
    string line;
    for (int i = 0; i < n; ++i) {
        cin >> d[i].n >> d[i].rmed;
        for (int j = 0; j < d[i].n; ++j) {
            int tmp;
            cin >> tmp;
            d[i].remain.emplace_back(tmp);
        }
    }
    for (int i = 0; i < n; ++i) {
        proc(d[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (d[i].ok) {
            cout << "YES" << endl;
            for (auto a : d[i].ans) {
                cout << a << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
