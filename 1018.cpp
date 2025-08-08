#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    vector<string> pattern1 = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };
    vector<string> pattern2 = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };
    int ans = 10000;
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int cnt1 = 0;
            int cnt2 = 0;
            for (int x = 0; x < 8; ++x) {
                for (int y = 0; y < 8; ++y) {
                    if (board[i + x][j + y] != pattern1[x][y]) cnt1++;
                    if (board[i + x][j + y] != pattern2[x][y]) cnt2++;
                }
            }
            ans = min(ans, min(cnt1, cnt2));
        }
    }
    cout << ans;
}