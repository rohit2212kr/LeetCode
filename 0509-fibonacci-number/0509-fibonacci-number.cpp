class Solution {
public:
    unordered_map<int, int> mp;
    int fib(int n) {
        if(n<=1) return n;
        if(mp.find(n) != mp.end()){
            return mp[n];
        }
        int ans = fib(n-1) + fib(n-2);
        mp[n] = ans;
        return ans;
    }
};