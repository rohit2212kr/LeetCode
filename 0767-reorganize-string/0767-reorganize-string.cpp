class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for(char c : s){
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto f : freq){
            pq.push({f.second, f.first});
        }

        string ans = "";

        char prev = '#';

        while(ans.size() < s.size()){
            if(pq.empty()){
                return "";
            }

            auto curr = pq.top();
            pq.pop();

            if(curr.second == prev){
                if(pq.empty()){
                    return "";
                }

                auto next = pq.top();
                pq.pop();

                ans += next.second;
                next.first--;

                if(next.first > 0){
                    pq.push(next);
                }

                pq.push(curr);
                prev = next.second;
            }
            else{
                ans += curr.second;
                curr.first--;

                if(curr.first > 0){
                    pq.push(curr);
                }

                prev = curr.second;
            }
        }

        return ans;
    }
};