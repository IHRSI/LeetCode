//Beggers method(Sticks and bar): (n+r-1)c(r-1),r=3
//Keep ovrflow in mind . used ll for datatype conversion from int to long long.
class Solution {// TC=(1), TC=O(1) // best soln
public:
    long long distributeCandies(int n, int limit) {
        long long ans = (n + 2LL) * (n + 1LL) / 2; // Beggars method: C(n+2, 2)
         //   Used inclusion exclution principle(IEP)
        // Subtract cases where 1 child exceeds the limit
        if (n - (limit + 1) >= 0)
            ans -= 3LL * (n - (limit + 1) + 2) * (n - (limit + 1) + 1) / 2;

        // Add back cases where 2 children exceed the limit
        if (n - 2 * (limit + 1) >= 0)
            ans += 3LL * (n - 2 * (limit + 1) + 2) * (n - 2 * (limit + 1) + 1) / 2;

        // Subtract cases where all 3 children exceed the limit
        if (n - 3 * (limit + 1) >= 0)
            ans -= (n - 3 * (limit + 1) + 2) * (n - 3 * (limit + 1) + 1) / 2;

        return ans;
    }
};
// Editorial concise soln less code same logic
class Solution {
public:
    long long cal(int x) {
        if (x < 0) {
            return 0;
        }
        return (long)x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        return cal(n + 2) - 3 * cal(n - limit + 1) +
               3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
    }
};
