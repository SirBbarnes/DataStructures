//
// Created by Sergio Torres on 2019-03-29.
//

#include "maze_node.h"

maze_node::maze_node(uint8_t value) : value(value) {
    top = NULL;
    right = NULL;
    bottom = NULL;
    left = NULL;
}

uint8_t maze_node::getValue() const {
    return value;
}
void maze_node::setValue(uint8_t value) {
    maze_node::value = value;
}


maze_node *maze_node::getTop() const {
    return top;
}
void maze_node::setTop(maze_node *top) {
    maze_node::top = top;
}


maze_node *maze_node::getRight() const {
    return right;
}
void maze_node::setRight(maze_node *right) {
    maze_node::right = right;
}


maze_node *maze_node::getBottom() const {
    return bottom;
}
void maze_node::setBottom(maze_node *bottom) {
    maze_node::bottom = bottom;
}


maze_node *maze_node::getLeft() const {
    return left;
}
void maze_node::setLeft(maze_node *left) {
    maze_node::left = left;
}