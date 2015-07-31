class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //返回值
        vector<int>ret;
        //建立映射
        map<int,int>mp;
        for(int i = 0; i < nums.size(); ++i){
            //在map中查找，如果找到说明之前出现过对应的值
            if(mp.find(nums[i]) == mp.end()){
                mp[target - nums[i]] = i;
            }else{
                ret.push_back(mp[nums[i]]+1);
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
