#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<vector<int>> chicken_combi;
int min_chicken_distance = INT_MAX;

int calculate_chicken_distance(const vector<pair<int, int>>& selected_chickens) {
    int total_distance = 0;

    for (const auto& house : houses) {
        int min_distance = INT_MAX;
        for (const auto& chicken : selected_chickens) {
            int distance = abs(house.first - chicken.first) + abs(house.second - chicken.second);
            min_distance = min(min_distance, distance);
        }
        total_distance += min_distance;
    }

    return total_distance;
}

void combi(int start, vector<pair<int, int>>& selected_chickens) {
    if (selected_chickens.size() == M) {
        int distance = calculate_chicken_distance(selected_chickens);
        min_chicken_distance = min(min_chicken_distance, distance);
        return;
    }

    for (int i = start; i < chickens.size(); i++) {
        selected_chickens.push_back(chickens[i]);
        combi(i + 1, selected_chickens);
        selected_chickens.pop_back();
        //조합 생성하기
    }
}

int main() {
    cin >> N >> M;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int cell;
            cin >> cell;
            if (cell == 1) {
                houses.push_back({r, c});
            } else if (cell == 2) {
                chickens.push_back({r, c});
            }
        }
    }

    vector<pair<int, int>> selected_chickens;
    combi(0, selected_chickens);

    cout << min_chicken_distance << endl;
    return 0;
}
