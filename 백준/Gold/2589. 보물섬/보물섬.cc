#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int max_distance = 0;

vector<vector<char>> map; // 지도 저장
vector<vector<int>> dist; // 거리 저장

int dx[] = {-1, 1, 0, 0}; // 상하좌우 이동
int dy[] = {0, 0, -1, 1};

void bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0; // 시작 위치 거리 0

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 검사 및 육지 여부 확인
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] == 'L' && dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1; // 거리 업데이트
            }
        }
    }
}

int main() {
    cin >> N >> M;
    map.resize(N, vector<char>(M)); // 지도 크기 할당
    dist.resize(N, vector<int>(M, -1)); // 거리 배열 초기화

    // 지도 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    // 모든 육지(L)에서 BFS 수행
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L') {
                dist.assign(N, vector<int>(M, -1)); // 거리 배열 초기화
                bfs(i, j); // BFS 호출

                // 최대 거리 찾기
                for (int x = 0; x < N; x++) {
                    for (int y = 0; y < M; y++) {
                        if (dist[x][y] != -1) {
                            max_distance = max(max_distance, dist[x][y]);
                        }
                    }
                }
            }
        }
    }

    cout << max_distance << endl; // 결과 출력
    return 0;
}
