#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    string dialInfo[10] = {
        "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
    };
    unordered_map<char, int> um;

    for(int i = 0; i < 10; ++i) {
        if(!dialInfo[i].empty()) {
            for(const auto alphabet : dialInfo[i]) {
                um[alphabet] = i;
            }
        }
    } 

    int result = 0;

    string dialInput;
    cin >> dialInput;

    for(const auto iter : dialInput) {
        result += um[iter] + 1;
    }

    cout << result << endl;
    
    return 0;
}