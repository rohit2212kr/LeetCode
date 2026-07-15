class Solution {
public:
    int MOD = 1e9 + 7;  //10^9 + 7
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n-odd;

        long long e = rec(5, even);
        long long o = rec(4, odd);

        long long ans = (e*o)%MOD;

        return ans;

    }
    
    int rec(long long base, long long exp){
        if(exp == 0) return 1;

        long long half = rec(base, exp/2);
        long long res = (half*half)%MOD;

        if(exp%2 != 0){
            res = (res*base)%MOD;
        }
        return res;
    }
};