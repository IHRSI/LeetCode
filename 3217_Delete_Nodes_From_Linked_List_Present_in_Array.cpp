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
