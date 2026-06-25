class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count =0, tarCount =0;

        for(int i =0;i<nums.size() ;i++){
            for(int j =i;j<nums.size();j++){
                if(nums[j] == target )tarCount++;
                if(2 * tarCount > (j-i+1))count++;
            }
            tarCount=0;
        }

        return count;
    }
};