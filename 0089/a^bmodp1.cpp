#include <iostream>
using namespace std;

/*
李煜东，《算法进阶指南》第一个sample。。。如果这题我会的话，力扣375场周赛我就不会翻车了。。。当时卡在a^b模p。一直在溢出
3^11mod7
3^(8+2+1)
3^8 * 3^2 * 3^1 mod 7
可以证明， a * b mod p = (a mod p) * (b mod p)
虽然绝大多数人都能看出来，还是简证如下：
a = x*p + y,   a * b mod p = (x * p + y) * b mod p = x * b * p mod p + y * b mod p = y * b mod p
所以 a * b mod p = (a mod p) * b 或者双展开，一样

*/
int powermod(int a, int b, int p) {
    int ans = 1 % p;
    for (;b;b>>=1) {
        if (b&1) ans = ((long long)ans * a) % p;
        a = ((long long)a * a) % p;
    }
    return ans;
}

int main(){
    int a, b, p;
    cin >> a >> b >> p;
    int ans = powermod(a, b, p);
    cout << ans << endl;
    return 0;
}
