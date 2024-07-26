#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//최소의 칸 수를 찾아야 하기 때문에 bfs를 쓴다.

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    //이동할 맵과 거리를 저장해준다.
    
    for (int i = 0; i <n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    //queue가 빌 때까지 반복
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << dist[x][y] << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] == 1 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
