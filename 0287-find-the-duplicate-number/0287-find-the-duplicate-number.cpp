class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int fast = 0;
        int slow = 0;

        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow == fast){
                break;
            }
        }
        int s = 0;
        while(s!=fast){
            s = nums[s];
            fast = nums[fast];
        }
        return s;

    }
};