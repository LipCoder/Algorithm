#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string croatiaAlphabet[8] = {
        "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
    };

    unordered_map<string, bool> wordCheckingList;
    for(const auto alphabet : croatiaAlphabet) {
        wordCheckingList[alphabet] = true;
    }

    string input;
    cin >> input;

    for(int cnt = 3; cnt >= 2; --cnt) {                     // croatia alphabet min, max length
        for(int i = 0;; ++i) {
            if(i + cnt > input.length())
                break;

            if(wordCheckingList[input.substr(i, cnt)]) {    // check the sub string is croatia alphabet
                input.replace(i, cnt, "*");                 // replace croatia alphabet to '*'
            }
        }
    }

    cout << input.length() << endl;

    return 0;
}