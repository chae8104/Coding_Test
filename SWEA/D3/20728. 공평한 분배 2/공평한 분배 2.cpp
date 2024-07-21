#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        cin >> N >> K;
        vector<int> N_lst(N);

        for (int i = 0; i < N; i++) {
            cin >> N_lst[i];
        }

        // 배열을 정렬
        sort(N_lst.begin(), N_lst.end());

        // 최소 차이를 찾기
        int min_diff = numeric_limits<int>::max();

        for (int i = 0; i <= N - K; i++) {
            int diff = N_lst[i + K - 1] - N_lst[i];
            min_diff = min(min_diff, diff);
        }

        cout << "#" << tc << " " << min_diff << endl;
    }

    return 0;
}
