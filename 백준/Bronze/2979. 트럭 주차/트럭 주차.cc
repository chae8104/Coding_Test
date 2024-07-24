#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    map<int, int> mm;
    int minNum = 101, maxNum = 0;

    for (int c = 0; c < 3; c++) {
        int i, j;
        cin >> i >> j;
        maxNum = max(maxNum, j);
        minNum = min(minNum, i);

        for (int x = i; x < j; x++) {
            mm[x]++;
        }
    }

    int total = 0;
    
    for (int x = minNum; x < maxNum; x++) {
        int truckCount = mm[x];
        if (truckCount == 1) {
            total += A;
        } else if (truckCount == 2) {
            total += B*2;
        } else if (truckCount == 3) {
            total += C*3;
        }
    }

    cout << total;

    return 0;
}
