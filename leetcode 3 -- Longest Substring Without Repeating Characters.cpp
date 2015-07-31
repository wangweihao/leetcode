class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret_size = 0;
        int j = -1;
        int hash[256];
        memset(hash, -1, sizeof(hash));
        for(int i = 0; i < s.size();i++){
            //说明s[i]出现过
            if(hash[s[i]] > j){
                //i(右)和j(左)就相当于滑动窗口的边界，改变i,j值就是移动滑动窗口
                j = hash[s[i]];
            }
            //比较并更新返回值
            if(i-j > ret_size){
                ret_size = i-j;
            }
            //记录出现过的下标
            hash[s[i]] = i;
        }
        return ret_size;
    }
};
