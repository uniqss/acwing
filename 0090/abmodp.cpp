#include <iostream>
using namespace std;
typedef long long ll;

ll plusmod(ll a, ll b, ll p) {
    a %= p, b %= p;
    ll ans = 0;
    for (;b;b>>=1) {
        if(b&1) ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}
int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    long long ans = plusmod(a, b, p);
    cout << ans << endl;
    return 0;
}
