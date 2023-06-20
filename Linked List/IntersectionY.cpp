/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *headA, Node *headB)
{
        Node*tempA=headA;
        Node*tempB=headB;
        int flag=0;
        while(headA && headB)
        {   
            if(headA==headB)
            {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
             
            if(headA==NULL && headB==NULL)
            {
                return NULL;
            }
            if(headA==NULL)
            {
                headA=tempB;
            }
            if(headB==NULL)
            {
                headB=tempA;
            }
        }
        return NULL;
}
