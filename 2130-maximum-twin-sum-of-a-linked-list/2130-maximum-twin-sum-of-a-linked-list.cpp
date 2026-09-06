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
    int pairSum(ListNode* head) {
        vector<int> a;
        while(head){
        a.push_back(head->val);
        head=head->next;
        }
        int i=0;
        int j=a.size()-1;
        int mx=INT_MIN;
        while(i<j){
            mx=max(mx,a[i]+a[j]);
            i++;
            j--;
        }
        return mx;
        
    }
};