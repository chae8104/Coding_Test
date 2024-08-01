#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    int max_size = 0;

    for (int size = 1; size <= min(n, m); size++) {
        for (int i = 0; i <= n - size; i++) {
            for (int j = 0; j <= m - size; j++) {
                char topLeft = map[i][j];
                char topRight = map[i][j + size - 1];
                char bottomLeft = map[i + size - 1][j];
                char bottomRight = map[i + size - 1][j + size - 1];

                if (topLeft == topRight && topRight == bottomLeft && bottomLeft == bottomRight) {
                    max_size = max(max_size, size * size);
                }
            }
        }
    }

    cout << max_size << endl;

    return 0;
}