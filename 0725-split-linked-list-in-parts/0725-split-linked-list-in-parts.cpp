class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        int length = 0;
        ListNode* current = head;
        
        while (current) {
            length++;
            current = current->next;
        }
        
        int part_size = length / k;
        int extra = length % k;
        current = head;
        
        for (int i = 0; i < k && current != nullptr; ++i) {
            result[i] = current;
            int current_part_size = part_size + (extra > 0 ? 1 : 0);
            extra--;
            
            for (int j = 1; j < current_part_size; ++j) {
                current = current->next;
            }
            
            ListNode* next_part = current->next;
            current->next = nullptr;
            current = next_part;
        }
        
        return result;
    }
};