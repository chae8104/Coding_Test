#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int input;
	cin >> input;
	int rectangle = 0;
	for(int i =0; i<input; i++){
		int x;
		int y;
		cin >> x >> y;
		rectangle = max(rectangle, x*y);
	}
	cout<< rectangle <<endl;
	return 0;
}