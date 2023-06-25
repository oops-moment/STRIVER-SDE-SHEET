class Solution {
public:
  int partition(vector<int>& arr, int l, int r, int pivot){
        int i=l, j=l;
        while(i<r){
            if(arr[i]<=pivot){
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        swap(arr[j], arr[r]);
        return j;
    }
    
    int kthSmallest(vector<int>& arr, int l, int r, int k) {
        int pivot = arr[r];
        int pi = partition(arr, l, r, pivot);
        if (pi == k - 1) {
            return arr[pi];
        }
        else if (pi < (k - 1)) {
            return kthSmallest(arr, pi + 1, r, k);
        }
        else {
            return kthSmallest(arr, l, pi - 1, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int kthSmall = nums.size() - k + 1;
        return kthSmallest(nums, 0, nums.size() - 1, kthSmall);
    }
};
