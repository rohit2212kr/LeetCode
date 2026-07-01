class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st;

        for (int a : asteroids) {

            while (!st.empty() && st.back() > 0 && a < 0) {
                if (abs(st.back()) < abs(a)) {
                    st.pop_back();

                } else if (abs(st.back()) == abs(a)) {
                    st.pop_back();
                    a = 0;
                    break;
                }
                else{
                    a = 0;
                }
            }
            if(a != 0){
                st.push_back(a);
            }
        }
        return st;
    }
};