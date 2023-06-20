ListNode* fastPointer=head;
        ListNode* slowPointer=head;

        for(int i=0;i<n;i++)
        {
            fastPointer=fastPointer->next;
        }
        if(fastPointer==NULL)
        {
            return slowPointer->next;
        }
        while(fastPointer->next!=NULL)
        {
            slowPointer=slowPointer->next;
            fastPointer=fastPointer->next;
        }
        slowPointer->next=slowPointer->next->next;
        return head;
