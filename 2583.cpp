#include <bits/stdc++.h>

using namespace std;

int grid[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k;

int main() {
    cin >> m >> n >> k;
    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++)
            for (int k = x1; k < x2; k++)
                grid[j][k] = 1; // 직사각형 그리기
    }
    int count = 0; // 영역 개수 설정
    vector<int> ans; // 영역 넓이 입력할 답

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 || vis[i][j] == 1) {
                continue; // 한 번 지나가거나 범위 아니면 패스
            }
            queue<pair<int, int> > Q; // 저장 큐 설정
            vis[i][j] = 1;
            Q.push({i, j}); // 방문 표시하고 큐에 넣기
            int width = 1;
            count++; // 좌표가 들어갔으므로 넓이와 영역 개수 변경
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir]; // 탐색하기
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (grid[nx][ny] == 1 || vis[nx][ny] == 1)
                        continue; // 조건 맞추기
                    Q.push({nx, ny}); //
                    vis[nx][ny] = 1; // 새로 탐색한 좌표 큐에 넣고 방문 표시
                    width++; // 탐색 끝날 때 까지 넓이 추가
                }
            }
            ans.push_back(width); // ans 에 width 넣기
        }
    }
    sort(ans.begin(), ans.end());

    cout << count << '\n';
    for (int i: ans)
        cout << i << ' ';

    return 0;
}



