class Solution {
public:
    vector<vector<int>> ans;
    void btrack(int start, vector<int>& nums, vector<int>& curr){
       
        ans.push_back(curr);
         
        // somthing to check the duplicate in ans....i cant figure out
        for(int i = start; i<nums.size(); i++){
            if(i> start && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            btrack(i+1,nums, curr);
            curr.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        btrack(0, nums, curr);
        return ans;
    }
};