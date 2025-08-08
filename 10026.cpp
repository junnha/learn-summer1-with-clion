#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
vector<string> board;
int visited[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, bool color_blind) {
    queue<pair<int, int> > Q;
    Q.push({x, y});
    visited[x][y] = 1;
    char color = board[x][y];
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (color_blind) {
                // 적록색약: R,G를 동일하게
                if ((color == 'R' || color == 'G') && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) {
                    visited[nx][ny] = 1;
                    Q.push({nx, ny});
                } else if (color == 'B' && board[nx][ny] == 'B') {
                    visited[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            } else {
                if (board[nx][ny] != color) continue;
                visited[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    board.resize(N);
    for (int i = 0; i < N; i++)
        cin >> board[i];

    int normal = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j, false);
                normal++;
            }
        }
    }

    int cb = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j, true);
                cb++;
            }
        }
    }

    cout << normal << " " << cb << '\n';
    return 0;
}
