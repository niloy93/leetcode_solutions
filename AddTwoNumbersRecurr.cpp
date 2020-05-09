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
    ListNode* res;
    int carry=0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL && carry == 0)
            return NULL;
        
        ListNode* temp = new ListNode;
        if(l1 == NULL && l2 == NULL && carry > 0)
        {
            temp->val = carry;
            temp->next = NULL;
            return temp;
        }
        if(l1 == NULL && l2 != NULL)
        {
            temp->val = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            temp->next = addTwoNumbers(l1,l2->next);
        }
        if(l2 == NULL && l1 != NULL)
        {
            temp->val = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            temp->next = addTwoNumbers(l1->next,l2);
        }
        if(l1 != NULL && l2 != NULL)
        {
            temp->val = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            temp->next = addTwoNumbers(l1->next, l2->next);
        }
        
        res = temp;
        return res;
        
    }
};