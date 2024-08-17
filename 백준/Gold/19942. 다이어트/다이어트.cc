#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;

    int mp, mf, ms, mv;
    //단백질 지방 탄수 비타민
    cin >> mp >> mf >> ms >> mv;

    vector<vector<int>> foods(N, vector<int>(5));
    for (int i = 0; i < N; i++) {
        cin >> foods[i][0] >> foods[i][1] >> foods[i][2] >> foods[i][3] >> foods[i][4];
    }
    //단백질 지방 탄수 비타민 가격

    vector<int> selected(N, 0);
    int min_cost = -1;
    vector<int> result;

    for (int mask = 0; mask < (1 << N); mask++) {
        int protein = 0, fat = 0, carb = 0, vitamin = 0, cost = 0;
        vector<int> current;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                protein += foods[i][0];
                fat += foods[i][1];
                carb += foods[i][2];
                vitamin += foods[i][3];
                cost += foods[i][4];
                current.push_back(i + 1);
            }
        }

        if (protein >= mp && fat >= mf && carb >= ms && vitamin >= mv) {
            if (min_cost == -1 || cost < min_cost) {
                min_cost = cost;
                result = current;
            }
            else if (cost == min_cost && current < result) {
                result = current;
            }
        }
    }

    if (min_cost == -1) {
        cout << -1 << endl;
    }
    else {
        cout << min_cost << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}