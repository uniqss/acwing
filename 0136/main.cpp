#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> an(n);
    for (int i = 0; i < n; ++i) cin >> an[i];
    map<int, int> dict;
    vector<pair<int, int>> ans(n, {INT_MAX, 0});
    dict[an[0]] = 1;
    for (int i = 1; i < n; ++i) {
        int ai = an[i];
        auto it = dict.find(ai);
        if (it == dict.end()) {
            dict[ai] = i + 1;
            it = dict.find(ai);
        }
        auto it_next = it;
        if (it != dict.begin()) {
            --it;
            if (abs(it->first - ai) < ans[i].first) {
                ans[i].first = abs(it->first - ai);
                ans[i].second = it->second;
            }
        }
        ++it_next;
        if (it_next != dict.end()) {
            if (abs(it_next->first - ai) < ans[i].first) {
                ans[i].first = abs(it_next->first - ai);
                ans[i].second = it_next->second;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
