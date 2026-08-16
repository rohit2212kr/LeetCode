class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void btrack(int index, string digits, string& curr){
        if(curr.size() == digits.size()){
            ans.push_back(curr);
            return;
        }
        string letter = mp[digits[index] - '0'];

        for(char c : letter){
            curr.push_back(c);
            btrack(index+1, digits, curr);
            curr.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string curr;
        btrack(0, digits, curr);
        return ans;
    }

};