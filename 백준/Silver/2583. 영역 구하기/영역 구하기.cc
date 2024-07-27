#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[101][101] = {0};
bool visited[101][101] = {false};
int m, n, k;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<int> areas;

int dfs(int y, int x) {
    visited[y][x] = true;
    int area = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < m && nx >= 0 && nx < n && !visited[ny][nx] && a[ny][nx] == 0) {
            area += dfs(ny, nx);
        }
    }
    return area;
}

int main() {
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                a[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0 && !visited[i][j]) {
                int areaSize = dfs(i, j);
                areas.push_back(areaSize);
            }
        }
    }

    sort(areas.begin(), areas.end());
    cout << areas.size() << endl;
    for (int area : areas) {
        cout << area << " ";
    }
    cout << endl;

    return 0;
}
