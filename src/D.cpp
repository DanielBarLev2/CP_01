// We read each test case separately. then, for each test we iterate through the elements and printing the optimal value
// using the patten:
// player one choose odd and odd when player two choose odd and even.
// after two turns, there are three less odd numbers, and the score reduced by one.
// thus, the optimal value is the sum of the total seen elements, minus odd numbers count minus 1 each three odds.
// In particular, opt_val = s - c / 3 - ((c % 3) == 1).
// Time complexity: O(N)
// reading each element and calculating its optimal value of k numbers in O(1).

#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test;
    std::cin >> test;

    while (test--) {
        int n;
        std::cin >> n;

        // s = sum array to the k element.
        // c = num of odd elements.
        // v = current element.
        // opt_val = the optimal value of the game.
        long long opt_val, v, c = 0, s = 0;
        // Print first base cases opt_val is equal to the only element.
        std::cin >> opt_val;
        std::cout << opt_val << " ";

        // add to sum, check if the first element is odd.
        s += opt_val;
        if (opt_val % 2) {
            c++;
        }

        // iterate through the rest of the values and  update the optimal value for each k using the pattern below:
        for (int i = 1; i < n; i++) {
            std::cin >> v;

            s += v;
            if (v % 2) {
                c++;
            }

            // pattern
            opt_val = s - (c / 3) - ((c % 3) == 1);

            std::cout << opt_val << " ";
        }
        std::cout << "\n";
    }
}
// end of code