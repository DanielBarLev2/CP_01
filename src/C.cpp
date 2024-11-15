// DP approach:
// I used two variables (dp_u and dp_d) to keep track of the number of valid configurations,
// for face-up and face-down cards, instead of arrays, to save space.
// For each card, I calculated new values for dp_u and dp_d by checking that adjacent cards don’t show the same number.
// I made sure to use modulo 998244353 in every calculation to handle large numbers and avoid overflow.
// Finally, I added the values of dp_u and dp_d at the end and took the modulo to get the result.
// Time Complexity: O(N)
// Iterate through the cards once.
// Space Complexity: O(1)

#include <iostream>

int main() {
    // Modulo value as specified in the problem, use to overcome overflow since 2^n is too big number.
    int const mod = 998244353;

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read the number of Cards
    int num;
    std::cin >> num;

    // dp_f - the sum of valid configurations for the first i cards where A_i is faced up.
    // dp_d - the sum of valid configurations for the first i cards where A_i is faced down.
    // Base Case, first card can be faced both up and down.
    int dp_u = 1, dp_d = 1;

    // Keep track of current card and previous card.
    int A_prev, B_prev, A_curr, B_curr;
    std::cin >> A_prev >> B_prev;
    for (int i = 0; i < num - 1; ++i) {
        // those are helper variables to overcome overflow.
        // temp_u - the sum of valid configurations for the first i cards where A_i is faced up.
        // temp_d - the sum of valid configurations for the first i cards where A_i is faced down.
        int temp_u = 0, temp_d = 0;
        std::cin >> A_curr >> B_curr;

        // Tests all four cases:
        // if the values are not equal, a flip can be made. Hence, updating dp_d or dp_u.
        if (A_prev != A_curr) {
            temp_u = (temp_u + dp_u) % mod;
        }
        if (B_prev != B_curr) {
            temp_d = (temp_d + dp_d) % mod;
        }
        if (A_prev != B_curr) {
            temp_d = (temp_d + dp_u) % mod;
        }
        if (B_prev != A_curr) {
            temp_u = (temp_u + dp_d) % mod;
        }

        // Update dp_u and dp_d for the next iteration
        dp_u = temp_u;
        dp_d = temp_d;

        // Move the current card values to the previous card variables for the next iteration
        A_prev = A_curr;
        B_prev = B_curr;
    }

    // Output
    std::cout << (dp_u + dp_d) % mod << '\n';

    return 0;
}
// End of code