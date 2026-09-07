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
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        if (curr->val > 4) {
            head = new ListNode(1, head);
        }
        
        while (curr != nullptr) {
            curr->val = (curr->val * 2) % 10;
            if (curr->next != nullptr && curr->next->val > 4) {
                curr->val++;
            }
            curr = curr->next;
        }
        
        return head;
    }
};