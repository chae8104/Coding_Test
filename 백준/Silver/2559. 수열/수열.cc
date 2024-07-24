#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num, count;
    cin >> num >> count;
    vector<int> temp(num);
    
    for(int i = 0; i < num; i++) {
        cin >> temp[i];
    }
    
    int max_sum = 0;
    int current_sum = 0;
    
    for (int i = 0; i < count; i++) {
        current_sum += temp[i];
    }
    
    max_sum = current_sum;

    for (int start =1; start <=num - count; start++) {
        current_sum = current_sum - temp[start - 1] + temp[start + count - 1];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;
    
    return 0;
}
