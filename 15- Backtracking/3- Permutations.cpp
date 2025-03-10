class Solution {
    public:
    vector<vector<int>> ans ;

    void solve(vector<int>& nums , int index) {
        if (index == nums.size()) {
            ans.push_back(nums) ;
            return;
        }

        for (int i = index ; i < nums.size() ; i++) { // for options
            swap(nums[index] , nums[i]); // do
            solve(nums , index + 1 ); // recurese
            swap(nums[index] , nums[i]) ;  // undo
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums , 0) ;
        return ans ;
    }
};