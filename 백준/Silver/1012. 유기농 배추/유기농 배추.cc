#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int a, int b, vector<vector<int>> &map, vector<vector<int>> &visited) {
    if (a < 0 || a >= map.size() || b < 0 || b >= map[0].size() || visited[a][b] || map[a][b] == 0) {
        return;
    }
    
    visited[a][b] = 1;

    for (int direction = 0; direction < 4; direction++) {
        int na = a + dx[direction];
        int nb = b + dy[direction];
        dfs(na, nb, map, visited);
    }
}

int main() {
    int test_case;
    cin >> test_case;

    for (int test = 0; test < test_case; test++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> map(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int cabbage = 0; cabbage < k; cabbage++) {
            int x, y;
            cin >> y >> x;
            map[y][x] = 1; 
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, map, visited);
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
