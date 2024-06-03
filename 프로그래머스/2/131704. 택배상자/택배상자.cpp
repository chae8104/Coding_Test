#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//1번 상자부터 n번 상자까지 번호가 증가하는 수서대로 컨테이너 벨트에 일렬로 놓인다
//한 방향으로만 진행가능, ㄹ벨트에 놓인 순서대로 내릴 수 있다
// 택배 기사가 알려준 순서에 맞게 택배상자를 실어야 한다

//맨 앞에 놓인 상자가 실어야 하는 순서가 아니면 잠시 다른 곳에 보관
//보조 컨테이너 벨트를 추가로 설치
//보조 컨테이너는 앞뒤로 이동이 가능하지만 입구 외에 다른 면이 막혀 있어서 맨앞의 상자만 뺄수있다(가장 마지막에 보조 벨트에 보관한 상자부터 꺼낸다 stack 구조)
//보조 컨테이너 벨트를 이용해도 순서대로 상자를 못 싣는다면 상자를 싣지 않는다


int solution(vector<int> order) {
    int answer = 0;
    stack<int> subContainer;
    //보조 컨테이너
    int currentBox = 1;
    //현재 박스
    int n = order.size();

    for (int i = 0; i < n; ++i) {
        int targetBox = order[i];

        while (currentBox <= n && (subContainer.empty() || subContainer.top() != targetBox)) //현재 박스는 n이하이고 서브컨테이너가 없는경우거나 
        {
            subContainer.push(currentBox);
            currentBox++;
        }
        //서브컨테이너가 비어있고 보조벨트가 타겟일 경우 
        if (!subContainer.empty() && subContainer.top() == targetBox) {
            subContainer.pop();
            answer++;
        } else {
            break;
        }
    }

    return answer;
}
