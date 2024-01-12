#include <iostream>
using namespace std;
int lowbit(int x) {
    return x &(-x);
}
int main(){
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        int ret = 0;
        while (t) ++ret, t -= lowbit(t);
        cout << ret << " ";
    }
    return 0;
}