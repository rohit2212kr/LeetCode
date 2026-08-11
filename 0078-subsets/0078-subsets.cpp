class Solution {
public:
    vector<vector<int>> ans;
    void btrack(int i, vector<int>& curr, vector<int>& nums) {
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        } 

        curr.push_back(nums[i]);
        btrack(i+1, curr, nums);
        curr.pop_back();

        btrack(i+1, curr, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;

        btrack(0, curr, nums);
        return ans;
    }
};