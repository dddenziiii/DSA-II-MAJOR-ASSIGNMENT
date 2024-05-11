/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>  // Ensure this is included to use std::tuple and std::get

using namespace std;

// Function to find the maximum deadline among the tasks
int findMaxDeadline(const vector<tuple<int, int, int>>& tasks) {
    int maxDeadline = 0;
    for (const auto& task : tasks) {
        // Accessing the deadline of the task
        maxDeadline = max(maxDeadline, get<1>(task));
    }
    return maxDeadline;
}

// Function to schedule tasks to maximize profit
vector<int> TaskScheduling(int numTasks, vector<tuple<int, int, int>> tasks) {
    // Sort tasks based on profit in descending order
    sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
        return get<2>(a) > get<2>(b);  // Sort by profit
        });

    int maxDeadline = findMaxDeadline(tasks);
    vector<bool> slot(maxDeadline + 1, false);  // Track free time slots

    int countTasks = 0, totalProfit = 0;

    // Iterate over sorted tasks
    for (int i = 0; i < numTasks; ++i) {
        // Start from the last possible slot
        for (int j = min(maxDeadline, get<1>(tasks[i])); j > 0; --j) {
            if (!slot[j]) {  // If slot is free
                slot[j] = true;  // Mark slot as filled
                totalProfit += get<2>(tasks[i]);  // Add task's profit
                countTasks++;
                break;
            }
        }
    }

    return { countTasks, totalProfit }; // Return count of tasks and total profit
}

int main() {
    // Example 1
    vector<tuple<int, int, int>> tasks1 = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    auto result1 = TaskScheduling(4, tasks1);
    cout << "Number of tasks completed: " << result1[0] << ", Maximum profit: " << result1[1] << endl;

    // Example 2
    vector<tuple<int, int, int>> tasks2 = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    auto result2 = TaskScheduling(5, tasks2);
    cout << "Number of tasks completed: " << result2[0] << ", Maximum profit: " << result2[1] << endl;

    return 0;
}
