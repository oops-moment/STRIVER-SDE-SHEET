class Solution {
public:
    double myPow(double x, int n) {
        // Binary Exponentiation for the same
        int isNegative = 0;
        long long temp = n;  // Change data type to long long
        if (n < 0) {
            isNegative = 1;
            temp *= -1;
        }
        double finalAnswer = 1;

        while (temp > 0) {
            if (temp % 2 == 0) {
                temp /= 2;
                x *= x;
            } else {
                temp -= 1;
                finalAnswer *= x;
            }
        }

        if (isNegative) {
            return 1.0 / finalAnswer;
        } else {
            return finalAnswer;
        }
    }
};
