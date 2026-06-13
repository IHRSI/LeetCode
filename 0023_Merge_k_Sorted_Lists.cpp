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

//Using PriorityQueue - Min Heap
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {//TC=O(Nlogk), SC=O(logk)
        auto cmp=[](ListNode* a, ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        for(auto l:lists){
            if(l) pq.push(l);
        }
        if(pq.empty()) return nullptr;
        ListNode* head=pq.top();
        pq.pop();
        if(head->next) pq.push(head->next);
        ListNode* tail=head;
        while(!pq.empty()){
            ListNode* n=pq.top();
            pq.pop();
            tail->next=n;
            tail=tail->next;
            if(n->next) pq.push(n->next);
        }
        return head;
    }
};

//Using Merge Sort(Divide n Conquer)
class Solution {//TC=O(Nlogk), SC=O(logk+N)~O(N) , N is total no. of nodes
public:
    ListNode* merge2sortedll(ListNode* l1,ListNode* l2){//This func is Q no. 21
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<=l2->val){
            l1->next=merge2sortedll(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge2sortedll(l2->next,l1);
            return l2;
        }
        return nullptr;
    }
    ListNode* dividenmerge(int s,int e,vector<ListNode*>& lists){
        if(s==e) return lists[s];
        int mid=s+(e-s)/2;
        ListNode* l1=dividenmerge(s,mid,lists);
        ListNode* l2=dividenmerge(mid+1,e,lists);
        return merge2sortedll(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return nullptr;
        return dividenmerge(0,k-1,lists);
    }
};

//Using array
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {//TC=O(n+nlogn+n)~O(nlogn), SC=O(n+logn)~O(n)
        int k=lists.size();
        vector<int> arr;
        for(auto list: lists){
            while(list){
                arr.push_back(list->val);
                list=list->next;
            }
        }
        if(arr.size()==0) return nullptr;
        sort(arr.begin(),arr.end());
        ListNode* head=new ListNode(arr[0]);
        ListNode* curr=head;
        for(int i=1;i<arr.size();++i){
            curr->next=new ListNode(arr[i]);
            curr=curr->next;
        }
        return head;
    }
};
