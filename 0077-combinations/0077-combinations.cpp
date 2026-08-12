class Solution {
public:


    vector<vector<int>> ans;

    void btrack(int i, int n, int k, vector<int>& curr){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if(i>n) return;

        curr.push_back(i);
        btrack(i+1, n, k, curr);
        curr.pop_back();

        btrack(i+1, n, k, curr);
    }




    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;

        btrack(1, n, k, curr);

        return ans;
    }
};