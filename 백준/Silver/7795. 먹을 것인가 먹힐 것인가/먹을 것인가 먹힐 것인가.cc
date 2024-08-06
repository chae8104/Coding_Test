#include <iostream>
#include <algorithm>

using namespace std;
int test_case;

int main(){
    cin >> test_case;
    for(int i =0; i< test_case; i++){
        int A,B;
        cin >> A >> B;
        vector<int> va(A);
        vector<int> vb(B);
        int answer = 0;
        
        for(int x = 0; x< A; x++){
            cin >> va[x];
        }
        for(int y =0; y < B; y++){
            cin >> vb[y];
        }
        
        for(int p = 0; p < A; p++){
            for(int q = 0; q < B; q++){
                if(va[p] > vb[q]){
                    answer++;
                }
            }
        }
        cout << answer << endl;
        
    }
    return 0;
}