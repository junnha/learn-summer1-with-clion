#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불 전파 시간
int dist2[1002][1002]; // 지훈
int r,c;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int> > Q1; // 불의 큐
queue<pair<int,int> > Q2; // 지훈이의 큐

void bfsfire() {
    while(!Q1.empty()) {
        pair<int,int>cur = Q1.front();
        Q1.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(dist1[nx][ny]>=0||board[nx][ny]=='#') continue;

            dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
            Q1.push({nx,ny});
        }
    }
}
void bfsJ() {
    while(!Q2.empty()) {
        pair<int,int> cur = Q2.front();
        Q2.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << dist2[cur.X][cur.Y]+1;
                exit(0);
            }

            if(board[nx][ny]=='#' || dist2[nx][ny]>=0) continue; //
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue;

            dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
            Q2.push({nx,ny});
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int t=0;t<r;t++) {
        cin >> board[t];
    }
    for(int i = 0; i < 1002; i++)
        for(int j = 0; j < 1002; j++) {
            dist1[i][j] = -1;
            dist2[i][j] = -1;
        }
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            if(board[i][j]=='F') {
                Q1.push({i,j});
                dist1[i][j] = 0;
            }
            if(board[i][j]=='J') {
                Q2.push({i,j});
                dist2[i][j] = 0;
            }
        }
    bfsfire();
    bfsJ();
    cout << "IMPOSSIBLE";
}