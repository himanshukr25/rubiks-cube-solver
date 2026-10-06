#ifndef CUBE_H
#define CUBE_H

enum class Face {
    UP,
    DOWN,
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

class Cube {
private:
    char face[6][3][3];

public:
    Cube();

    void display() const;

    bool isSolved() const;
};

#endif