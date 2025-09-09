#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    int aux = 6 - a - b; // 1+2+3=6 → 남는 기둥
    func(a, aux, n - 1);
    cout << a << ' ' << b << '\n';
    func(aux, b, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    cout << ((1LL << T) - 1) << '\n';
    func(1, 3, T);
    return 0;
}
