class Solution { //TC- O(n) tough to analyse , SC-O(n)
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                nge[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return nge;
    }
};
