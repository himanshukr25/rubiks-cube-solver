#include "cube.h"
#include <iostream>

using namespace std;

int main() {
    Cube cube;

    cout << "Initial cube:\n";
    cube.display();

    cube.moveU();
    cube.moveU();
    cube.moveU();
    cube.moveU();

    cout << "\nAfter U U U U:\n";
    cube.display();

    if (cube.isSolved()) {
        cout << "\nTest PASSED: Cube returned to solved state.\n";
    } else {
        cout << "\nTest FAILED: Cube is not solved.\n";
    }

    return 0;
}