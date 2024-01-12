

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int main() {
    string input;
    cin >> input;
    int n = input.size();
    if (n < 4) {
        cout << "No" << endl;
        return 0;
    }
    unordered_map<char, int> c2count;
    for (char c : input) ++c2count[c];
    if (c2count.size() <= 1 || c2count.size() > 4) {
        cout << "No" << endl;
        return 0;
    }
    int multi = 0; // 可分
    for (auto it = c2count.begin(); it != c2count.end(); ++it) {
        if (it->second > 1) ++multi;
    }
    // 两堆必分两堆
    if (c2count.size() == 2&& multi < 2) {
        cout << "No";
        return 0;
    }
    // 三堆必分一堆
    if (c2count.size() == 3&&multi < 1) {
        cout << "No";
        return 0;
    }
    cout << "Yes";

    return 0;
}
