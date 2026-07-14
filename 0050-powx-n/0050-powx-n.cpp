class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x = 1/x;
            N= -N;
        }
        return rec(x, N);
    }

    double rec(double x, long long N){
        if(N == 0) return 1;

        double half = rec(x, N/2);
        double res = half * half;

        if(N%2 != 0){
            res = res*x;
        }
        return res;
    }
};