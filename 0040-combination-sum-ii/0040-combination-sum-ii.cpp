class Solution {
public:
    vector<vector<int>> ans;
    void btrack(int i, int target, vector<int>& cad, vector<int>& curr){
        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(target < 0 || i == cad.size()) return;
        for(int j = i; j<cad.size(); j++){
            if(j>i && cad[j] == cad[j-1]) continue;
            if(cad[j] > target) break;
            curr.push_back(cad[j]);
            btrack(j+1, target-cad[j], cad, curr);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        btrack(0, target, candidates, curr);

        return ans;
    }
};