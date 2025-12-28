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

//Recursive approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {//TC=O(n), SC=O(n) - It goes in the recursive stack calls
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* revhead=reverseList(head->next);
        ListNode* endnode=head->next;
        endnode->next=head;
        head->next=nullptr;
        return revhead;
    }
};

//3 pointer iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {//TC=O(n), SC=O(1)
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* prev=nullptr;
        ListNode* nxt;
        while(head!=nullptr){
            nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
};

//Using array
class Solution {
public:
    ListNode* reverseList(ListNode* head) {//TC=O(2n), SC=O(n)
        if(head==nullptr || head->next==nullptr) return head;
        vector<int> a;//Instead of vector an stack could also be used
        ListNode* curr=head;
        while(curr!=nullptr){
            a.push_back(curr->val);
            curr=curr->next;
        }
        int n=a.size();
        curr=head;
        for(int i=n-1;i>=0;--i){
            curr->val=a[i];
            curr=curr->next;
        }
        return head;
    }
};
