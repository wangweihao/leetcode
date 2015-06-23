/*
 * =====================================================================================
 *
 *       Filename:  32.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月18日 12时13分01秒
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

int longestValidParentheses(char* s) {
    char *p = s;
    char *q;
    int ret = 0;
    int left;
    int right;
    while(*p != '\0'){
        if(*p == ')'){
            ++p;
            continue;
        }else if(*p == '('){
            left = 1;
            right = 0;
            q = p+1;
            while(*q != '\0'){
                //printf("s:%s\n", q);
                if(*q == '('){
                    left++;
                }else if(*q == ')'){
                    right++;
                }
                if(right == left){
                    if(right+left > ret){
                        ret = right+left;
                        //printf("ret:%d\n", ret);
                    }
                }else if(right > left){
                    p = q;
                    q++;
                    break;
                }
                ++q;
            }
            ++p;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
	char *s = "(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((";
    int ret = longestValidParentheses(s);
    printf("%d\n", ret);

	return EXIT_SUCCESS;
}


