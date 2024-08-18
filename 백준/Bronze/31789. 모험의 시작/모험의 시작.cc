#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long X, S;
    cin >> X >> S;

    bool check = false;

    for (int i = 0; i < N; i++) {
        long long c, p;
        cin >> c >> p;

        if (c <= X && p > S) {
            check = true;
        }
    }

    if (check) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}