class Solution {
    public:
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,1,-1};
    
        bool isValid(int r , int c , vector<vector<char>>& grid) {
            return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() ;
        }
        void DFS(int r , int c , vector<vector<bool>>& visited , vector<vector<char>> &grid) {
            if (!isValid(r , c , grid) || visited[r][c] || grid[r][c] == '0')
                return;
    
            visited[r][c] = true ;
    
            for (int d = 0 ; d < 4 ; d++) {
                int nr = r + dr[d] ;
                int nc = c + dc[d] ;
    
                DFS(nr , nc , visited , grid);
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size() , m = grid[0].size() ;
            vector<vector<bool>> visited(n , vector<bool>(m, false));
    
            int islands  = 0 ;
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < m ; j++) {
                    if (!visited[i][j] && grid[i][j] == '1') {
                        DFS(i , j , visited , grid);
                        islands++ ; 
                    }
                }
            }
    
            return islands ; 
        }
    };