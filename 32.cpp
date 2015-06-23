/*
 * =====================================================================================
 *
 *       Filename:  32-2.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2015年06月18日 12时44分01秒
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
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int longestValidParentheses(string s) {
    stack<int>sk;
    vector<int>ivec(s.length());
    for(int &i : ivec){
        i = 0;
    }
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '('){
            sk.push(i);
        }else if(s[i] == ')' && !sk.empty()){
            ivec[i] = 1;
            ivec[sk.top()] = 1;
            sk.pop();
        }
    }
    int ret= 0;
    int tmp = 0;
    for(const int &i : ivec){
        cout << i << endl;
        if(i == 1){
            tmp++;
        }else{
            if(tmp > ret){
                ret = tmp;
                cout << "ret:" << ret << endl; 
                tmp = 0;
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
	string s = "()";
    std::cout << longestValidParentheses(s) << std::endl;

	return EXIT_SUCCESS;
}


