ListNode*head= new ListNode(0);
        ListNode*temp=head;
        int carry=0;
        int currentSum=0;
        while(carry || l1 || l2)
        {   
            currentSum=0;
            if(carry)
            {
                currentSum+=carry;
            }
            if(l1)
            {
                currentSum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                currentSum+=l2->val;
                l2=l2->next;
            }
            carry=currentSum/10;
            currentSum%=10;
            ListNode* newNode= new ListNode(currentSum);
            temp->next=newNode;
            temp=newNode;
        }
        return head->next;
