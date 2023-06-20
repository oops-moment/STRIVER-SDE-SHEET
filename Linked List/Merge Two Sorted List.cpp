#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)
{
     if(list1==NULL)
       {
           return list2;
       }
       if(list2==NULL)
       {
           return list1;
       }
    Node<int>* newHead=NULL;
    Node<int>* storeHead=NULL;
       if(list1->data <list2->data)
       {
           newHead=list1;
           storeHead=list1;
           list1=list1->next;
       }
       else
       {
            newHead=list2;
           storeHead=list2;
           list2=list2->next;
       }

       while(list1!=NULL && list2!=NULL)
       {
            if(list1->data <list2->data)
                {   
                    storeHead->next=list1;
                    storeHead=list1;
                    list1=list1->next;
                }
            else
                {   
                    storeHead->next=list2;
                    storeHead=list2;
                    list2=list2->next;
                }
       }
        while(list1!=NULL)
       {  
          storeHead->next=list1;
          storeHead=list1;
            list1=list1->next;
             
       }
        while( list2!=NULL)
       {
        storeHead->next=list2;
         storeHead=list2;
          list2=list2->next;
       }
       return newHead;
}
