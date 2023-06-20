vector<int>nodes;
        while(head!=NULL)
        {
            nodes.push_back(head->val);
            head=head->next;
        }
        vector<int>nodesr=nodes;
        reverse(nodes.begin(),nodes.end());
        if(nodes==nodesr)
        {
            return true;
        }
        else
        {
            return false;
        }
