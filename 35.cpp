/*
 * =====================================================================================
 *
 *       Filename:  35.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2015年06月24日 00时24分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (wangweihao), 578867817@qq.com
 *        Company:  xiyoulinuxgroup
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int>&nums, int target){
    int index;
    int left = 0;
    int right = nums.size()-1;
    int mid = 0;
    while(left <= right){
        mid = left+(right-left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << "left:" << left << " right:" << right << endl;
    return right+1;
}


int main(int argc, char *argv[])
{
	vector<int>ivec = {1,3,5,6};
    int target = 7;

    cout << searchInsert(ivec, target) << endl;

	return EXIT_SUCCESS;
}


