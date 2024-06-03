#include <vector>
#include <queue>
using namespace std;

//bfs는 visited랑 몇번움직인지 체크해주기
//더이상 움직일 수 없다면 return -1해주기


int bfs(int n, int m, vector<vector<int>> &maps) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> distance(n, vector<int>(m, 0)); // 거리 기록을 위한 벡터
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    q.push({0, 0}); // 시작 노드를 큐에 삽입
    visited[0][0] = true; // 시작 노드를 방문했다고 표시
    distance[0][0] = 1; // 시작 위치의 거리값을 1로 설정
    
    // BFS 탐색 시작
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && maps[nx][ny] == 1 && !visited[nx][ny]) {//nx는 범위를
                visited[nx][ny] = true;
                q.push({nx, ny});
                distance[nx][ny] = distance[x][y] + 1; // 거리 갱신해주기
            }
        }
    }
    
    if(distance[n-1][m-1] < 1){
        return -1;
    }
    
    return distance[n-1][m-1];
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    answer = bfs(n,m, maps);
    
    return answer;
}