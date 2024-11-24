#include <iostream>

using namespace std;

int main() {
    char ch;
    cin >> ch;
    
    int asciiValue = static_cast<int>(ch);
    cout << asciiValue << endl;
    
    return 0;
}
