//Using Upper Bound
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {//TC=O(logn), SC=O(1)
        auto c=upper_bound(letters.begin(),letters.end(),target);
        if(c!=letters.end()) return *c;
        return letters[0];
    }
};

//Alternate way same logic
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int c=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(c!=letters.size()) return letters[c];
        return letters[0];
    }
};

//Using Binary Search
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {//TC=O(logn), SC=O(1)
        int n=letters.size();
        int l=0,r=n-1;
        int pos=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(letters[mid]>target){
                pos=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        if(pos!=-1) return letters[pos];
        return letters[0];
    }
};

//Brute Force
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {//TC=O(n), SC=O(1)
        int n=letters.size();
        for(int i=0;i<n;++i){
            if(target<letters[i]) return letters[i];
        }
        return letters[0];
    }
};
