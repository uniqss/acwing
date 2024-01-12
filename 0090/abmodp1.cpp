#include <iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll plusmod(ll a, ll b, ll p) {
    a %= p, b %= p;
    ll c = (ld)a * b / p;
    cout << c << endl;
    ll ab = a * b, cp = c * p;
    cout << ab << " cp:" << cp << endl;
    ll ans = a * b - c * p;
    return ans;
}
int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    ll ans = plusmod(a, b, p);
    cout << ans << endl;
    return 0;
}
