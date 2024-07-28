#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int a, int b, int h, vector<vector<int>> &map, vector<vector<int>> &visited, int n) {
    if (a < 0 || a >= n || b < 0 || b >= n || visited[a][b] || map[a][b] <= h) {
        return;
    }
    
    visited[a][b] = 1;

    for (int direction = 0; direction < 4; direction++) {
        int na = a + dx[direction];
        int nb = b + dy[direction];
        dfs(na, nb, h, map, visited, n);
    }
}

int main() {
    int n;
    int height = 0;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n, 0));
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            height = max(height, map[i][j]);
        }
    }
    
    int max_area = 0;
    
    for (int h = 0; h <= height; h++) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] > h && !visited[i][j]) {
                    dfs(i, j, h, map, visited, n);
                    area++;
                }
            }
        }
        
        max_area = max(max_area, area);
    }
    
    cout << max_area << endl;
    
    return 0;
}
