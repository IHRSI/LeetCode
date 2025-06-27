//Best approach was BS + Divide and coquer TC=O((n1+n2)logC)) i didnt understand this - This Q hasnt come in any company so not trying to understad this approach.

//Binary Search inside Binary Search - half open BS(on ans - minimising the range )*Inclusive BS(on arr2 counting)

/*If x 1≥0, then nums 2[j]×x1  forms a non-decreasing sequence. We use binary search to count how many products are ≤v.
If x1<0, then nums 2[j]×x1 forms a non-increasing sequence. In this case, we use binary search to find how many products 
are greater than v, denoted as t. Then, the number of products ≤v is n 2−t, where n 2 is the length of nums2.
 */
class Solution {//TC=O(n1*logn2*logC) , SC=O(1)
public:
    int f(vector<int>& nums2, long long x1, long long v) {
        int n2 = nums2.size();
        int left = 0, right = n2-1;
        while (left <= right) {//Inclusive BS - counting
            int mid = (left + right) >> 1;
            if (x1 >= 0 && nums2[mid] * x1 <= v ||// less than equal to v
                x1 < 0 && nums2[mid] * x1 > v) {// greater than v
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        if (x1 >= 0) {
            return left;
        } else {
            return n2 - left;//
        }
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size();
        long long left = -1e10, right = 1e10;//C=right-left , the range of ans
        while (left < right) {//BS on ans , minimisatin of range
            long long mid = (left + right) >> 1;
            long long count = 0;
            for (int i = 0; i < n1; i++) {
                count += f(nums2, nums1[i], mid);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

class Solution {// Used max heap gave TLE
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {//TC=O(n^2*logk) SC=O(K)
        int n1=nums1.size();
        int n2=nums2.size();
        long long ans;
        priority_queue<long long> mh;
        for(int &i : nums1){
            for(int &j: nums2){
                mh.push(i*1ll*j);
                if(mh.size()>k) mh.pop();
            }            
        }
        return mh.top();
        }
};
