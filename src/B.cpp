//It sorts the intervals first by start time (ascending) and then by end time (descending).
//Two linear passes are made:
//one to track intervals contained by previous ones and another to track those contained by subsequent ones.
// Time Complexity: O(N*Log(N))
// Sorting (optimally): O(N*Log(N))
// Two Linear traversals: O(N)
// Space Complexity: O(N)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
struct Interval {
    int start, end, id;
};
int main() {
    // Read the number of intervals
    int num;
    std::scanf("%d", &num);
    // Vector of intervals struct with id
    std::vector<Interval> intervals(num);
    // Read the intervals
    for (int i = 0; i < num; ++i) {
        std::scanf("%d %d", &intervals[i].start, &intervals[i].end);
        intervals[i].id = i;
    }
    // Sort by start interval (ascending order); Tie-breaking by end interval (descending order)
    std::sort(intervals.begin(), intervals.end(), [](const Interval& x, const Interval& y) {
       if (x.start == y.start) return x.end > y.end;
       return x.start < y.start;
   });
    // Output vectors
    std::vector<int> is_contained(num, 0);
    std::vector<int> contained(num, 0);
    // Iterate over intervals from left to right
    int max_end = -1;
    for (int i = 0; i < num; i++) {
        if (intervals[i].end <= max_end) {
            is_contained[intervals[i].id] = 1;
        } else {
            max_end = intervals[i].end;
        }
    }
    // Iterate over intervals from right to left
    int min_end = std::pow(10, 10);
    for (int i = num - 1; i >= 0; i--) {
        if (intervals[i].end >= min_end) {
            contained[intervals[i].id] = 1;
        } else {
            min_end = intervals[i].end;
        }
    }
    // Print contained status
    for (int i = 0; i < num; i++) {
        std::printf("%d ", contained[i]);
    }
    std::printf("\n");
    // Print is_contained status
    for (int i = 0; i < num; i++) {
        std::printf("%d ", is_contained[i]);
    }
    std::printf("\n");
    return 0;
}
// End of code