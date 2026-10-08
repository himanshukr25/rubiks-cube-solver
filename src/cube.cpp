#include "cube.h"
#include <iostream>

using namespace std;

Cube::Cube() {
    const char colors[6] = {
        'W',  // UP
        'Y',  // DOWN
        'G',  // FRONT
        'B',  // BACK
        'O',  // LEFT
        'R'   // RIGHT
    };

    for (int f = 0; f < 6; f++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                face[f][i][j] = colors[f];
            }
        }
    }
}


void Cube::rotateFaceClockwise(Face f) {
    int index = static_cast<int>(f);

    char temp[3][3];

    // Copy the original face
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = face[index][i][j];
        }
    }

    // Rotate 90 degrees clockwise
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            face[index][j][2 - i] = temp[i][j];
        }
    }
}

void Cube::moveU() {
    rotateFaceClockwise(Face::UP);

    char temp[3];

    for (int j = 0; j < 3; j++) {
        temp[j] = face[static_cast<int>(Face::FRONT)][0][j];
    }

    for (int j = 0; j < 3; j++) {
        face[static_cast<int>(Face::FRONT)][0][j] =
            face[static_cast<int>(Face::RIGHT)][0][j];
    }

    for (int j = 0; j < 3; j++) {
        face[static_cast<int>(Face::RIGHT)][0][j] =
            face[static_cast<int>(Face::BACK)][0][j];
    }

    for (int j = 0; j < 3; j++) {
        face[static_cast<int>(Face::BACK)][0][j] =
            face[static_cast<int>(Face::LEFT)][0][j];
    }

    for (int j = 0; j < 3; j++) {
        face[static_cast<int>(Face::LEFT)][0][j] = temp[j];
    }
}

void Cube::display() const {
    cout << "\n";

    // UP
    for (int i = 0; i < 3; i++) {
        cout << "      ";
        for (int j = 0; j < 3; j++) {
            cout << face[static_cast<int>(Face::UP)][i][j] << " ";
        }
        cout << "\n";
    }

    // LEFT, FRONT, RIGHT, BACK
    for (int i = 0; i < 3; i++) {
        for (Face f : {Face::LEFT, Face::FRONT, Face::RIGHT, Face::BACK}) {
            for (int j = 0; j < 3; j++) {
                cout << face[static_cast<int>(f)][i][j] << " ";
            }
            cout << "  ";
        }
        cout << "\n";
    }

    // DOWN
    for (int i = 0; i < 3; i++) {
        cout << "      ";
        for (int j = 0; j < 3; j++) {
            cout << face[static_cast<int>(Face::DOWN)][i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

bool Cube::isSolved() const {
    for (int f = 0; f < 6; f++) {
        char center = face[f][1][1];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (face[f][i][j] != center) {
                    return false;
                }
            }
        }
    }

    return true;
}