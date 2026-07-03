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
    ListNode* sortList(ListNode* head) {
        vector<int> ls;
        ListNode* temp=head;
        while(temp){
            ls.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        sort(ls.begin(),ls.end());
        int i=0;
        while(i<ls.size()){
            temp->val=ls[i];
            temp=temp->next;
            i++;

        }
        return head;

        
    }
};