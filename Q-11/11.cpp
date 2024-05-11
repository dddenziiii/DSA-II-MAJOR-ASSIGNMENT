/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Check if the current maximum number of pages allocated to a student is feasible
bool isAllocationFeasible(int books[], int numOfBooks, int students, int midValue) {
    int requiredStudents = 1;
    int totalPagesAllocated = 0;

    // Iterate through the array of pages
    for (int i = 0; i < numOfBooks; ++i) {
        // If current book's pages exceed midValue, it's not feasible
        if (books[i] > midValue)
            return false;

        // If current pages allocated + current book's pages > midValue,
        // allocate this book to the next student
        if (totalPagesAllocated + books[i] > midValue) {
            requiredStudents++;
            totalPagesAllocated = books[i];

            // If number of students required exceed the limit, it's not feasible
            if (requiredStudents > students)
                return false;
        } else {
            totalPagesAllocated += books[i];
        }
    }

    return true;
}

// Find the minimum number of pages that a student can get
int findMinimumPages(int books[], int numOfBooks, int students) {
    if (numOfBooks < students)
        return -1;

    int totalPages = 0, maxPages = 0;

    // Calculate the total number of pages and maximum number of pages
    for (int i = 0; i < numOfBooks; ++i) {
        totalPages += books[i];
        maxPages = max(maxPages, books[i]);
    }

    int start = maxPages, end = totalPages, result = -1;

    // Perform binary search to find the minimum feasible maximum number of pages
    while (start <= end) {
        int midValue = (start + end) / 2;

        // If current midValue is feasible, search in the left half
        if (isAllocationFeasible(books, numOfBooks, students, midValue)) {
            result = midValue;
            end = midValue - 1;
        } else {
            // If current midValue is not feasible, search in the right half
            start = midValue + 1;
        }
    }

    return result;
}

int main() {
    int numOfBooks = 3;
    int bookPages[] = {15, 17, 20};
    int students = 2;

    cout << "Output: " << findMinimumPages(bookPages, numOfBooks, students) << endl;

    return 0;
}
