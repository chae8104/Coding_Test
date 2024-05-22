#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n+1, 1);
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] -= 1;
    
    for(int i = 1; i <= n; i++){
        if(student[i] == 0){
            if(i > 1 && student[i-1] > 1){
                student[i]++;
                student[i-1]--;
            }else if(i < n && student[i+1] > 1){
                student[i]++;
                student[i+1]--;
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(student[i] > 0) answer++;
    }
    return answer;
}
