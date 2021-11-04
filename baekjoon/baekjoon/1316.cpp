#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int count = 0;
    cin >> count;

    vector<string> v(count, "");
    for(auto& str : v) {
        cin >> str;
    }

    int result = 0;
    for(const auto str : v) {
        unordered_map<char, bool> um; 
        char tempCh = ' ';      
        for(const auto ch : str) {
            if(tempCh != ch) {
                if(um[ch]) {
                    --result;
                    break;
                } else {
                    um[ch] = true;
                } 
                tempCh = ch;
            }
        }
        ++result;
    }

    cout << result << endl;

    return 0;
}
