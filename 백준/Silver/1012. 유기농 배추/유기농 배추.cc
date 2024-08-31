#include <iostream>
#include <vector>

using namespace std;

int test_case;
int m, n, k;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int start_x, int start_y, vector<vector<int>>& map, vector<vector<int>>& visited) {
    visited[start_x][start_y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = start_x + dx[i];
        int ny = start_y + dy[i];
        
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && map[nx][ny] == 1 && visited[nx][ny] != 1) {
            dfs(nx, ny, map, visited);
        }
    }
}

int main() {
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        cin >> m >> n >> k;

        vector<vector<int>> map(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1 && visited[i][j] != 1) {
                    dfs(i, j, map, visited);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    
    return 0;
}