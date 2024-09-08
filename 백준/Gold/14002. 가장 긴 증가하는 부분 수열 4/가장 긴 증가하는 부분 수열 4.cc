#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(n, 1);
    vector<int> prev_list(n, -1);
    int ret = 1, idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }

    cout << ret << endl;

    vector<int> lis;
    while (idx != -1) {
        lis.push_back(a[idx]);
        idx = prev_list[idx];
    }

    reverse(lis.begin(), lis.end());
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}