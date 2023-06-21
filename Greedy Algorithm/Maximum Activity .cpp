int n = end.size();
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++)
        {
            pq.push({end[i],start[i]});
        }
        int count=0;
        int endTime=-1;
        while(pq.empty()==0)
        {
            auto it =pq.top();
            pq.pop();
            if(it.second>=endTime)
            {
                count++;
                endTime=it.first;
            }
        }
        return count;
