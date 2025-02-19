class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int cnt = 0 ;
            int curr = -1 ;
            vector<int> ans ;
            for (auto x : nums) {
                if (curr != x) {
                    cnt = 1 ;
                    curr = x ;
                    ans.push_back(x) ;
                }
                else if (curr == x && (cnt + 1) <= 2) {
                    cnt++ ;
                    ans.push_back(x) ;
                }
            }
    
            nums = ans ;
            return ans.size() ;
        }
    };