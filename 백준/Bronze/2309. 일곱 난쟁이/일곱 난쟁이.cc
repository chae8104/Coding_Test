#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> nan;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        nan.push_back(x);
        sum += x;
    }

    sort(nan.begin(), nan.end());

    for (int a = 0; a < 9; a++) {
        for (int b = a + 1; b < 9; b++) {
            if (sum - nan[a] - nan[b] == 100) {
                nan.erase(nan.begin() + b);
                nan.erase(nan.begin() + a);
                break;
            }
        }
        if (nan.size() == 7) break;
    }

    for (int q = 0; q < 7; q++) {
        cout << nan[q] << endl;
    }

    return 0;
}
