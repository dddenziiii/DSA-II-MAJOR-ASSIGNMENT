/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Point {
    int row, col;
};

void findPaths(vector<vector<int>>& grid, int row, int col, vector<string>& paths, string path, int size) {
    if (row < 0 || row >= size || col < 0 || col >= size || grid[row][col] == 0) return;
    if (row == size - 1 && col == size - 1) {
        paths.push_back(path);
        return;
    }

    grid[row][col] = 0; // Mark the cell as visited
    // Explore all possible directions
    if (row < size - 1) { // Move down
        findPaths(grid, row + 1, col, paths, path + 'D', size);
    }
    if (col < size - 1) { // Move right
        findPaths(grid, row, col + 1, paths, path + 'R', size);
    }
    if (row > 0) { // Move up
        findPaths(grid, row - 1, col, paths, path + 'U', size);
    }
    if (col > 0) { // Move left
        findPaths(grid, row, col - 1, paths, path + 'L', size);
    }
    grid[row][col] = 1; // Unmark the cell
}

vector<string> findValidPaths(int size, vector<vector<int>>& grid) {
    vector<string> paths;
    if (grid[0][0] == 1 && grid[size - 1][size - 1] == 1) { // Check if start and end are accessible
        findPaths(grid, 0, 0, paths, "", size);
    }
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
    // Example 1
    int size1 = 4;
    vector<vector<int>> grid1 = { {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    vector<string> result1 = findValidPaths(size1, grid1);
    if (result1.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (const string& path : result1) {
            cout << path << " ";
        }
        cout << endl;
    }

    // Example 2
    int size2 = 2;
    vector<vector<int>> grid2 = { {1, 0}, {1, 0} };
    vector<string> result2 = findValidPaths(size2, grid2);
    if (result2.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (const string& path : result2) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
