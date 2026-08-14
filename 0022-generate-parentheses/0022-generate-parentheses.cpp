class Solution {
public:
    vector<string> ans;
    void btrack(int close, int open, int n, string& curr){
        if(close  == n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr += '(' ;
            open++;
            btrack(close, open, n, curr);
            open--;
            curr.pop_back();
        }
        if(close<open){
            curr += ')';
            close++;
            btrack(close, open, n, curr);
            close--;
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr;

        btrack(0,0, n, curr);
        return ans;
    }
};