/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int firstElement, secondElement;
};

// Function to find the maximum length of the chain
int findMaxChainLength(Pair array[], int size) {
    // Sort pairs based on their first elements and then their second elements if the first elements are equal
    sort(array, array + size, [](const Pair& a, const Pair& b) {
        if (a.firstElement == b.firstElement) return a.secondElement < b.secondElement;
        return a.firstElement < b.firstElement;
        });

    // Dynamic programming array to store the maximum chain length ending at each pair
    vector<int> dp(size, 1);  // Each pair forms a chain of length 1 by itself

    // Build the longest chain using dynamic programming
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (array[j].secondElement < array[i].firstElement && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Get the maximum value from the dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    // Example 1
    Pair array1[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int size1 = sizeof(array1) / sizeof(array1[0]);
    cout << "Maximum chain length is " << findMaxChainLength(array1, size1) << endl;

    // Example 2
    Pair array2[] = { {5, 10}, {1, 11} };
    int size2 = sizeof(array2) / sizeof(array2[0]);
    cout << "Maximum chain length is " << findMaxChainLength(array2, size2) << endl;

    return 0;
}
