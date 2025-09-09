#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int query;
        cin >> query;

        int low = lower_bound(cards.begin(), cards.end(), query) - cards.begin();
        int high = upper_bound(cards.begin(), cards.end(), query) - cards.begin();
        cout << high - low << " ";
    }
    cout << '\n';
}
