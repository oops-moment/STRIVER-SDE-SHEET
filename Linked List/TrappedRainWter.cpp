 int  n=arr.size();
        long long left[n]; // these are the arrays that store the maximum to the left and righ t
        long long maxm=INT_MIN;
        for(long long  i=0;i<n;i++)
        {
            if(arr[i]>maxm)
            {
                maxm=arr[i];
            }
            left[i]=maxm;
        }
        maxm=INT_MIN;
        for(long long i=n-1;i>=0;i--)
        {
            if(arr[i]>maxm)
            {
                maxm=arr[i];
            }
            left[i]=min(left[i],maxm);
        }
        long long answer=0;
        for(int i=0;i<n;i++)
        {
            answer+=left[i]-arr[i];
        }
        return answer;
