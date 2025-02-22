class Solution {
    public:
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
            vector<vector<int>> adjList(numCourses) ;
            vector<int> indegree(numCourses, 0 );
    
            for (auto prerequisite  : prerequisites) {
                int crs = prerequisite[0];
                int preq= prerequisite[1] ;
                adjList[preq].push_back(crs) ;
                indegree[crs]++ ;
            }
    
            priority_queue<int , vector<int> , greater<int>> pq;
            vector<int> inorder ;
    
            for (int i = 0 ; i < numCourses ; i++)
                if (indegree[i] == 0)
                    pq.push(i) ;
    
            while (!pq.empty()) {
                auto curr = pq.top() ;
                pq.pop();
    
                inorder.push_back(curr) ;
                for (auto neighbour : adjList[curr]) {
                    indegree[neighbour]-- ;
                    if (indegree[neighbour] == 0)
                        pq.push(neighbour) ;
                }
            }
    
            return inorder.size() == numCourses ;
        }
    };