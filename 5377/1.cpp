#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
// priority_queue不能用，map不能erase by value 这是哪个古老版本的stl啊。。。。神啊
// vim一回车就页面乱弹，这平台做的真TM的SB
using namespace std;
struct kii {
    int ki;
    int i;
};
int main() {
    int n;
    cin >> n;
    vector<vector<int>> cipi(n, vector<int>(3));
    for (int i = 0; i < n; ++i) cin >> cipi[i][0] >> cipi[i][1], cipi[i][2] = i;
    int k;
    cin >> k;
    vector<kii> ki(k);
    for (int i = 0; i < k; ++i) cin >> ki[i].ki, ki[i].i = i;
    sort(cipi.begin(), cipi.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
        if (lhs[1] > rhs[1]) return true;
        if (lhs[1] == rhs[1] && lhs[0] < rhs[0]) return true;
        return false;
    });
    int m = 0, s = 0;
    sort(ki.begin(), ki.end(), [](const kii& lhs, const kii& rhs) { return lhs.ki < rhs.ki; });
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        int ci = cipi[i][0], pi = cipi[i][1], ni = cipi[i][2];
        int j = ki.size() - 1;
        if (ki[j].ki >= ci) {
            while (j >= 0 && ki[j].ki >= ci) --j;
            ++j;
            auto kval = ki[j];
            ki[j] = ki[ki.size() - 1];
            ki.resize(ki.size() - 1);
            ++m, s += pi;
            ans.push_back({ni + 1, kval.i + 1});
            if (ki.empty()) break;
        }
        sort(ki.begin(), ki.end(), [](const kii& lhs, const kii& rhs) { return lhs.ki < rhs.ki; });
    }
    cout << m << " " << s << endl;
    for (const auto& [ai, bi] : ans) cout << ai << " " << bi << endl;

    return 0;
}
