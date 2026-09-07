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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        std::vector<ListNode*> nodes;
        ListNode* current = head;
        while (current != nullptr) {
            nodes.push_back(current);
            current = current->next;
        }

        int left = 0;
        int right = nodes.size() - 1;

        while (left < right) {
            nodes[left]->next = nodes[right];
            left++;
            
            if (left == right) break;
            
            nodes[right]->next = nodes[left];
            right--;
        }

        nodes[left]->next = nullptr;
    }
};