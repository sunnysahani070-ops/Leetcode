/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Interweave the original and copied nodes
        // Original: A -> B -> C
        // Interweaved: A -> A' -> B -> B' -> C -> C'
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node* copiedHead = head->next;
        Node* copiedCurr = copiedHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copiedCurr->next) {
                copiedCurr->next = copiedCurr->next->next;
            }
            curr = curr->next;
            copiedCurr = copiedCurr->next;
        }

        return copiedHead;
    }
};