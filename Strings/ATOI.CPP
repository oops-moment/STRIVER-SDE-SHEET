class Solution {
public:
    int myAtoi(string s) {
        int finalAnswer = 0;
        int i = 0;

        // Skip leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        int positive = 1;
        if (i < s.length()) {
            if (s[i] == '-') {
                positive = 0;
                i++;
            } else if (s[i] == '+') {
                i++;
            }
        }

        // Calculate the integer value
        for (int j = i; j < s.length(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                // Check for overflow
                if (finalAnswer > INT_MAX / 10 || (finalAnswer == INT_MAX / 10 && (s[j] - '0') > INT_MAX % 10)) {
                    return positive == 0 ? INT_MIN : INT_MAX;
                }
                finalAnswer = finalAnswer * 10 + (s[j] - '0');
            } else {
                break;
            }
        }

        if (positive == 0) {
            finalAnswer *= -1;
        }

        return finalAnswer;
    }
};
