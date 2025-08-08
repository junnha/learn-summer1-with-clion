#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int field[50][50];
int visited[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, int n, int m) {
    queue<pair<int, int> > Q;
    Q.push({x, y});
    visited[x][y] = 1;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (field[nx][ny] == 0) continue;
            visited[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int m, n, k;
        cin >> m >> n >> k;
        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < k; i++) {
            int y, x;
            cin >> y >> x;
            field[x][y] = 1;
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] && !visited[i][j]) {
                    bfs(i, j, n, m);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}
