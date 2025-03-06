class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans ;
            sort(nums.begin() , nums.end());
            for (int i = 0 ; i < nums.size() - 2 ; i++) {
                if (i > 0 && nums[i] == nums[i-1])
                    continue;
                int l = i + 1 , r = nums.size() - 1 ;
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r] ;
                    if (sum < 0)
                        l++ ;
                    else if (sum > 0)
                        r-- ;
                    else {
                        ans.push_back({nums[i] , nums[l] , nums[r]});
                        // to handel duplicates
                        l++ ;
                        while (l < r && nums[l] == nums[l-1])
                            l++;
                        r-- ;
                        while (l < r && nums[r] == nums[r+1])
                            r-- ;
                    }
                }
            }
            return ans ;
        }
    };