#include <numeric> // Required for std::gcd

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            int gcdValue = std::gcd(curr->val, curr->next->val);

            ListNode* gcdNode = new ListNode(gcdValue);

            gcdNode->next = curr->next;
            curr->next = gcdNode;
            curr = gcdNode->next;
        }

        return head;
    }
};