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
    ListNode* rotateRight(ListNode* head, int k) {//TC=O(n), SC=O(1)
        if(!head || !head->next || k==0) return head;
        int n=0;
        ListNode* top=head;
        while(top->next!=nullptr){
            ++n;
            top=top->next;
        }
        ++n;
        top->next=head;
        if(k&n==0) return head;
        int rotate=n-(k%n);
        while(rotate--){
            top=top->next;
        }
        head=top->next;
        top->next=nullptr;
        return head;
    }
};
