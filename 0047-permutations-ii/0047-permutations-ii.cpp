class Solution {
public:
    vector<vector<int>> ans;
    void btrack( vector<int>& nums, vector<int>& curr, vector<bool>& used){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i =0; i< nums.size(); i++){
            if(used[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            curr.push_back(nums[i]);
            used[i] = true;
            btrack( nums, curr, used);
            used[i] = false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used( nums.size(), false);
        sort(nums.begin(), nums.end());
        btrack( nums, curr, used);
        return ans;

    }
};