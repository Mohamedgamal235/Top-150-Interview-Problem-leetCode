class Solution {
public:
    
    int DFS(unordered_map<int, vector<int>>& adjList , int node , unordered_set<int>& visited ) {
        visited.insert(node) ;

        for (auto neighbours : adjList[node]) {
            if (!visited.count(neighbours))
                return 1 + DFS(adjList , neighbours , visited) ; 
        }
        return 1 ; 
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        set<int> stNums(nums.begin() , nums.end());

        unordered_map<int, vector<int>> adjList ; 
        for (auto val : stNums) {
            if (stNums.count(val+1)) {
                adjList[val].push_back(val+1) ;
                adjList[val+1].push_back(val) ; 
            }
        }

        unordered_set<int> visited ;

        int ans = 0 ; 
        for (auto val : stNums) {
            int sz = 0 ;
            if (!visited.count(val)) 
                 sz = DFS(adjList , val , visited) ; 

            ans = max(ans , sz) ; 
        }

        return ans ; 
    }
};