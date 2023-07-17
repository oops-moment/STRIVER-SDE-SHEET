   queue<pair<Node*,int>>q;
        map<int,int>mp;
        vector<int>finalAnswer;
        if(root==NULL)
        {
            return  finalAnswer;
        }
        q.push({root,0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* temp=it.first;
            int index=it.second;
            int val=temp->data;
            if(mp[index]==0)
               {
                   mp[index]=val;
                   
               }
            if(temp->left)
            {
               q.push({temp->left,index-1}); 
            }
            if(temp->right)
            {
                q.push({temp->right,index+1});
            }
            
        }
        for(auto it:mp )
        {
            finalAnswer.push_back(it.second);   
        }
        
        return finalAnswer;
