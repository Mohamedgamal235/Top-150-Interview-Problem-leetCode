class Solution {
    int removeDuplicates(vector<int> &nums) {
        int nonDuplicate = 0 ;
        if(nums.size() == 1){return 1;}
        for(int i = 1; i< nums.size(); i++){
            if(nums[nonDuplicate] != nums[i]){
                nonDuplicate++;
                nums[nonDuplicate]= nums[i];
            }
        }
        return nonDuplicate;
    }
};