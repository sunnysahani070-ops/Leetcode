class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        
        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val < current->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return reverseList(head);
    }
};