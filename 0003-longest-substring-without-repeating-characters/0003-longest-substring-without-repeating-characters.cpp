class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =  s.size();
        unordered_map<char, int> mp;
        int maxi = 0;
        
        int i = 0;
        int j = 0;
        
        while(j<n){
            while(mp.find(s[j]) != mp.end()){
                mp[s[i]]--;
                mp.erase(s[i]);
                i++;   
            }
            mp[s[j]]++;
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};