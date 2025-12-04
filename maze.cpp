#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Maze {
private:

    char grid[20][20];
    bool visited[20][20];
    bool solvable;
    int startRow, startCol;
    int endRow, endCol;


    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};

    bool isValid(int r, int c) {
        return (r >= 0 && r < 20 && c >= 0 && c < 20 &&
                grid[r][c] != '#' && !visited[r][c]);
    }

    bool dfs(int r, int c) {
        if (r == endRow && c == endCol) {
            return true;
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dRow[i];
            int nc = c + dCol[i];

            if (isValid(nr, nc)) {
                if (dfs(nr, nc)) {
                    return true;
                }
            }
        }

        return false;
    }

public:

    Maze(ifstream &fin) {
        solvable = false;


        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                visited[i][j] = false;


        string line;
        for (int r = 0; r < 20; r++) {
            getline(fin, line);
            for (int c = 0; c < 20; c++) {
                grid[r][c] = line[c];
                if (line[c] == 'S') {
                    startRow = r;
                    startCol = c;
                }
                if (line[c] == 'E') {
                    endRow = r;
                    endCol = c;
                }
            }
        }


        solvable = dfs(startRow, startCol);

        // skip blank line between mazes
        string blank;
        getline(fin, blank);
    }

    string toString() {
        return string("Maze: ") + (solvable ? "YES" : "NO");
    }
};