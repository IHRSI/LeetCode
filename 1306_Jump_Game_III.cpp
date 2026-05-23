//DFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {//TC=O(n), SC=O(n) worst case - 38.5mb - This stack memory is often larger per node than queue entries.
        if(start<0 || start>=arr.size() || arr[start]<0) return 0;
        if(arr[start]==0) return 1;
        arr[start]*=-1;
        int a=canReach(arr,start-arr[start]);
        int b=canReach(arr,start+arr[start]);
        return a||b;
    }
};

//BFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {//TC=O(n), SC=O(n) - 35.3mb - This stack memory is often larger per node than queue entries.
        int n=arr.size();
        vector<bool> visited(n,0);
        queue<int> q;
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            if(arr[idx]==0) return 1;
            int front=idx+arr[idx];
            int back=idx-arr[idx];
            if(front<n && !visited[front]){
                q.push(front);
                visited[front]=1;
            }
            if(back>=0 && !visited[back]){
                q.push(back);
                visited[back]=1;
            }
        }
        return 0;
    }
};
