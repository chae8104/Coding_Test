#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int n = s.length();
    int minLength = n;

    for (int i = 1; i <= n / 2; i++) {
        string compressed = "";
        string prev = s.substr(0, i);
        int count = 1;

        for (int j = i; j < n; j += i) {
            string current = s.substr(j, i);

            if (prev == current) {
                count++;
            } 
            else {
                compressed += (count > 1 ? to_string(count) : "") + prev;
                prev = current;
                count = 1;
            }
        }
        compressed += (count > 1 ? to_string(count) : "") + prev;

        minLength = min(minLength, (int)compressed.length());
    }

    return minLength;
}