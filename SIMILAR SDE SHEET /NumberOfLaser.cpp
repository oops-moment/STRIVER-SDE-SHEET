class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>finalAnswer;
        for(int i=0;i<bank.size();i++)
        {   
            int count=0;
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1')
                {
                    count++;
                }

            }
            if(count>0)
                finalAnswer.push_back(count);
        }
        int totalAnswer=0;
        for(int j=1;j<finalAnswer.size();j++)
        {
            totalAnswer+=finalAnswer[j]*finalAnswer[j-1];
        }
        return totalAnswer;
    }
};
