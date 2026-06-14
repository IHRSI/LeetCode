//When slow and fast meet inside the cycle, the meeting point is positioned such that the distance
//from head to the cycle start equals the distance from the meeting point to the cycle start (moving forward along the list).

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
    ListNode *detectCycle(ListNode *head) {//TC=O(n), SC=O(1)
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

//Using hashing
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {//TC=O(n), SC=O(n)
        if(!head || !head->next) return nullptr;
        unordered_set<ListNode*> us;
        while(head){
            if(us.find(head)!=us.end()) return head;
            us.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};
