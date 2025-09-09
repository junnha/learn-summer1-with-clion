#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int board[103][103][103];
int dist[103][103][103];
int m, n, h;

queue<tuple<int, int, int> > Q;

void bfs() {
    while (!Q.empty()) {
        auto [cz, cy, cx] = Q.front();
        Q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nz = cz + dz[dir];
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
            if (dist[nz][ny][nx] >= 0) continue;

            dist[nz][ny][nx] = dist[cz][cy][cx] + 1;
            Q.push({nz, ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];

                if (board[i][j][k] == 1) {
                    Q.push({i, j, k});
                }
                if (board[i][j][k] == 0) {
                    dist[i][j][k] = -1;
                }
            }
        }
    }

    bfs();

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[i][j][k] == -1) {
                    cout << -1 << "\n";
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
    cout << ans << "\n";
}
