#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);
    
    for(int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        meetings[i] = {end, start};
    }
    
    sort(meetings.begin(), meetings.end());
    
    int count = 0;
    int last = 0;
    
    for (auto meeting : meetings) {
        int end_time = meeting.first;
        int start_time = meeting.second;

        if (start_time >= last) {
            count++;
            last = end_time;
        }
    }

    cout << count << endl;
    return 0;
}