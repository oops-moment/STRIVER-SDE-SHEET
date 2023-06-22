void recurse(vector<int>&candidates,vector<vector<int>>&finalAnswer,vector<int>&temp,int target,int index)
    {   
        //Base Case
        if(target==0)
        {   
            finalAnswer.push_back(temp);
            return;
        }
        if(index<0)
        {
            return ;
        }       
        if(candidates[index]<=target)
        {
            temp.push_back(candidates[index]);
            recurse(candidates,finalAnswer,temp,target-candidates[index],index);
            temp.pop_back();
           
        }
         recurse(candidates,finalAnswer,temp,target,index-1);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>finalAnswer;
        vector<int>temp;
        int index=candidates.size()-1;
        recurse(candidates,finalAnswer,temp,target,index);
        return finalAnswer;
    }
