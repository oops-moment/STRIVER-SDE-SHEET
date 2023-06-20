if(head==NULL || head ->next==NULL||k==0 )
        {
            return head;
        }
        ListNode* fastPointer=head;
        ListNode* slowPointer=head;
        int totalNodes=0;
        while(fastPointer!=NULL)
        {
            totalNodes++;
            fastPointer=fastPointer->next;
        }
         k%=totalNodes;
         if(k==0)
         {
             return head;
         }
        fastPointer=head;
        for(int i=0;i<k;i++)
        {
            fastPointer=fastPointer->next;
        }
        while(fastPointer->next)
        {
            fastPointer=fastPointer->next;
            slowPointer=slowPointer->next;
        }
        ListNode*temp=head;
        head=slowPointer->next;
        slowPointer->next=NULL;
        fastPointer->next=temp;
        return head;
