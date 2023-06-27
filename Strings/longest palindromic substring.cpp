class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int length = 1; // at least one length ka toh substring hoga
        for (int i = 0; i < s.length(); i++) {
            int low = i - 1;
            int high = i;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                int newl = high - low + 1;
                if (newl > length) {
                    start = low;
                    length = newl;
                }
                low--;
                high++;
            }

            // code for even length substring

            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                int newl = high - low + 1;
                if (newl > length) {
                    start = low;
                    length = newl;
                }
                low--;
                high++;
            }

            // code for odd length substring
        }

        // now we have the start and also the length of the palindromic substring
        return s.substr(start, length);
    }
};
