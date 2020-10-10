//
// Created by Sergio Torres on 2019-03-28.
//

#include "maze.h"

using namespace std;

uint8_t Maze::getN() const {
    return n;
}
void Maze::setN(uint8_t n) {
    Maze::n = n;
}


double Maze::getPercent() const {
    return percent;
}
void Maze::setPercent(double percent) {
    Maze::percent = percent;
}


uint8_t Maze::getDx() const {
    return dx;
}
void Maze::setDx(uint8_t dx) {
    Maze::dx = dx;
}


uint8_t Maze::getDy() const {
    return dy;
}
void Maze::setDy(uint8_t dy) {
    Maze::dy = dy;
}


uint8_t Maze::getGx() const {
    return gx;
}
void Maze::setGx(uint8_t gx) {
    Maze::gx = gx;
}


uint8_t Maze::getGy() const {
    return gy;
}
void Maze::setGy(uint8_t gy) {
    Maze::gy = gy;
}


Maze::Maze(uint8_t n, double percent, uint32_t randomSeed) : n(n), percent(percent) {
    setDx(-1);
    setDy(-1);
    setGx(-1);
    setGy(-1);
    uint8_t i, j;
    head = NULL;
    maze_node *p, *row;
    for (i = 0; i < n; i++) {
        row = head;
        if (row != NULL) {
            while (row->getBottom() != NULL) row = row->getBottom();
        }
        for (j = 0; j < n; j++) {
            if (i == 0) {
                if (head == NULL) {
                    head = new maze_node(0);
                } else {
                    p = head;
                    while (p->getRight() != NULL) p = p->getRight();
                    p->setRight(new maze_node(0));
                    (p->getRight())->setLeft(p);
                }
            } else {
                p = row;
                while (p->getBottom() != NULL) p = p->getRight();
                p->setBottom(new maze_node(0));
                (p->getBottom())->setTop(p);
                if (p->getLeft() != NULL) {
                    ((p->getLeft())->getBottom())->setRight(p->getBottom());
                    (p->getBottom())->setLeft(((p->getLeft())->getBottom()));
                }
            }
        }
    }

    uint8_t x,y;
    i = n * n * (1 - percent);
    srand(randomSeed);
    for (j = 0; j < i; j++) {
        bool cellFound = false;
        while (!cellFound) {
            x = rand() % n;
            y = rand() % n;
            if (getValue(x,y) == 0) {
                setValue(x,y,1);
                cellFound = true;
            }
        }
    }
}

void Maze::printMaze() {
    uint8_t i,j,k;
    char a[] = {' ', '*'};

    maze_node *p = NULL;
    cout << "+";
    for (i = 0; i < n * 2 - 1; i++) cout << "-";
    cout << "+" << endl;
    for (i = 0; i < n; i++) {
        p = head;
        cout << "|";
        for (k = 0; k < i; k++) p = p->getBottom();
        for (j = 0; j < n; j++) {
            if ((j == getDx()) && (i == getDy()))
                cout << "D" << " ";
            else if ((j == getGx()) && (i == getGy()))
                cout << "#" << " ";
            else
                cout << a[p->getValue()] << " ";

            p = p->getRight();
        }
        cout << (char) 8 << "|" << endl;
    }
    cout << "+";
    for (i = 0; i < n * 2 - 1; i++) cout << "-";
    cout << "+" << endl;
}

uint8_t Maze::getValue(uint8_t x, uint8_t y) {
    uint8_t i;
    maze_node *p = head;
    for (i = 0; i < x; i++) p = p->getRight();
    for (i = 0; i < y; i++) p = p->getBottom();
    return p->getValue();
}

void Maze::setValue(uint8_t x, uint8_t y, uint8_t val) {
    uint8_t i;
    maze_node *p = head;
    for (i = 0; i < x; i++) p = p->getRight();
    for (i = 0; i < y; i++) p = p->getBottom();
    p->setValue(val);
}

void Maze::printMaze2() {
    uint8_t i,j,k;
    char a[] = {' ', '*'};

    maze_node *p = NULL;
    cout << "+";
    for (i = 0; i < n; i++) cout << "-";
    cout << "+" << endl;
    for (i = 0; i < n; i++) {
        p = head;
        cout << "|";
        for (k = 0; k < i; k++) p = p->getBottom();
        for (j = 0; j < n; j++) {
            if ((j == getDx()) && (i == getDy()))
                cout << "D";
            else if ((j == getGx()) && (i == getGy()))
                cout << "#";
            else
                cout << a[p->getValue()];

            p = p->getRight();
        }
        cout << "|" << endl;
    }
    cout << "+";
    for (i = 0; i < n; i++) cout << "-";
    cout << "+" << endl;
}

void Maze::clear(uint8_t x, uint8_t y) {
    (maze.at(x)).at(y) = 0;
    for (auto i = daedalusLocation.begin(); i != daedalusLocation.end();) {
        if (i->x == x && i->y == y) {
            i = daedalusLocation.erase(i);
        } else{
            i++;
        }
    }
}

void Maze::setDaedalusLocation(uint8_t x, uint8_t y) {
    if (getValue(x,y) == 0 && getGx() != x && getGy() != y) {
        setDx(x);
        setDy(y);
    }
}

void Maze::setGateLocation(uint8_t x, uint8_t y) {
    if (getValue(x,y) == 0 && getDx() != x && getDy() != y) {
        setGx(x);
        setGy(y);
    }
}

bool Maze::takenDae(uint8_t x, uint8_t y) {
    if ((getDx() != ' ') && (getDy() != ' '))
        return true;
    else
        return false;
}

bool Maze::takenGa(uint8_t x, uint8_t y) {
    if ((getGx() != ' ') && (getGy() != ' '))
        return true;
    else
        return false;
}

uint8_t Maze::getSize() const {
    return size;
}

void Maze::setSize(uint8_t size) {
    Maze::size = size;
}

void Maze::solve(int w, int x, int y, int z) {
    bool visitedTop = false;
    bool visitedLeft = false;
    bool visitedRight = false;
    bool visitedBottom = false;


    while ((w && x) != (y && z)) {
        for (int i = 1; (w && x) != (y && z); i++) {
            if (w - i == ' ') {
                if (!visitedTop) {
                    w = w + i;

                    visitedTop = true;
                    cout << "Top";
                }
                else
                    visitedTop = false;

            } else if (x + i == ' ') {
                if (!visitedRight) {
                    w = w - i;
                    visitedRight = true;
                    cout << "Right";
                } else
                    visitedRight = false;

            } else if (w + i == ' ') {
                if (!visitedBottom) {
                    x = x + i;
                    visitedBottom = true;
                    cout << "Bottom";
                } else
                    visitedBottom = false;

            } else if (x - i == ' ') {
                if (!visitedLeft) {
                    x = x - i;
                    visitedLeft = true;
                    cout << "Left";
                } else
                    visitedLeft = false;

            } else {
                cout << "There is no path to take" << endl;
                break;
            }

        }
        break;
    }
}

