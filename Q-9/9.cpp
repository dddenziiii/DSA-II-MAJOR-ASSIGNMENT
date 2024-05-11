/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Data structure representing a node in the Trie
struct TrieNode {
    TrieNode* children[26]; // Array to store child nodes
    bool isEndOfWord; // Flag to indicate the end of a word

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};

// Inserts a word into the Trie(DFS)
void insertWord(TrieNode* root, string word) {
    TrieNode* current = root;
    // Traverse the Trie to insert the word
    for (char c : word) {
        int index = c - 'A'; // Convert character to an index
        if (!current->children[index])
            current->children[index] = new TrieNode();
        current = current->children[index];
    }
    current->isEndOfWord = true; // Mark the end of the word
}

// Depth First Search (DFS) function to search for words in the board
void searchBoard(vector<vector<char>>& board, int row, int col, TrieNode* root, string path, unordered_set<string>& resultSet, vector<vector<bool>>& visited) {
    // Base case and boundary conditions
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col])
        return;

    int index = board[row][col] - 'A'; // Convert character to an index
    if (!root->children[index])
        return;

    path += board[row][col]; // Append the character to the current path
    if (root->children[index]->isEndOfWord)
        resultSet.insert(path); // Found a valid word, add it to the result set

    visited[row][col] = true; // Mark the cell as visited

    // Move to all 8 adjacent cells
    int rowMoves[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colMoves[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; ++i)
        searchBoard(board, row + rowMoves[i], col + colMoves[i], root->children[index], path, resultSet, visited);

    visited[row][col] = false; // Backtrack: Mark the cell as not visited
}

// Function to find words in the Boggle board
vector<string> findWords(vector<vector<char>>& board, vector<string>& dictionary) {
    unordered_set<string> resultSet; // Store unique words found in the board
    int rows = board.size();
    int cols = board[0].size();

    TrieNode* root = new TrieNode(); // Initialize the root of the Trie
    // Insert all words from the dictionary into the Trie
    for (string word : dictionary)
        insertWord(root, word);

    vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // Matrix to mark visited cells

    // Search for words starting from each cell in the board
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            string path = ""; // Initialize the current path
            searchBoard(board, i, j, root, path, resultSet, visited);
        }
    }

    vector<string> result(resultSet.begin(), resultSet.end()); // Convert the result set to a vector
    return result;
}

int main() {
    int rows = 3, cols = 3;
    vector<vector<char>> board = {{'G','I','Z'}, {'U','E','K'}, {'Q','S','E'}};
    int dictionarySize = 4;
    vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};

    vector<string> wordsFound = findWords(board, dictionary); // Find words in the Boggle board

    // Print the words found in the board
    for (string word : wordsFound)
        cout << word << " ";
    cout << endl;

    return 0;
}
