#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int T; 
    cin >> T;
    
    for (int test_case = 1; test_case <= T; ++test_case) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        // 숫자별 타일 좌표 저장 
        vector<vector<pair<int,int>>> positions(k+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                positions[a[i][j]].emplace_back(i, j);
            }
        }

        // dp벡터는 거리 저장
        vector<int> dist_prev(positions[1].size(), 0);
        bool possible = true;

        for (int num = 1; num < k; num++) {
            if (positions[num].empty() || positions[num+1].empty()) {
                possible = false;
                break;
            }

            vector<int> dist_next(positions[num+1].size(), INT_MAX);

            // num의 각 타일에서 num+1의 각 타일까지 거리 계산
            for (int i = 0; i < (int)positions[num].size(); i++) {
                int x1 = positions[num][i].first;
                int y1 = positions[num][i].second;
                int cur_dist = dist_prev[i];
                if (cur_dist == INT_MAX) continue;

                for (int j = 0; j < (int)positions[num+1].size(); j++) {
                    int x2 = positions[num+1][j].first;
                    int y2 = positions[num+1][j].second;
                    int cost = abs(x1 - x2) + abs(y1 - y2);
                    if (dist_next[j] > cur_dist + cost) {
                        dist_next[j] = cur_dist + cost;
                    }
                }
            }

            bool has_path = false;
            for (auto d : dist_next) {
                if (d != INT_MAX) {
                    has_path = true;
                    break;
                }
            }
            if (!has_path) {
                possible = false;
                break;
            }

            dist_prev = dist_next;
        }

        int answer = -1;
        if (possible) {
            answer = INT_MAX;
            for (auto d : dist_prev) {
                if (d < answer)
                    answer = d;
            }
        }

        cout << "#" << test_case << " " << answer << "\n";
    }

    return 0;
}
