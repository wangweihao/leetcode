//要考虑的情况很多，包括数组为空，两个给定数组的顺序是小到大还是大到小，一些边界问题等等。
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3(nums1.size()+nums2.size());
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        //任意一个数组为空的情况
        if(nums1.size() == 0){
            if(nums2.size()%2 == 0){
                return static_cast<double>(nums2[nums2.size()/2-1]+nums2[nums2.size()/2])/2;
            }else{
                return nums2[nums2.size()/2];
            }
        }
        if(nums2.size() == 0){
            if(nums1.size()%2 == 0){
                return static_cast<double>(nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2;
            }else{
                return nums1[nums1.size()/2];
            }
        }
        //从小到大排列的数组和从大到小排列的数组
        if(*nums1.begin() < *(nums1.end()-1)){
            while(iter1 != nums1.end() && iter2 != nums2.end()){
                if(*iter1 < *iter2){
                    nums3.push_back(*iter1);
                    ++iter1;
                }else{
                    nums3.push_back(*iter2);
                    ++iter2;
                }
            }
        }else{
           while(iter1 != nums1.end() && iter2 != nums2.end()){
                if(*iter1 > *iter2){
                    nums3.push_back(*iter1);
                    ++iter1;
                }else{
                    nums3.push_back(*iter2);
                    ++iter2;
                }
            }
        }
        //copy剩余的数组
        if(iter1 != nums1.end()){
            copy(iter1, nums1.end(), nums3.end());
        }else if(iter2 != nums2.end()){
            copy(iter2, nums2.end(), nums3.end());
        }
        int size = nums3.size();
        if(size%2 == 0){
            return static_cast<double>(nums3[size/2] + nums3[size/2-1])/2; 
        }else{
            return nums3[size/2];
        }
    }
};
