#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    for(int a = 0; a< test_case; a++){
        int n;
        cin >> n;

        map<string, int> m;
        for(int i = 0; i < n; i++){
            string name, type;
            cin >> name >> type;
            m[type]++;
        }

        long long answer = 1;
        for(auto item : m){
            answer *= (item.second + 1);
        }
        
        answer -= 1;
        cout << answer << endl;
    }
    
    return 0;
}