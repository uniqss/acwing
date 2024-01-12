#include <iostream>
using namespace std;
int main(){
    double n, l = -10000, r = 10000, mid;
    cin >> n;
    while (r - l > 1e-8) {
        mid = (l + r) / 2;
        if (mid * mid * mid < n) l = mid;
        else r = mid;
    }
    printf("%lf\n", l);
    
    return 0;
}