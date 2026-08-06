class Solution {
public:
    // Function to calculate the product of digits of a number
    int digitProduct(int num) {
        int product = 1;

        while (num > 0) {
            product *= (num % 10); // Multiply the last digit
            num /= 10;             // Remove the last digit
        }

        return product;
    }

    int smallestNumber(int n, int t) {

        // Keep checking numbers starting from n
        while (true) {

            // If the digit product is divisible by t, return it
            if (digitProduct(n) % t == 0)
                return n;

            n++;
        }
    }
};