//Hashing method
class Solution {//TC=SC=O(n), here we use bool datatype
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<bool> freq(n+1,false);
        vector<int> ans;
        int common=0;
        for(int i=0; i<n;++i){
            if(A[i]==B[i]) common++;
            if(freq[A[i]]==true) common++;
            if(freq[B[i]]==true) common++;
            freq[A[i]]=true;
            freq[B[i]]=true;
            ans.push_back(common);
        }
        return ans;

    }
};

//BitMasking - Better SC=O(1)
