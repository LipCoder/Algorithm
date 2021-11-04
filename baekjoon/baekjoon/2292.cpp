#include <iostream>
#include <vector>

using namespace std;

const int GAP = 6;

int main() {
    int input;
    cin >> input;

    int layer = 1, stack = 2;

    if(input > 1) {
        while(stack <= input) {
            stack += (GAP * layer++);
        }
    }

    cout << layer << endl;

    return 0;
}