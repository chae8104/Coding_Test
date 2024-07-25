#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//특정 값들이 입력 되고 그 합이 딱 맞으면 그때 만들 수 있다.

int main(){
    int N, need;
    int answer = 0;
    cin >> N;
    cin >> need;
    
    vector<int> material;
    
    for(int i = 0; i< N; i++){
        int x;
        cin >> x;
        material.push_back(x);
    }
    
    for(int a = 0; a<N; a++){
        for(int b = a+1; b<N; b++){
            if(material[a]+material[b] == need){
                answer++;
            }
        }
    }
    
    cout<< answer;
    
    return 0;
}