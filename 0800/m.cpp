#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n), b(m);
    for (int& ai : a) cin >> ai;
    for (int& bi : b) cin >> bi;
    int i = 0, j = b.size() - 1;
    while (i < a.size() && j >= 0) {
        int sum = a[i] + b[j];
        if (sum == x) break;
        if (sum > x) --j;
        else ++i;
    }
    cout << i << " " << j;
    return 0;
}