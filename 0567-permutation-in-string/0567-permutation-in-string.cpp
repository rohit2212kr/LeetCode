class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        unordered_map<char, int> mp;
        unordered_map<char, int> ap;
        for(char c : s1){
            mp[c]++;
        }
        int i = 0;
        int j = 0;

        while(j<n){
            ap[s2[j]]++;
            if((j-i+1) == s1.size()){
                if(ap == mp){
                    return true;
                }
                ap[s2[i]]--;
                if(ap[s2[i]] == 0){
                    ap.erase(s2[i]);
                }
                i++;
            }
            j++;
        }
        return false;
    }
};