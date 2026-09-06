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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head; 
        int groupLen = 2;

        while (prev != nullptr && prev->next != nullptr) {
            ListNode* node = prev->next;
            int count = 0;
            while (node != nullptr && count < groupLen) {
                node = node->next;
                count++;
            }
            if (count % 2 == 0) {
                ListNode* curr = prev->next;
                ListNode* reverseHead = nullptr;
                ListNode* reverseTail = curr; 
                ListNode* nextNode = nullptr;

                for (int i = 0; i < count; ++i) {
                    nextNode = curr->next;
                    curr->next = reverseHead;
                    reverseHead = curr;
                    curr = nextNode;
                }
                prev->next = reverseHead;
                reverseTail->next = curr;

                prev = reverseTail;
            } 
            else {
                for (int i = 0; i < count; ++i) {
                    prev = prev->next;
                }
            }
            groupLen++;
        }

        return head;
    }
};