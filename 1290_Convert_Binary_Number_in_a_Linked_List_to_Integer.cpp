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
//My approach - efficient
class Solution {//TC=O(n) , SC=O(1)
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=nullptr){
            ans=(ans<<1)|head->val;//ans=ans*2+head->val;
            head=head->next;
        }
        return ans;
    }
};

//Not efficient - first reverses then calc the decimal value
//T.C : O(2n)
//S.C : O(1), Ignoring Recursion stack space occupied during reversal of LinkedList
class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    int getDecimalValue(ListNode* head) {
        head= reverseLL(head);
        int result = 0;
        int power = 0;
        while(head) {
            if(head->val == 1) {
                result += pow(2, power);
            }
            power++;
            head = head->next;
        }
        return result;
    }
};
