#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    //2차원 벡터를 생성 y 축은 arr1.size()로 설정 즉 열의 개수는 arr1의 열의 개수와 같다
    //2차원 벡터의 x축은 arr2[0]의 개수와 같다
    for (int i = 0; i < arr1.size(); ++i) {
        for (int j = 0; j < arr2[0].size(); ++j) {
            for (int k = 0; k < arr1[0].size(); ++k) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return answer;
}
