/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum number of schedulable events in the venue
int maximumSchedulableEvents(int startTime[], int endTime[], int numEvents) {
  // Create a vector to store events with their end and start times (reversed)
  vector<pair<int, int>> events;

  // Populate the vector with event times
  for (int i = 0; i < numEvents; i++) {
    events.push_back({endTime[i], startTime[i]});
  }

  // Sort the events based on their end times (ascending)
  sort(events.begin(), events.end());

  // The count of events that can be scheduled
  int count = 0;
  // Variable to track the end time of the last attended event
  int lastEndTime = 0;

  // Iterate over the sorted events
  for (int i = 0; i < numEvents; i++) {
    // If the start time of the current event is greater than the end time of the last event
    if (events[i].second > lastEndTime) {
      // Attend the event
      count++;
      // Update the last end time to the end time of the current event
      lastEndTime = events[i].first;
    }
  }

  return count;
}

int main() {
  // Example 1
  int numEvents1 = 6;
  int startTime1[] = {1, 3, 0, 5, 8, 5};
  int endTime1[] = {2, 4, 6, 7, 9, 9};
  cout << "Maximum number of schedulable events for example 1: " << maximumSchedulableEvents(startTime1, endTime1, numEvents1) << endl;

  // Example 2
  int numEvents2 = 3;
  int startTime2[] = {10, 12, 20};
  int endTime2[] = {20, 25, 30};
  cout << "Maximum number of schedulable events for example 2: " << maximumSchedulableEvents(startTime2, endTime2, numEvents2) << endl;

  return 0;
}
