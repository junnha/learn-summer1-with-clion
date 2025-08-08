#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    int M;
    cin >> M;
    while (M--) {
        int x;
        cin >> x;

        if (binary_search(A.begin(), A.end(), x)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}