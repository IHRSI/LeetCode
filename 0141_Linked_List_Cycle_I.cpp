/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Using slow fast ptr
class Solution {
public:
    bool hasCycle(ListNode *head) {//TC=O(n), SC=O(1)
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return 1;
        }
        return 0;
    }
};

//Using hasing
class Solution {
public:
    bool hasCycle(ListNode *head) {//TC=O(n), SC=O(n)
        if(!head || !head->next) return 0;
        unordered_set<ListNode*> us;
        while(head){
            if(us.find(head)!=us.end()) return 1;
            us.insert(head);
            head=head->next;
        }
        return 0;
    }
};
