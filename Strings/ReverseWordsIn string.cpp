
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> temp;
        while (ss >> word) {
            temp.push_back(word);
        }
        reverse(temp.begin(), temp.end());
        string finalAnswer = "";
        for (int i = 0; i < temp.size(); i++) {
            finalAnswer += temp[i];
            if (i != temp.size() - 1) {
                finalAnswer += " ";
            }
        }
        return finalAnswer;
    }
};
