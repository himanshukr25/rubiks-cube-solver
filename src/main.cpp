#include "cube.h"
#include <iostream>

using namespace std;

int main() {
    Cube cube;

    cube.display();

    if (cube.isSolved()) {
        cout << "Cube is solved!\n";
    } else {
        cout << "Cube is not solved.\n";
    }

    return 0;
}