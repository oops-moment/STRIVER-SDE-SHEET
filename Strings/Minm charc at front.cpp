Minimum character to be inserted at front to make sring palindromic

int minCharsforPalindrome(string s) {
	// Write your code here.
        int length = 1; // at least one length ka toh substring hoga
        for (int i = 0; i < s.length(); i++) {
            int low = i - 1;
            int high = i;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                int newl = high - low + 1;
                if (newl > length && low==0) {
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
                if (newl > length&&low==0) {
                    length = newl;
                }
                low--;
                high++;
            }

            // code for odd length substring
        }
		return s.length()-length;
	
}
// we will find the longes tpalinfrom such that the sstart to 0;aabaaca
