//
// Created by Sergio Torres on 2019-03-28.
//

#include <iostream>
#include <cstdint>
#include <vector>
#include "maze_node.h"

#ifndef MAZE_PROJECT_MAZE_H
#define MAZE_PROJECT_MAZE_H

struct position {
    uint8_t x;
    uint8_t y;
};


class Maze {
    maze_node *head;
    uint8_t n;
    double percent;
    uint8_t dx;
    uint8_t dy;
    uint8_t gx;
    uint8_t gy;

    std::vector<std::vector<int8_t>> maze;
    std::vector<position> daedalusLocation;
    uint8_t size;

public:
    uint8_t getSize() const;
    void setSize(uint8_t size);

    uint8_t getDx() const;
    void setDx(uint8_t dx);

    uint8_t getDy() const;
    void setDy(uint8_t dy);

    uint8_t getGx() const;
    void setGx(uint8_t gx);

    uint8_t getGy() const;
    void setGy(uint8_t gy);

    uint8_t getN() const;
    void setN(uint8_t n);

    double getPercent() const;
    void setPercent(double percent);

public:
    Maze(uint8_t n, double percent, uint32_t randomSeed);
    void clear(uint8_t x, uint8_t y);
    void printMaze();
    void printMaze2();
    uint8_t getValue(uint8_t x, uint8_t y);
    void setValue(uint8_t x, uint8_t y, uint8_t val);
    void setDaedalusLocation(uint8_t x, uint8_t y);
    void setGateLocation(uint8_t x, uint8_t y);
    bool takenDae(uint8_t x, uint8_t y);
    bool takenGa(uint8_t x, uint8_t y);
    void solve(int w, int x, int y, int z);
};


#endif //MAZE_PROJECT_MAZE_H
