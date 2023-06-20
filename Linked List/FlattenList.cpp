 vector<int>allNodes;
   Node*temp=root;
   while(temp!=NULL)
   {   
       Node* bottomNode=temp;
       while(bottomNode)
       {
           allNodes.push_back(bottomNode->data);
           bottomNode=bottomNode->bottom;
       }
       temp=temp->next;
   }
   sort(allNodes.begin(),allNodes.end());
    Node*head= new Node(0);
    temp=head;
   for(int i=0;i<allNodes.size();i++)
   {   
       Node*newNode=new Node(allNodes[i]);
       temp->bottom=newNode;
       temp=newNode;
       
       
   }
   return head->bottom;
