#include <bits/stdc++.h>
using namespace std;

vector<int> maxMinWindow(vector<int> nums, int n) {
    vector<int> finalAnswer;
    for(int k = 1; k <= n; k++) {
        deque<int> dq;
        vector<int> result;
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.front()] >= nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
        }
        result.push_back(nums[dq.back()]);
        for(int i = k; i < n; i++) {
            while(!dq.empty() && dq.back() <= (i - k)) {
                dq.pop_back();
            }
            while(!dq.empty() && nums[dq.front()] >= nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
            result.push_back(nums[dq.back()]);
        }
        finalAnswer.push_back(*max_element(result.begin(), result.end()));
    }
    return finalAnswer;
}
