EASY ONE YOU JUST NEED TO FIND THE COUNT OF POSITIVE AND NEGATIVE NUMBER SINCE THE ARRAY WAS SORTED I JUST ITERATED TILL LIKE FIRST POSITIVE THEN BREAKED THE LOOP
SOME BSTARDS DID O(LOGN) OFC BINARY SEARCH THEY SEARCHED FOR JUS TGREATER THAN O YES GOOD ONE OFC 
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0;
        int neg=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                neg++;
            }
            else if(nums[i]>0)
            {
                pos+=nums.size()-i;
                break;
            }
        }
        return max(pos,neg);
    }
};
