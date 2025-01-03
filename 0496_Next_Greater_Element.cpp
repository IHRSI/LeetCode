//Brute Force method, Used vector
class Solution { // TC- O(n1*n2*n2) , SC- O(n1) , Better SC
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans(n1,-1);
        for(int i=0;i<n1;++i){
            for(int j=0;j<n2;++j){
                if(nums1[i]==nums2[j]){
                    for(int k=j ; k<n2; k++){
                        if(nums2[k]>nums1[i]){ 
                            ans[i]=nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};

//Efficient TC method , Used UM
class Solution { // TC -O(n2) , SC-O(n1+n2)
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2= nums2.size();
        stack<int> st;
        unordered_map<int,int> nge;
        for (int i = 0; i < n2; i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                nge[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nge[nums2[st.top()]]=-1;
            st.pop();
        }
        vector<int> ans;
        for(int ele: nums1){
            ans.push_back(nge[ele]);
        }
        return ans;
    }
};
