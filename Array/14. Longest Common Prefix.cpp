class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            sort(strs.begin() , strs.end()) ;
    
            string first = strs[0] ;
            string ans = "" ;
            for (int c = 0 ; c < first.size() ; c++) {
                bool isSame = true ;
                for (int i = 1 ; i < strs.size() ; i++) {
                    if (first[c] != strs[i][c]) {
                        isSame = false ;
                        break;
                    }
                }
                if (!isSame)
                    break;
    
                ans += first[c] ;
            }
    
            return ans ;
        }
    };