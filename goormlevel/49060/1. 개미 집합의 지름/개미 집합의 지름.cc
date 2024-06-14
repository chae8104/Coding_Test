#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num, dist;
	vector<int> ant;

	// 개미의 수와 지름을 입력받는 부분
	cin >> num >> dist;

	// 개미의 위치를 입력받고 vector에 push_back하는 부분
	for(int i = 0; i < num; i++) {
		int a;
		cin >> a;
		ant.push_back(a);
	}

	sort(ant.begin(), ant.end());
	int left = 0, right = 0;
	int size_ant = ant.size();
	int min_remove_ant = num;  // 초기값을 최대 개미 수로 설정
	while(right < num){
		if(ant[right] - ant[left] <= dist){
			int remove_ant = num - (right - left +1);
			min_remove_ant = min(min_remove_ant, remove_ant);
			right++;
		}
		else{
			left++;
		}
	}

	// 최소 개미 수 출력
	cout << min_remove_ant << endl;

	return 0;
}
