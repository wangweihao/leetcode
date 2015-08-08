#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int myAtoi(string str)
{
    string s = "0123456789";
    if(str.size() == 0)
        return 0;
    //截取出字符串,不应该有0
    auto beg = str.find_first_of("123456789");
    if(beg >= str.size())
        return 0;
    auto end = beg+2;
    while(1)
    {
        if(str[end] >= 48 && str[end] <= 57)
        {
            ++end;
        }else
        {
            break;
        }
    }
    auto ret = str.substr(beg, end-beg);
    int flag = 0;
    //找寻负号的个数，判断正负
    for(int i = 0; i <= beg; ++i){
        if(str[i] == '-')
        {
            flag++;
        }
    }
    //如果数字位数超过最大值位数，越界，判断正负后直接返回
    if(ret.size() > 10)
    {
        if(flag%2 == 1){
            return -2147483648;
        }else{
            return 2147483647;
        }
    }
    //声明为double因为double范围大可以找到越界的情况
    double d = 0;
    int t = ret.size()-1;
    //字符串转化为整型
    for(char a:ret)
    {
        d += (a-48)*pow(10,t);
        t--;
    }
    //转化正负
    if(flag%2 == 1)
        d = -d;
    //判断是否数字位数相等且越界越界，越界返回最大或者最小值
    if(d > 2147483647){
        return 2147483647;
    }else if(d < -2147483648){
        return -2147483648;
    }else{
        //将double转换为int返回
        return static_cast<int>(d);
    }


    return 0;
}

int main(int argc, char *argv[])
{
    cout << myAtoi("   123456") << endl;
    cout << myAtoi("u123456") << endl;
    cout << myAtoi("123 123") << endl;
    cout << myAtoi("---123456") << endl;
    cout << myAtoi("+-2") << endl;
    cout << myAtoi("-+2") << endl;
    cout << myAtoi("----u123456") << endl;
    cout << myAtoi("-111111111111111") << endl;
    cout << myAtoi("111111111111111") << endl;


    return EXIT_SUCCESS;
}
