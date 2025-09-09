#include <bits/stdc++.h>
using namespace std;

int main() {
    string board[27];
    int vis[27][27];
    int N;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int count = 0;
    vector<int> ans;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j] == 1 || board[i][j] == '0') continue;

            queue<pair<int, int> > Q;
            vis[i][j] = 1;
            Q.push({i, j});
            int width = 1;
            count++;

            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny] == 1 || board[nx][ny] == '0') continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    width++;
                }
            }
            ans.push_back(width);
        }
    }

    cout << count << '\n';
    sort(ans.begin(), ans.end());
    for (int x: ans)
        cout << x << '\n';

    return 0;
}
