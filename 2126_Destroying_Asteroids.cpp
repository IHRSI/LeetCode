class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {//TC=O(nlogn+n)~O(nlogn), SC=O(logn)
        sort(asteroids.begin(),asteroids.end());
        long inc_mass=mass;
        for(int e: asteroids){
            if(e>inc_mass) return false;
            inc_mass+=e;
        }
        return true;
    }
};
