#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        int leftptr = -1;
        for (int i = 0; i < version1.length(); i++) {
            if (version1[i] == '.') {
                string temp = version1.substr(leftptr + 1, i - leftptr - 1);
                int val = stoi(temp);
                v1.push_back(val);
                leftptr = i;
            }
        }
        string temp = version1.substr(leftptr + 1);
        int val = stoi(temp);
        v1.push_back(val);

        vector<int> v2;
        leftptr = -1;
        for (int i = 0; i < version2.length(); i++) {
            if (version2[i] == '.') {
                string temp = version2.substr(leftptr + 1, i - leftptr - 1);
                int val = stoi(temp);
                v2.push_back(val);
                leftptr = i;
            }
        }
        temp = version2.substr(leftptr + 1);
        val = stoi(temp);
        v2.push_back(val);

        // Compare number revision by revision
        for (int i = 0; i < min(v1.size(), v2.size()); i++) {
            if (v1[i] < v2[i]) {
                return -1;
            } else if (v1[i] > v2[i]) {
                return 1;
            }
        }

        // If all revisions compared are equal, check for additional revisions
        if (v1.size() < v2.size()) {
            for (int i = v1.size(); i < v2.size(); i++) {
                if (v2[i] > 0) {
                    return -1;
                }
            }
        } else if (v1.size() > v2.size()) {
            for (int i = v2.size(); i < v1.size(); i++) {
                if (v1[i] > 0) {
                    return 1;
                }
            }
        }

        return 0;
    }
};
