#include <iostream>
#include <algorithm>

using namespace std; 

int n, m, a[104][104];
string s; 

int main () {
	cin >> n >> m;
    //가로 세로 길이 입력받고
    
	for(int i = 0; i < n; i++){
		cin >> s;
        //각 줄마다 string입력받고
		for(int j = 0; j < m; j++){
			if(s[j] == '.'){
                a[i][j] = -1;
            }
            //.이면 -1로 초기화
			else{ 
                a[i][j] = 0;
            }
            // c면 0으로 초기화
		}
	}
    
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0){ 
				int cnt = 1;
                //c인 부분을 찾아서
				while(a[i][j + 1] == -1){
                    //.인 부분인 동안 cnt 증가
					a[i][j + 1] = cnt++;
					j++;
				} 
			}
		} 
	}
    
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){ 
            cout << a[i][j] << " ";
        }
		cout << endl;
	} 
    
	return 0;
}