#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int maxResult;

// 중복 상태 방문 방지를 위한 해시
unordered_set<string> visited[11];

void dfs(string numStr, int depth, int maxDepth) {
    // 이미 같은 상태에서 같은 깊이에 방문한 경우 스킵
    if (visited[depth].find(numStr) != visited[depth].end()) return;
    visited[depth].insert(numStr);

    // 교환 횟수를 다 사용한 경우
    if (depth == maxDepth) {
        maxResult = max(maxResult, stoi(numStr));
        return;
    }

    int len = numStr.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            swap(numStr[i], numStr[j]);
            dfs(numStr, depth + 1, maxDepth);
            swap(numStr[i], numStr[j]);  // 원상복구
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        string numStr;
        int changeCount;
        cin >> numStr >> changeCount;

        // visited 초기화
        for (int i = 0; i <= 10; ++i) {
            visited[i].clear();
        }

        maxResult = 0;
        dfs(numStr, 0, changeCount);

        cout << "#" << test_case << " " << maxResult << endl;
    }
    return 0;
}
