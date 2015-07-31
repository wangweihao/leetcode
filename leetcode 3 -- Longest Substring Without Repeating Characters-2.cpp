//比较函数
static int 
compare(const void *p1, const void *p2){
    return strcmp(*(char*const*)p1, *(char*const*)p2);
}

//比较相同长度的函数
int cmp_same(char *p1, char *p2){
    int ret = 0;
    while(*p1 != '\0' && *p2 != '\0'){
        if(*p1 == *p2){
            ++p1;
            ++p2;
            ++ret;
        }
    }
    return ret;
}

int lengthOfLongestSubstring(char* s) {
    const int num = strlen(s);
    //指针数组
    char *p[num];
    int i = 0;
    int ret_size = 0;
    int t = 0;
    //指针数组初始化
    for(i = 0; i < num; ++i){
        p[i] = s+i;
    }
    //排序指向字符串的指针
    qsort(p, num, sizeof(char*), compare); 
    for(i = 0; i < num-1; ++i){
        //找到公共前缀
        t = cmp_same(p[i], p[i+1]);
        if(t > ret_size){
            ret_size = t;
        }
    }
    return ret_size;
}
