#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, v;
    cin >> a >> b >> v;

    int k = v - a;
    int cnt = (k + (a - b) - 1) / (a - b) + 1;

    cout << cnt;
}

