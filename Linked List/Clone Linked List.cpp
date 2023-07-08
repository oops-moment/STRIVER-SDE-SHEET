/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node*temp=head;
        while(temp!=NULL)
        {
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        // we have created nodes for all
        for(auto it : mp)
        {
            Node*orig=it.first;
            Node*copy=it.second;
            if(orig->next==NULL)
            {
                copy->next=NULL;
            }
            else
            {
                copy->next=mp[orig->next];

            }
            if(orig->random==NULL)
            {
                copy->random=NULL;
            }
            else
            {
                copy->random=mp[orig->random];
            }
            
        }
        return mp[head];

    }
};
