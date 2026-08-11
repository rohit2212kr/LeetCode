class Solution {
public:
    vector<vector<int>> ans;

    void btrack(int i, int target, vector<int>& curr, vector<int> cad){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if (target < 0 || i == cad.size()) return;
        
        curr.push_back(cad[i]);
        btrack(i, target -cad[i], curr, cad);
        curr.pop_back();

        btrack(i+1, target, curr, cad);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        btrack(0, target, curr, candidates);
        return ans;
    }
};