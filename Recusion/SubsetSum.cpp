 void recurse(vector<int>arr,vector<int>&finalAnswer,int index, int sum)
    {   
        if(index==arr.size())
        {   
            
            finalAnswer.push_back(sum);
            return;
        }
        if(index<arr.size())
            recurse(arr,finalAnswer,index+1,sum+arr[index]);
        recurse(arr,finalAnswer,index+1,sum);
    }
vector<int> subsetSum(vector<int> &arr){
	// Write your code here.	
	 // Write Your Code here
        vector<int>finalAnswer;
        int sum=0;
        int index=0;
        recurse(arr,finalAnswer,index,sum);
		sort(finalAnswer.begin(),finalAnswer.en
        return finalAnswer;
        
}
