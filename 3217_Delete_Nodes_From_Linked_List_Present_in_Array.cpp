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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {//TC=O(n+m), SC=O(n)
        unordered_set<int> us;
        for(int e: nums) us.insert(e);
        while (head && us.count(head->val)) head = head->next;
        ListNode *prev=nullptr;
        ListNode *curr=head;
        while(curr!=nullptr){
            if(us.find(curr->val)!=us.end()) prev->next=curr->next;
            else prev=curr;
            curr=curr->next;
        }
        return head;
    }
};

//Using dummy node that points to head to handle the separate case i.e if value belongs to the head only
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {//TC=O(n+m), SC=O(n)
        unordered_set<int> us;
        for(int e: nums) us.insert(e);
        ListNode dummy(0,head);//addition
        ListNode *prev=&dummy;
        ListNode *curr=head;
        while(curr!=nullptr){
            if(us.find(curr->val)!=us.end()) prev->next=curr->next;
            else prev=curr;
            curr=curr->next;
        }
        return dummy.next;// change
    }
};
