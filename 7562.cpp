#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int knight[302][302];
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

queue<pair<int, int> > Q;

void bfs(int N, int ex, int ey) {
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        if (cur.X == ex && cur.Y == ey) return; // 도착지 도착하면 종료

        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (knight[nx][ny] != -1) continue;
            knight[nx][ny] = knight[cur.X][cur.Y] + 1; // 이동횟수 저장
            Q.push({nx, ny});
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        memset(knight, -1, sizeof(knight));
        while (!Q.empty()) Q.pop(); // 큐 비우기
        int sx, sy;
        int ex, ey;
        cin >> sx >> sy;
        cin >> ex >> ey;
        knight[sx][sy] = 0;
        Q.push({sx, sy});
        bfs(N, ex, ey);
        cout << knight[ex][ey] << '\n';
    }
}
