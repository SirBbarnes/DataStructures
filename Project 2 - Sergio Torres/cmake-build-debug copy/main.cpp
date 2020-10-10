//
// Created by Sergio Torres on 2019-03-29.
//

#include <iostream>
#include "maze_node.h"
#include "maze.h"

using namespace std;

int main() {
    int a,b,d,e,f,g;
    double c;
    maze_node x(67);

    cout << "What is the x-dimension of the maze? " << endl;
    cin >> a;

    cout << "What is the y-dimension of the maze? " << endl;
    cin >> b;

    cout << "What is the percentage of free space in the maze? " << endl;
    cin >> c;

    Maze l(a,c,b);
    l.printMaze2();
    cout << endl;

    cout << "What is the x-coordinate of Daedalus? " << endl;
    cin >> d;

    cout << "What is the y-coordinate of Daedalus? " << endl;
    cin >> e;

    cout << "What is the x-coordinate of the gate? " << endl;
    cin >> f;

    cout << "What is the y-coordinate of the gate? " << endl;
    cin >> g;

    if (l.takenDae(d,e)) {
        l.setValue(d,e,0);
        l.setDaedalusLocation(d, e);
    }
    else {
        l.setDaedalusLocation(d, e);
    }

    if (l.takenGa(f,g)) {
        l.setValue(f,g,0);
        l.setGateLocation(f, g);
    }
    else {
        l.setGateLocation(f, g);
    }

    l.printMaze2();
    l.solve(d,e,f,g);


    cout << "Daedalus Start Location: " << "(" << d << ", " << e << ")" << endl;
    cout << "Gate Location: " << "(" << f << ", " << g << ")" << endl;



    return 0;

}