 if(node->next==NULL)
       {
           delete(node);
       } 
       else
       {
           node->val=node->next->val;
           node->next=node->next->next;
       }
