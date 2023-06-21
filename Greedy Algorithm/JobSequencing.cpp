 vector<int>deadLine(n,0);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({arr[i].profit,arr[i].dead});
        }
        vector<int>finalAnswer(2,0);
        while(!pq.empty())
        {
            auto it =pq.top();
            int deadline=it.second;
            pq.pop();
            for(int i=deadline-1;i>=0;i--)
            {
                if(deadLine[i]==0)
                {
                    deadLine[i]=1;
                    finalAnswer[0]++;
                    finalAnswer[1]+=it.first;
                    break;
                }
            }
        }
        return finalAnswer;
    } 
