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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* prev = &dummy;
            
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            ListNode* nextTemp = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = nextTemp;
        }
        
        return dummy.next;
    }
};