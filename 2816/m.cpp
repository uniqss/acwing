#include <iostream>
#include <vector>
using namespace std;
bool ck(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) return false;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) if (++i == a.size()) return true;
        ++j;
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& ai : a) cin >> ai;
    for (int& bi : b) cin >> bi;
    cout << (ck(a, b) ? "Yes" : "No") << endl;
    return 0;
}