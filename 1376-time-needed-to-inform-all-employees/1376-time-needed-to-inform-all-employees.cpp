class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
         vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        
        int ans=0;
        queue<pair<int,int>> q;
        q.push({headID, 0});
        
        while(!q.empty()){
            pair<int,int> ele = q.front();
            q.pop();
            int boss = ele.first;
            int last_time = ele.second;
            
            ans = max(ans, last_time);
            for(auto &it: adj[boss]){
                q.push({it, last_time + informTime[boss]});
            }
        }
        return ans;
    }
};