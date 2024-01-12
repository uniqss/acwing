#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int mindis(int n, const vector<vector<int>>& data) {
    int ans = 0, count = 0;
    vector<bool> vis(n);
    auto dfs = [&](int curr){
        if ()
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> data(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> data[i][j];
        }
    }
    int ans = mindis(n, data);
    return 0;
}
