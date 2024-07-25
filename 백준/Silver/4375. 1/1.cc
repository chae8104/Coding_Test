#include <iostream>

using namespace std;

int main() {
    long long num;
    while (cin >> num) {
        long long na = 1;
        long long length = 1;

        while (true) {
            if (na % num == 0) {
                cout << length << endl;
                break;
            }
            else{
                na = na*10 +1;
                na = na%num;
                length++;
            }
        }
    }
    
    return 0;
}
