 if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode*slowPointer=head;
        ListNode*fastPointer=head;
        while(fastPointer!=NULL && fastPointer->next!=NULL)
        {
            fastPointer=fastPointer->next->next;
            slowPointer=slowPointer->next;
        }
        return slowPointer;
