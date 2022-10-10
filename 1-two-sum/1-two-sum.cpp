class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> v;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]+nums[j]==target){
        //             v.push_back(i);
        //             v.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return v;
          map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                return {i, m[target - nums[i]]};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
        
        
    }
};