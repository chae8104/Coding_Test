#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    set<int> A, B;
    
    for(int i = 0; i < n; i++){
        int element;
        cin >> element;
        A.insert(element);
    }
    
    for (int i = 0; i < m; i++) {
        int element;
        cin >> element;
        B.insert(element);
    }
    
    set<int> s;

    for(int a : A){
        if (B.find(a) == B.end()){
            s.insert(a);
        }
    }

    for (int b : B) {
        if (A.find(b) == A.end()) {
            s.insert(b);
        }
    }
    cout << s.size() << endl;

    return 0;
}