class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        // Only store odd numbers
        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        // 2 is prime
        int count = 1;

        // Check only odd numbers
        for (int i = 3; i < n; i += 2) {

            if (isPrime[i]) {

                count++;

                // No need to mark if i*i >= n
                if (i <= (n - 1) / i) {

                    // Start from i*i
                    // Move by 2*i because we only care about odd numbers
                    for (int j = i * i; j < n; j += 2 * i) {
                        isPrime[j] = false;
                    }
                }
            }
        }

        return count;
    }
};