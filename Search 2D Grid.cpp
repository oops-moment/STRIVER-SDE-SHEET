class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int cols=matrix[0].size();
        int high=row*cols-1;
        int low=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid/cols][mid%cols]>target)
            {
                high=mid-1;
            }
            else if(matrix[mid/cols][mid%cols]==target)

            {
                return true;
            }
            else
            {
                low=mid+1;
            }
            
        }
        return false;

    }
};
