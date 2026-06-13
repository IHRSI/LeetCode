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

//Iterative
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {//TC=O(n+m), SC=O(1)
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1)
            tail->next = list1;
        else
            tail->next = list2;
        return dummy->next;
    }
};

//Recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {//TC=O(n+m), SC=O(n+m)
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val<=list2->val){
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list2->next,list1);
            return list2;
        }
        return nullptr;
    }
};

//Using array
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {//TC=O(n+m+(n+m)log(n+m))~O((n+m)log(n+m)), SC=O(n+m)
        if(!list1) return list2;
        if(!list2) return list1;
        vector<int> arr;
        while(list1){
            arr.push_back(list1->val);
            list1=list1->next;
        }
        while(list2){
            arr.push_back(list2->val);
            list2=list2->next;
        }
        sort(arr.begin(),arr.end());
        ListNode* ans=new ListNode(arr[0]);
        ListNode* curr=ans;
        for(int i=1;i<arr.size();++i){
            curr->next=new ListNode(arr[i]);
            curr=curr->next;
        }
        return ans;
    }
};
