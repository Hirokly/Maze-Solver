#include <iostream>
#include <fstream>
#include "maze.cpp"
using namespace std;

int main() {
    ifstream fin("maze.dat");

    if (!fin) {
        cout << "Error opening maze.dat\n";
        return 1;
    }


    while (!fin.eof()) {
        Maze m(fin);
        cout << m.toString() << endl;
    }

    return 0;
}