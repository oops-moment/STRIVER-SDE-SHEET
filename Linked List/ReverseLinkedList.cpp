/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // we are given the head we need to return the reversed linked list.
         ListNode *temp=NULL; // temp pointer points to null
         while(head!=NULL)
         {
  ListNode*next=head->next; // final head points to this basically
  head->next=temp;
  temp=head;
  head=next;
         }
         return temp;
    }
};
