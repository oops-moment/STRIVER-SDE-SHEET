 ListNode* slowPointer=head;
        ListNode* fastPointer=head;
        while(fastPointer && fastPointer->next)
        {
            slowPointer=slowPointer->next;
            fastPointer=fastPointer->next->next;
            if(slowPointer==fastPointer)
            {
                while(head!=slowPointer)
                {
                    head=head->next;
                    slowPointer=slowPointer->next;
                }
                return head;
            }
        }
        return NULL;
