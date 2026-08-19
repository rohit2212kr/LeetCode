class Solution {
public:
    priority_queue<int> pq;
    int findKthLargest(vector<int>& nums, int k) {
        for(int i : nums){
            pq.push(i);
        }
        for(int i = 0; i<k-1; i++){
            pq.pop();
        }
        return pq.top();
    }
};