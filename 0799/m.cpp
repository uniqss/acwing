#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int calc(const vector<int>& d) {
    int ret = 0, start = 0;
    unordered_map<int, int> n2c;
    for (int i = 0; i < d.size(); ++i) {
        ++n2c[d[i]];
        while (n2c[d[i]] > 1) --n2c[d[start++]];
        ret = max(ret, i - start + 1);
    }
    return ret;
}
int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for (int& di : d) cin >> di;
    cout << calc(d);
    return 0;
}