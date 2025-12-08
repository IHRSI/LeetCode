//Let n be the number of tasks at initialization and m be the number of subsequent operations.
class TaskManager {//SC=O(n+m)
public://TC:
    unordered_map<int,pair<int,int>> um;
    priority_queue<pair<int,int>> heap;
    TaskManager(vector<vector<int>>& tasks) {//O(nlogn)
        for(auto ele: tasks){
            add(ele[0],ele[1],ele[2]);
        }
    }
    void add(int userId, int taskId, int priority) {//O(log(n+m))
        um[taskId]={userId,priority};
        heap.emplace(priority,taskId);
    }
    void edit(int taskId, int newPriority) {//O(log(n+m))
        um[taskId].second=newPriority;
        heap.emplace(newPriority,taskId);
    }
    void rmv(int taskId) {//O(1)
        um.erase(taskId);
    }
    int execTop() {
        while(!heap.empty()){//O(log(n+m))
            auto [pr,tsk]=heap.top();
            heap.pop();
            if(um.find(tsk)!=um.end() && pr==um[tsk].second){
                int usr=um[tsk].first;
                um.erase(tsk);
                return usr;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
