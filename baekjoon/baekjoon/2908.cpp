#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int numberGenerator(string num) {
    reverse(num.begin(), num.end());
    return atoi(num.c_str());
}

int main() {

    string a, b;
    cin >> a >> b;

    int convertA = numberGenerator(a);
    int convertB = numberGenerator(b);

    cout << ((convertA > convertB) ?  convertA : convertB) << endl;

    return 0;
}