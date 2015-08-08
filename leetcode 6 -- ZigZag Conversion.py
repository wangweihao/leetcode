#!usr/bin/env python
#coding:UTF-8

List = []
NewList = []

def func(str, numRows):
    size = numRows*2-2
    if size == 0:
        return size
    if len(str)%size == 0:
        g = len(str)/size
    else:
        g = len(str)/size+1
        str += (size-len(str)%size)*' '
    for i in range(g):
        List.append(str[size*i:size*i+size])

    for s in List:
        print s
        l1 = list(s[:numRows])
        l2 = list(s[size:size/2:-1].center(numRows))
        NewList.append(l1)
        NewList.append(l2)
    s = ''
    print NewList
    for i in range(numRows):
        for j in NewList:
            if j[i] != ' ':
                s += j[i]
    print s



if __name__ == '__main__':
    func('PAYPALISHIRING', 3)
