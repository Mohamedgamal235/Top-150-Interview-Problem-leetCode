class Solution {
    public:
        int numberOfSolutions = 0 ;
    
        bool isValid(int n , vector<vector<char>>& grid , int r , int c ) {
            for (int i = 0 ; i < r; ++i) {
                if (grid[i][c] == 'Q')
                    return false;
            }
    
            for (int i = r , j = c ; i >= 0 && j >= 0 ; i-- , j--) {
                if (grid[i][j] == 'Q')
                    return false ;
            }
    
            for (int i = r , j = c ; i >= 0 && j < n ; i-- , j++) {
                if (grid[i][j] == 'Q')
                    return false ;
            }
    
            return true ;
        }
    
        void solve(int n , vector<vector<char>>& grid , int r ) {
            if (r == n) {
                numberOfSolutions++ ;
                return;
            }
    
            for (int i = 0 ; i < n ; i++) {
                if (isValid(n , grid , r,i)) { // for valid option
                    // do
                    grid[r][i] = 'Q' ;
                    // recurse
                    solve(n , grid , r+1) ;
                    // undo
                    grid[r][i] = '.' ;
                }
            }
        }
    
        int totalNQueens(int n) {
            vector<vector<char>> grid(n, vector<char>(n, '.'));
            solve(n , grid , 0) ;
    
            return numberOfSolutions ;
        }
    };