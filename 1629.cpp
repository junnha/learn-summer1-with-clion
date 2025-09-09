#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func1(ll a, ll b, ll m) {
    if (b == 1) {
        return a % m;
    }
    ll val = func1(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0) {
        return val;
    }
    return val * a % m;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << func1(a, b, c);
}
