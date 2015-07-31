#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int min(int a, int b){
    return a<b ? a:b;
}

char * longestPalindrome(char *s){
    int length = strlen(s);
    const int N = 2*length+1;
    char a[N];
    int len[N];
    int i;
    a[0] = '@';
    a[1] = '#';
    for(i = 0; i < length; ++i){
        a[2*i+2] = s[i];
        a[2*i+3] = '#';
    }
    a[2*length+2] = '\0';
    printf("%s\n", a);

    int RightMax = 0;//最大右边值
    int MaxLen = 0;//最大长度
    int po = 0;//最大长度的中间节点
    for(i = 0; i < N; i++){
        //说明可以不匹配或者匹配剩余
        if(RightMax > i){
            len[i] = min(RightMax-i, len[2*po-i]);
        }else{
            //需要自己匹配
            len[i] = 1;
        }
        while(a[i-len[i]] == a[len[i]+i]){
            len[i]++;
        }
        //是否需要更新右边最大坐标值
        if(len[i]+i > RightMax){
            RightMax = len[i]+i;
            po = i;
        }
        if(len[i] > MaxLen){
            MaxLen = len[i];
        }
    }
    printf("%d\n", MaxLen-1);
    printf("%d\n", po);
    char p[1000];
    int j;
    //提取结果字符串
    for(i = po-MaxLen+1, j = 0; i < po+MaxLen; ++i){
        printf("%c",a[i]);
        if(a[i] != '#'){
            p[j] = a[i];
            j++;
        }
    }
    printf("\n");
    p[j] = '\0';
    printf("%s\n", p);
}

int main(int argc, char *argv[])
{
    char *s = "zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez";
    char *p = longestPalindrome(s);

    return EXIT_SUCCESS;
}
