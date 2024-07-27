#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& map) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size() && map[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, visited, map);
        }
    }
}

int main() {
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int n, m, cabbage;
        cin >> n >> m >> cabbage;

        vector<vector<int>> map(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int j = 0; j < cabbage; j++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        int count = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (map[x][y] == 1 && !visited[x][y]) {
                    dfs(x, y, visited, map);
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
