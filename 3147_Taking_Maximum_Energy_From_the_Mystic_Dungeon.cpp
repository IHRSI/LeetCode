class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {//TC=O(n-k) , SC=O(1)
        int n=energy.size();
        for(int i=n-k-1;i>=0;--i){
            energy[i]+=energy[i+k];
        }
        return *max_element(energy.begin(),energy.end());
    }
};
