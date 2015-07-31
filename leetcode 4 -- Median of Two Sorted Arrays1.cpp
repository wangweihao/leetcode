class Solution { 
public: 
    //虽然时间复杂度不满足要求，但是这段代码的确通过了- -
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        int n = nums1.size(); 
        nums1.resize(nums1.size()+nums2.size()); 
        auto iter = nums1.begin() + n; 
        copy(nums2.begin(), nums2.end(), iter); 
        sort(nums1.begin(), nums1.end()); 
        if(nums1.size()%2 == 0){ 
            return static_cast<double>(nums1[nums1.size()/2-1] + nums1[nums1.size()/2])/2; 
        }else{ 
            return nums1[nums1.size()/2]; 
        } 
    } 
}; 
