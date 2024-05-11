/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>

using namespace std;

// Function to find the kth element in the merged sorted array
int findKthElement(int firstArray[], int secondArray[], int sizeFirst, int sizeSecond, int kth) {
    int firstIndex = 0, secondIndex = 0, count = 0;
    int result;

    // Merge the arrays until one of them is exhausted or kth elements are found
    while (firstIndex < sizeFirst && secondIndex < sizeSecond && count < kth) {
        if (firstArray[firstIndex] < secondArray[secondIndex])
            result = firstArray[firstIndex++];
        else
            result = secondArray[secondIndex++];
        count++;
    }

    // If kth element is found, return it
    if (count == kth)
        return result;

    // If one of the arrays is exhausted, continue with the other array
    while (firstIndex < sizeFirst && count < kth) {
        result = firstArray[firstIndex++];
        count++;
    }
    while (secondIndex < sizeSecond && count < kth) {
        result = secondArray[secondIndex++];
        count++;
    }

    return result;
}

int main() {
    int first[] = {2, 3, 6, 7, 9};
    int second[] = {1, 4, 8, 10};
    int sizeFirst = sizeof(first) / sizeof(first[0]);
    int sizeSecond = sizeof(second) / sizeof(second[0]);
    int kth = 5;

    cout << "Output: " << findKthElement(first, second, sizeFirst, sizeSecond, kth) << endl;

    return 0;
}
