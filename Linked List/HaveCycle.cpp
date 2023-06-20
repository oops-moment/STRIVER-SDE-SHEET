if(head==NULL)
        {
            return false;
        }
        ListNode* slowPointer=head;
        ListNode* fastPointer=head;
        while(fastPointer && fastPointer->next)
        {
            slowPointer=slowPointer->next;
            fastPointer=fastPointer->next->next;
            if(slowPointer==fastPointer)
            {
                return true;
            }
        }
        return false;
