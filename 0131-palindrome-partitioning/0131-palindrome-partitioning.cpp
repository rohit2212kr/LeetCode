class Solution {
public:

    vector<vector<string>> ans;

    void btrack(int start, vector<string>& curr, string s){
        if(start == s.size()){
            ans.push_back(curr);
            return;
        }
        for(int end = start; end< s.size(); end++){
            int left = start;
            int right = end;
            bool palindrome = true;
            while(left<right){
                if(s[left] == s[right]){
                    left++;
                    right--;
                }
                else{
                    palindrome = false;
                    break;
                }
            }
            if(palindrome){
                curr.push_back(s.substr(start, end-start+1));
                btrack(end+1, curr, s);
                curr.pop_back();
            }

            

        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        btrack(0, curr, s);
        return ans;
    }
};