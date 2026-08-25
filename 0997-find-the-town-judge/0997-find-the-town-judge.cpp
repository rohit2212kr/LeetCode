class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> incoming(n + 1, 0);
        vector<int> outgoing(n + 1, 0);

        for(int i = 0; i < trust.size(); i++){
            
            int a = trust[i][0];
            int b = trust[i][1];

            outgoing[a]++;
            incoming[b]++;
        }

        for(int person = 1; person <= n; person++){
            
            if(incoming[person] == n - 1 && outgoing[person] == 0)
                return person;
        }

        return -1;
    }
};