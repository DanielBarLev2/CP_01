//The code reads multiple test cases, where each test case consists of n integers,
//and calculates the maximum absolute difference between consecutive integers.
//It stores these differences in a vector and computes the minimum value from this vector.

// Time Complexity: O(N)
// One pass on the input, while making O(1) calculations on board O(N).
// finding min over n elements in O(N).
// Space Complexity: O(N) -- storing the input

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        // this vector contains maximum possible difference in absolute value of a_i neighbors.
        // e.g: (|a1 - a2|, max{|a1-a2|, |a2-a3|}, ...)
        std::vector<int> max_diff(n);
        int a1, a2, a3 = 0;

        // finds diff between first two elements
        scanf("%d", &a1);
        scanf("%d", &a2);
        max_diff[0] = std::abs(a1 - a2);

        // iteratively computes max{|a1-a2|, |a2-a3|}
        for (int i = 1; i < n-1; i++) {
            scanf("%d", &a3);
            max_diff[i] = std::max(std::abs(a1 - a2), std::abs(a2 - a3));
            a1 = a2;
            a2 = a3;
        }

        // compute last element
        max_diff[n-1] = std::abs(a1 - a2);

        // finds the optimal solution
        auto min_elem = std::min_element(max_diff.begin(), max_diff.end());
        printf("%d", *min_elem);
        std::printf("\n");

    }
    return 0;
}