//
// Created by Sergio Torres on 2019-03-29.
//
#include <iostream>
#include <cstdint>

#ifndef MAZE_PROJECT_MAZE_NODE_H
#define MAZE_PROJECT_MAZE_NODE_H


class maze_node {
    uint8_t value;
    maze_node *top;
    maze_node *right;
    maze_node *bottom;
    maze_node *left;

public:
    maze_node(uint8_t value);

    uint8_t getValue() const;
    void setValue(uint8_t value);

    maze_node *getTop() const;
    void setTop(maze_node *top);

    maze_node *getRight() const;
    void setRight(maze_node *right);

    maze_node *getBottom() const;
    void setBottom(maze_node *bottom);

    maze_node *getLeft() const;
    void setLeft(maze_node *left);
};


#endif //MAZE_PROJECT_MAZE_NODE_H
