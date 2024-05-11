/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void explorePaths(vector<vector<int>>& grid, int row, int col, string currentPath, vector<string>& allPaths, vector<vector<bool>>& isVisited) {
    int gridSize = grid.size();
    if (row < 0 || col < 0 || row >= gridSize || col >= gridSize || grid[row][col] == 0 || isVisited[row][col])
        return;

    if (row == gridSize - 1 && col == gridSize - 1) {
        allPaths.push_back(currentPath);
        return;
    }

    isVisited[row][col] = true;

    // Explore downwards
    if (row + 1 < gridSize && !isVisited[row + 1][col] && grid[row + 1][col] == 1)
        explorePaths(grid, row + 1, col, currentPath + 'D', allPaths, isVisited);

    // Explore rightwards
    if (col + 1 < gridSize && !isVisited[row][col + 1] && grid[row][col + 1] == 1)
        explorePaths(grid, row, col + 1, currentPath + 'R', allPaths, isVisited);

    // Explore leftwards
    if (col - 1 >= 0 && !isVisited[row][col - 1] && grid[row][col - 1] == 1)
        explorePaths(grid, row, col - 1, currentPath + 'L', allPaths, isVisited);

    isVisited[row][col] = false;
}

vector<string> findPaths(vector<vector<int>>& grid) {
    int gridSize = grid.size();
    vector<string> allPaths;
    vector<vector<bool>> isVisited(gridSize, vector<bool>(gridSize, false));
    if (grid[0][0] == 0)
        return allPaths; // If the starting cell is blocked, no paths exist
    explorePaths(grid, 0, 0, "", allPaths, isVisited);
    return allPaths;
}

int main() {
    vector<vector<int>> grid1 = { {1, 0, 0, 0},
                                  {1, 1, 0, 1},
                                  {1, 1, 0, 0},
                                  {0, 1, 1, 1} };
    vector<string> paths1 = findPaths(grid1);
    if (paths1.empty())
        cout << "-1" << endl;
    else {
        for (const string& path : paths1)
            cout << path << " ";
        cout << endl;
    }

    vector<vector<int>> grid2 = { {1, 0},
                                  {1, 0} };
    vector<string> paths2 = findPaths(grid2);
    if (paths2.empty())
        cout << "-1" << endl;
    else {
        for (const string& path : paths2)
            cout << path << " ";
        cout << endl;
    }

    return 0;
}
