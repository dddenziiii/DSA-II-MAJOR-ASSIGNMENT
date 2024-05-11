/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>
using namespace std;

bool isNodeSafe(int node, vector<vector<int>>& adjacencyMatrix, vector<int>& nodeColors, int color) {
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[node][i] && nodeColors[i] == color) return false;
    }
    return true;
}

bool colorGraph(vector<vector<int>>& adjacencyMatrix, vector<int>& nodeColors, int maxColors, int node) {
    int numNodes = adjacencyMatrix.size();
    if (node == numNodes) return true;

    for (int color = 1; color <= maxColors; ++color) {
        if (isNodeSafe(node, adjacencyMatrix, nodeColors, color)) {
            nodeColors[node] = color;
            if (colorGraph(adjacencyMatrix, nodeColors, maxColors, node + 1))
                return true;
            nodeColors[node] = 0;  // Backtrack
        }
    }
    return false;
}

int canColorizeGraph(vector<vector<int>>& adjacencyMatrix, int maxColors) {
    int numNodes = adjacencyMatrix.size();
    vector<int> nodeColors(numNodes, 0);
    return colorGraph(adjacencyMatrix, nodeColors, maxColors, 0) ? 1 : 0;
}

vector<vector<int>> generateAdjacencyMatrix(int numNodes, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes, 0));
    for (auto& edge : edges) {
        adjacencyMatrix[edge.first][edge.second] = 1;
        adjacencyMatrix[edge.second][edge.first] = 1; // Since the graph is undirected
    }
    return adjacencyMatrix;
}

int main() {
    // Example 1
    int numNodes1 = 4, maxColors1 = 3;
    vector<pair<int, int>> edges1 = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2} };
    vector<vector<int>> adjacencyMatrix1 = generateAdjacencyMatrix(numNodes1, edges1);
    cout << "Example 1: " << canColorizeGraph(adjacencyMatrix1, maxColors1) << endl;

    // Example 2
    int numNodes2 = 3, maxColors2 = 2;
    vector<pair<int, int>> edges2 = { {0, 1}, {1, 2}, {0, 2} };
    vector<vector<int>> adjacencyMatrix2 = generateAdjacencyMatrix(numNodes2, edges2);
    cout << "Example 2: " << canColorizeGraph(adjacencyMatrix2, maxColors2) << endl;

    return 0;
}
