#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> count;
    int n = elements.size();
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += elements[(i + j) % n];
            count.insert(sum);
        }
    }

    return count.size();
}