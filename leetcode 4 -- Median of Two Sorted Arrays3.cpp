int min(int a, int b){
    return a < b ? a : b;
}

double findMedian(int *a, int n, int *b, int m, int k){
    //假定a是短的数组，如果不是则交换a，b位置
    if(n > m){
        findMedian(b, m, a, n, k);
    }
    if(n == 0){
        return b[k-1];
    }
    if(k == 1){
        return min(a[0], b[0]);
    }
    int p = min(k/2, n), q = k-p;
    //判断截取的部分
    if(a[p-1] > b[q-1]){
        //截取b数组，且原本寻找第k个元素变为寻找k-q个元素，进一步缩小了范围，下面类似，可以看出k在不断变化。
        return findMedian(a, n, b+q, m-q, k-q);
    }else if(a[p-1] < b[q-1]){
        return findMedian(a+p, n-p, b, m, k-p);
    }else{
        return a[p-1];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size;
    if(size%2 == 0){
        return findMedian(nums1, nums1Size, nums2, nums2Size, size/2+1);
    }else{
        return (findMedian(nums1, nums1Size, nums2, nums2Size, size/2+1) + findMedian(nums1, nums1Size, nums2, nums2Size, size/2))/2;
    }
}
