#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // numeric_limits 사용을 위해 포함

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numTestCases = 10; // 총 테스트 케이스 개수

    // 각 테스트 케이스 처리
    for (int t = 1; t <= numTestCases; ++t) {
        int testCaseNumber;
        cin >> testCaseNumber; // 테스트 케이스 번호 입력

        // 100x100 크기의 사다리 배열 선언
        vector<vector<int>> ladder(100, vector<int>(100));

        // 사다리 배열 입력
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                cin >> ladder[i][j];
            }
        }

        // 최단 이동 횟수와 그때의 출발점 x좌표를 저장할 변수 초기화
        int min_total_steps = numeric_limits<int>::max(); // 가능한 최대값으로 초기화
        int best_start_x = -1;

        // 모든 가능한 출발점 (맨 위 행의 1)에서 시작
        for (int start_x = 0; start_x < 100; ++start_x) {
            // 맨 위 행(y=0)에 사다리가 있는 경우만 출발점으로 고려
            if (ladder[0][start_x] == 1) {
                int current_y = 0;
                int current_x = start_x;
                int current_steps = 0; // 현재 경로의 이동 횟수

                // 바닥(y=99)에 도달할 때까지 시뮬레이션
                while (current_y < 99) {
                    // 아래로 한 칸 이동
                    current_y++;
                    current_steps++;

                    // 아래로 이동한 후, 현재 행(current_y)에서 좌우 이동 가능한지 확인
                    // 왼쪽 확인: 현재 x좌표의 왼쪽(current_x - 1)에 사다리 가로선이 있는지
                    if (current_x > 0 && ladder[current_y][current_x - 1] == 1) {
                        // 왼쪽으로 가로선을 따라 이동
                        while (current_x > 0 && ladder[current_y][current_x - 1] == 1) {
                            current_x--; // 왼쪽으로 이동
                            current_steps++; // 이동 횟수 증가
                        }
                    }
                    // 오른쪽 확인: 현재 x좌표의 오른쪽(current_x + 1)에 사다리 가로선이 있는지
                    // 왼쪽으로 이동하지 않은 경우에만 오른쪽 확인
                    else if (current_x < 99 && ladder[current_y][current_x + 1] == 1) {
                        // 오른쪽으로 가로선을 따라 이동
                        while (current_x < 99 && ladder[current_y][current_x + 1] == 1) {
                            current_x++; // 오른쪽으로 이동
                            current_steps++; // 이동 횟수 증가
                        }
                    }
                    // 좌우로 이동할 수 없으면 그대로 위로 올라감 (current_x는 변경되지 않음)
                } // while (current_y < 99) 종료

                // 바닥에 도착했을 때, 현재 경로의 이동 횟수를 최솟값과 비교
                if (current_steps <= min_total_steps) {
                    // 현재 경로의 이동 횟수가 더 짧거나 같으면
                    min_total_steps = current_steps; // 최솟값 업데이트
                    best_start_x = start_x;          // 출발점 x좌표 업데이트
                    // <= 조건을 사용하여 같은 최솟값인 경우,
                    // 루프가 start_x를 0부터 99까지 순회하므로
                    // 자연스럽게 더 큰 x좌표가 저장됩니다.
                }

            } // if (ladder[0][start_x] == 1) 종료
        } // for (start_x = 0; ... ) 종료

        // 테스트 케이스 결과 출력
        cout << "#" << testCaseNumber << " " << best_start_x << endl;
    } // for (t = 1; ... ) 종료

    return 0;
}
