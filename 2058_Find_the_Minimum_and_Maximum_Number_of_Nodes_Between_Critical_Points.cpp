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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {//TC=O(n), SC=O(1)
        if(!head) return {-1,-1};
        int prev=head->val;
        head=head->next;
        if(!head) return {-1,-1};
        int mindis=INT_MAX,maxdis=0;
        int disct=0,adj_disct=0;
        int cri_pt_ct=0;
        while(head->next){
            int num=head->val;
            int nxt=head->next->val;
            if((num>prev && num>nxt) || (num<prev && num<nxt)){
                if(cri_pt_ct==0){
                    ++cri_pt_ct;
                }
                else{
                    ++cri_pt_ct;
                    mindis=min(adj_disct,mindis);
                    adj_disct=0;
                }
                maxdis=disct;
            }
            if(cri_pt_ct>0){
                ++disct;
                ++adj_disct;
            }
            prev=num;
            head=head->next;
        }
        if(cri_pt_ct<2) return {-1,-1};
        return {mindis,maxdis};
    }
};
