#!/usr/bin/env python
#coding:UTF-8

def isMatch(s, p):
    if len(p) == 0:
        return len(s) == 0
    if len(p) == 1:
        return len(s) == 1 and p[0] == s[0]
    if p[1] == '*':
        while len(s) != 0 and (p[0] == '.' or p[0] == s[0]):
            if isMatch(s, p[2:]):
                return True
            s = s[1:]
        return isMatch(s, p[2:])
    else:
        if len(s) != 0 and (p[0] == '.' or p[0] == s[0]):
            return isMatch(s[1:], p[1:])
        return False

if __name__ == '__main__':
    print isMatch('aa', 'a')
    print isMatch('aa', 'aa')
    print isMatch('aaa', 'a')
    print isMatch('aa', '.*')
    print isMatch('ab', '.*')
    print isMatch('aab', 'c*a*b')
    print isMatch('aaaab', '.*ab')
    print isMatch('aaaaaaaaccc', 'a*ccc')
