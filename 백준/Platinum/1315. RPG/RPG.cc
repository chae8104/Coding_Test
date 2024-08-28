#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct game {
    int x, y, c; 
};

vector<game> a;

int n, dp[1001][1001];
bool visited[101]; 

int rpg(int STR, int INT) {
    int &ret = dp[STR][INT];
    if (ret != -1) return ret;

    ret = 0;
    vector<int> v;
    int pnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].x <= STR || a[i].y <= INT) {
            ret++;
            if (!visited[i]) {
                visited[i] = true;
                pnt += a[i].c;
                v.push_back(i);
            }
        }
    }

    for (int p = 0; p <= pnt; p++) {
        int nextSTR = min(1000, STR + p);
        int nextINT = min(1000, INT + pnt - p);
        ret = max(ret, rpg(nextSTR, nextINT));
    }

    for (int here : v) {
        visited[here] = false;
    }

    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int STR, INT, PNT;
        cin >> STR >> INT >> PNT;
        a.push_back({STR, INT, PNT});
    }

    memset(dp, -1, sizeof(dp));
    
    cout << rpg(1, 1) << endl;

    return 0;
}
