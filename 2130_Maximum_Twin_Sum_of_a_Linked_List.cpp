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

// LL Reverse + slow fast ptr
class Solution {
public:
    ListNode* reverse(ListNode* curr){//TC=O(3*n/2)~O(n), SC=O(1)
        ListNode* prev=nullptr;
        ListNode* nxt;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        int ans=0;
        ListNode* head2=reverse(slow);
        while(head2){
            ans=max(ans,(head->val)+(head2->val));
            head=head->next;
            head2=head2->next;
        }
        return ans;
    }
};

//Stack + slow fast ptr
class Solution {
public:
    int pairSum(ListNode* head) {//TC=O(n), SC=O(n/2)~O(n)
        stack<int> s;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        int ans=0;
        while(slow){
            ans=max(ans,s.top()+slow->val);
            s.pop();
            slow=slow->next;
        }
        return ans;
    }
};

//Array Conversion
class Solution {
public:
    int pairSum(ListNode* head) {//TC=O(n+n/2)~O(n), SC=O(n)
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n/2;++i){
            ans=max(ans,arr[i]+arr[n-i-1]);
        }
        return ans;
    }
};
