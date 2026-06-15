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

//Using slow fast ptr
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {//TC=O(n/2)~O(n), SC=O(1)
        if(!head->next) return nullptr;
        ListNode* prev=nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        return head;
    }
};


//Using array
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {//TC=O(n), SC=O(n)
        if(!head->next) return nullptr;
        vector<ListNode*> arr;
        ListNode* curr=head;
        while(curr){
            arr.push_back(curr);
            curr=curr->next;
        }
        int mid=arr.size()/2;
        arr[mid-1]->next=arr[mid]->next;
        return head;
    }
};
